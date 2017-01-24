#pragma once

#include<SFML\Graphics.hpp>
#include"GameStates.h"
#include"Entity.h"
#include"AIPlayer.h"
#include"Player.h"
#include"Bullets.h"
#include"Update.h"
#include"State.h"
#include<list>
#include"Explosion.h"
#include"PauseMenu.h"
#include"Maps.h"
#include"Map2.h"
#include<memory>
#include"SelectMap.h"
//#include"AbstactMap.h"


/*
ΝΑ ΜΠΟΡΩ ΝΑ ΓΙΝΕΤΑΙ ΕΠΙΛΟΓΗ ΠΙΣΤΑΣ
ΝΑ ΒΑΛΩ ΗΧΟΥΣ
*/


class PlayingState : public GameStates
{
private:
	Delay playerMoveDelay;
	sf::RenderWindow & win;
	sf::Event & ev;
    sf::Font GuiFont;
	sf::Text PlayerText;
	Map * map; 
	Entity  * PlayerSpaceShip;
	sf::View view;
	std::list<Entity *> enemieList;
	std::list<Entity *> explosionList;
	bool gamePaused;
	bool freezeBullets;
	PauseMenu pauseMenu;
	float freezeBulletsCountDownTimer;
	sf::RectangleShape freezeBulletsRect;
	sf::RectangleShape freezeBulletsColorRect; //το πράσινο χρώμα που θα δείχνει μέσα πόσο χρόνο έχουμε ακόμα για feauture ! 
	Delay increaseCountDownTimer;
	int enemieDestroyCounter;
public:

 virtual void Events();
 virtual void draw();
 virtual void Update();
 PlayingState(sf::RenderWindow & win,sf::Event & ev,const sf::Font & font);
~PlayingState();

};

