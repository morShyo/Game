// This is a personal academic project. Dear PVS-Studio, please check it.

// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com

#include "Button.h"

Button::Button(float _x, float _y, float _width, float _height,
	sf::Font &_font, std::string _text, unsigned _characterSize,
	sf::Color _textIdleColor, sf::Color _textHoverColor, sf::Color _textActiveColor,
	sf::Color _idleColor, sf::Color _hoverColor, sf::Color _activeColor)
	
	: textIdleColor(_textIdleColor), textHoverColor(_textHoverColor), textActiveColor(_textActiveColor),
	idleColor(_idleColor), hoverColor(_hoverColor), activeColor(_activeColor)
{
	buttonState = BTN_IDLE;

	shape.setPosition(sf::Vector2f(_x, _y));
	shape.setSize(sf::Vector2f(_width, _height));
	shape.setFillColor(_idleColor);

	text.setFont(_font);
	text.setString(_text);
	text.setFillColor(_textIdleColor);
	text.setCharacterSize(_characterSize);
	text.setPosition(
		shape.getPosition().x + shape.getSize().x / 2.0f - text.getGlobalBounds().width / 2.0f,
		shape.getPosition().y + shape.getSize().y / 2.0f - text.getGlobalBounds().height / 2.0f
	);
}

Button::~Button()
{

}

const bool Button::isPressed() const
{
	return buttonState == BTN_ACTIVE;
}

//Functions

void Button::update(const sf::Vector2f& _mousePos)
{
	//Idle
	buttonState = BTN_IDLE;

	//Hover
	if (shape.getGlobalBounds().contains(_mousePos))
	{
		buttonState = BTN_HOVER;


		//Pressed
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			buttonState = BTN_ACTIVE;
		}
	}

	switch (buttonState)
	{
	case BTN_IDLE:
		shape.setFillColor(idleColor);
		text.setFillColor(textIdleColor);
		break;
	case BTN_HOVER:
		shape.setFillColor(hoverColor);
		text.setFillColor(textHoverColor);
		break;
	case BTN_ACTIVE:
		shape.setFillColor(activeColor);
		text.setFillColor(textActiveColor);
		break;
	default:
		//error case 
		shape.setFillColor(sf::Color::Red);
		text.setFillColor(sf::Color::Blue);
		break;
	}
}

void Button::render(sf::RenderTarget& _target)
{
	_target.draw(shape);
	_target.draw(text);
}
