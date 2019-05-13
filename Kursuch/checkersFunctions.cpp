
#include "checkersFunctions.h"



void prepareGame() {
	gameBoard.getWindow()->clear();
	//подготовить переменные:
	selection = " ";
	turn = Red;
	captureDirection = ' ';
	initialRowParity = ' ';
	wasCapture = false;
	loser = ' ';
	selected = 0;
	targeted = 0;
	inBetween = 0;
	wEaten = 0;
	bEaten = 0;
	font.loadFromFile("Resources/Arial.ttf");
	locked.setPosition(650.0f, 440.0f);
	locked.setFont(font);
	winMsg.setString("");
	egMsg.setString("");
	wEat.setString("");
	bEat.setString("");
	wPie.setRadius(30.0f);
	wPie.setOutlineThickness(5.0f);
	wPie.setPosition(740.0f, 30.0f);
	wPie.setFillColor(sf::Color::White);
	wPie.setOutlineColor(sf::Color(102, 51, 0, 255));
	bPie.setRadius(30.0f);
	bPie.setOutlineThickness(5.0f);
	bPie.setPosition(740.0f, 550.0f);
	bPie.setFillColor(sf::Color::Black);
	bPie.setOutlineColor(sf::Color(102, 51, 0, 255));
	

	//подготовить квадраты и фигуры:
	squares[0] = sq::Square(Red,"a1",'1'); squares[1] = sq::Square(Red,"c1",'1'); 
	squares[2] = sq::Square(Red,"e1",'1'); squares[3] = sq::Square(Red,"g1",'1');
	squares[4] = sq::Square(Red,"b2",'2'); squares[5] = sq::Square(Red,"d2",'2'); 
	squares[6] = sq::Square(Red,"f2",'2'); squares[7] = sq::Square(Red,"h2",'2');
	squares[8] = sq::Square(Red,"a3",'3'); squares[9] = sq::Square(Red,"c3",'3'); 
	squares[10] = sq::Square(Red,"e3",'3'); squares[11] = sq::Square(Red,"g3",'3');
	squares[12] = sq::Square(' ',"b4",'4'); squares[13] = sq::Square(' ',"d4",'4'); 
	squares[14] = sq::Square(' ',"f4",'4'); squares[15] = sq::Square(' ',"h4",'4');
	squares[16] = sq::Square(' ',"a5",'5'); squares[17] = sq::Square(' ',"c5",'5'); 
	squares[18] = sq::Square(' ',"e5",'5'); squares[19] = sq::Square(' ',"g5",'5');
	squares[20] = sq::Square(Black,"b6",'6'); squares[21] = sq::Square(Black,"d6",'6'); 
	squares[22] = sq::Square(Black,"f6",'6'); squares[23] = sq::Square(Black,"h6",'6');
	squares[24] = sq::Square(Black,"a7",'7'); squares[25] = sq::Square(Black,"c7",'7'); 
	squares[26] = sq::Square(Black,"e7",'7'); squares[27] = sq::Square(Black,"g7",'7');
	squares[28] = sq::Square(Black,"b8",'8'); squares[29] = sq::Square(Black,"d8",'8'); 
	squares[30] = sq::Square(Black,"f8",'8'); squares[31] = sq::Square(Black,"h8",'8');
	return;
}

// Запрос действий пользователя (клик по окну, нажатие кнопок, закрыть окно, и т.п.).
std::string get_GUI_Input() {
  std::string result = " ";

  if (!gameBoard.getWindow()) {
    return "quit";
  }

  sf::Texture help_guide;
  help_guide.loadFromFile("Resources/help.png");
  sf::Sprite help(help_guide);
  help.setPosition(sf::Vector2f(650.0f, 150.0f));
  curTurn.setPosition(650.0f, 400.0f);
  curTurn.setFont(font);
  wEat.setPosition(650.0f, 20.0f);
  wEat.setFont(font);
  bEat.setPosition(650.0f, 540.0f);
  bEat.setFont(font);
  wEat.setCharacterSize(60);
  bEat.setCharacterSize(60);
  winMsg.setPosition(180.0f, 250.0f);
  winMsg.setCharacterSize(60);
  winMsg.setFillColor(sf::Color::Black);
  winMsg.setOutlineColor(sf::Color::Red);
  winMsg.setOutlineThickness(5);
  winMsg.setFont(font);
  egMsg.setPosition(180.0f, 315.0f);
  egMsg.setCharacterSize(40);
  egMsg.setFillColor(sf::Color::Black);
  egMsg.setOutlineColor(sf::Color::Red);
  egMsg.setOutlineThickness(2);
  egMsg.setFont(font);  
  while (gameBoard.getWindow()->isOpen()) {
    sf::Event what;

    while (gameBoard.getWindow()->pollEvent(what)) {
      switch (what.type) {
      case sf::Event::Closed:
        gameBoard.getWindow()->close();
        return "quit";
      case sf::Event::MouseButtonPressed:
        result = gameBoard.interpretClick(what, checkers::squares);
        return result;
        break;
      case sf::Event::KeyReleased:
        switch (what.key.code) {
          case sf::Keyboard::H:
            // to display the helpful guide
            return "h";
          case sf::Keyboard::Q:
            // to quit
            return "q";
          case sf::Keyboard::R:
            // to reset (in case a piece that cannot be moved is picked)
            return "r";
          case sf::Keyboard::S:
            // to skip the option to do a consecutive jump
            return "s";
		  case sf::Keyboard::N:
			  //new game
			  return "n";
        }
      default:
        break;
      }
    }

    gameBoard.getWindow()->clear();
    gameBoard.draw(*gameBoard.getWindow(), checkers::squares);
	gameBoard.getWindow()->draw(curTurn);
	gameBoard.getWindow()->draw(locked);
    gameBoard.getWindow()->draw(help);
	gameBoard.getWindow()->draw(winMsg);
	gameBoard.getWindow()->draw(egMsg);
	gameBoard.getWindow()->draw(wPie);
	gameBoard.getWindow()->draw(bPie);
	gameBoard.getWindow()->draw(wEat);
	gameBoard.getWindow()->draw(bEat);
    gameBoard.getWindow()->display();
  }

  return result;
}

