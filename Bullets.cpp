#include "Bullets.h"
#include<iostream>
#include"Exceptions.h"

sf::Texture Bullets::bulletBlueText;
sf::Texture Bullets::bulletRedText;

Bullets::Bullets()
{
}

Bullets::Bullets(BulletsId bulletId, const sf::Vector2f & Pos, const sf::Vector2f & EntityVelocity) :Entity("Bullet", Pos, EntityVelocity, bulletId == BulletsId::blueFireBullet ? bulletBlueText : bulletRedText)
{

	//EntSprite.setTexture(bulletText);
	EntSprite.setPosition(Pos);
	if (bulletId == BulletsId::blueFireBullet)
	{
		EntAnimation.CreateAnimation(0.1,bulletBlueText, EntSprite);
	}
	else
	{
		EntAnimation.CreateAnimation(0.1, bulletRedText, EntSprite);
	}
	for (int c = 0; c < 16; c++)
	EntAnimation.AddAnimFrame(sf::IntRect(0, c * 32, 64, 32));
	EntSprite.setTextureRect(sf::IntRect(EntAnimation.GetFrameIndex(0)));
}


void Bullets::loadTextures()
{
	if (!bulletBlueText.loadFromFile("images/fire_blue.png"))throw FAILED_TO_LOAD_TEXTURE("fire_blue.png");
	if (!bulletRedText.loadFromFile("images/fire_red.png"))throw FAILED_TO_LOAD_TEXTURE("fire_red.png");
}





void Bullets::Update2(const sf::Vector2f & EntPos)
{
	Entity::Update();

	if (this->EntPos.x > EntPos.x+1000 || this->EntPos.x <0 )
    {
		entityAlive = false;
	}

}

void Bullets::Update()
{
	Entity::Update();

	if (EntPos.x <= 0 || EntPos.x >= 800)entityAlive = false;
}




Bullets::~Bullets()
{
}
