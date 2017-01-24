#pragma once

#include<SFML\Graphics.hpp>
#include"Exceptions.h"
#include<string>
#include"Update.h"


class BackGrounds : public sf::Drawable 
{
	
		
    public:
		enum class Direction{Right=1,left=-1};
		void Draw();
		void Update(); // Kouna Tin Pista Kai tha tin bazei piso stin thesi tis ! 
		void SetUp(float BackPosX,float BackPosY,float Width,float Height,int DirX,int DirY,float VelocityX,float VelocityY,const sf::Texture & BGText);
		BackGrounds(float BackPosX, float BackPosY, float Width, float Height, int DirX, int DirY, float VelocityX, float VelocityY,const sf::Texture & BGText);
		BackGrounds();
		~BackGrounds();		
		static sf::Vector2i WindowDimensions;
		const sf::Vector2f & GetBackGroundPos()const{ return BackPos; }
		const sf::Vector2f & GetBackDimensions()const{ return BackDimensions; }
		const sf::Vector2f & GetVelocity()const { return Velocity; }

private:
	sf::Vector2f BackPos;
	sf::Vector2f BackDimensions;
	 sf::Vector2i Dir;
	mutable sf::Sprite  BackGroundSprite;
	sf::Texture BackGroundTexture;
	mutable sf::Sprite BackGroundCopy; //AntiGrafo tou background image ! 
	sf::Vector2f Velocity;
	Direction dir;
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states)const;
};

