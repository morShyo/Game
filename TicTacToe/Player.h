#pragma once

#include "Entity.h"

class Player :
	public Entity
{
private:
	//Variables

	//Initializer functions
	void initVariables();

public:
	Player(float _x, float _y, sf::Texture& _playerTexture, sf::Texture& _projectileTexture, float _speed, sf::RenderWindow* _window, float _projectileSpeed, float _shootingTimer);
	virtual ~Player();

	//Functions
	
};