bool isSquare (std::string sq) {
	//используется только в конструкторе
	if(sq == "a1" || sq == "c1" || sq == "e1" || sq == "g1" 
		|| sq == "b2" || sq == "d2" || sq == "f2" || sq == "h2"
		|| sq == "a3" || sq == "c3" || sq == "e3" || sq == "g3"
		|| sq == "b4" || sq == "d4" || sq == "f4" || sq == "h4"
		|| sq == "a5" || sq == "c5" || sq == "e5" || sq == "g5"
		|| sq == "b6" || sq == "d6" || sq == "f6" || sq == "h6"
		|| sq == "a7" || sq == "c7" || sq == "e7" || sq == "g7"
		|| sq == "b8" || sq == "d8" || sq == "f8" || sq == "h8") return true;
	return false;
}

char reverseCrown(char color) {
	if(color == Red) return cRed;
	if(color == Black) return cBlack;
	if(color == cRed) return Red;
	if(color == cBlack) return Black;
	error("Exception: reverseCrown() used on a char that is not 'r', 'b', 'R', or 'B'\n");
}


bool cannotMakeMove() {
	for(size_t i = 0; i < squares.size(); ++i)
	{
		if(possibleMovement(&squares[i])) 
		{ 
			return false; //передвижение возможно
		}
		if(possibleCapture(&squares[i])) return false;
	}
	return true;
}

bool possibleMovement(sq::Square *initSq) {
	//фигура в initSq может переместиться на 1 квадрат?

	//если цвет в initSq не верный return false(не тот ход)
	if(turn != initSq->color() && reverseCrown(turn) != initSq->color())
	{
		return false;
	}

	switch (initSq->color()) {
	case Red:
		//если белый, может ли фигура двинуться на 1 квадрат вперед
		for(size_t i = 0; i < initSq->getFrtAdjSqs().size(); ++i)
		{
			//size_t i хранит адрес соседнего квадрата
			//проверить пустой ли квадрат с этим адресом
			if(initSq->getFrtAdjSqs()[i] != " " && //предотвращает использование getAddress не на квадрат
				squares[getAddress(initSq->getFrtAdjSqs()[i])].color() == ' ') 
			{
				return true;
			}
		}
		break;
	case Black:
		//если черный, может ли фигура двинуться на 1 квадрат назад (с нашей точки зрения)
		for(size_t i = 0; i < initSq->getBacAdjSqs().size(); ++i)
		{
			//size_t i хранит адрес соседнего квадрата
			//проверить пустой ли квадрат с этим адресом
			if(initSq->getBacAdjSqs()[i] != " " && //предотвращает использование getAddress не на квадрат
				squares[getAddress(initSq->getBacAdjSqs()[i])].color() == ' ') 
			{
				return true;
			}
		}
		break;
	case cRed: case cBlack:
		//если дамка, фигура может двигаться в любом направлении
		for(size_t i = 0; i < initSq->getFrtAdjSqs().size(); ++i) //здесь, size() возвращает 2 и работает для обоих
															   //getFrtAdjSqs and getBacAdjSqs
		{
			//size_t i хранит адрес соседнего квадрата
			//проверить пустой ли квадрат с этим адресом
			if(initSq->getFrtAdjSqs()[i] != " " && //предотвращает использование getAddress не на квадрат
				squares[getAddress(initSq->getFrtAdjSqs()[i])].color() == ' ') 
			{
				return true;
			}
			if(initSq->getBacAdjSqs()[i] != " " && //предотвращает использование getAddress не на квадрат
				squares[getAddress(initSq->getBacAdjSqs()[i])].color() == ' ') 
			{
				return true;
			}
		}
		break;
	}
	return false;
}

