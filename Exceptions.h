#pragma once

#include<exception>


class FAILED_TO_LOAD_TEXTURE : public std::runtime_error
{

public:
	FAILED_TO_LOAD_TEXTURE(const char * Message) :std::runtime_error(Message)
	{

	}

};


class FAILED_TO_LOAD_FONT : public std::runtime_error
{
public :

	FAILED_TO_LOAD_FONT(const char * Message) :std::runtime_error(Message)
	{

	}

};

class FAILED_TO_LOAD_SOUND : public std::runtime_error
{
public:

	FAILED_TO_LOAD_SOUND(const char * Message) :std::runtime_error(Message)
	{

	}

};