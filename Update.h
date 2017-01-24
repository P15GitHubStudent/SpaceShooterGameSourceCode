#pragma once

#include<SFML\Graphics.hpp>

class Update
{
public:
	Update(float updatetime=0);
	
	bool IsTimeToUpdate();
	void RestartClock();
	void SetUpdateTime(float Time);
	void IncreaseTime();
	void DecreaseTime();
	const sf::Time & getTime()const;
private:
	sf::Clock Clock;
	sf::Time Time;
	float UpdateValue;
	
};


typedef Update Delay;

