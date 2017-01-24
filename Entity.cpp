#include "Entity.h"
#include<iostream>


//POS,DRAW,SET THE LIFESTATE ! 

Entity::Entity(const std::string & EntityName, const sf::Vector2f & Pos, const sf::Vector2f & EntitiyVelocity,const sf::Texture & EntTexture) :EntName(EntityName), EntPos(Pos)
, EntVelocity(EntitiyVelocity), EntSprite(EntTexture)
{
	entAccelerated = false;
	entityAlive = true;

}

Entity::Entity() : EntName(""), EntPos(0, 0)
{
	entAccelerated = false;
	entityAlive = true;
}

void Entity::draw(sf::RenderTarget& target, sf::RenderStates states)const
{
	target.draw(EntSprite);

}

/*
void Entity::setAccelerated(bool accelerateState)
{

	entAccelerated = accelerateState;
}
*/

void Entity::setEntDelay(float delaysecs)
{
	entDelay.SetUpdateTime(delaysecs);
}

/*
void Entity::AccelarateEntity()
{

	if (entAccelerated)
	{

		if (entAcceleration <3.5)entAcceleration += 0.3;

		entDelay.IncreaseTime();
		 
		if (entDelay.IsTimeToUpdate())
		{
			entAccelerated = false;
			//entAcceleration = 0;
		}

	}

	else
	{

		if (entAcceleration > 0)
		{
			entAcceleration -= 0.3f;
		}
			
		if (entAcceleration < 0)entAcceleration = 0;

	}
}
*/


void Entity::setVelocityX(float velocityX)
{
	EntVelocity.x = velocityX;
}

void Entity::setVelocityY(float velocityY)
{
	EntVelocity.y = velocityY;
}

void Entity::setVelocityVector(const sf::Vector2f & vec)
{
	EntVelocity = vec;
}


void Entity::Update()
{
	
	EntPos.x += EntVelocity.x;
	EntPos.y += EntVelocity.y;
	EntSprite.setPosition(EntPos);
	EntAnimation.Play();


}


void Entity::CreateEntity(const std::string & EntityName, const sf::Vector2f & Pos, const sf::Vector2f & EntityVelocity, const sf::Texture & EntTexture)
{
	EntName = EntityName;
	EntPos = Pos;
	EntVelocity = EntityVelocity;
	EntSprite.setTexture(EntTexture);
	EntSprite.setPosition(EntPos);
	
}


/*Επιστρέφει την θέση ενός Entitie!*/
const sf::Vector2f & Entity::GetEntPos()const
{
	return EntPos;
}

//Επιστρέφει το Sprite 
const sf::Sprite & Entity::GetEntSprite()const
{
	return EntSprite;
}

