#include "Menu.h"



Menu::Menu(sf::RenderWindow & window, sf::Event & event, const sf::Font & font) : win(window), ev(event), Font(font)
{


	state = State::MENU;
	MenuMap = new Map1();

	Map1::InitializeMap();
	Map2::InitializeMap();

	MenuMap->createMap();

	Buttons.setSize(sf::Vector2f(300, 29));

	Buttons.setFillColor(sf::Color::Red);

	Buttons.setPosition(300, 135);

	Text.setFont(font);

	Text.setCharacterSize(18);

	menuCurrentState = MenuStates::SELECT;

	//Text.setColor(sf::Color::Yellow);

	MenuCounter = 0;
	
	menuphases = new MenuSelectPhase(win, ev, MenuMap, font, Buttons, Text,state);

	//menuphases = new MenuSelectMapPhase(win, ev, MenuMap, font, state);
}


void Menu::UpdateMenuPhasePtr(MenuStates newMenuState)
{
	//delete menuphases;
	//menuphases = nullptr;
	if (newMenuState == MenuStates::SELECT)
	{
		menuphases = new MenuSelectPhase(win, ev, MenuMap, Font, Buttons, Text, state);
	
	}
	else if (newMenuState == MenuStates::MapOption)
	{
		menuphases = new MenuSelectMapPhase(win, ev, MenuMap, Font, state);
	}

	if (menuphases == nullptr)throw std::runtime_error("menuphases->NULL |NULL POINTER EXCEPTION| ");

}


void Menu::UpdateMenuState()
{
	
	MenuStates updatedMenuState=menuphases->getMenuState();

	if (updatedMenuState != menuCurrentState)
	{
		UpdateMenuPhasePtr(updatedMenuState);
		menuCurrentState = updatedMenuState;
	}

}


void Menu::Events()
{
	menuphases->Events();

}


void Menu::draw()
{
	win.clear();

	win.draw(*menuphases);
	
	win.display();
}


void Menu::Update()
{
	menuphases->Update();

	UpdateMenuState();

}


Menu::~Menu()
{
	delete menuphases;

}
