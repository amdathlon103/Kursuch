#ifndef CHECKERSSQUARE_H
#define CHECKERSSQUARE_H

#include <SFML/Graphics.hpp>
#include "CheckersPiece.h"

namespace ch {

// представл€ет отдельный квадрат на доске
class Square {
 public:
  
  // Ќабор дл€ каждого доступного квадрата на доскею
  // Last дл€ использовани€ циклов, например Board::positionAccessibleSquares().

  enum Name {
    a1, c1, e1, g1,
    b2, d2, f2, h2,
    a3, c3, e3, g3,
    b4, d4, f4, h4,
    a5, c5, e5, g5,
    b6, d6, f6, h6,
    a7, c7, e7, g7,
    b8, d8, f8, h8,
    last
  };

  // следующие 16 констант дл€ позиционировани€ квадратов на доске.
  //  оэффициент дл€ увеличени€ координаты с изменением разрешени€.
  // (после замены доски на спрайт не используетс€)
  //  олонны дл€ X координаты:
	static const int kColumn_a_positional_multiplier = 0;
	static const int kColumn_b_positional_multiplier = 1;
	static const int kColumn_c_positional_multiplier = 2;
	static const int kColumn_d_positional_multiplier = 3;
	static const int kColumn_e_positional_multiplier = 4;
	static const int kColumn_f_positional_multiplier = 5;
	static const int kColumn_g_positional_multiplier = 6;
	static const int kColumn_h_positional_multiplier = 7;
  // –€ды дл€ Y координаты:
	static const int kRow_1_positional_multiplier = 7;
	static const int kRow_2_positional_multiplier = 6;
	static const int kRow_3_positional_multiplier = 5;
	static const int kRow_4_positional_multiplier = 4;
	static const int kRow_5_positional_multiplier = 3;
	static const int kRow_6_positional_multiplier = 2;
	static const int kRow_7_positional_multiplier = 1;
	static const int kRow_8_positional_multiplier = 0;

	
	Square(const float length, 
         const sf::Color &color = sf::Color::Black, 
				 const sf::Vector2f &position = sf::Vector2f(0,0));

  // ¬ыводит квадраты на окно renderWindow.
	void draw(sf::RenderWindow &renderWindow);


	static sf::Vector2f set_sq_position(int square, const float &squareLength);
	
	static sf::Vector2f set_a1_position(const float &squareLength);
	static sf::Vector2f set_a3_position(const float &squareLength);
	static sf::Vector2f set_a5_position(const float &squareLength);
	static sf::Vector2f set_a7_position(const float &squareLength);
	static sf::Vector2f set_b2_position(const float &squareLength);
	static sf::Vector2f set_b4_position(const float &squareLength);
	static sf::Vector2f set_b6_position(const float &squareLength);
	static sf::Vector2f set_b8_position(const float &squareLength);
	static sf::Vector2f set_c1_position(const float &squareLength);
	static sf::Vector2f set_c3_position(const float &squareLength);
	static sf::Vector2f set_c5_position(const float &squareLength);
	static sf::Vector2f set_c7_position(const float &squareLength);
	static sf::Vector2f set_d2_position(const float &squareLength);
	static sf::Vector2f set_d4_position(const float &squareLength);
	static sf::Vector2f set_d6_position(const float &squareLength);
	static sf::Vector2f set_d8_position(const float &squareLength);
	static sf::Vector2f set_e1_position(const float &squareLength);
	static sf::Vector2f set_e3_position(const float &squareLength);
	static sf::Vector2f set_e5_position(const float &squareLength);
	static sf::Vector2f set_e7_position(const float &squareLength);
	static sf::Vector2f set_f2_position(const float &squareLength);
	static sf::Vector2f set_f4_position(const float &squareLength);
	static sf::Vector2f set_f6_position(const float &squareLength);
	static sf::Vector2f set_f8_position(const float &squareLength);
	static sf::Vector2f set_g1_position(const float &squareLength);
	static sf::Vector2f set_g3_position(const float &squareLength);
	static sf::Vector2f set_g5_position(const float &squareLength);
	static sf::Vector2f set_g7_position(const float &squareLength);
	static sf::Vector2f set_h2_position(const float &squareLength);
	static sf::Vector2f set_h4_position(const float &squareLength);
	static sf::Vector2f set_h6_position(const float &squareLength);
	static sf::Vector2f set_h8_position(const float &squareLength);

	
  sf::Vector2f getSize() const;
	
  sf::Vector2f getPosition() const;
	
  sf::Color getColor() const;

	void setSize(const sf::Vector2f &newSize);

	void setPosition(const sf::Vector2f &newPosition);

	void setColor(const sf::Color &newColor);

  // ¬озвращает набор координат, который позиционирует фигуры по центру квадрата
  sf::Vector2f getCoordinatesToPlacePiece(Piece &piece_to_place);

 private:
  // ‘актический квадрат. используетс€ в Square::draw(). Ќевидимый.
	sf::RectangleShape square;

  // »спользуетс€ только в sf::Vector2f
  // getCoordinatesToPlacePiece().
  // ¬озвращает координату центра квадрата.
  sf::Vector2f getCenterCoordinates();
};

} // namespace ch

#endif