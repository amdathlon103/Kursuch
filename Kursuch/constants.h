#ifndef CONSTANTS_H
#define CONSTANTS_H

namespace constants {
	const char Red = 'r';//белый
	const char cRed = 'R'; //дамка белая
	const char Black = 'b';//черный
	const char cBlack = 'B'; //дамка черная
	const char Both = 'x'; //in case of a tie, char loser = Both
	const char Left = 'L';
	const char Right = 'R';
	const char Odd = 'O';
	const char Even = 'E';
	const int lowVectorRange = 0;
	
	//адреса квадратов на концах доски (для перехода в дамки):
	const int b8 = 28;
	const int d8 = 29;
	const int f8 = 30;
	const int h8 = 31;
	const int a1 = 0;
	const int c1 = 1;
	const int e1 = 2;
	const int g1 = 3;

	//для захвата (пояснение в пояснительной записке):
	const int rOddRightCapJmp = 9; //расстояние от старта до цели, если
								   //фигура двигается из нечетного ряда вправо
								   //первое условие захвата белых выполняется
	const int rOddRightHafJmp = 4; //расстояние от старта до цели, если
								   //фигура двигается из нечетного ряда влево
								   //первое условие захвата белых выполняется
	//следующие константы по тому же принципу
	const int rEvenRightCapJmp = 9; //второе условие захвата белых
	const int rEvenRightHafJmp = 5;
	
	const int rOddLeftCapJmp = 7; //третье условие захвата белых
	const int rOddLeftHafJmp = 3;
	
	const int rEvenLeftCapJmp = 7; //четвертое условие захвата белых
	const int rEvenLeftHafJmp = 4;

	const int bOddLeftCapJmp = -9; //первое условие захвата черных
	const int bOddLeftHafJmp = -5;
	
	const int bEvenLeftCapJmp = -9; //второе условие захвата черных
	const int bEvenLeftHafJmp = -4;
	
	const int bOddRightCapJmp = -7; //третье условие захвата черных
	const int bOddRightHafJmp = -4;
	
	const int bEvenRightCapJmp = -7; //четвертое условие захвата черных
	const int bEvenRightHafJmp = -3;
}

using namespace constants;

#endif