void getSquare() {

	std::cout << "Current turn: "<<turn<<"\n";
	std::cout << "Enter coordinate of piece you want to move (ex. a1, f8):\n";
	
  selection = get_GUI_Input();
  std::cout << selection << std::endl;
  
	if(selection == "h" || selection == "help")
		{ displayHelp(); getSquare(); }
	if(selection == "d" || selection == "display") 
		{ displayBoard(squares,2); getSquare(); }
	if(selection == "r" || selection == "reset") 
		{ displayBoard(squares,2); std::cout << "\nCannot reset! No selected piece.\n"; getSquare(); }
	if(selection == "q" || selection == "quit") return;
	if(!goodSquare(selection)) getSquare();
	return;
}

bool goodSquare(std::string sq) {	
	//проверяет правильный ли цвет фигуры в квадрате и доступен ли квадрат

	if(!isSquare(sq)) { std::cout << "\nError: You did not select an accessible square\n"; return false; }
	
	selected = getAddress(selection); //getAddress(...) после isSquare чтобы предотвратить ошибки

	if(turn != squares[selected].color() && reverseCrown(turn) != squares[selected].color()) 
		{ std::cout << "\nError: Picked wrong color.\n"; return false; }
			
	return true; 
}

void getTarget() {
	locked.setString(L"Фигура выбрана!");
	if(selection == "q" || selection == "quit") return;
	std::cout<<"Enter coordinate of target square (ex. a1, f8):\n";
	//std::cin >> selection;
  selection = get_GUI_Input();
  std::cout << selection << '\n';

	if(selection == "d" || selection == "display") 
		{ displayBoard(squares,2); getTarget(); }
	if(selection == "r" || selection == "reset")	//сброс фигуры, если у выбранной фигуры нет доступных ходов
	{	
		locked.setString("");
		displayBoard(squares,2); getSquare(); 
		if(selection == "q" || selection == "quit") return; getTarget(); 
	}
	
	if(selection == "q" || selection == "quit") return;
	if(!goodTarget(selection)) getTarget();
	return;
}

bool goodTarget(std::string sq) {

	//проверить квадрат ли sq
	if(!isSquare(sq)) 
	{
		std::cout << "\nError: Targeted square is not a square\n";
		return false;
	}

	targeted = getAddress(selection); 
	
	//проверить, отличается ли targeted от selected
	if(targeted == selected)
	{
		std::cout << "\nError: Targeted square and selected square are the same?\n";
		return false;
	}

	//проверить пустой ли sq
	if(squares[targeted].color() != ' ') 
	{
		std::cout << "\nError: The target square is not empty.\n";
		return false;
	}

	if(!squares[selected].isCrowned())
	{
		if(turn == Red)
		{
			if(!oneFrSqAway() && !twoFrSqAway()) 
			{
				std::cout << "\nError: The target square is not within reach.\n";
				return false;
			}
			if(twoFrSqAway())
			{
				//если target в 2х квадратах впереди, то должен быть захват
				if(!isCapture()) 
				{
					std::cout << "\nError: The target square is two squares away, but there is no captured piece.\n";
					return false;
				}
			}
		}
		if(turn == Black)
		{
			if(!oneBcSqAway() && !twoBcSqAway()) 
			{
				std::cout << "\nError: The target square is not within reach.\n";
				return false;
			}
			if(twoBcSqAway())
			{
				////если target в 2х квадратах сзади, то должен быть захват
				if(!isCapture())
				{
					std::cout << "\nError: The target square is two squares away, but there is no piece to capture.\n";
					return false;
				}
			}
		}
	}
	if(squares[selected].isCrowned())
	{
		//дамки могут двигаться вперед или назад
		if(!oneFrSqAway() && !oneBcSqAway() && !twoFrSqAway() && !twoBcSqAway())
		{
			std::cout << "\nError: The target square is not within reach.\n";
			return false;
		}
		if(twoFrSqAway() || twoBcSqAway())
		{
			//если target в 2х квадратах, то должен быть захват
			if(!isCapture())
			{
				std::cout << "\nError: The target square is two squares away, but there is no piece to capture.\n";
				return false;
			}
		}
	}
	
	return true; //Success!
}

int getAddress(std::string sq)
{
	for(size_t i = 0; i < squares.size(); ++i)
		{
			if(sq == squares[i].square())
			{
				return i;
			}
		}
	error("Exception: used getAddress on non-square\n");
}

