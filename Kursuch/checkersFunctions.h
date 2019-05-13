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
char reverseCrown(char color); //���������� ���� � ������ ('R' ��� 'B')
								//��� ������� ('r' ��� 'b')
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
char getRowParity(char row); //������ ��� �������� ���
		
//��� ��� ������� ��� ����� � ������� sq::Square getSqInBetween(...)
	bool upCapture(sq::Square *initSq, sq::Square *targetSq); //������ ����� (� ����� ����� ������)?
	bool downCapture(sq::Square *initSq, sq::Square *targetSq); //������ ����?
bool R_Capture1();
bool R_Capture2();
bool R_Capture3();
bool R_Capture4();
bool B_Capture1();
bool B_Capture2();
bool B_Capture3();
bool B_Capture4();
char oppoColor(char color);
bool isCapture(); //���������� �� ������?
void updateBoard();
bool isPromotion(); //������ ���������� ������?
bool possibleCapture(sq::Square *initSq); //�������� �� ������?
void getConsecutiveJmpTarget(); //���� �������� ����������������� ������ �������������
bool goodConsecutiveJmpTarget(std::string sq); 
void displayHelp();
void redTurn();
void blackTurn();
bool gameOver(); //����� ����?
void redLoses();
void blackLoses();
void tieGame();
void checkersGame();
void handleLoss();
bool playAgain();
void exit();

#endif