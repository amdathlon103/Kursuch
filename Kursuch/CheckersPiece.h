#ifndef CHECKERSPIECE_H
#define CHECKERSPIECE_H

#include <SFML/Graphics.hpp>

namespace ch {

	// ����������, ����� � Piece ���� ����� � Square.
class Square;

// ���������� ������ �� �����.
class Piece {
 public:
  Piece(const float &radius, 
        const sf::Color &color, 
        const float &outlineThickness);

  // ������� ������ �� ����� renderWindow.
  void draw(sf::RenderWindow &renderWindow);

  void setPosition(const sf::Vector2f &newPosition);

  void setColor(const sf::Color &newColor);

  void setOutlineColor(const sf::Color &newColor);

  sf::CircleShape getCircle();

  sf::Vector2f getPosition();

 private:
  // ������� �������� ������ ��� draw().
  sf::CircleShape circle;
};

} // namespace ch

#endif