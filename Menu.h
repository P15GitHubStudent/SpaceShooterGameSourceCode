#pragma once

#include<SFML\Graphics.hpp>
#include"GameEngine.h"
#include"SelectMap.h"
#include"State.h"
#include"MenuStates.h"
#include<array>
#include<memory>

class MenuPhases : public sf::Drawable 
{
protected:
	
	State & gameState;
	//MenuStates & menuState;
	sf::RenderWindow & win;
	sf::Event & ev;
	Map * & MenuMap;
	const sf::Font & font;
	MenuStates  menuState;


	virtual void draw(sf::RenderTarget& target, sf::RenderStates states)const
	{
		target.draw(*MenuMap);
	}

public:
	MenuPhases(sf::RenderWindow & window, sf::Event & Event, Map *& menuMap, const sf::Font & Font, State & GameState) :win(window), ev(Event), MenuMap(menuMap), font(Font)
		, gameState(GameState)
	{

	}

	MenuStates& getMenuState()
	{
		return menuState;
	}


	virtual void Update()
	{
		MenuMap->update();
	}


	virtual void Events()
	{
		if (ev.type == sf::Event::Closed)
		{

			gameState = State::EXIT;
			
		}
	}

	virtual ~MenuPhases()
	{
		//std::cout << "~MenuPhases" << "\n";
	}            



	};


class Counters
{

private:
	int counter;
	int min;
	int max;
public:
	Counters(int min, int max)
	{
		int tmp;
		if (min > max)
		{
			tmp = min;
			min = max;
			max = tmp;

		}
		counter = min;
		this->min = min;
		this->max = max;
	}

	void increaseCounter(const int & num=1)
	{
		counter = counter < max ? counter + num : max;
	}

	void decreaseCounter(const int & num=1)
	{
		counter = counter < min ? counter - num : min;
	}


	Counters operator ++()
	{
		increaseCounter();
	}

	Counters operator ++(int)
	{
		Counters counter(min, max);

		increaseCounter();

		return counter;
	}

	Counters operator --()
	{
		decreaseCounter();
	}

	Counters operator --(int)
	{
		Counters counter(min, max);
		
		decreaseCounter();

		return counter;
	}

	Counters operator += (const int  & num)
	{
		increaseCounter(num);
		return *this;
	}

	Counters operator -=(const int & num)
	{
		counter -= num;
		return *this;
	}


	int getCounter()const
	{
		return counter;
	}

};

extern SelectedMap selectedMap;

class MenuSelectMapPhase : public MenuPhases 
{

  private:
	sf::View MapView1;
	sf::View MapView2;
	sf::RectangleShape  mapSelector;
	Counters menuCounter;
	bool returnPressed;
	std::array<std::unique_ptr<Map>,2> ArrayMap;
	mutable sf::Text text;
	Delay delay;
	float currentDelay;
	


	void draw(sf::RenderTarget & target, sf::RenderStates states)const
	{
		
		MenuPhases::draw(target, states);

		target.draw(mapSelector);

		target.setView(MapView1);

		target.draw(*ArrayMap[0]);

		target.setView(target.getDefaultView());

		target.setView(MapView2);

		target.draw(*ArrayMap[1]);

		target.setView(target.getDefaultView());

		text.setPosition(sf::Vector2f(300, 0));

		text.setString(L"Διάλλεξε Πίστα ");

		//text.setColor(sf::Color::Red);
		
		text.setStyle(sf::Text::Style::Underlined);

		target.draw(text);

		text.setCharacterSize(25);

		text.setPosition(0, text.getCharacterSize()+4);

		text.setString(L"Χρησιμοποίησε τα βελάκια( -> <- ) Enter για να επιλέξεις τρέχων πίστα");

		text.setStyle(sf::Text::Style::Regular);

		target.draw(text);


	}


	

public:
	MenuSelectMapPhase(sf::RenderWindow & window, sf::Event & Event, Map * &  menuMap, const sf::Font & Font, State & GameState) :MenuPhases(window, Event, menuMap, Font, GameState), menuCounter(0,1)
	{
		
		menuState = MenuStates::MapOption;

		currentDelay = 0;

		delay.SetUpdateTime(currentDelay);

		text.setFont(Font);
		//text.setString(L"Διαθέσιμες Πίστες\n Χρησιμοποιστέ τα δεξιά αριστερά βελάκια για να διαλέξεις την πίστα  \n μόλις αποφασίσεις ποια πίστα θές πάτα το Enter");
		//text.setPosition(330, 0);
		//text.setColor(sf::Color::Red);
		//text.setStyle(sf::Text::Style::Underlined);
		
		returnPressed = false;
		mapSelector.setFillColor(sf::Color::Transparent);
		mapSelector.setOutlineThickness(1.1);
		mapSelector.setSize(sf::Vector2f(283, 130));
		mapSelector.setOutlineColor(sf::Color::Red);
		mapSelector.setPosition(sf::Vector2f(400,300));
		MapView1.setViewport(sf::FloatRect(0, 0.5, 0.35, 0.35));
		MapView2.setViewport(sf::FloatRect(0.5, 0.5, 0.35, 0.35));
		ArrayMap[1] = std::unique_ptr<Map>(new Map2());
		ArrayMap[0] = std::unique_ptr<Map>(new Map1());
		for (int c = 0; c < 2; c++)ArrayMap[c]->createMap();
		
	   
	}

