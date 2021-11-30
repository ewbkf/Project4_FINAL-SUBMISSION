#pragma once
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <vector>
#include "Media.h"
#include "Book.h"
#include "Movie.h"
#include "Music.h"
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

char getFirst(string string1) {			//The name says it all.
	char resultingChar;
	resultingChar = string1[0];
	return resultingChar;
}

void newM(vector<Media*> &vP, vector<vector<string>> vS, int i1) {
	Media* newMedia;
	vector<string> stars;
	Movie newMovie;

	try {
		//builds the vector of stars to be used in the constructor.
		for (int i = 7; i < vS.at(i1).size(); i++) {
			stars.push_back(vS.at(i1).at(i));
		}
		
		//The below line of code that seems unnecessarily long uses the Movie object constructor to build a new object at the location newMedia is pointing to.
						//type						 //title		  //director	   //rating				  //genre		   //runtime			  //year released        //Vector of stars (from that line earlier in the funtion. Its like 5 lines above this trust me.)
		newMovie = Movie(getFirst(vS.at(i1).at(0)), vS.at(i1).at(1), vS.at(i1).at(2), stoi(vS.at(i1).at(3)), vS.at(i1).at(4), stoi(vS.at(i1).at(5)), stoi(vS.at(i1).at(6)), stars);
		newMedia = &newMovie;
	}
	catch (out_of_range) {
		//FIXME: Dont let this make it to submission pls. 
		cout << "You fucked up your iterator. Nice going.";
		abort();
	}
	catch (invalid_argument) {
		cout << "Invalid Argument at " << i1 << endl;
	}

	//adds the newly created pointer to our list of media. 
	vP.push_back(newMedia);
}

void newS(vector<Media*> &vP, vector<vector<string>> vS, int i1) {
	Media* newMedia;
	Music newMusic;
	try {
		newMusic = Music(getFirst(vS.at(i1).at(0)), vS.at(i1).at(1), vS.at(i1).at(2), stoi(vS.at(i1).at(3)), vS.at(i1).at(4), stoi(vS.at(i1).at(5)), stoi(vS.at(i1).at(6)));
		newMedia = &newMusic;
		vP.push_back(newMedia);
	}
	catch (out_of_range) {
		cout << "OOR Error at " << i1 << endl;
	}
	catch (invalid_argument) {
		cout << "IVA Error at " << i1 << endl;
	}
}

void newB(vector<Media*> &vP, vector<vector<string>> vS, int i1) {
	Media* newMedia;
	Book newBook;
	try {
		newBook = Book(getFirst(vS.at(i1).at(0)), vS.at(i1).at(1), vS.at(i1).at(2), stoi(vS.at(i1).at(3)), vS.at(i1).at(4), stoi(vS.at(i1).at(5)), stoi(vS.at(i1).at(6)));
		newMedia = &newBook;
		vP.push_back(newMedia);
	}
	catch(out_of_range){
		cout << "Item missing at " << i1 << endl;
	}
}

void newEntry(vector<Media*> &vP, vector<vector<string>> vS) {
	char type;

	for(int i = 0; i < vS.size(); i++) {
		type = 'E';
		type = getFirst(vS.at(i).at(0));
		type = toupper(type);
		
		switch (type) {
		case 'M':
			newM(vP, vS, i);
			break;
		case 'S':
			newS(vP, vS, i);
			break;
		case 'B':
			newB(vP, vS, i);
			break;
		case 'Q':
			break;
		default:
			throw runtime_error("Error creating Media object, please check input file.");
		}

	}
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