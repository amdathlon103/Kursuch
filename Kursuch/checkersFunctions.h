#ifndef CHECKERSFUNCTIONS_H
#define	CHECKERSFUNCTIONS_H

#include <SFML/Graphics.hpp>
#include "constants.h"
#include "gameBoard.h"
#include "square.h"
#include "checkersVariables.h"
using namespace checkers;
#include <string>
#include <iostream>

void prepareGame();

std::string get_GUI_Input();

bool isSquare(std::string square);
char reverseCrown(char color); //возвращает цвет в дамках ('R' или 'B')
								//или обычный ('r' или 'b')
bool cannotMakeMove();
bool possibleMovement(sq::Square *initSq);

void getSquare();
bool goodSquare(std::string sq);
void getTarget();
bool goodTarget(std::string sq);
bool oneFrSqAway();
bool oneBcSqAway();
bool twoFrSqAway();
bool twoBcSqAway();
int getAddress(std::string sq);
char getLetCoordinate(std::string sq1);
std::string getSqInBetween(sq::Square *initSq, sq::Square *targetSq);
char getCapDirection(std::string *initSq, std::string *targetSq);
char getRowParity(char row); //четный или нечетный ряд
		
//эти две функции для дамок в функции sq::Square getSqInBetween(...)
	bool upCapture(sq::Square *initSq, sq::Square *targetSq); //захват вверх (с нашей точки зрения)?
	bool downCapture(sq::Square *initSq, sq::Square *targetSq); //захват вниз?
bool R_Capture1();
bool R_Capture2();
bool R_Capture3();
bool R_Capture4();
bool B_Capture1();
bool B_Capture2();
bool B_Capture3();
bool B_Capture4();
char oppoColor(char color);
bool isCapture(); //произойдет ли захват?
void updateBoard();
bool isPromotion(); //фигура становится дамкой?
bool possibleCapture(sq::Square *initSq); //возможен ли захват?
void getConsecutiveJmpTarget(); //ввод квадрата последовательного прыжка пользователем
bool goodConsecutiveJmpTarget(std::string sq); 
void displayHelp();
void redTurn();
void blackTurn();
bool gameOver(); //конец игры?
void redLoses();
void blackLoses();
void tieGame();
void checkersGame();
void handleLoss();
bool playAgain();
void exit();

#endif