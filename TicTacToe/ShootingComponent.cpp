#include "ShootingComponent.h"

ShootingComponent::ShootingComponent(sf::Sprite& _sprite, sf::Texture& _projectileTexture, sf::Vector2f _scale, float _speed, float _timer, sf::RenderWindow* _window)
	: sprite(_sprite), speed(_speed)
{
	projectile.setTexture(_projectileTexture);
	projectile.setOrigin(sprite.getTexture()->getSize().x, sprite.getTexture()->getSize().y);
	projectile.setScale(_scale);

	maxTimer = _timer;
	timer = maxTimer;
}

ShootingComponent::~ShootingComponent()
{
	for (auto &proj : projectiles)
	{
		delete proj;
	}
}

void ShootingComponent::shoot(sf::Vector2f _dir, float _dt)
{
	if (timer > maxTimer)
	{
		sf::Vector2f projectilePos_(sprite.getPosition());
		if (_dir.x > 0.0f)
			projectilePos_.x += sprite.getGlobalBounds().width / 2.0f;
		else if (_dir.x < 0.0f)
			projectilePos_.x -= sprite.getGlobalBounds().width / 2.0f;
		if (_dir.y > 0.0f)
			projectilePos_.y += sprite.getGlobalBounds().height / 2.0f;
		else if (_dir.y < 0.0f)
			projectilePos_.y -= sprite.getGlobalBounds().height / 2.0f;

		projectiles.push_back(new Projectile(_dir, projectilePos_));

		timer = 0.0f;
	}
	//Calculate on which side of the sprite to spawn the bullet  IMPORTANT DO IT HERE
	
}

void ShootingComponent::update(sf::RenderWindow& _window, float _dt)
{
	//updates shooting timer
	timer += 1000.0f * _dt;

	//Gets size of the projectiles

	

	sf::Vector2f projSize_;
	projSize_.x = projectile.getGlobalBounds().width;
	projSize_.y = projectile.getGlobalBounds().height;

	auto it = projectiles.begin();
	while(it != projectiles.end())
	{
		//updates projectiles positions depenidng on speed
		(*it)->update(speed, _dt);
		 //deletes if out of bounds
		if ((*it)->getPos().x + projSize_.x / 2.0f > _window.getSize().x
			|| (*it)->getPos().x - projSize_.x / 2.0f < 0
			|| (*it)->getPos().y + projSize_.y / 2.0f > _window.getSize().y
			|| (*it)->getPos().y - projSize_.y / 2.0f < 0)
		{
			delete *it;
			it = projectiles.erase(it);
		}
		else ++it;
	}
}

void ShootingComponent::render(sf::RenderTarget & _target)
{
	for (auto &proj : projectiles)
	{
		projectile.setPosition(proj->getPos());
		_target.draw(projectile);
	}
}