bool oneFrSqAway()
{
	//цель в 1 квадрате впереди?
	for(size_t i = 0; i < squares[selected].getFrtAdjSqs().size(); ++i) //size() всегда равен 2
	{
		if(squares[selected].getFrtAdjSqs()[i] == squares[targeted].square()) return true;
	}

	return false;
}

bool oneBcSqAway()
{
	//цель в 1 квадрате сзади?
	for(size_t i = 0; i < squares[selected].getBacAdjSqs().size(); ++i) //size() всегда равен 2
	{
		if(squares[selected].getBacAdjSqs()[i] == squares[targeted].square()) return true;
	}

	return false;
}

bool twoFrSqAway()
{
	//цель в 2 квадратах впереди?
	for(size_t i = 0; i < squares[selected].getFrtJmpSqs().size(); ++i) //size() всегда равен 2
	{
		if(squares[selected].getFrtJmpSqs()[i] == squares[targeted].square()) return true;
	}

	return false;
}

bool twoBcSqAway()
{
	//цель в 2х квадратах сзади? (для дамок)
	for(size_t i = 0; i < squares[selected].getBacJmpSqs().size(); ++i) //size() всегда равен 2
	{
		if(squares[selected].getBacJmpSqs()[i] == squares[targeted].square()) return true;
	}

	return false;
}

char getLetCoordinate(std::string sq)
	//возвращает буквенную координату любого квадрата
{
	if(sq == "a1" || sq == "a3" || sq == "a5" || sq == "a7") return 'a';
	if(sq == "b2" || sq == "b4" || sq == "b6" || sq == "b8") return 'b';
	if(sq == "c1" || sq == "c3" || sq == "c5" || sq == "c7") return 'c';
	if(sq == "d2" || sq == "d4" || sq == "d6" || sq == "d8") return 'd';
	if(sq == "e1" || sq == "e3" || sq == "e5" || sq == "e7") return 'e';
	if(sq == "f2" || sq == "f4" || sq == "f6" || sq == "f8") return 'f';
	if(sq == "g1" || sq == "g3" || sq == "g5" || sq == "g7") return 'g';
	if(sq == "h2" || sq == "h4" || sq == "h6" || sq == "h8") return 'h';
	error("Exception: The argument of getLetCoordinate is not a square\n");
}

std::string getSqInBetween(sq::Square *initSq, sq::Square *targetSq)
{
	//находит квадрат между беря letCoord,
	// numCoord, и добавляя их в newSquare в конце

	captureDirection = getCapDirection(&initSq->square(), &targetSq->square());

	std::string newSquare = " ";
	char letCoord = ' ';
	char numCoord = ' ';

	//получить букву квадрата между
	switch(getLetCoordinate(initSq->square())) 
	{
	case 'a': if(captureDirection == Right) letCoord = 'b'; break;
	case 'b': if(captureDirection == Right) letCoord = 'c'; break;
			
	case 'c': if(captureDirection == Right) letCoord = 'd';
			  if(captureDirection == Left) letCoord = 'b'; break;
			
	case 'd': if(captureDirection == Right) letCoord = 'e';
		      if(captureDirection == Left) letCoord = 'c'; break;
			
	case 'e': if(captureDirection == Right) letCoord = 'f';
		      if(captureDirection == Left) letCoord = 'd'; break;
			
	case 'f': if(captureDirection == Right) letCoord = 'g';
			  if(captureDirection == Left) letCoord = 'e'; break;
			
	case 'g': if(captureDirection == Left) letCoord = 'f'; break;
	case 'h': if(captureDirection == Left) letCoord = 'g'; break;
	
	default: error("Exception: getSqInBetween(...) cannot get letter part of name.\n");
	}

	//получить цифру квадрата между
	if(!initSq->isCrowned())
	{
		switch(turn) 
		{
			case Red:
				numCoord = targetSq->row() - 1; 
				break;
			case Black:
				numCoord = targetSq->row() + 1;
				break;
			default:
				error("Exception: char turn is neither 'r' nor 'b'\n");
		}
	}
	if(initSq->isCrowned())
	{
		if(upCapture(initSq,targetSq)) numCoord = targetSq->row() - 1; //если захват вверх, обращаться как с захватом белых
		if(downCapture(initSq,targetSq)) numCoord = targetSq->row() + 1; //если вниз - черных
	}
	
	newSquare = letCoord; 
	newSquare += numCoord;
	return newSquare;
}

char getCapDirection(std::string *initSq, std::string *targetSq)
{
	//эти условия работают и для черных, и для белых
	if(getLetCoordinate(*initSq) < getLetCoordinate(*targetSq)) 
		//например b2 в d4, b "меньше" d, так что направление верное
		return Right;
	
	if(getLetCoordinate(*initSq) > getLetCoordinate(*targetSq)) 
		return Left;
	error("Exception: The selected and targeted squares are on the same row\n");
}

