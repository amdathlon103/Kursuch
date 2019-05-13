#include "square.h"

bool isSquare(std::string square);

namespace sq {

sf::Mutex squaresMutex;

void Square::changeColor(char newColor) {
  squaresMutex.lock();
	if (c != newColor) c = newColor;
  squaresMutex.unlock();
	return;
}

Square::Square() {
	c = ' ';
	s = "a1";
	r = '1';
	frtAdjSqs = setFrtAdjSqs(s);
	bacAdjSqs = setBacAdjSqs(s);
	frtJmpSqs = setFrtJmpSqs(s);
	bacJmpSqs = setBacJmpSqs(s);
	crowned = false;
	captured = false;
	return;
}

Square::Square(char c_, std::string s_, char r_) 
:c(c_), s(s_), r(r_)
{ 
	
	//�������� �� ������ ������������
	if(c_ != Red && c_ != cRed && c_ != Black && c_ != cBlack && c_ != ' ') 
		error("Exception: constructor use without correct color ('r','R','b','B',' ')"); 
	if(!isSquare(s_)) 
		error("Exception: constructor use without correct square");
	switch(r_) {  
		case '1': case '2': case '3': case '4':
		case '5': case '6': case '7': case '8':
			break;
		default:
			error("Exception: constructor use without correct row");
	}

	
	frtAdjSqs = setFrtAdjSqs(s);
	bacAdjSqs = setBacAdjSqs(s);
	frtJmpSqs = setFrtJmpSqs(s);
	bacJmpSqs = setBacJmpSqs(s);
	if(c_ == cRed || c_ == cBlack) 
		crowned = true;
	else 
		crowned = false;
	captured = false;
	return;
}

std::vector<std::string> Square::setFrtAdjSqs(std::string sq) {

	std::vector<std::string> sqs(2," "); //�������� ��������, ����� �������� � frtAdjSqs

	if(sq == "a1") {sqs[0] = "b2"; return sqs;}
	if(sq == "a3") {sqs[0] = "b4"; return sqs;}
	if(sq == "a5") {sqs[0] = "b6"; return sqs;}
	if(sq == "a7") {sqs[0] = "b8"; return sqs;}

	if(sq == "b2") {sqs[0] = "a3"; sqs[1] = "c3"; return sqs;}
	if(sq == "b4") {sqs[0] = "a5"; sqs[1] = "c5"; return sqs;}
	if(sq == "b6") {sqs[0] = "a7"; sqs[1] = "c7"; return sqs;}
	if(sq == "b8") return sqs;	

	if(sq == "c1") {sqs[0] = "b2"; sqs[1] = "d2"; return sqs;}
	if(sq == "c3") {sqs[0] = "b4"; sqs[1] = "d4"; return sqs;}
	if(sq == "c5") {sqs[0] = "b6"; sqs[1] = "d6"; return sqs;}
	if(sq == "c7") {sqs[0] = "b8"; sqs[1] = "d8"; return sqs;}

	if(sq == "d2") {sqs[0] = "c3"; sqs[1] = "e3"; return sqs;}
	if(sq == "d4") {sqs[0] = "c5"; sqs[1] = "e5"; return sqs;}
	if(sq == "d6") {sqs[0] = "c7"; sqs[1] = "e7"; return sqs;}
	if(sq == "d8") return sqs;	

	if(sq == "e1") {sqs[0] = "d2"; sqs[1] = "f2"; return sqs;}
	if(sq == "e3") {sqs[0] = "d4"; sqs[1] = "f4"; return sqs;}
	if(sq == "e5") {sqs[0] = "d6"; sqs[1] = "f6"; return sqs;}
	if(sq == "e7") {sqs[0] = "d8"; sqs[1] = "f8"; return sqs;}

	if(sq == "f2") {sqs[0] = "e3"; sqs[1] = "g3"; return sqs;}
	if(sq == "f4") {sqs[0] = "e5"; sqs[1] = "g5"; return sqs;}
	if(sq == "f6") {sqs[0] = "e7"; sqs[1] = "g7"; return sqs;}
	if(sq == "f8") return sqs;	

	if(sq == "g1") {sqs[0] = "f2"; sqs[1] = "h2"; return sqs;}
	if(sq == "g3") {sqs[0] = "f4"; sqs[1] = "h4"; return sqs;}
	if(sq == "g5") {sqs[0] = "f6"; sqs[1] = "h6"; return sqs;}
	if(sq == "g7") {sqs[0] = "f8"; sqs[1] = "h8"; return sqs;}

	if(sq == "h2") {sqs[0] = "g3"; return sqs;}
	if(sq == "h4") {sqs[0] = "g5"; return sqs;}
	if(sq == "h6") {sqs[0] = "g7"; return sqs;}
	if(sq == "h8") return sqs;	

	error("Exception: constructor use without an accessible square");
}

std::vector<std::string> Square::setBacAdjSqs(std::string sq) {

	std::vector<std::string> sqs(2," "); 

	if(sq == "a1") return sqs;	
	if(sq == "a3") {sqs[0] = "b2"; return sqs;}
	if(sq == "a5") {sqs[0] = "b4"; return sqs;}
	if(sq == "a7") {sqs[0] = "b6"; return sqs;}

	if(sq == "b2") {sqs[0] = "a1"; sqs[1] = "c1"; return sqs;}
	if(sq == "b4") {sqs[0] = "a3"; sqs[1] = "c3"; return sqs;}
	if(sq == "b6") {sqs[0] = "a5"; sqs[1] = "c5"; return sqs;}
	if(sq == "b8") {sqs[0] = "a7"; sqs[1] = "c7"; return sqs;}

	if(sq == "c1") return sqs;	
	if(sq == "c3") {sqs[0] = "b2"; sqs[1] = "d2"; return sqs;}
	if(sq == "c5") {sqs[0] = "b4"; sqs[1] = "d4"; return sqs;}
	if(sq == "c7") {sqs[0] = "b6"; sqs[1] = "d6"; return sqs;}

	if(sq == "d2") {sqs[0] = "c1"; sqs[1] = "e1"; return sqs;}
	if(sq == "d4") {sqs[0] = "c3"; sqs[1] = "e3"; return sqs;}
	if(sq == "d6") {sqs[0] = "c5"; sqs[1] = "e5"; return sqs;}
	if(sq == "d8") {sqs[0] = "c7"; sqs[1] = "e7"; return sqs;}

	if(sq == "e1") return sqs;	
	if(sq == "e3") {sqs[0] = "d2"; sqs[1] = "f2"; return sqs;}
	if(sq == "e5") {sqs[0] = "d4"; sqs[1] = "f4"; return sqs;}
	if(sq == "e7") {sqs[0] = "d6"; sqs[1] = "f6"; return sqs;}

	if(sq == "f2") {sqs[0] = "e1"; sqs[1] = "g1"; return sqs;}
	if(sq == "f4") {sqs[0] = "e3"; sqs[1] = "g3"; return sqs;}
	if(sq == "f6") {sqs[0] = "e5"; sqs[1] = "g5"; return sqs;}
	if(sq == "f8") {sqs[0] = "e7"; sqs[1] = "g7"; return sqs;}

	if(sq == "g1") return sqs;	
	if(sq == "g3") {sqs[0] = "f2"; sqs[1] = "h2"; return sqs;}
	if(sq == "g5") {sqs[0] = "f4"; sqs[1] = "h4"; return sqs;}
	if(sq == "g7") {sqs[0] = "f6"; sqs[1] = "h6"; return sqs;}

	if(sq == "h2") {sqs[0] = "g1"; return sqs;}
	if(sq == "h4") {sqs[0] = "g3"; return sqs;}
	if(sq == "h6") {sqs[0] = "g5"; return sqs;}
	if(sq == "h8") {sqs[0] = "g7"; return sqs;}

	error("Exception: constructor use without an accessible square");
}

std::vector<std::string> Square::setFrtJmpSqs(std::string sq) {

	std::vector<std::string> sqs(2," "); 
	
	if(sq == "a1") {sqs[0] = "c3"; return sqs;}
	if(sq == "a3") {sqs[0] = "c5"; return sqs;}
	if(sq == "a5") {sqs[0] = "c7"; return sqs;}
	if(sq == "a7") return sqs;	

	if(sq == "b2") {sqs[0] = "d4"; return sqs;}
	if(sq == "b4") {sqs[0] = "d6"; return sqs;}
	if(sq == "b6") {sqs[0] = "d8"; return sqs;}
	if(sq == "b8") return sqs;	

	if(sq == "c1") {sqs[0] = "a3"; sqs[1] = "e3"; return sqs;}
	if(sq == "c3") {sqs[0] = "a5"; sqs[1] = "e5"; return sqs;}
	if(sq == "c5") {sqs[0] = "a7"; sqs[1] = "e7"; return sqs;}
	if(sq == "c7") return sqs;	

	if(sq == "d2") {sqs[0] = "b4"; sqs[1] = "f4"; return sqs;}
	if(sq == "d4") {sqs[0] = "b6"; sqs[1] = "f6"; return sqs;}
	if(sq == "d6") {sqs[0] = "b8"; sqs[1] = "f8"; return sqs;}
	if(sq == "d8") return sqs;	

	if(sq == "e1") {sqs[0] = "c3"; sqs[1] = "g3"; return sqs;}
	if(sq == "e3") {sqs[0] = "c5"; sqs[1] = "g5"; return sqs;}
	if(sq == "e5") {sqs[0] = "c7"; sqs[1] = "g7"; return sqs;}
	if(sq == "e7") return sqs;	

	if(sq == "f2") {sqs[0] = "d4"; sqs[1] = "h4"; return sqs;}
	if(sq == "f4") {sqs[0] = "d6"; sqs[1] = "h6"; return sqs;}
	if(sq == "f6") {sqs[0] = "d8"; sqs[1] = "h8"; return sqs;}
	if(sq == "f8") return sqs;	

	if(sq == "g1") {sqs[0] = "e3"; return sqs;}
	if(sq == "g3") {sqs[0] = "e5"; return sqs;}
	if(sq == "g5") {sqs[0] = "e7"; return sqs;}
	if(sq == "g7") return sqs;	

	if(sq == "h2") {sqs[0] = "f4"; return sqs;}
	if(sq == "h4") {sqs[0] = "f6"; return sqs;}
	if(sq == "h6") {sqs[0] = "f8"; return sqs;}
	if(sq == "h8") return sqs;	

	error("Exception: constructor use without an accessible square");
}

std::vector<std::string> Square::setBacJmpSqs(std::string sq) {

	std::vector<std::string> sqs(2," "); 
	
	if(sq == "a1") return sqs;	
	if(sq == "a3") {sqs[0] = "c1"; return sqs;}
	if(sq == "a5") {sqs[0] = "c3"; return sqs;}
	if(sq == "a7") {sqs[0] = "c5"; return sqs;}

	if(sq == "b2") return sqs;	
	if(sq == "b4") {sqs[0] = "d2"; return sqs;}
	if(sq == "b6") {sqs[0] = "d4"; return sqs;}
	if(sq == "b8") {sqs[0] = "d6"; return sqs;}

	if(sq == "c1") return sqs;	
	if(sq == "c3") {sqs[0] = "a1"; sqs[1] = "e1"; return sqs;}
	if(sq == "c5") {sqs[0] = "a3"; sqs[1] = "e3"; return sqs;}
	if(sq == "c7") {sqs[0] = "a5"; sqs[1] = "e5"; return sqs;}

	if(sq == "d2") return sqs;	
	if(sq == "d4") {sqs[0] = "b2"; sqs[1] = "f2"; return sqs;}
	if(sq == "d6") {sqs[0] = "b4"; sqs[1] = "f4"; return sqs;}
	if(sq == "d8") {sqs[0] = "b6"; sqs[1] = "f6"; return sqs;}

	if(sq == "e1") return sqs;	
	if(sq == "e3") {sqs[0] = "c1"; sqs[1] = "g1"; return sqs;}
	if(sq == "e5") {sqs[0] = "c3"; sqs[1] = "g3"; return sqs;}
	if(sq == "e7") {sqs[0] = "c5"; sqs[1] = "g5"; return sqs;}

	if(sq == "f2") return sqs;	
	if(sq == "f4") {sqs[0] = "d2"; sqs[1] = "h2"; return sqs;}
	if(sq == "f6") {sqs[0] = "d4"; sqs[1] = "h4"; return sqs;}
	if(sq == "f8") {sqs[0] = "d6"; sqs[1] = "h6"; return sqs;}

	if(sq == "g1") return sqs;	
	if(sq == "g3") {sqs[0] = "e1"; return sqs;}
	if(sq == "g5") {sqs[0] = "e3"; return sqs;}
	if(sq == "g7") {sqs[0] = "e5"; return sqs;}

	if(sq == "h2") return sqs;	
	if(sq == "h4") {sqs[0] = "f2"; return sqs;}
	if(sq == "h6") {sqs[0] = "f4"; return sqs;}
	if(sq == "h8") {sqs[0] = "f6"; return sqs;}
	
	error("Exception: constructor use without an accessible square");
}

} // namespace sq