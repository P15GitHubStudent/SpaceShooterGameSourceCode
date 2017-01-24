
#include"PlayingState.h"
#include"Asteroids.h"
#include"Explosion.h"
#include<sstream>
#include"AbstactMap.h"



PlayingState::PlayingState(sf::RenderWindow & window, sf::Event & event, const sf::Font & font) :win(window), ev(event), pauseMenu(win,ev,font,state)
{


	state = State::PLAY;
	/////////////////////////////////////////
	Map2::InitializeMap();
	map = new Map2();

	if (SelectedMap::selectedmap == 0)map = new Map1();
	else map = new Map2();

	map->createMap();
	/////////////////////////////////////////


	AiPlayer::LoadTextures();
	Asteroids::initTextures();
	Bullets::loadTextures();
	Explosion::loadTexture();

	PlayerSpaceShip = new Player(sf::Vector2f(0, 100), sf::Vector2f(0, 0));

	
	PlayerText.setFont(font);
	PlayerText.setPosition(0, 0);
	PlayerText.setColor(sf::Color::White);


	playerMoveDelay.SetUpdateTime(0.0185);

	////////////////////////////////////////////////////////
	gamePaused = false;
	freezeBullets = false;

	freezeBulletsRect.setPosition(140, 10);
	freezeBulletsRect.setSize(sf::Vector2f(200, 20));
	freezeBulletsRect.setOutlineThickness(1.9f);	
	freezeBulletsRect.setOutlineColor(sf::Color::Red);
	freezeBulletsRect.setFillColor(sf::Color::Black);

	freezeBulletsColorRect.setPosition(140, 10);
	freezeBulletsColorRect.setFillColor(sf::Color::Green);
	freezeBulletsColorRect.setSize(sf::Vector2f(200, 20));


	freezeBulletsCountDownTimer = 100;

	increaseCountDownTimer.SetUpdateTime(10);

}




void PlayingState::Events()
{
	if (Player::getPlayerLives() <= 0)
	{
		pauseMenu.Events();
		return;
	}

	while (win.pollEvent(ev))
	{
		switch (ev.type)
		{

		case sf::Event::Closed:
			state = State::EXIT;
			break;


		case sf::Event::KeyPressed:

			

			if (ev.key.code == sf::Keyboard::Space && !gamePaused)
			{
				
					Player::laserShots.push_back(new Bullets(Bullets::blueFireBullet,sf::Vector2f(PlayerSpaceShip->GetEntPos().x + 30, PlayerSpaceShip->GetEntPos().y + 5), sf::Vector2f(10,0)));
				
			}
			if (ev.key.code == sf::Keyboard::Escape)
			{
				//state = State::PAUSEGAME;
				gamePaused = !gamePaused;
			}
			if (ev.key.code == sf::Keyboard::A && freezeBulletsCountDownTimer>0 && !gamePaused)
			{
				freezeBullets = !freezeBullets;
			}
			if (ev.key.code == sf::Keyboard::Delete && !gamePaused)
			{
				state = State::MENU;
			}

			break;
		}
	}
	
	if (gamePaused)
	{
		pauseMenu.Events();
		return;
	}

	playerMoveDelay.IncreaseTime();

	if (playerMoveDelay.IsTimeToUpdate())
	{ 

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{
			
			PlayerSpaceShip->moveUp(3.5);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		{
			
			PlayerSpaceShip->moveDown(3.5);
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
		
			PlayerSpaceShip->moveRight(5);
			//view.move(sf::Vector2f(5, 0));
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			
			PlayerSpaceShip->moveLeft(5);
			//view.move(sf::Vector2f(-5, 0));
		}

	}


}

void PlayingState::Update()
{

map->update();

if (gamePaused || Player::getPlayerLives()<=0)
{
	pauseMenu.Update();
	return;
}

 PlayerSpaceShip->Update();

 Entity::updateEntityList(enemieList);

 Entity::updateEntityList(explosionList);


 if (!freezeBullets)
 {
	 Entity::updateEntityList(AiPlayer::laserShoots);

	 increaseCountDownTimer.IncreaseTime();

	 if (increaseCountDownTimer.IsTimeToUpdate() && freezeBulletsCountDownTimer < 100)
	 {
	 }
 }
 else
 {
	 freezeBulletsCountDownTimer = freezeBulletsCountDownTimer >0 ? freezeBulletsCountDownTimer-0.1:0;

	 increaseCountDownTimer.RestartClock();

 }

 if (rand() % 110 == 0)
 {
	 int probabilities = rand() % 50; 

	 if (probabilities<= 30)
	 {
		 enemieList.push_back(new AiPlayer(sf::Vector2f(PlayerSpaceShip->GetEntPos().x + 750, rand() % 750), sf::Vector2f(-2, 0)));
	 }
	 else
	 {
		 enemieList.push_back(new Asteroids(sf::Vector2f(PlayerSpaceShip->GetEntPos().x + 750, rand() % 750), sf::Vector2f(-3, 0)));
	 }
	
 }


 for (auto c : enemieList)
 {
	 for (auto j : Player::laserShots)
	 {
		 if (Entity::Collide(c, j))
		 {
			 explosionList.push_back(new Explosion(sf::Vector2f(c->GetEntPos()), sf::Vector2f(0, 0)));
			 c->entityAlive = false;
			 j->entityAlive = false;
			 if (c->GetEntityName() == "asteroid")Player::increasePlayerScore(1);
			 else Player::increasePlayerScore(Player::getPlayerScore() * 0.30+5);
			 if (enemieDestroyCounter >= 60)enemieDestroyCounter = 60;
			 enemieDestroyCounter++;

		 }
	 }

	 if (Entity::Collide(PlayerSpaceShip, c))
	 {
		 c->entityAlive = false;
		 explosionList.push_back(new Explosion(sf::Vector2f(c->GetEntPos()), sf::Vector2f(0, 0)));
		 Player::decreasePlayerLive();
	 }
 }
 
}


void PlayingState::draw()
{
	bool stopGame = false;

	if (gamePaused || Player::getPlayerLives()<=0)stopGame = true;

	win.clear();

	win.draw(*map);

	if (!stopGame)
	{

		std::stringstream pscoreString;
		pscoreString << "Score:" << Player::getPlayerScore() << " \nlives: " << Player::getPlayerLives();
		PlayerText.setString(pscoreString.str());
		win.draw(PlayerText);

		win.draw(*PlayerSpaceShip);
		Entity::drawEntityList(enemieList, win);
		Entity::drawEntityList(explosionList, win);
		Entity::drawEntityList(AiPlayer::laserShoots, win);

		win.draw(freezeBulletsRect);
		freezeBulletsColorRect.setSize(sf::Vector2f(freezeBulletsCountDownTimer * 2, 20));
		win.draw(freezeBulletsColorRect);
	}
	else
	{
		pauseMenu.draw();
	}





//	if (gamePaused|| Player::getPlayerLives()<0)pauseMenu.draw();

	win.display();

}

PlayingState::~PlayingState()
{
	delete PlayerSpaceShip;
	Entity::deleteEntityList(explosionList);
	Entity::deleteEntityList(enemieList);
	Entity::deleteEntityList(AiPlayer::laserShoots);
	AiPlayer::laserShoots.clear();
	explosionList.clear();
	enemieList.clear();
	delete map;
}


