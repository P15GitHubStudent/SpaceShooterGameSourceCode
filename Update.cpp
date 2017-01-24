#include"Update.h"

Update::Update(float updatetime)
{
	SetUpdateTime(updatetime);
}


void Update::SetUpdateTime(float updatetime)
{
	UpdateValue = updatetime > 0 ? updatetime : 0;
}


void Update::RestartClock()
{
	Clock.restart();
}


void Update::IncreaseTime()
{
	Time += Clock.getElapsedTime();
	Clock.restart();

}

void Update::DecreaseTime()
{
	Time -= sf::seconds(UpdateValue);
}

const sf::Time & Update::getTime()const
{
	return Time; 
}


bool Update::IsTimeToUpdate()
{
	if (Time.asSeconds() >= UpdateValue)
	{
		if (UpdateValue == 0)
		{
			Time = sf::seconds(0); 
			return true;
		}

		Time -= sf::seconds(UpdateValue);
		Clock.restart();
		return true;
	}

	return false;
}

