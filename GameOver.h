#pragma once



#pragma once

#include<SFML\Graphics.hpp>
#include"GameStates.h"
#include"Entity.h"
#include"AIPlayer.h"
#include"Player.h"
#include"Bullets.h"
#include"Maps.h"
#include"Update.h"
#include<vector>
#include"State.h"


class GameOver
{
private:
	sf::RenderWindow & win;
	sf::Event &ev;
	//const sf::Font & font;
	sf::Text PauseText;
	int counter;
	sf::RectangleShape rect;
	bool enterPressed;
	State & stateRef;
	int score;

public:
	GameOver(sf::RenderWindow & window, sf::Event & ev, const sf::Font & font, State & state,int pScore);
	void Events();
	void Update();
	void draw();
	~GameOver();
};

