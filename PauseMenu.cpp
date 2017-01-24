#include "PauseMenu.h"



PauseMenu::PauseMenu(sf::RenderWindow & window, sf::Event & event, const sf::Font & Font, State & State) :ev(event), win(window), stateRef(State)
{ 
	state =State::PLAY;
	counter = 0;
	PauseText.setFont(Font);
	PauseText.setPosition(500, 300);
	PauseText.setOrigin(200, 150);
	PauseText.setString(L"Παιχνίδι σταμάτησε \n\n κύριο Μενού \n\n Επανεκκίνιση");
	PauseText.setColor(sf::Color::White);
	rect.setPosition(250,230);
	rect.setSize(sf::Vector2f(25, 25));
	rect.setFillColor(sf::Color::Red);
	enterPressed = false;

}

void PauseMenu::draw()
{
	
	//playingStatePtr->draw();
	win.draw(rect);
	win.draw(PauseText);
}



void PauseMenu::Events()
{

	if (ev.key.code == sf::Keyboard::Down&&counter<1)
	{
		counter++;
	}
	else if (ev.key.code == sf::Keyboard::Up && counter>0)
	{
		counter--;
	}
	else if (ev.key.code == sf::Keyboard::Return)
	{
		enterPressed = true;


	}
}

void PauseMenu::Update()
{

	if (counter == 0)
	{

		rect.setPosition(250, 230);
	}
	
	else if (counter==1)
	{
		rect.setPosition(250, 300);
	}
	
	if (enterPressed)
	{
		if (counter == 0)stateRef = State::MENU;
		else stateRef = State::RESTARTGAME;
	}

}


PauseMenu::~PauseMenu()
{
}
