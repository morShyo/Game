#pragma once

#include "MovementComponent.h"
#include "ShootingComponent.h"

class Entity
{

private:
	sf::RenderWindow* window;
	sf::Sprite sprite;
	MovementComponent* movementComponent;
	ShootingComponent* shootingComponent;

	void initVariables();
	

public:

	Entity(sf::RenderWindow* _window);
	virtual ~Entity();

	//Component functions
	void setTexture(sf::Texture& _texture);

	void createMovementComponent(const float _speed);
	void createShootingComponent(sf::Texture& _projectileTexture, sf::Vector2f _scale, float _speed, float _timer);

	//Functions

	virtual void setSize(const float _x, const float _y);
	virtual void setPosition(const float _x, const float _y);

	virtual sf::Vector2f getDirection();

	virtual void move(const float _dirX, const float _dirY, const float _dt);
	virtual void shoot(sf::Vector2f _dir, float _dt);

	virtual void update(const float _dt);
	virtual void render(sf::RenderTarget& _target);

};



