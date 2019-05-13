#ifndef CHECKERSBOARD_H
#define CHECKERSBOARD_H

#include <SFML/Graphics.hpp>
#include <string>
#include <vector>
#include "square.h"
#include "CheckersSquare.h"
#include "CheckersPiece.h"

namespace ch {

// Представление доски и её квадратов как класс.
class Board {
 public:

  Board(const float boardLength = 0.0,
        const sf::Color &color1 = sf::Color::Red,
        const sf::Color &color2 = sf::Color::Black,
        const sf::Color &borderColor = sf::Color::Blue);


  // Выводит доску и квадраты(в данном случае невидимые) на экран renderWindow.
  void draw(sf::RenderWindow &renderWindow, std::vector<sq::Square> &squares_list);

  sf::RenderWindow* getWindow() const;

  sf::Vector2f getSize() const;

  float getBorderThickness() const;

  sf::Color getBorderColor() const;

  sf::Vector2f getPosition() const;

  sf::Color getSquareColor1() const;

  sf::Color getSquareColor2() const;

  void setWindow(sf::RenderWindow &newWindow);

  void setSize(const sf::Vector2f &newSize);

  void setBorderThickness(const float &newBorderThickness);

  void setBorderColor(const sf::Color &newBorderColor);

  void setPosition(const sf::Vector2f &newPosition);

  void setSquareColor1(const sf::Color &newColor);

  void setSquareColor2(const sf::Color &newColor);
  
  void drawPieces(sf::RenderWindow &window,
                 std::vector<sq::Square> &updates);

  std::string interpretClick(sf::Event &what, std::vector<sq::Square> &squares);

 private:
  
  // Окно, на которое будет выведена доска.
  sf::RenderWindow* window;

  // Было фактически доской, заменено на спрайт.
  sf::RectangleShape board;

  
  // Содержит квадраты доски. Их тип ch::Square и они хранятся в этом векторе.
  // Квадратов всего 32, т.к. содержит только доступные квадраты.
  // Рисуются неввидимыми для присутствия на экране.
  std::vector<Square> squaresVect;
  
  sf::Color squareColor1;

  sf::Color squareColor2;


  // Длина квадратов.
  float squareLength;


  // Используется в конструкторе для определения размера доски.
  static const int boardLengthInSquares = 8;


  // Создает и распределяет квадраты, хранимые в squaresVect.
  void setAccessibleSquares(const sf::Color &color,
                            const float &squareLength);


  // Вызывается в setAccessibleSquares(), чтобы создать квадраты.
  void constructAccessibleSquares(const sf::Color &color);


  // Вызывается в setAccessibleSquares(), чтобы распределить квадраты.
  void positionAccessibleSquares(const float &squareLength);

  
  // Вызывается в draw(), чтобы фактически вывести квадраты из
  // squaresVect на renderWindow.
  void drawSquares(sf::RenderWindow &renderWindow);

  void adjustSquaresPositions(const sf::Vector2f &positionalChange);

};

} // namespace ch

#endif