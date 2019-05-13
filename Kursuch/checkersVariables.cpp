#include "checkersVariables.h"

std::vector<sq::Square> checkers::squares(32, sq::Square(' ',"a1",'1')); //заданы "a1" and '1' чтобы избежить ошибок 
std::string checkers::selection = " ";
char checkers::turn = ' ';
char checkers::captureDirection = ' ';
char checkers::initialRowParity = ' ';
bool checkers::wasCapture = false; 
char checkers::loser = ' '; 
sf::Text checkers::curTurn;
sf::Font checkers::font;
sf::Text checkers::locked;
sf::Text checkers::winMsg;
sf::Text checkers::egMsg;
sf::CircleShape checkers::wPie;
sf::Text checkers::wEat;
sf::CircleShape checkers::bPie;
sf::Text checkers::bEat;
short checkers::wEaten = 0;
short checkers::bEaten = 0;
int checkers::selected = 0;
int checkers::targeted = 0;
int checkers::inBetween = 0;

ch::Board checkers::gameBoard = ch::Board(600.0f);