char getRowParity(char row)
{
	//четный или нечетный ряд, в зависимости от численной координаты
	switch(row) 
		{
		case '1': case '3': case '5': case '7':
			return Odd;
		case '2': case '4': case '6': case '8':
			return Even;
		}
	error("Exception: The row argument used in getRowParity is not from 1-8\n");
}

bool upCapture(sq::Square *initSq, sq::Square *targetSq) {
	if(initSq->row() < targetSq->row()) return true;
	return false;
}

bool downCapture(sq::Square *initSq, sq::Square *targetSq) {
	if(initSq->row() > targetSq->row()) return true;
	return false;
}

bool R_Capture1()
{
	//первое условие белых выполняется?
	if(initialRowParity == Odd && captureDirection == Right) return true;
	return false;
}

bool R_Capture2()
{
	//второе условие белых выполняется?
	if(initialRowParity == Even && captureDirection == Right) return true;
	return false;
}

bool R_Capture3()
{
	//третье условие белых выполняется?
	if(initialRowParity == Odd && captureDirection == Left) return true;
	return false;
}

bool R_Capture4()
{
	//четвертое условие белых выполняется?
	if(initialRowParity == Even && captureDirection == Left) return true;
	return false;
}

bool B_Capture1()
{
	//первое условие черных выполняется?
	if(initialRowParity == Odd && captureDirection == Left) return true;
	return false;
}

bool B_Capture2()
{
	//второе условие черных выполняется?
	if(initialRowParity == Even && captureDirection == Left) return true;
	return false;
}

bool B_Capture3()
{
	//третье условие черных выполняется?
	if(initialRowParity == Odd && captureDirection == Right) return true;
	return false;
}

bool B_Capture4()
{
	//четвертое условие черных выполняется?
	if(initialRowParity == Even && captureDirection == Right) return true;
	return false;
}

char oppoColor(char color) { 
	switch(color) {
	case Red: return Black;
	case Black: return Red;
	case cRed: return cBlack;
	case cBlack: return cRed;
	default: error("Exception: oppoColor(...) used on non-color\n");
	}
}

bool isCapture() {
	//происходит ли захват?

	//проверить на условия захвата
	// 1) определить цвет

	// 2) определить четность ряда
	initialRowParity = getRowParity(squares[selected].row());

	// 3) определить направление захвата
	captureDirection = getCapDirection(&squares[selected].square(), &squares[targeted].square());

	//проверить выполняется ли какое нибудь из условий захвата
	if(!squares[selected].isCrowned())
	{
		switch(turn)
		{
		case Red:
			if(R_Capture1() && targeted - selected == rOddRightCapJmp ||
				R_Capture2() && targeted - selected == rEvenRightCapJmp ||
				R_Capture3() && targeted - selected == rOddLeftCapJmp ||
				R_Capture4() && targeted - selected == rEvenLeftCapJmp) ;
			else return false;

			break;
		case Black:
			if(B_Capture1() && targeted - selected == bOddLeftCapJmp ||
				B_Capture2() && targeted - selected == bEvenLeftCapJmp ||
				B_Capture3() && targeted - selected == bOddRightCapJmp ||
				B_Capture4() && targeted - selected == bEvenRightCapJmp) ;
			else return false;

			break;
		}
	}
	if(squares[selected].isCrowned())
	{
		if(R_Capture1() && targeted - selected == rOddRightCapJmp ||
			R_Capture2() && targeted - selected == rEvenRightCapJmp ||
			R_Capture3() && targeted - selected == rOddLeftCapJmp ||
			R_Capture4() && targeted - selected == rEvenLeftCapJmp ||
			B_Capture1() && targeted - selected == bOddLeftCapJmp ||
			B_Capture2() && targeted - selected == bEvenLeftCapJmp ||
			B_Capture3() && targeted - selected == bOddRightCapJmp ||
			B_Capture4() && targeted - selected == bEvenRightCapJmp) ;
		else return false;
	}

	//сохранить адрес квадрата между inBetween
	inBetween = getAddress(getSqInBetween(&squares[selected], &squares[targeted] ));

	if(squares[inBetween].color() != oppoColor(turn) && squares[inBetween].color() != reverseCrown(oppoColor(turn))) return false;
	//счетчик захваченых фигур
	switch (squares[inBetween].color()) {
		case 'r':
			wEaten += 1;
			wEat.setString(std::to_string(wEaten));
			break;
		case 'R':
			wEaten += 1;
			wEat.setString(std::to_string(wEaten));
			break;
		case'b':
			bEaten += 1;
			bEat.setString(std::to_string(bEaten));
			break;
		case'B':
			bEaten += 1;
			bEat.setString(std::to_string(bEaten));
			break;
	}

	//отметить фигуру между как захваченую
	squares[inBetween].switchCap(true);  //этот квадрат теперь захвачен
	return true;
}

