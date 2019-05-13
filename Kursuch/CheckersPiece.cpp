#include "CheckersPiece.h"

namespace ch {

Piece::Piece(const float &radius, 
        const sf::Color &color, 
        const float &outlineThickness)
    : circle(radius)
{
  circle.setFillColor(color);
  circle.setOutlineThickness(outlineThickness);
  //circle.setOutlineColor(sf::Color(153, 102, 51, 0));
}


// использует метод draw() для вывода фигур на экран.
// использует поле sf::CircleShape circle.
void Piece::draw(sf::RenderWindow &renderWindow) {
  renderWindow.draw(circle);
}


// передвигает фигуру.
void Piece::setPosition(const sf::Vector2f &newPosition) {
  circle.setPosition(newPosition);
}

void Piece::setColor(const sf::Color &newColor) {
  circle.setFillColor(newColor);
}

void Piece::setOutlineColor(const sf::Color &newColor) {
  circle.setOutlineColor(newColor);
}

sf::CircleShape Piece::getCircle() {
  return circle;
}

sf::Vector2f Piece::getPosition() {
  return circle.getPosition();
}

} // namespace ch