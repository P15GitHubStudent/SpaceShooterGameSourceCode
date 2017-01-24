#pragma once


#include"State.h"

class GameStates
{

protected:
	State state;
public:

	GameStates(){}


	virtual void Events() = 0;
	virtual void draw() = 0;
	virtual void Update() = 0;

	State getCurrentState(){
		return state;
	}

	virtual~GameStates(){}
};

