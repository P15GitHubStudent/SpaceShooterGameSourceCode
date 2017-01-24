#pragma once

#include<SFML\Graphics.hpp>
#include"Update.h"
#include<vector>



class Animation
{
public:
	Animation()
	{ 
		Paused = true;
		Loop = true;
		Texture = nullptr;
		Sprite = nullptr;
	}
	void AddAnimFrame(const sf::IntRect & AnimFrame);
	void CreateAnimation(float AnimDelay, sf::Texture & AnimTexture,sf::Sprite & AnimatedSprite); 
	void Play();
	void Stop(bool StopAnim);
	void SetLoop();
	const sf::IntRect & GetFrameIndex(int c){
		return AnimationFrames[c];
	}

	bool IsOver()const
	{
		return over;
	}

private:
	bool over;
	bool Paused;
	bool Loop;
	bool IsAnimationOver()const;
	Update FrameTimer;
	float Delay;
	std::vector<sf::IntRect> AnimationFrames;
	sf::Texture * Texture;
	sf::Sprite * Sprite;
	int AnimationCounter;

};

