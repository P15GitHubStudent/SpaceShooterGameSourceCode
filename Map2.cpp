#include "Map2.h"


#include"Exceptions.h"


sf::Texture Map2::BGText;
sf::Texture Map2::MGText;
sf::Texture Map2::FGText;


void Map2::InitializeMap()
{
	if (!BGText.loadFromFile("images/starfield.png"))throw FAILED_TO_LOAD_TEXTURE("images/starfield.png");
	if (!MGText.loadFromFile("images/farback.gif"))throw FAILED_TO_LOAD_TEXTURE("images/farback.gif");
	if (!FGText.loadFromFile("images/starFG.png"))throw FAILED_TO_LOAD_TEXTURE("images/starFG.png");

}


void Map2::createMap()
{

	BG.SetUp(0, 0, 800, 600, -1, 0, 1, 0, BGText);
	MG.SetUp(0, 0, 1700, 600,-1, 0, 3, 0, MGText);
	FG.SetUp(0, 0, 800, 600, -1, 0, 4, 0, BGText);

}

Map2::Map2()
{

}

void Map2::update()
{
	
	BG.Update();
	MG.Update();
	FG.Update();
}



void  Map2::draw(sf::RenderTarget& target, sf::RenderStates states)const
{
	target.draw(MG);
	target.draw(BG);
	target.draw(FG);
}

Map2::~Map2()
{

}


