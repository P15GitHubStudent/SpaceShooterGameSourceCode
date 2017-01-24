#include "BackGrounds.h"


sf::Vector2i BackGrounds::WindowDimensions(800,600);


BackGrounds::BackGrounds(float BackPosX, float BackPosY, float Width, float Height, int DirX, int DirY, float VeloxityX, float VelocityY, const sf::Texture & BGTexture)
{
	SetUp(BackPosX, BackPosY, Width, Height, DirX, DirY, VeloxityX, VelocityY, BGTexture);
}

BackGrounds::BackGrounds()
{

}

void BackGrounds::SetUp(float BackPosX, float BackPosY, float Width, float Height, int DirX, int DirY, float VeloxityX, float VelocityY, const sf::Texture & BGTexture)
{
	BackPos.x = BackPosX;
	BackPos.y = BackPosY;
	BackDimensions.x = Width;
	BackDimensions.y = Height;
	Velocity.x = VeloxityX;
	Velocity.y = VelocityY;
	Dir.x = DirX;
	Dir.y = DirY;
	BackGroundSprite.setTexture(BGTexture);
	BackGroundCopy.setTexture(BGTexture);
}


void BackGrounds::Update()
{
	BackPos.x += Velocity.x * Dir.x;

	if (BackPos.x + BackDimensions.x <= 0)BackPos.x = 0;

}

void BackGrounds::draw(sf::RenderTarget& target, sf::RenderStates states)const
{

	BackGroundSprite.setPosition(BackPos);

	target.draw(BackGroundSprite);
 
	
	if (BackPos.x + BackDimensions.x < 800)
	{

		BackGroundCopy.setPosition(BackPos.x + BackDimensions.x, BackPos.y);
		target.draw(BackGroundCopy);
	}
	
	
}


BackGrounds::~BackGrounds()
{
}
