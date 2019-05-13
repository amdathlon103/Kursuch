#ifndef GAMEBOARD_H
#define GAMEBOARD_H

#include <iostream>
#include <vector>
#include <string>
#include "square.h"
//вывод доски в консоль, для удобства проверки
void displayBoard(const std::vector<sq::Square> &sqVect, int widthInUnderscores);
void compactBoard(const std::vector<sq::Square> &sqVect);
void defaultBoard(const std::vector<sq::Square> &sqVect);
void wideBoard(const std::vector<sq::Square> &sqVect);

#endif