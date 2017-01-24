#pragma once

#include<SFML\Graphics.hpp>
#include"Update.h"
#include"SelectMap.h"
#include"AbstactMap.h"
#include"GameStates.h"
#include"PlayingState.h"
#include"State.h"
#include"Menu.h"
#include"PauseMenu.h"



class GameEngine
{
public:

	GameEngine(const sf::Uint32 WinStyle=sf::Style::Default,sf::Vector2i  winDimenion=sf::Vector2i(800,600),const sf::String & GameTitle=L"Παιχνίδι");
	~GameEngine();
	void Run();

	private:

        GameStates * gs;
		sf::Font GuiFont;
		sf::Font GameFont;
		Update GameUpdate;
		bool Render; 
		sf::Event ev;
		sf::RenderWindow win;
		State GameState; // Κρατάμε την τρέχουσα κατάσταση του παιχνιδιού !
		void updateStates();
		void updateGameStatePtr(GameStates * newGameStatePtr);
		/////////////////////////
};

