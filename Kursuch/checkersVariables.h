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
	extern std::string selection; //���� ���������������� ���� �������� � ���� ����������
	//11 ���������� ��� ����������
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
	extern char turn; //��� 'r' (�����) ��� 'b' (������)
	extern char captureDirection; //��� 'R' (�����) ��� 'L' (����)
	extern char initialRowParity; //��� 'O' (��������) ��� 'E' (������)
	extern bool wasCapture; //��� ������ � ���� ����?
					 //������������ ��� �������� �� ���������������� ������
	extern char loser; //��� 'r' (�����) ��� 'b' (������)
			   //��� ��������?
	
	//��� ��������:
	extern int selected; //�������� ��������� ����� ��������� ������.
	extern int targeted; //�������� ��������� ����� ��������, ���� ������� ������
	extern int inBetween; //�������� ��������� ����� �������� ����� selected � targeted ����������(� ������ �������)
				  
  extern ch::Board gameBoard;
} // namespace checkers

#endif