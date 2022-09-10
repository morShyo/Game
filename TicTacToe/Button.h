#pragma once

#include <SFML/Graphics.hpp>

#include <iostream>

enum button_states { BTN_IDLE = 0, BTN_HOVER, BTN_ACTIVE };

class Button
{
private:
	short unsigned buttonState;

	sf::RectangleShape shape;
	sf::Text text;

	sf::Color textIdleColor;
	sf::Color textHoverColor;
	sf::Color textActiveColor;

	sf::Color idleColor;
	sf::Color hoverColor;
	sf::Color activeColor;

public:
	Button(float _x, float _y, float _width, float _height,
		sf::Font &_font, std::string _text, unsigned _characterSize,
		sf::Color _textIdleColor, sf::Color _textHoverColor, sf::Color _textActiveColor,
		sf::Color _idleColor, sf::Color _hoverColor, sf::Color _activeColor);
	~Button();

	//Accessors
	const bool isPressed() const;

	//Functions
	void update(const sf::Vector2f& _mousePos);
	void render(sf::RenderTarget& _target);

};