void updateBoard() {
	// 1) регулирует движение фигур:
	//чтобы "передвинуть" фигуру, меняем цвет нужного квадрата
	//на цвет текущего квадрата, 
	squares[targeted].changeColor(squares[selected].color());
	
	//затем меняем цвет текущего квадрата на пустой
	squares[selected].changeColor(' ');

	if(squares[selected].isCrowned()) 
	{ 
		squares[selected].switchCrown(false); 
		squares[targeted].switchCrown(true); 
	}

	// 2) регулирует захваты (заставляет исчезать захваченые фигуры):
	for(size_t i=0; i<squares.size(); ++i)
	{
		if(squares[i].isCaptured()) 
		{
			squares[i].changeColor(' '); 
			squares[i].switchCrown(false);
			squares[i].switchCap(false);
			wasCapture = true;
			std::cout << "\nThe piece on " << squares[i].square() << " has been captured.\n";
		}
	}

	// 3) чики брики и в дамки
	if(isPromotion() && !squares[targeted].isCrowned()) 
	{ 
		squares[targeted].switchCrown(true); 
		squares[targeted].changeColor(reverseCrown(squares[targeted].color())); 
	}
}

bool isPromotion() {
	if(turn == Red) {
		switch(targeted) {
		case b8: case d8: case f8: case h8: return true;
		default: return false;
		}
	}
	if(turn == Black) {
		switch(targeted) {
		case a1: case c1: case e1: case g1: return true;
		default: return false;
		}
	}
}

bool possibleCapture(sq::Square *initSq) {
	//возможен ли захват?
	//используется для последовательных прыжков
	//используется2 после передвижения фигуры в ходу

	int address = getAddress(initSq->square()); 
	initialRowParity = getRowParity(initSq->row());
	//проверка условий захвата
	if(initSq->color() == Red || initSq->isCrowned()) 
	{
		if(initialRowParity == Odd && 
		address + rOddRightCapJmp < squares.size() && 
		squares[address + rOddRightCapJmp].color() == ' ' &&
		squares[address + rOddRightHafJmp].square() == getSqInBetween(initSq,&squares[address + rOddRightCapJmp])) 
		{
			if(squares[address + rOddRightHafJmp].color() == oppoColor(initSq->color()) ||
				squares[address + rOddRightHafJmp].color() == reverseCrown(oppoColor(initSq->color()))) return true;
		}
		
		if(initialRowParity == Even &&
		address + rEvenRightCapJmp < squares.size() && 
		squares[address + rEvenRightCapJmp].color() == ' ' &&
		squares[address + rEvenRightHafJmp].square() == getSqInBetween(initSq,&squares[address + rEvenRightCapJmp])) 
		{
			if(squares[address + rEvenRightHafJmp].color() == oppoColor(initSq->color()) ||
				squares[address + rEvenRightHafJmp].color() == reverseCrown(oppoColor(initSq->color()))) return true;
		}
		
		if(initialRowParity == Odd &&
		address + rOddLeftCapJmp < squares.size() &&
		squares[address + rOddLeftCapJmp].color() == ' ' &&
		squares[address + rOddLeftHafJmp].square() == getSqInBetween(&squares[address],&squares[address + rOddLeftCapJmp])) 
		{
			if(squares[address + rOddLeftHafJmp].color() == oppoColor(initSq->color()) ||
				squares[address + rOddLeftHafJmp].color() == reverseCrown(oppoColor(initSq->color()))) return true;
		}

		if(initialRowParity == Even &&
		address + rEvenLeftCapJmp < squares.size() &&
		squares[address + rEvenLeftCapJmp].color() == ' ' &&
		squares[address + rEvenLeftHafJmp].square() == getSqInBetween(&squares[address],&squares[address + rEvenLeftCapJmp]))
		{
			if(squares[address + rEvenLeftHafJmp].color() == oppoColor(initSq->color()) ||
				squares[address + rEvenLeftHafJmp].color() == reverseCrown(oppoColor(initSq->color()))) return true;
		}
	}
	if(initSq->color() == Black || initSq->isCrowned())
	{
		if(initialRowParity == Odd &&
		address + bOddLeftCapJmp >= lowVectorRange && 
		squares[address + bOddLeftCapJmp].color() == ' ' &&
		squares[address + bOddLeftHafJmp].square() == getSqInBetween(&squares[address],&squares[address + bOddLeftCapJmp])) 
		{
			if(squares[address + bOddLeftHafJmp].color() == oppoColor(initSq->color()) ||
				squares[address + bOddLeftHafJmp].color() == reverseCrown(oppoColor(initSq->color()))) return true;
		}

		if(initialRowParity == Even &&
		address + bEvenLeftCapJmp >= lowVectorRange && 
		squares[address + bEvenLeftCapJmp].color() == ' ' &&
		squares[address + bEvenLeftHafJmp].square() == getSqInBetween(&squares[address],&squares[address + bEvenLeftCapJmp])) 
		{
			if(squares[address + bEvenLeftHafJmp].color() == oppoColor(initSq->color()) ||
				squares[address + bEvenLeftHafJmp].color() == reverseCrown(oppoColor(initSq->color()))) return true;
		}
		
		if(initialRowParity == Odd && 
		address + bOddRightCapJmp >= lowVectorRange && 
		squares[address + bOddRightCapJmp].color() == ' ' &&
		squares[address + bOddRightHafJmp].square() == getSqInBetween(&squares[address],&squares[address + bOddRightCapJmp]))
		{
			if(squares[address + bOddRightHafJmp].color() == oppoColor(initSq->color()) ||
				squares[address + bOddRightHafJmp].color() == reverseCrown(oppoColor(initSq->color()))) return true;
		}

		if(initialRowParity == Even &&
			address + bEvenRightCapJmp >= lowVectorRange && 
			squares[address + bEvenRightCapJmp].color() == ' ' &&
			squares[address + bEvenRightHafJmp].square() == getSqInBetween(&squares[address],&squares[address + bEvenRightCapJmp]))
		{
			if(squares[address + bEvenRightHafJmp].color() == oppoColor(initSq->color()) ||
				squares[address + bEvenRightHafJmp].color() == reverseCrown(oppoColor(initSq->color()))) return true;
		}
	}
	return false;
}

