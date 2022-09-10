// This is a personal academic project. Dear PVS-Studio, please check it.

// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com

#include "Player.h"


//Initializer functions

void Player::initVariables()
{
 
}


//Constructor / Destructor
Player::Player(float _x, float _y, sf::Texture& _playerTexture, sf::Texture& _projectileTexture, float _speed, sf::RenderWindow* _window, float _projectileSpeed, float _shootingTimer)
	: Entity(_window)
{
	Entity::setPosition(_x, _y);

	setTexture(_playerTexture);

	createMovementComponent(_speed);

	createShootingComponent(_projectileTexture, sf::Vector2f(0.02f, 0.02f), _projectileSpeed, _shootingTimer);
	
}

Player::~Player()
{

}
