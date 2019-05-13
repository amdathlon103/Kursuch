#ifndef SQUARE_H
#define SQUARE_H

#include <SFML/Graphics.hpp>
#include <string>
#include <vector>
#include <iostream>
#include "constants.h"
#include "error.h"

namespace sq {

struct Square
{
	char color() const { return c; }
	std::string square() const { return s; }
	char row() const { return r; }
	std::vector<std::string> getFrtAdjSqs() const { return frtAdjSqs; }
	std::vector<std::string> getBacAdjSqs() const { return bacAdjSqs; }
	std::vector<std::string> getFrtJmpSqs() const { return frtJmpSqs; }
	std::vector<std::string> getBacJmpSqs() const { return bacJmpSqs; }
	bool isCrowned() const { return crowned; }
	void switchCrown(bool status) { crowned = status; return; }
	bool isCaptured() const { return captured; }
	void switchCap(bool status) { captured = status; return; }
	
	void changeColor(char newColor);
	
	Square();
	Square(char c_, std::string s_, char r_);

	std::vector<std::string> setFrtAdjSqs(std::string sq); //sets std::vector<std::string> FrtAdjSqs
	std::vector<std::string> setBacAdjSqs(std::string sq); //sets std::vector<std::string> BacAdjSqs
	std::vector<std::string> setFrtJmpSqs(std::string sq); //sets std::vector<std::string> frontJumpSqs
	std::vector<std::string> setBacJmpSqs(std::string sq); //sets std::vector<std::string> backJumpSqs
	
private: 
	char c;  
	//���� ������ � ��������
		//'r' �����
		//'R' ����� �����
		//'b' ������
		//'B' ������ �����
		//' ' ������
	std::string s;  //��� ��������. ����� ���� a1, e5, etc.
	char r;  //���. ����� ���� 1,2,3,...8
	std::vector<std::string> frtAdjSqs; //�������� �������� �������� �������
	std::vector<std::string> bacAdjSqs; //�������� �������� �������� �����
	std::vector<std::string> adjSqs; //�������� �������� ��������
	std::vector<std::string> frtJmpSqs; //�������� �������� ����� ������ �������
								 //������������ ��� ��������
	std::vector<std::string> bacJmpSqs; //�������� �������� ����� ������ �����
	                            //������������ ��� �������� � �������� �����
	bool crowned; //������ � �������� �����?
				  //���� �����, �� ����� ��������� �����
	bool captured; //������ � ������ �������� ���������?
};

} // namespace sq

#endif