#include "GameEngine.h"


//https://gamedevelopment.tutsplus.com/articles/enjoy-these-totally-free-space-based-shoot-em-up-sprites--gamedev-2368
//http://www.scratchguide.com/category/general/
//http://opengameart.org/content/2d-planets-0



GameEngine::GameEngine(const sf::Uint32 WinStyle, sf::Vector2i  winDimenion, const sf::String & GameTitle) : win(sf::VideoMode(winDimenion.x, winDimenion.y), GameTitle, WinStyle), GameUpdate(1.0f / 60)
{

	win.setKeyRepeatEnabled(false);
	win.setFramerateLimit(60);

	GameState = State::MENU;

	Render = true;

	if (!GameFont.loadFromFile("fonts/arial.ttf"))throw FAILED_TO_LOAD_FONT("arial.ttf");

	gs = new Menu(win, ev, GameFont);


}

void GameEngine::updateGameStatePtr(GameStates * newGameStatePtr)
{
	if (newGameStatePtr == nullptr)throw std::runtime_error("newGameStatePtr->NULL");

	//GameStates * oldptr = gs;

	delete gs;

	gs = newGameStatePtr;

	//delete oldptr;

}

void GameEngine::updateStates()
{
	State CurrentState = gs->getCurrentState();

	if (CurrentState == GameState)return;

	switch (CurrentState)
	{

	case State::EXIT:
		GameState = State::EXIT;
		break;
	case State::PLAY:
		updateGameStatePtr(new PlayingState(win, ev, GameFont));
		break;
	case State::MENU:
		updateGameStatePtr(new Menu(win, ev, GameFont));
		break;
	case State::RESTARTGAME:
		updateGameStatePtr(new PlayingState(win, ev, GameFont));
		break;
	case State::RESUMEGAME:
		break;
	}

	GameState = CurrentState;


}


void GameEngine::Run()
{

	while (GameState != State::EXIT)
	{

		updateStates();

		gs->Events();


		if (GameUpdate.IsTimeToUpdate())
		{

			Render = true;
			gs->Update();
		}

		if (Render)
		{
			gs->draw();
			Render = false;
		}

		GameUpdate.IncreaseTime();

	}

}


GameEngine::~GameEngine()
{

	delete gs;

}

