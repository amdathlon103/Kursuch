#ifndef CHECKERSVARIABLES_H
#define CHECKERSVARIABLES_H

#include <string>
#include <vector>
#include <iostream>
#include <exception>
#include "square.h"
#include "CheckersBoard.h"

namespace checkers 
{
	extern std::vector<sq::Square> squares;
	extern std::string selection; //¬есь пользовательский ввод хранитс€ в этой переменной
	//11 переменных дл€ интерфейса
	extern sf::Text curTurn;
	extern sf::Font font;
	extern sf::Text locked;
	extern sf::Text winMsg;
	extern sf::Text egMsg;
	extern sf::CircleShape wPie;
	extern sf::Text wEat;
	extern sf::CircleShape bPie;
	extern sf::Text bEat;
	extern short wEaten;
	extern short bEaten;
	extern char turn; //или 'r' (Ѕелый) или 'b' („ерный)
	extern char captureDirection; //или 'R' (ѕраво) или 'L' (Ћево)
	extern char initialRowParity; //или 'O' (нечетный) или 'E' (четный)
	extern bool wasCapture; //был захват в этом ходу?
					 //используетс€ дл€ проверки на последовательные прыжки
	extern char loser; //или 'r' (Ѕелый) или 'b' (черный)
			   //кто проиграл?
	
	//дл€ векторов:
	extern int selected; //содержит векторный адрес выбранной фигуры.
	extern int targeted; //содержит векторный адрес квадрата, куда двинуть фигуру
	extern int inBetween; //содержит векторный адрес квадрата между selected и targeted квадратами(в случае захвата)
				  
  extern ch::Board gameBoard;
} // namespace checkers

#endif