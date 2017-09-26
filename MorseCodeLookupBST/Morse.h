#pragma once

#include <iostream>
#include <fstream>
#include <string>

using std::cin;
using std::cout;
using std::string;
using std::ostream;
using std::fstream;
using std::endl;

#define MAX_MORSE_LEN 15

// this will be the data item that is passed into my template
class Morse
{
public:
	// Constructor
	Morse(char newChar = '\0', string newString = "");

	// Copy Constructor
	Morse(Morse &copy);

	// Getters
	char getChar() const;
	string getStr() const;

	// Setters
	void setC(const char &c);
	void setMorseStr(const string &str);

	// Destructor
	~Morse();

	// Overloaded Assignment
	Morse & operator= (Morse &rhs);

private:
	char mC;
	string mMorseString;
};

// Description: this is the overloading of the stream insertion operator when the right hand
//				side is of type "Data." It will be used to print to the screen when 'cout'
//				is called.
ostream & operator<< (ostream &lhs, const Morse &rhs);

// Desription: this is the overloaded 'greater than' operator. It will compare two 
//			   Morse objects based on the CHARACTER.
bool operator> (Morse &lhs, Morse &rhs);

// Desription: this is the overloaded 'less than' operator. It will compare two 
//			   Morse objects based on the CHARACTER.
bool operator< (Morse &lhs, Morse &rhs);

// Description: this is the overloaded 'stream extaction' operator for the Morse class;
//				it reads in from an input file stream type (ifstream) and stores into
//				an object of class Morse
fstream & operator >> (fstream &lhs, Morse &rhs);

// Description: this function overloads the '==' operator such that IF the 'mC' values of
//				the Morse objects are equal, then 'true' is returned. I am doing this so 
//				that my templated BST search function works properly.
bool operator== (Morse &lhs, Morse &rhs);

// Description: this function overloads the '!=' operator such that IF the 'mC' values of
//				the Morse objects are not equal, then 'true' is returned. I am doing this so 
//				that my templated BST search function works properly.
bool operator!= (Morse &lhs, Morse &rhs);