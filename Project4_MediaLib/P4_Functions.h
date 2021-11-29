#pragma once
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <vector>
#include "Media.h"
#include "Book.h"
using namespace std;

void printMenu() {										//Prints the menu. 
	cout << "M - Print Movie List" << endl;
	cout << "B - Print Book  List" << endl;
	cout << "S - Print Song  List" << endl;
	cout << "A - Print All Media" << endl;
	cout << "F - Find Movie Star is in" << endl;
	cout << "G - Print Stars from Given Movie" << endl;
	cout << "T - Print Media Count" << endl;
	cout << "Q - Quit" << endl;
}

void csvToVector(vector<vector<string>>& recipientVector, ifstream& donorCSV) {
	vector<string> currentLine;
	string tempString;									//A container for the current row in the CSV
	string word;										//A container to hold the parsed words from each row. 
	istringstream inSS;

	while (word != "Q") {								//Runs until it runs into a line that ends in Q. I would typically use .eof() here, but this was causing errors for some reason. 
		currentLine.clear();							//Emptys the variable. 
		tempString = "";								//Assigns to an empty string. 
		inSS.clear();									//Clears the string stream. 
		getline(donorCSV, tempString);					//Grabs the next row in the CSV.
		istringstream inSS(tempString);


		while (getline(inSS, word, ',')) {				//Loads the strings separated by commas into a vector. 
			currentLine.push_back(word);
		}

		recipientVector.push_back(currentLine);			//Loads the vectors of strings into a vector (2D). This is our CSV file as a vector. 
	}
}

char getFirstCharFromString(string string1) {			//The name says it all.
	char resultingChar;
	resultingChar = string1[0];
	return resultingChar;
}

void newEntry(vector<Media*> vP, vector<vector<string>> vS) {
	char type = ' ';
	type = getFirstCharFromString()

	type = toupper(type);

	while (true) {
		switch (type) {
		case 'M':

		case 'S':

		case 'B':

		default:

		}

	}
}