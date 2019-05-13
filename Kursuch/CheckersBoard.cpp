#include "CheckersBoard.h"

namespace ch {


Board::Board(const float boardLength, const sf::Color &color1, 
			       const sf::Color &color2, const sf::Color &borderColor) 

    : window(NULL),
      board(sf::RectangleShape(sf::Vector2f(boardLength,boardLength))), 
	    squareColor1(color1), 
	    squareColor2(color2),
		  squareLength(boardLength / Board::boardLengthInSquares)
{
  setAccessibleSquares(squareColor1, squareLength);
	board.setFillColor(squareColor2);
	board.setOutlineColor(borderColor);
}


// выводит на экран renderWindow спрайт доски и фигуры.
void Board::draw(sf::RenderWindow &renderWindow, 
                 std::vector<sq::Square> &squares_list) {
 // renderWindow.draw(board);
	//drawSquares(renderWindow);
	sf::Texture bord;
	bord.loadFromFile("Resources/board0.png");
	sf::Sprite gBoard(bord);
	gBoard.setPosition(sf::Vector2f(15.5f, 14.0f));
	gBoard.setScale(1.34, 1.34);
	renderWindow.draw(gBoard);
  drawPieces(renderWindow, squares_list);
}


sf::RenderWindow* Board::getWindow() const {
  return window;
}

sf::Vector2f Board::getSize() const { 
  return board.getSize();
}
		

float Board::getBorderThickness() const { 
  return board.getOutlineThickness();
}


sf::Color Board::getBorderColor() const { 
  return board.getOutlineColor(); 
}


sf::Vector2f Board::getPosition() const {
  return board.getPosition(); 
}
	
  
sf::Color Board::getSquareColor1() const {
  return squareColor1; 
}
	
 	
sf::Color Board::getSquareColor2() const {
  return squareColor2; 
}


void Board::setWindow(sf::RenderWindow &newWindow) {
  window = &newWindow;
}


void Board::setSize(const sf::Vector2f &newSize) {
  board.setSize(newSize);
}
	

void Board::setBorderThickness(const float &newBorderThickness) {
	board.setOutlineThickness(newBorderThickness);		
}
	

void Board::setBorderColor(const sf::Color &newBorderColor) { 
	board.setOutlineColor(newBorderColor); 
}
	

void Board::setPosition(const sf::Vector2f &newPosition) {
	adjustSquaresPositions(newPosition - board.getPosition());
	board.setPosition(newPosition); 
}
	

void Board::setSquareColor1(const sf::Color &newColor) {
	squareColor1 = newColor;
}
	

void Board::setSquareColor2(const sf::Color &newColor) {
	squareColor2 = newColor; 
}

void Board::drawPieces(sf::RenderWindow &window,
                 std::vector<sq::Square> &updates) {
  Piece piece_to_draw(30.0f, sf::Color(), 5.0f);

  for (unsigned i = 0; i < updates.size(); ++i) {
    switch (updates[i].color()) {
    case Red:
      piece_to_draw.setColor(sf::Color::White);
      piece_to_draw.setPosition(squaresVect[i].getCoordinatesToPlacePiece(piece_to_draw));
      piece_to_draw.setOutlineColor(sf::Color(102, 51, 0, 255));
      piece_to_draw.draw(window);
      break;
    case Black:
      piece_to_draw.setColor(sf::Color::Black);
      piece_to_draw.setPosition(squaresVect[i].getCoordinatesToPlacePiece(piece_to_draw));
      piece_to_draw.setOutlineColor(sf::Color(102, 51, 0, 255));
      piece_to_draw.draw(window);
      break;
    case cRed:
      piece_to_draw.setColor(sf::Color::White);
      piece_to_draw.setPosition(squaresVect[i].getCoordinatesToPlacePiece(piece_to_draw));
      piece_to_draw.setOutlineColor(sf::Color::White);
      piece_to_draw.draw(window);
      break;
    case cBlack:
      piece_to_draw.setColor(sf::Color::Black);
      piece_to_draw.setPosition(squaresVect[i].getCoordinatesToPlacePiece(piece_to_draw));
      piece_to_draw.setOutlineColor(sf::Color::Black);
      piece_to_draw.draw(window);
      break;
    }
  }
}

std::string Board::interpretClick(sf::Event &what, std::vector<sq::Square> &squares_list) {
  for (unsigned i = 0; i < ch::Square::last; ++i) {
    if (what.mouseButton.x > squaresVect[i].getPosition().x &&
        what.mouseButton.x < squaresVect[i].getPosition().x + squaresVect[i].getSize().x &&
        what.mouseButton.y > squaresVect[i].getPosition().y &&
        what.mouseButton.y < squaresVect[i].getPosition().y + squaresVect[i].getSize().y) {
        return squares_list[i].square();
        }
  } 
  return "click_not_interpreted";
}


void Board::setAccessibleSquares(const sf::Color &color, 
                                 const float &squareLength) {
	constructAccessibleSquares(color);
	positionAccessibleSquares(squareLength);
}


void Board::constructAccessibleSquares(const sf::Color &color) {
	for (unsigned i = 0; squaresVect.size() != 32; ++i) {
		squaresVect.push_back(Square(squareLength, color));
	}
}


void Board::positionAccessibleSquares(const float &squareLength) {
	for (unsigned i = 0; i != Square::last; ++i) {
		squaresVect[i].setPosition(Square::set_sq_position(i, squareLength));
	}
}


void Board::drawSquares(sf::RenderWindow &renderWindow) {
	for (unsigned i = 0; i < squaresVect.size(); ++i)
		squaresVect[i].draw(renderWindow);
}


void Board::adjustSquaresPositions(const sf::Vector2f &positionalChange) {
  for (unsigned i = 0; i < squaresVect.size(); ++i) {
		squaresVect[i].setPosition(
			sf::Vector2f(squaresVect[i].getPosition().x + positionalChange.x,
			             squaresVect[i].getPosition().y + positionalChange.y));
	}
}

} // namespace ch