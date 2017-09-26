#include "Morse.h"

Morse::Morse(char newChar, string newString)
{
	this->mC = newChar;
	this->mMorseString = newString;
}

Morse::Morse(Morse &copy)
{
	this->setC(copy.getChar());
	this->setMorseStr(copy.getStr());
}

char Morse::getChar() const
{
	return this->mC;
}

string Morse::getStr() const
{
	return this->mMorseString;
}

void Morse::setC(const char &c)
{
	this->mC = c;
}

void Morse::setMorseStr(const string &str)
{
	this->mMorseString = str;
}

Morse::~Morse() {
	// empty destructor
}

Morse & Morse::operator= (Morse &rhs)
{
	this->setC(rhs.getChar());
	this->setMorseStr(rhs.getStr());

	return (*this);
}

ostream & operator<< (ostream &lhs, const Morse &rhs)
{
	lhs << "\t" << rhs.getChar() << "\t" << rhs.getStr() << endl;
	// print horizontal tab, character, horizontal tab, morse string, then an endline
	return lhs;
}

bool operator> (Morse &lhs, Morse &rhs)
{
	bool success = false;

	if (lhs.getChar() > rhs.getChar()) {   // compare based on characters only
		success = true;
	}

	return success;
}

bool operator< (Morse &lhs, Morse &rhs)
{
	bool success = false;

	if (lhs.getChar() < rhs.getChar()) {  // compare based on characters only
		success = true;
	}

	return success;
}

fstream & operator >> (fstream &lhs, Morse &rhs)
{
	char c = '\0', space = '\0', morse[MAX_MORSE_LEN] = "";
	
	lhs.get(c);    // read in alpha, numerical, or other character
	lhs.get(space);		// read in space, which separates the char from the string in my file
	lhs.getline(morse, MAX_MORSE_LEN);  // read in Morse string
	string morse_str = morse;  // have to read into a string this way (because I'm on a virtual machine, so it's weird)

	// store items into Morse object
	rhs.setC(c);
	rhs.setMorseStr(morse_str);
	
	return lhs;
}

bool operator== (Morse &lhs, Morse &rhs)
{
	bool result = false;
	if (lhs.getChar() == rhs.getChar()) {   // compare the characters
		result = true;
	}
	return result;
}

bool operator!= (Morse &lhs, Morse &rhs)
{
	bool result = false;
	if (lhs.getChar() != rhs.getChar()) {	// compare the characters
		result = true;
	}
	return result;
}