void getConsecutiveJmpTarget() {
	if(selection == "q" || selection == "quit") return;
	std::cout<<"Current turn is still: " << turn << '\n';
	std::cout<<"Piece to move is on " << squares[selected].square() << ".\n";
	std::cout<<"Enter coordinate of target square for consecutive jump (ex. a1, f8).\n";
	std::cout<<"Or enter 's' or 'skip' to skip this consecutive jump.\n";
  selection = get_GUI_Input();
  std::cout << selection << '\n';
	//std::cin >> selection;

	if(selection == "d" || selection == "display") 
		{ displayBoard(squares,2); getConsecutiveJmpTarget(); }
	if(selection == "q" || selection == "quit") return;
	if(selection == "s" || selection == "skip") return; 
	if(!goodConsecutiveJmpTarget(selection)) getConsecutiveJmpTarget(); 
	return;
}

bool goodConsecutiveJmpTarget(std::string sq) {
	//то же самое что и bool goodTarget(std::string sq), за исключением:
		//нет проверки на пустоту ячейки цели (проверяется в bool possibleCapture())
	
	if(!isSquare(sq)) 
	{
		std::cout << "\nError: Targeted square is not a square\n";
		return false;
	}

	targeted = getAddress(selection); 
	
	if(targeted == selected)
	{
		std::cout << "\nError: Targeted square and selected square are the same?\n";
		return false;
	}

	if(!squares[selected].isCrowned())
	{
		if(turn == Red)
		{
			if(oneFrSqAway())
			{
				std::cout << "\nError: A consecutive turn must be a capture.\n" <<
					"Or enter 's' to skip the consecutive capture.\n";
				return false;
			}
			else if(twoFrSqAway())
			{
				if(!isCapture()) 
				{
					std::cout << "\nError: The target square is two squares away, but there is no captured piece.\n";
					return false;
				}
			}
			else
			{
				std::cout << "\nError: The target is not within reach.\n";
				return false;
			}
		}
		if(turn == Black)
		{
			if(oneBcSqAway())
			{
				std::cout << "\nError: A consecutive turn must be a capture.\n" <<
					"Otherwise, enter 's' to skip the consecutive capture.\n";
				return false;
			}
			else if(twoBcSqAway())
			{
				if(!isCapture())
				{
					std::cout << "\nError: The target square is two squares away, but there is no piece to capture.\n";
					return false;
				}
			}
			else
			{
				std::cout << "\nError: The target is not within reach.\n";
				return false;
			}
		}
	}
	if(squares[selected].isCrowned())
	{
		if(oneFrSqAway() || oneBcSqAway())
		{
			std::cout << "\nError: A consecutive turn must be a capture.\n" <<
				"Otherwise, enter 's' to skip the consecutive capture.\n";
			return false;
		}
		else if(twoFrSqAway() || twoBcSqAway())
		{
			if(!isCapture())
			{
				std::cout << "\nError: The target square is two squares away, but there is no piece to capture.\n";
				return false;
			}
		}
		else
		{
			std::cout << "\nError: The target square is not within reach.\n";
			return false;
		}
	}
	
	return true; //Success!
}

void displayHelp() {
	std::cout << "List of key commands:\n"
		<< "\t'q' to quit\n"
		<< "\t'd' to display the game board again\n"
		<< "\t'r' to reset the current turn (to pick a different piece to move)\n";
}