	 void Update()
	{
		MenuMap->update();

		for (int c = 0; c < ArrayMap.size(); c++)ArrayMap[c]->update();

		mapSelector.setPosition(menuCounter.getCounter() * 400, 300);

		MenuMap = &(*ArrayMap[menuCounter.getCounter()]);

		delay.IncreaseTime();

		if (returnPressed)
		{
          
			//selMap = menuCounter.getCounter() >0 ? SelectMap::Map1 : SelectMap::Map2;
			SelectedMap::selectedmap = menuCounter.getCounter();
			menuState = MenuStates::SELECT;
			
		}
		
		
	}



	 void Events()
	 {
		 while (win.pollEvent(ev))
		 {
			 MenuPhases::Events();

			 if (!delay.IsTimeToUpdate())return;

			 currentDelay = 0;

			 delay.SetUpdateTime(currentDelay);

			 switch (ev.type)
			 {

			 case sf::Event::KeyPressed:
				 if (ev.key.code == sf::Keyboard::Right)
				 {
					 menuCounter++;
					 currentDelay = 0.6;
					 delay.SetUpdateTime(currentDelay);
				 }
				 if (ev.key.code == sf::Keyboard::Left)
				 {
					 menuCounter--;
					 currentDelay = 0.6;
					 delay.SetUpdateTime(currentDelay);
				 }

				 if (ev.key.code == sf::Keyboard::Return)
				 {
					 returnPressed = true;
//sexy comment 					 
				 }

				 //if (ev.key.code == sf::Keyboard::Return)ReturnKeyPressed = true;
				 break;
			 }

		 }
	 }



};



class MenuSelectPhase : public MenuPhases 
{

private:

	sf::RectangleShape & optionSelectorRectRef;
	sf::Text & optionTextsRef;
	int menuCounter;
	const int MaxSelectOption,PlayOption,mapOption,quitOption;
	bool ReturnKeyPressed;


	void draw(sf::RenderTarget& target, sf::RenderStates states)const
	{
		MenuPhases::draw(target, states);

		optionSelectorRectRef.setPosition(300, 140 * (menuCounter + 1));

		target.draw(optionSelectorRectRef);

		for (int c = 0; c < MaxSelectOption; c++)
		{
			 sf::String string = getStringMenuPhase1(c);
			 optionTextsRef.setString(string);
			 optionTextsRef.setPosition(sf::Vector2f(400, (c + 1) * 142));
			 target.draw(optionTextsRef);
		}


	}

	sf::String getStringMenuPhase1(int index)const 
	{
		switch (index)
		{
		case 0:
			return sf::String(L"Παίξε");
			break;
		case 1:
			return sf::String(L"Επιλογή Πίστας");
			break;

		case 2:
			return sf::String(L"Εξοδος");
			break;
		}
	}

public:

	MenuSelectPhase(sf::RenderWindow & window, sf::Event & Event, Map *&  menuMap, const sf::Font & Font, sf::RectangleShape & OptionSelector, sf::Text & TextMenu, State & state) :MenuPhases(window, Event, menuMap, Font, state)
	, optionTextsRef(TextMenu), optionSelectorRectRef(OptionSelector), menuCounter(0), MaxSelectOption(3), PlayOption(0), mapOption(1), quitOption(2) // να το επαναφέρω
	{
		menuState = MenuStates::SELECT;
		ReturnKeyPressed = false;
	}


	 void Update()
	{
		MenuPhases::Update();

		if (ReturnKeyPressed)
		{

			if (menuCounter == PlayOption)
			{
				gameState = State::PLAY;	
			}
			else if (menuCounter == mapOption)
			{
				menuState = MenuStates::MapOption;
			}
			else
			{
				gameState = State::EXIT;
			}

			ReturnKeyPressed = false;
		}

	}

	 
	void Events()
	{
		while (win.pollEvent(ev))
		{
			MenuPhases::Events();

			switch (ev.type)
			{
				
			case sf::Event::KeyPressed:
				if (ev.key.code == sf::Keyboard::Down && menuCounter < MaxSelectOption-1)
					menuCounter++;
				if (ev.key.code == sf::Keyboard::Up && menuCounter > 0)menuCounter--;
				if (ev.key.code == sf::Keyboard::Return)ReturnKeyPressed = true;
				break;
			}

		}
	}


	~MenuSelectPhase()
	{
		//std::cout << "~MenuSelectPhase" << "\n";
	}


};


class Menu : public GameStates
{

private:
	int MenuCounter;
	sf::RenderWindow & win;
	sf::Event & ev;
	Map * MenuMap;
	const sf::Font & Font;
	sf::Text Text; 
	sf::RectangleShape Buttons;
	sf::String  getStringMenuPhase1(int Index);
	MenuStates menuCurrentState;
	MenuPhases * menuphases;
	void UpdateMenuState();
	void UpdateMenuPhasePtr(MenuStates newMenuState);
public:

	Menu(sf::RenderWindow & window, sf::Event & event,const sf::Font & font);
	void Events();
	void draw();
	void Update();
	Menu();
	~Menu();
};

