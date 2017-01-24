#include"Animation.h"
#include<iostream>


void Animation::CreateAnimation(float AnimDelay, sf::Texture & AnimTexture, sf::Sprite & AnimSprite)
{
	Sprite = &AnimSprite;
	Texture =&AnimTexture;
	Delay = AnimDelay;
	FrameTimer.SetUpdateTime(Delay);
	AnimationCounter = 0;
	AnimSprite.setTexture(AnimTexture);
	Paused = false;
	FrameTimer.RestartClock();
	over = false;

}

void Animation::Stop(bool StopAnim)
{
	Paused = StopAnim;
}

void Animation::Play()
{
	
	if (Paused)
	{
		FrameTimer.RestartClock();
		return;
	}
		
	FrameTimer.IncreaseTime();

	if (FrameTimer.IsTimeToUpdate())
	{

		AnimationCounter++;

		

		if (AnimationCounter >= AnimationFrames.size())
		{
			AnimationCounter = 0;	
			over = true;
		}

		Sprite->setTextureRect(AnimationFrames[AnimationCounter]);
	}

}



void Animation::AddAnimFrame(const sf::IntRect  & AnimRect)
{
	AnimationFrames.push_back(AnimRect);
}


