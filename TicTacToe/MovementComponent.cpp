// This is a personal academic project. Dear PVS-Studio, please check it.

// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com

#include "MovementComponent.h"

MovementComponent::MovementComponent(sf::Sprite& _sprite, float _speed)
	: sprite(_sprite), speed(_speed), direction(sf::Vector2f(1.0f, 0.0f)) 
{

}

MovementComponent::~MovementComponent()
{

}


//Functions

const sf::Vector2f MovementComponent::getDirection() const
{	
	return direction;
}


const void MovementComponent::move(const float _dirX, const float _dirY, const float _dt)
{
	//changes where the sprite is looking
	if (_dirX > 0.0f)
		sprite.setScale(abs(sprite.getScale().x), sprite.getScale().y);
	else if (_dirX < 0.0f)
		sprite.setScale(-abs(sprite.getScale().x), sprite.getScale().y);


	sprite.move(_dirX * speed * _dt, _dirY * speed * _dt);

	//Updates the state of the entity
	direction.x = _dirX;
	direction.y = _dirY;
}

