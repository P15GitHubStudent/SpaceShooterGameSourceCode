#pragma once

#include<SFML\Graphics.hpp>
#include"Animation.h"
#include<string>
#include<iostream>
#include<list>


class Entity : public sf::Drawable 
{

protected:

	std::string EntName; 
	sf::Sprite EntSprite;
	sf::Vector2f EntPos;
	Animation EntAnimation; //Ent Animation Xreaizetai mia fora to sprite  gia na kanei create to animation !
	sf::Vector2f EntVelocity;
	sf::Vector2f EntSize;
	sf::Text EntNameText;
	float entAcceleration;
	int entAccelerationCounter;
	bool entAccelerated;
	Delay entDelay;
	sf::Text EntText;
	

public:
	bool entityAlive;

	static bool Collide(Entity * entA, Entity * entB)
	{
		return entA->GetEntSprite().getGlobalBounds().intersects(entB->GetEntSprite().getGlobalBounds());
	}

	void moveUp(float Val)
	{
		//EntSprite.move(0, -Val);
		EntPos.y-=Val;
	}
	void moveDown(float Val)
	{
		//EntSprite.move(0, +Val);
		EntPos.y += Val;
		//EntPos.y += Val;
	}

	void moveRight(float Val)
	{
		EntPos.x +=Val;
	}

	void moveLeft(float Val)
	{
		EntPos.x -= Val;
	}

	//void setAccelerated(bool accelerateState);
	//void AccelarateEntity();
	Entity(const std::string & EntityName,const sf::Vector2f & Pos,const sf::Vector2f & EntityVelocity,const sf::Texture & EntTexture);
	Entity();
	void CreateEntity(const std::string & EntityName, const sf::Vector2f & Pos, const sf::Vector2f & EntityVelocity, const sf::Texture & EntTexture);
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states)const;
	virtual void Update();
	virtual void Update2(const sf::Vector2f & playerPosition)
	{
		Update();
	}
	const std::string & GetEntityName()const
	{
		return EntName;
	}

	bool IsEntAlive()const
	{
		return entityAlive;
	}
	const sf::Vector2f & GetEntPos()const;
	const sf::Vector2f & GetEntVelocity()const
	{
		return EntVelocity;
	}

	void setEntDelay(float delay);
	void StopEntAnimations();
	virtual ~Entity(){};
	const sf::Sprite & GetEntSprite()const;

	void setVelocityX(float velocityX);
	void setVelocityY(float veloctiyY);
	void setVelocityVector(const sf::Vector2f & velocity);
	void setEntPos(float x,float y)
	{
		EntSprite.setPosition(x, y);
	}

	static void deleteEntityList(std::list<Entity *> & entlist)
	{


		for (auto & it = entlist.begin(); it != entlist.end();)
		{


			if (it != entlist.end())
			{
				Entity * ent = *it;
				it = entlist.erase(it);
				delete ent;
			}


			if (it != entlist.end())it++;
		}

	}


	static void updateEntityList(std::list<Entity *> & entlist, const sf::Vector2f & entPos)
	{

		for (auto & it = entlist.begin(); it != entlist.end();)
		{
			Entity * ent = *it;

			ent->Update2(entPos);

			if (!ent->IsEntAlive())
			{
				it = entlist.erase(it);
				delete ent;
			}
			else
			{
				it++;
			}

		}

	}

	

	static void updateEntityList(std::list<Entity *> & entlist)
	{

		for (auto & it = entlist.begin(); it != entlist.end();)
		{
			Entity * ent = *it;

			ent->Update();

			if (!ent->IsEntAlive())
			{
				it = entlist.erase(it);
				delete ent;
			}
			else
			{
				it++;
			}

		}
	}

	static void drawEntityList(std::list<Entity *> entlist, sf::RenderWindow & win)
	{
		for (auto it : entlist)
		{
			win.draw(*it);
		}
	}






	
};