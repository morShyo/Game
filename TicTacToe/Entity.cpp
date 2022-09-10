// This is a personal academic project. Dear PVS-Studio, please check it.

// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com

#include "Entity.h"

void Entity::initVariables()
{
	movementComponent = nullptr;
	shootingComponent = nullptr;
}

Entity::Entity(sf::RenderWindow* _window)
	: window(_window)
{
	initVariables();
}

Entity::~Entity()
{
	delete movementComponent;
}

//component functions
void Entity::setTexture(sf::Texture& _texture)
{
	sprite.setTexture(_texture);
	sprite.setOrigin(sprite.getGlobalBounds().width / 2.0f, sprite.getGlobalBounds().height / 2.0f);
}


void Entity::createMovementComponent(const float _speed)
{
	movementComponent = new MovementComponent(sprite, _speed);
}

void Entity::createShootingComponent(sf::Texture & _projectileTexture, sf::Vector2f _scale, float _speed, float _timer)
{
	shootingComponent = new ShootingComponent(sprite, _projectileTexture, _scale, _speed, _timer, window);
}





//Funtions

void Entity::setSize(const float _x, const float _y)
{
	sprite.setScale(
		_x / sprite.getGlobalBounds().width,
		_y / sprite.getGlobalBounds().height
	);
}

void Entity::setPosition(const float _x, const float _y)
{
	sprite.setPosition(_x, _y);
}

sf::Vector2f Entity::getDirection()
{
	return movementComponent->getDirection();
}

void Entity::move(const float _dirX, const float _dirY, const float _dt)
{
	if (movementComponent)
	{
		movementComponent->move(_dirX, _dirY, _dt); //sets velocity

	}
}

void Entity::shoot(sf::Vector2f _dir, float _dt)
{
	if (shootingComponent)
	{
		shootingComponent->shoot(_dir, _dt);
	}
}

void Entity::update(const float _dt)
{
	shootingComponent->update(*window, _dt);
}

void Entity::render(sf::RenderTarget& _target)
{
	_target.draw(sprite);
	shootingComponent->render(_target);
}
