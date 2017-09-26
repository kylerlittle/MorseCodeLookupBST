#include "BST.h"

int main(void)
{
	fstream table;  // declare fstream type
	table.open("MorseTable.txt");  // open file

	// contruct binary tree
	BST<Morse> morseAlphabet(table);

	table.close();   // close file

	// print tree
	cout << "\tCharacter:\tMorse String:" << endl;
	morseAlphabet.printTree();

	fstream text;  // declare fstream type
	text.open("Convert.txt");    // open file

	// read in each character from file; search tree for the matching character;
	// then print the corresponding Morse String to the screen.
	// NOTE: 1 space should separate each Morse character; each string should have 3 spaces separating
	//		 and each new line character should also be echoed to the screen
	while (!text.eof()) {
		char c = '\0';
		text.get(c);
		if (c == '\n') {  // if there is a new line
			cout << endl;
		}
		else if (c == ' ') {  // if there is a space
			cout << "   ";
		}
		else if (c == '\0') {
			// empty else if (had to include this because my eof() is not working properly
		}
		else {
			Morse searchValue(toupper(c));   // sets default morseString to "" (no problem though; see below)
			// the following statement works because I have overloaded the '==' and '=' operators for the Morse class
			Morse found = morseAlphabet.search(searchValue);
			cout << found.getStr() << " ";
		}
	}
	cout << endl;   // add an extra end line

	text.close();		// close file

	return 0;
}