// This is a personal academic project. Dear PVS-Studio, please check it.

// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com

#include "MainMenuState.h"
#include "GameState.h"

//Initiliazer functions

void MainMenuState::initVariables()
{

}

void MainMenuState::initFonts()
{
	if (!font.loadFromFile("Fonts/Dosis-Light.ttf"))
	{
		throw("ERROR::MAINMENUSTATE:: COULD NOT LOAD FONT");
	}
}

void MainMenuState::initBackground()
{
	background.setSize(sf::Vector2f(static_cast<float>(window->getSize().x), static_cast<float>(window->getSize().y)));

	if (!backgroundTexture.loadFromFile("Resources/Images/Backgrounds/main_menu.png"))
	{
		throw "ERROR::MAINMENUSTATE::FAILES_TO_LOAD_BACKGROUDN_IMAGE";
	}
	background.setTexture(&backgroundTexture);
}


void MainMenuState::initKeybinds()
{
	std::ifstream ifs("Config/mainmenustate_keybinds.ini");

	if (ifs.is_open())
	{
		std::string key_;
		std::string key2_;
		while (ifs >> key_ >> key2_)
		{
			keybinds[key_] = supportedKeys.at(key2_);
		}
	}

	ifs.close();
}

void MainMenuState::initButtons()
{
	buttons["GAME_STATE"] = new Button(300.0f, 480.0f, 150.0f, 50.0f,
		font, "New Game", 50,
		sf::Color(70, 70, 70, 200), sf::Color(250, 250, 250, 250), sf::Color(20, 20, 20, 50),
		sf::Color(70, 70, 70, 0), sf::Color(150, 150, 150, 0), sf::Color(20, 20, 20, 0));

	buttons["SETTINGS"] = new Button(300.0f, 580.0f, 150.0f, 50.0f,
		font, "Settings", 50,
		sf::Color(70, 70, 70, 200), sf::Color(250, 250, 250, 250), sf::Color(20, 20, 20, 50),
		sf::Color(70, 70, 70, 0), sf::Color(150, 150, 150, 0), sf::Color(20, 20, 20, 0));

	buttons["EDITOR_STATE"] = new Button(300.0f, 680.0f, 150.0f, 50.0f,
		font, "Editor", 50,
		sf::Color(70, 70, 70, 200), sf::Color(250, 250, 250, 250), sf::Color(20, 20, 20, 50),
		sf::Color(70, 70, 70, 0), sf::Color(150, 150, 150, 0), sf::Color(20, 20, 20, 0));

	buttons["EXIT_STATE"] = new Button(300.0f, 780.0f, 150.0f, 50.0f,
		font, "Quit", 50,
		sf::Color(70, 70, 70, 200), sf::Color(250, 250, 250, 250), sf::Color(20, 20, 20, 50),
		sf::Color(70, 70, 70, 0), sf::Color(150, 150, 150, 0), sf::Color(20, 20, 20, 0));
}

MainMenuState::MainMenuState(sf::RenderWindow* _window, std::map<std::string, int>& _supportedKeys, std::stack<State*>* _states)
	: State(_window, _supportedKeys, _states)
{
	initVariables();
	initFonts();
	initBackground();
	MainMenuState::initKeybinds();
	initButtons();

}

MainMenuState::~MainMenuState()
{

}

void MainMenuState::updateInput(const float _dt)
{

}

void MainMenuState::updateButtons()
{
	for (auto &it : buttons)
	{
		it.second->update(mousePosView);
	}
	//New game
	if (buttons["GAME_STATE"]->isPressed())
	{
		states->push(new GameState(window, supportedKeys, states));
	}
	//Settings


	//Editor

	//Quit the game
	if (buttons["EXIT_STATE"]->isPressed())
	{
		endState();
	}
}

void MainMenuState::update(const float _dt)
{
	updateMousePositions();
	updateInput(_dt);

	updateButtons();
}

void MainMenuState::renderButtons(sf::RenderTarget & _target)
{
	for (auto &it : buttons)
	{
		it.second->render(_target);
	}
}

void MainMenuState::render(sf::RenderTarget& _target)
{
	_target.draw(background);

	renderButtons(_target);

	//REMOVE LATER, JUST A TEST
	/*sf::Text mouseText;
	mouseText.setPosition(mousePosView.x, mousePosView.y - 50.0f);
	mouseText.setFont(font);
	mouseText.setCharacterSize(12);
	std::stringstream ss;
	ss << mousePosView.x << "  " << mousePosView.y;
	mouseText.setString(ss.str());
	_target->draw(mouseText);
*/
}
