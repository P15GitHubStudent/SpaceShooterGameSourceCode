
#include<SFML\Graphics.hpp>
#include<exception>
#include"GameEngine.h"
#include"Exceptions.h"
#include<locale>
#include"Maps.h"
#include"Map2.h"

const int Width = 800;
const int Height = 600;


int main(int argc,char ** argv)
{

	setlocale(LC_ALL, "greek");

	std::srand(time(NULL));

	try
	{
		GameEngine game(sf::Style::Titlebar | sf::Style::Close, sf::Vector2i(Width, Height), L"Παιχνίδι SpaceShooter");

		game.Run();
	}
	catch (const std::exception & exception)
	{
		std::cerr << "ΕΞΑΙΡΕΣΗ " << exception.what() << "\n"; 
		sf::sleep(sf::seconds(5));
	}
	


	return EXIT_SUCCESS;
}


/*
sf::RectangleShape frame;
frame.setPosition(300, 100);
frame.setSize(sf::Vector2f(300, 350));
frame.setFillColor(sf::Color::Transparent);
//frame.setOutlineThickness(1.5);
//frame.setOutlineColor(sf::Color::Red);

Map * Maps[2];
Maps[0] = new Map1();
Maps[1] = new Map2();

sf::RenderWindow win(sf::VideoMode(800, 600), L"GamePlay");
sf::Event ev;
bool isOpen = true;
Map2 map1;
Map2::InitializeMap();
Map1::InitializeMap();
sf::Text text;

sf::Font font;

font.loadFromFile("fonts/arial.ttf");

text.setFont(font);
text.setPosition(400, 0);


for (int c = 0; c < 2; c++)Maps[c]->createMap();

win.setFramerateLimit(60);

sf::RectangleShape mapSelector;
mapSelector.setOutlineThickness(1.1f);
mapSelector.setOutlineColor(sf::Color::Red);

sf::View mapView;
mapView.setViewport(sf::FloatRect(0, 0.5, 0.35, 0.35));
//mapView.setCenter(sf::Vector2f(300, 300));
//mapSelector.setPosition(mapView.getCenter().y, mapView.getCenter().x);
//mapSelector.setSize(sf::Vector2f(350,350));
//mapSelector.setFillColor(sf::Color::Transparent);
//mapView.setCenter(500, 500);

sf::RectangleShape rc;
rc.setFillColor(sf::Color::Red);
rc.setSize(sf::Vector2f(280, 125));
rc.setFillColor(sf::Color::Transparent);
rc.setOutlineThickness(1.1);
rc.setOutlineColor(sf::Color::Red);



sf::View mapView2;
mapView2.setViewport(sf::FloatRect(0.5 , 0.5, 0.35, 0.35));

//rc.setOrigin(rc.getSize().x / 2, rc.getSize().y / 2);
rc.setPosition(0, 300);


mapSelector.setPosition(0, 0);
while (isOpen)
{

while (win.pollEvent(ev))
{
switch (ev.type)
{
case sf::Event::Closed:
isOpen = false;
break;
}


}


for (int c = 0; c < 2; c++)Maps[c]->update();

win.clear();
win.draw(*Maps[0]);
win.draw(rc);
text.setPosition(400, 0);
text.setString(L"ΠΙΣΤΕΣ");
text.setColor(sf::Color::Red);
win.draw(text);
text.setPosition(0, 40);
text.setColor(sf::Color::White);
text.setString(L"Διάλλεξε μια πίστα με το ποντικι και πατα δεξί κλικ \n για να παίξεις με αυτή. ");
win.draw(text);
//text.setPosition(100, 420);
//text.setString(L"Διάστημα");
//text.setColor(sf::Color(100, 0, 0));
//win.draw(text);
//text.setPosition(320, 420);
//text.setString(L"Διαστημική Πίστα2");
win.draw(text);
win.draw(frame);
win.setView(mapView);

win.draw(*Maps[0]);
win.setView(win.getDefaultView());
win.setView(mapView2);
win.draw(*Maps[1]);
win.setView(win.getDefaultView());
win.display();

}






for (int c = 0; c < 2; c++)delete Maps[c];

*/