void redTurn() {
	curTurn.setString(L"Текущий ход: Белые");
	displayBoard(squares,2);
	getSquare();
	locked.setString(L"Фигура выбрана!");
	if(selection == "q" || selection == "quit") return;
	getTarget();
	if(selection == "q" || selection == "quit") return;
	updateBoard();
	while(wasCapture && possibleCapture(&squares[targeted])) 
	{
		selected = targeted;
		displayBoard(squares,2);
		getConsecutiveJmpTarget();
		if(selection == "q" || selection == "quit") return;
		if (selection == "s" || selection == "skip") {
			locked.setString(""); return;
		}													 //это нужно сделать перед updateBoard()
															//иначе updateBoard уберет squares[selected]
		updateBoard();
	}
	locked.setString("");
}

void blackTurn() {
	curTurn.setString(L"Текущий ход: Черные");
	displayBoard(squares,2);
	getSquare();
	locked.setString(L"Фигура выбрана!");
	if(selection == "q" || selection == "quit") return;
	getTarget();
	if(selection == "q" || selection == "quit") return;
	updateBoard();
	while(wasCapture && possibleCapture(&squares[targeted])) 
	{
		selected = targeted;
		displayBoard(squares,2);
		getConsecutiveJmpTarget();
		if(selection == "q" || selection == "quit") return;
		if(selection == "s" || selection == "skip") {
			locked.setString(""); return;
		}													 //это нужно сделать перед updateBoard()
															//иначе updateBoard уберет squares[selected]
		updateBoard();
	}
	locked.setString("");
}

bool gameOver() {
	bool rGameOver = true;
	bool bGameOver = true;

	if(loser == Both) return true; //в случае ничьей

	//конец игры, если у одной из сторон не осталось фигур
	for(size_t i = 0; i < squares.size(); ++i)
	{
		//если есть фигура одного из цветов,
		//то эта сторона не проиграла
		if(squares[i].color() == Red || squares[i].color() == cRed) rGameOver = false;
		if(squares[i].color() == Black || squares[i].color() == cBlack) bGameOver = false;
	}
	if(rGameOver && bGameOver) error("Exception: All of the pieces have disappeared\n");
	if(rGameOver) { loser = Red; return true; }
	if(bGameOver) { loser = Black; return true; }
	return false;
}

void checkersGame() {
	prepareGame();
	bool quit = false;

	while(!gameOver() && !quit)
	{
		if(cannotMakeMove())
		{
			//если нет доступных ходов у текущего игрока, то это ничья
			loser = Both; //это заставит gameOver() вернуть true
		}
		else if(turn == Red)
		{
			redTurn();
			if(selection == "q" || selection == "quit") quit = true;
			turn = oppoColor(turn);
		}
		else if(turn == Black)
		{
			blackTurn();
			if(selection == "q" || selection == "quit") quit = true;
			turn = oppoColor(turn);
		}
		wasCapture = false; //подготовка к следующему ходу
	}
	if(gameOver() && !quit)
	{
		handleLoss();
		if (playAgain()) checkersGame();
	}
}

void handleLoss() {
	if(loser == Red) redLoses();
	if(loser == Black) blackLoses();
	if(loser == Both) tieGame();
}

void redLoses() {
	//сообщает что черные победили
	winMsg.setString(L"Чёрные победили!");
	gameBoard.getWindow()->draw(winMsg);
	displayBoard(squares,2);
	std::cout << "Game over! Red loses. Black wins.\n";
}

void blackLoses() {
	//сообщает что белые победили
	winMsg.setString(L"Белые победили!");
	gameBoard.getWindow()->draw(winMsg);
	displayBoard(squares,2);
	std::cout << "Game over! Black loses. Red wins.\n";
}

void tieGame() {
	//сообщает о ничьей
	winMsg.setString(L"Ничья!");
	gameBoard.getWindow()->draw(winMsg);
	displayBoard(squares,2);
	std::cout << "Game over! The game is a draw.\n";
	if(turn == Red) std::cout << "Red cannot make a move.\n";
	if(turn == Black) std::cout << "Black cannot make a move.\n";
}

bool playAgain() {
	//пользователь хочет еще одну игру?
	std::cout << "\nWould you like to play another game?\n";
	egMsg.setString(L"Нажмите 'N' для новой игры.\nНажмите любую из кнопок\nв окне помощи для выхода.");
	gameBoard.getWindow()->draw(egMsg);
	gameBoard.getWindow()->display();
	selection = get_GUI_Input();
	std::cout << selection << '\n';
	/*while(selection != "yes" && selection != "y" && selection != "no" && selection != "n") 
		{ std::cout << "Type 'y' or 'n':\n"; std::cin >> selection; }*/
	if(selection == "yes" || selection == "n") return true;
	return false;
}

void exit() {
	//выход
	std::cout << "Enter a character to exit:\n";
	char c;
	std::cin >> c;
}