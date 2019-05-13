#ifndef CONSTANTS_H
#define CONSTANTS_H

namespace constants {
	const char Red = 'r';//�����
	const char cRed = 'R'; //����� �����
	const char Black = 'b';//������
	const char cBlack = 'B'; //����� ������
	const char Both = 'x'; //in case of a tie, char loser = Both
	const char Left = 'L';
	const char Right = 'R';
	const char Odd = 'O';
	const char Even = 'E';
	const int lowVectorRange = 0;
	
	//������ ��������� �� ������ ����� (��� �������� � �����):
	const int b8 = 28;
	const int d8 = 29;
	const int f8 = 30;
	const int h8 = 31;
	const int a1 = 0;
	const int c1 = 1;
	const int e1 = 2;
	const int g1 = 3;

	//��� ������� (��������� � ������������� �������):
	const int rOddRightCapJmp = 9; //���������� �� ������ �� ����, ����
								   //������ ��������� �� ��������� ���� ������
								   //������ ������� ������� ����� �����������
	const int rOddRightHafJmp = 4; //���������� �� ������ �� ����, ����
								   //������ ��������� �� ��������� ���� �����
								   //������ ������� ������� ����� �����������
	//��������� ��������� �� ���� �� ��������
	const int rEvenRightCapJmp = 9; //������ ������� ������� �����
	const int rEvenRightHafJmp = 5;
	
	const int rOddLeftCapJmp = 7; //������ ������� ������� �����
	const int rOddLeftHafJmp = 3;
	
	const int rEvenLeftCapJmp = 7; //��������� ������� ������� �����
	const int rEvenLeftHafJmp = 4;

	const int bOddLeftCapJmp = -9; //������ ������� ������� ������
	const int bOddLeftHafJmp = -5;
	
	const int bEvenLeftCapJmp = -9; //������ ������� ������� ������
	const int bEvenLeftHafJmp = -4;
	
	const int bOddRightCapJmp = -7; //������ ������� ������� ������
	const int bOddRightHafJmp = -4;
	
	const int bEvenRightCapJmp = -7; //��������� ������� ������� ������
	const int bEvenRightHafJmp = -3;
}

using namespace constants;

#endif