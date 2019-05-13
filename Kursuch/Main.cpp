#include <SFML/Graphics.hpp>
#include <iostream>
#include "CheckersBoard.h"
#include "checkersFunctions.h"
#include "checkersVariables.h"

// создает окно и доску на экране. запускает основной цикл
// checkersGame(). Ловит исключения.
int main()
try {
  sf::RenderWindow gameWindow(sf::VideoMode(1000, 650), 
                              "Checkers", sf::Style::Close);

  // Доска.
  checkers::gameBoard = ch::Board(600.0f);
  gameBoard.setPosition(sf::Vector2f(20.0f, 20.0f));
  gameBoard.setWindow(gameWindow);
  checkersGame();

	return 0;
}
catch(std::string message) {
	std::cerr << message <<'\n';
	exit();
	return 1;
}
catch (...) {
	std::cerr << "Unknown exception\n";
	exit();
	return 2;
}