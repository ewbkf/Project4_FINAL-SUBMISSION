#pragma once
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <vector>
#include <ctime>
#include "Media.h"
#include "Book.h"
#include "Movie.h"
#include "Music.h"
using namespace std;

//Vector sort function ===================================================================================================================
void vectorSortOMatic(vector<Media*>& media) {
	int minVal;
	vector<Media*> tempVec;
	for (int i = 0; i < media.size(); i++) {
		minVal = i;
		for (int j = 0; j < media.size(); j++) {
			if (media.at(j)->getRating() < media.at(minVal)->getRating())
				minVal = j;

			tempVec.push_back(media.at(minVal));
			media.at(minVal) = media.at(i);
			media.at(i) = tempVec.at(0);
			tempVec.pop_back();
		}
	}
}
//========================================================================================================================================





// Search for stars functions =============================================================================================================
void listMovieStars(vector<Media*>& media) {
	//	Movie movie = getMovie(movieName); 

	string movieName;
	cout << "ENTER A MOVIE NAME: ";
	cin >> movieName;
	//cout << endl; 

	for (int i = 0; i < media.size(); i++) cout << "+"; // formatting 
	if ((media.at(i)->getType() == 'M') && (movieName == media.at(i).getName) {

		cout << endl;
			cout << "THE STARS OF THE MOVIE " << media.getTitle() << " ARE:\n"; // gets the movie title
			for (int i = 0; i < media.size(); i++) cout << "=";
			cout << endl; // formatting 

			for (string star : media.getStars()) cout << star << endl; // gets the stars of the movie and prints it 
	}
}

void findStar(vector<Media*>& media) {
	for (int i = 0; i < 40; i++) {
		cout << "+";
	}
	cout << endl; // formatting

	string starName;

	cout << "ENTER A STAR NAME: ";
	cin >> starName;

	for (int i = 0; i < (media.size() - 1); i++) { // Loops through the media library (all)

		if (media.at(i)->getType() == 'M') (starName == media.at(i).getName()){ // Only looks at the books

			cout << starName << " appears in the following movie(s):\n"; // title 


			cout << media.at(i)->getTitle() << endl;

		}
	}
}








//All the print functions. ===============================================================================================================
void printMenu() {										//Prints the menu. 
	cout << "|**********************************|" << endl;
	cout << "|     M A I N  M E N U             |" << endl;
	cout << "|**********************************|" << endl;
	cout << "| M - Print Movie List             |" << endl;
	cout << "| B - Print Book  List             |" << endl;
	cout << "| S - Print Song  List             |" << endl;
	cout << "| A - Print All Media              |" << endl;
	cout << "| F - Find Movie Star is in        |" << endl;
	cout << "| G - Print Stars from Given Movie |" << endl;
	cout << "| T - Print Media Count            |" << endl;
	cout << "| 1 - Shuffle Songs                |" << endl;
	cout << "| 2 - Random Movie                 |" << endl; 
	cout << "| 3 - Random Book                  |" << endl;
	cout << "| 4 - List All Media by Rating     |" << endl;
	cout << "| Q - Quit                         |" << endl;
	cout << "|__________________________________|" << endl;
}

void PrintBookList(vector<Media*>& media) {
	cout << right << setw(30) << " ----------------------- " << endl;
	cout << right << setw(30) << "|   B O O K   L I S T   |" << endl; // Prints out the title
	cout << right << setw(30) << " ----------------------- " << endl;
	cout << left << setw(5) << "No." << left << setw(45) << "Title" << left << setw(35) << "Author" << left << setw(5) << "Year" << right << setw(5) << "Rating" << endl; // Prints out the headers 
	cout << "-----------------------------------------------------------------------------------------------" << endl;
	for (int i = 0; i < (media.size() - 1); i++) { // Loops through the media library (all)
		if (media.at(i)->getType() == 'B') { // Only looks at the books
			cout << left << setw(5) << i + 1; // Prints out the position 
			cout << left << setw(45) << static_cast <Book*>(media.at(i))->getTitle(); // Gets the book title and prints it 
			cout << left << setw(35) << static_cast <Book*>(media.at(i))->getAuthor(); // Gets the book author and prints it 
			cout << left << setw(5) << static_cast <Book*>(media.at(i))->getYearReleased(); // Gets the book year and prints it 
			cout << right << setw(5) << static_cast <Book*>(media.at(i))->getRating(); // Gets the book rating and prints it 
			cout << endl;
		}
	}
	cout << "-----------------------------------------------------------------------------------------------" << endl;
}

void PrintMovieList(vector<Media*>& media) {
	cout << right << setw(30) << " ----------------------- " << endl;
	cout << right << setw(30) << "|  M O V I E   L I S T  |" << endl; // Prints out the title 
	cout << right << setw(30) << " ----------------------- " << endl;
	cout << left << setw(5) << "No." << left << setw(45) << "Title" << left << setw(35) << "Director" << left << setw(6) << "Year" << right << setw(5) << "Rating " << endl; // Prints out the headers 
	cout << "-----------------------------------------------------------------------------------------------" << endl;
	for (int i = 0; i < (media.size() - 1); i++) { // Loops through the media library (all)
		if (media.at(i)->getType() == 'M') {
			cout << left  << setw(5)  << i + 1; // Prints out the position 
			cout << left  << setw(45) << static_cast <Movie*>(media.at(i))->getTitle(); // Gets the movie title and prints it 
			cout << left  << setw(35) << static_cast <Movie*>(media.at(i))->getDirector(); // Gets the movie director and prints it 
			cout << left  << setw(5)  << static_cast <Movie*>(media.at(i))->getYearReleased(); // Gets the movie year and prints it 
			cout << right << setw(5)  << static_cast <Movie*>(media.at(i))->getRating(); // Gets the movie rating and prints it 
			cout << endl;
		}
	}
	cout << "-----------------------------------------------------------------------------------------------" << endl;
}

void PrintSongList(vector<Media*>& media) {
	cout << right << setw(30) << " --------------------- " << endl;
	cout << right << setw(30) << "|  S O N G   L I S T  |" << endl; // Prints out the title 
	cout << right << setw(30) << " --------------------- " << endl;
	cout << left << setw(5) << "No." << left << setw(45) << "Title" << left << setw(35) << "Artist" << left << setw(5) << "Year" << right << setw(5) << "Rating" << endl; // Prints out the headers 
	cout << "-----------------------------------------------------------------------------------------------" << endl;
	for (int i = 0; i < (media.size() - 1); i++) { // Loops through the media library (all)
		if (media.at(i)->getType() == 'S') {
			cout << left << setw(5) << i + 1;// Prints out the position 
			cout << left << setw(45) << static_cast <Music*>(media.at(i))->getTitle(); // Gets the song title and prints it 
			cout << left << setw(35) << static_cast <Music*>(media.at(i))->getArtist(); // Gets the song artist and prints it 
			cout << left << setw(5) << static_cast <Music*>(media.at(i))->getYearReleased(); // Gets the song year and prints it 
			cout << right << setw(5) << static_cast <Music*>(media.at(i))->getRating(); // Gets the song rating and prints it 
			cout << endl;
		}
	}
	cout << "-----------------------------------------------------------------------------------------------" << endl;
}

void PrintMedia(vector<Media*>& media) {
	cout << "---------------------------------" << endl;
	cout << "P R I N T I N G  A L L  M E D I A" << endl;
	cout << "---------------------------------" << endl << endl;
	cout << right << setw(30) << "B O O K   L I S T:" << endl; // Prints out the title 
	cout << left << setw(5) << "No." << left << setw(45) << "Title" << left << setw(35) << "Author" << left << setw(5) << "Year" << right << setw(5) << "Rating " << endl; // Prints out the headers 
	cout << "-----------------------------------------------------------------------------------------------" << endl;

	for (int i = 0; i < (media.size() - 1); i++) {
		//for loop that iterates through media library 

		if (media.at(i)->getType() == 'B') {
			//if the type is B(Book type) then output the Location in list, Title, Author, year Released and Rating
			cout << left << setw(5) << i + 1;
			cout << left << setw(45) << static_cast <Book*>(media.at(i))->getTitle() << left << setw(35) << static_cast <Book*>(media.at(i))->getAuthor() << left << setw(5) << static_cast <Book*>(media.at(i))->getYearReleased() << right << setw(5) << static_cast <Book*>(media.at(i))->getRating() << endl;
		}
	}
	cout << "-----------------------------------------------------------------------------------------------" << endl;
	cout << right << setw(30) << "M O V I E   L I S T:" << endl; // Prints out the title 
	cout << left << setw(5) << "No." << left << setw(45) << "Title" << left << setw(35) << "Director" << left << setw(5) << "Year" << right << setw(5) << "Rating " << endl; // Prints out the headers 
	cout << "-----------------------------------------------------------------------------------------------" << endl;
	for (int i = 0; i < (media.size() - 1); i++) {
		//for loop that iterates through media library 

		if (media.at(i)->getType() == 'M') {
			//if the type is M(Movie type) then output the Location in List, Title, Director, Year Released and Rating

			cout << left << setw(5) << i + 1;
			cout << left << setw(45) << static_cast <Movie*>(media.at(i))->getTitle() << left << setw(35) << static_cast <Movie*>(media.at(i))->getDirector() << left << setw(5) << static_cast <Movie*>(media.at(i))->getYearReleased() << right << setw(5) << static_cast <Movie*>(media.at(i))->getRating() << endl;

		}
	}
	cout << "-----------------------------------------------------------------------------------------------" << endl;
	cout << right << setw(30) << "S O N G   L I S T:" << endl; // Prints out the title 
	cout << left << setw(5) << "No." << left << setw(45) << "Title" << left << setw(35) << "Author" << left << setw(5) << "Year" << left << setw(5) << "Rating " << endl; // Prints out the headers 
	cout << "-----------------------------------------------------------------------------------------------" << endl;
	for (int i = 0; i < (media.size() - 1); i++) {
		//for loop that iterates through media library 

		if (media.at(i)->getType() == 'S') {
			//if the type is S(Song type) then output the Location in List, Title, Artist, Year Released and Rating
			cout << left << setw(5) << i + 1;
			cout << left << setw(45) << static_cast <Music*>(media.at(i))->getTitle() << left << setw(35) << static_cast <Music*>(media.at(i))->getArtist() << left << setw(5) << static_cast <Music*>(media.at(i))->getYearReleased() << right << setw(5) << static_cast <Music*>(media.at(i))->getRating() << endl;
		}
	}
	cout << "-----------------------------------------------------------------------------------------------" << endl;
}

void PrintSortedMedia(vector<Media*>& media) {
	vector<Media*> newVec; //we have to declare a new vector to sort, otherwise, we will perminantly alter the origional vector. 
	newVec = media;

	vectorSortOMatic(newVec);

	cout << "---------------------------------" << endl;
	cout << "P R I N T I N G  A L L  M E D I A" << endl;
	cout << "  S O R T E D  B Y  R A T I N G  " << endl; 
	cout << "---------------------------------" << endl << endl;
	cout << "           B O O K   L I S T:" << endl; // Prints out the title 
	cout << left << setw(5) << "No." << left << setw(45) << "Title" << left << setw(35) << "Author" << left << setw(5) << "Year" << right << setw(5) << "Rating " << endl; // Prints out the headers 
	cout << "-----------------------------------------------------------------------------------------------" << endl;

	for (int i = 0; i < (newVec.size() - 1); i++) {
		//for loop that iterates through media library 

		if (newVec.at(i)->getType() == 'B') {
			//if the type is B(Book type) then output the Location in list, Title, Author, year Released and Rating
			cout << left << setw(5) << i + 1;
			cout << left << setw(45) << static_cast <Book*>(newVec.at(i))->getTitle() << left << setw(35) << static_cast <Book*>(newVec.at(i))->getAuthor() << left << setw(5) << static_cast <Book*>(newVec.at(i))->getYearReleased() << right << setw(5) << static_cast <Book*>(newVec.at(i))->getRating() << endl;
		}
	}
	cout << "-----------------------------------------------------------------------------------------------" << endl;
	cout << "           M O V I E   L I S T:" << endl; // Prints out the title 
	cout << left << setw(5) << "No." << left << setw(45) << "Title" << left << setw(35) << "Director" << left << setw(5) << "Year" << right << setw(5) << "Rating " << endl; // Prints out the headers 
	cout << "-----------------------------------------------------------------------------------------------" << endl;
	for (int i = 0; i < (newVec.size() - 1); i++) {
		//for loop that iterates through media library 

		if (newVec.at(i)->getType() == 'M') {
			//if the type is M(Movie type) then output the Location in List, Title, Director, Year Released and Rating

			cout << left << setw(5) << i + 1;
			cout << left << setw(45) << static_cast <Movie*>(newVec.at(i))->getTitle() << left << setw(35) << static_cast <Movie*>(newVec.at(i))->getDirector() << left << setw(5) << static_cast <Movie*>(newVec.at(i))->getYearReleased() << right << setw(5) << static_cast <Movie*>(newVec.at(i))->getRating() << endl;

		}
	}
	cout << "-----------------------------------------------------------------------------------------------" << endl;
	cout << "           S O N G   L I S T:" << endl; // Prints out the title 
	cout << left << setw(5) << "No." << left << setw(45) << "Title" << left << setw(35) << "Author" << left << setw(5) << "Year" << left << setw(5) << "Rating " << endl; // Prints out the headers 
	cout << "-----------------------------------------------------------------------------------------------" << endl;
	for (int i = 0; i < (newVec.size() - 1); i++) {
		//for loop that iterates through media library 

		if (newVec.at(i)->getType() == 'S') {
			//if the type is S(Song type) then output the Location in List, Title, Artist, Year Released and Rating
			cout << left << setw(5) << i + 1;
			cout << left << setw(45) << static_cast <Music*>(newVec.at(i))->getTitle() << left << setw(35) << static_cast <Music*>(newVec.at(i))->getArtist() << left << setw(5) << static_cast <Music*>(newVec.at(i))->getYearReleased() << right << setw(5) << static_cast <Music*>(newVec.at(i))->getRating() << endl;
		}
	}
	cout << "-----------------------------------------------------------------------------------------------" << endl;
}

void PrintMediaCount(vector<Media*> v) {
	int m = 0;
	int b = 0;
	int s = 0;

	for (int i = 0; i < v.size(); i++) {
		if (v.at(i)->getType() == 'B') {
			b++;
		}
		if (v.at(i)->getType() == 'M') {
			m++;
		}
		if (v.at(i)->getType() == 'S') {
			s++;
		}
	}
	cout << "-----------------------------" << endl;
	cout << " T O T A L  M E D I A   : " << v.size() <<  endl;
	cout << "-----------------------------" << endl;
	cout << " T O T A L  M O V I E S : " << m << endl; 
	cout << "-----------------------------" << endl;
	cout << " T O T A L  B O O K S   : " << b << endl;
	cout << "-----------------------------" << endl;
	cout << " T O T A L  S O N G S   : " << s << endl;
	cout << "-----------------------------" << endl;
}
//=========================================================================================================================================



//This is all for processing new entries ==================================================================================================
char getFirst(string s) {
	char resultingChar;
	resultingChar = s[0];
	return resultingChar;
}

void newM(vector<Media*> &vP, vector<vector<string>> vS, int i1, ofstream& eL) {
	Movie *newMedia;
	vector<string> stars;

	try {
		//builds the vector of stars to be used in the constructor.
		for (int i = 7; i < vS.at(i1).size(); i++) {
			stars.push_back(vS.at(i1).at(i));
		}
		
		//The below line of code that seems unnecessarily long uses the Movie object constructor to build a new object at the location newMedia is pointing to.
			
		 				    //type						//title			 //director		   //rating			    //genre		      //runtime			     //year released        //Vector of stars (from that line earlier in the funtion. Its like 5 lines above this trust me.)
		newMedia = new Movie(getFirst(vS.at(i1).at(0)), vS.at(i1).at(1), vS.at(i1).at(2), stoi(vS.at(i1).at(3)), vS.at(i1).at(4), stoi(vS.at(i1).at(5)), stoi(vS.at(i1).at(6)), stars);

		//adds the newly created pointer to our list of media. 
		vP.push_back(newMedia);
	}
	catch (out_of_range) {
		cout << "You goofed up your iterator. Nice going.";
		abort();
	}
	catch (invalid_argument) {
		eL << "Invalid Argument in the following entry: " << vS.at(i1).at(1) << endl; 
	}

}

void newS(vector<Media*> &vP, vector<vector<string>> vS, int i1, ofstream& eL) {
	Music* newMedia;

	try {
		newMedia = new Music(getFirst(vS.at(i1).at(0)), vS.at(i1).at(1), vS.at(i1).at(2), stoi(vS.at(i1).at(3)), vS.at(i1).at(4), stoi(vS.at(i1).at(5)), stoi(vS.at(i1).at(6)));
		vP.push_back(newMedia);
	}
	catch (out_of_range) {
		eL << "OOR Error at " << i1 << endl;
	}
	catch (invalid_argument) {
		eL << "Invalid Argument in the following entry: " << vS.at(i1).at(1) << endl;
	}
}

void newB(vector<Media*> &vP, vector<vector<string>> vS, int i1, ofstream& eL) {
	Book* newMedia;
	//Book newBook;
	try {
		newMedia = new Book(getFirst(vS.at(i1).at(0)), vS.at(i1).at(1), vS.at(i1).at(2), stoi(vS.at(i1).at(3)), vS.at(i1).at(4), stoi(vS.at(i1).at(5)), stoi(vS.at(i1).at(6)));
		//newMedia = &newBook;
		vP.push_back(newMedia);
	}
	catch(out_of_range){
		eL << "Item missing at " << i1 << endl;
	}
	catch (invalid_argument) {
		eL << "Invalid Argument in the following entry: " << vS.at(i1).at(1) << endl;
	}
}

void newEntry(vector<Media*> &vP, vector<vector<string>> vS, ofstream& eL) {
	char type;

	for(int i = 0; i < vS.size(); i++) {
		try {
			type = 'E';
			type = getFirst(vS.at(i).at(0));
			type = toupper(type);

			switch (type) {
			case 'M':
				newM(vP, vS, i, eL);
				break;
			case 'S':
				newS(vP, vS, i, eL);
				break;
			case 'B':
				newB(vP, vS, i, eL);
				break;
			case 'Q':
				break;
			default:
				throw runtime_error("Error creating Media object, please check input file.");
			}
		}
		catch (runtime_error& error) {
			eL << error.what() << endl;
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
//=========================================================================================================================================



//These are extra features! SHUFFLE =======================================================================================================
void RandomBook(vector<Media*>& media) {
	vector<string> randomBookV;
	for (int i = 0; i < (media.size() - 1); i++) { // Loops through the media library (all)
		if (media.at(i)->getType() == 'B') { // Only looks at the books
			randomBookV.push_back(static_cast <Book*>(media.at(i))->getTitle());
		}
	}
	cout << endl;
	cout << "Your Random Book: " << endl;
	cout << "--- " << randomBookV.at(rand() % randomBookV.size()) << " ---" << endl;
	cout << "Enjoy!" << endl;
}

void RandomMovie(vector<Media*>& media) {
	vector<string> randomMovieV;
	for (int i = 0; i < (media.size() - 1); i++) { // Loops through the media library (all)
		if (media.at(i)->getType() == 'M') { // Only looks at the books
			randomMovieV.push_back(static_cast <Movie*>(media.at(i))->getTitle());
		}
	}
	cout << endl;
	cout << "Your Random Movie: " << endl;
	cout << "--- " << randomMovieV.at(rand() % randomMovieV.size()) << " ---" << endl;
	cout << "Enjoy!" << endl;
}

void RandomSong(vector<Media*>& media) {
	vector<string> randomSongV;
	for (int i = 0; i < (media.size() - 1); i++) { // Loops through the media library (all)
		if (media.at(i)->getType() == 'S') { // Only looks at the books
			randomSongV.push_back(static_cast <Music*>(media.at(i))->getTitle());
		}
	}
	cout << endl;
	cout << "Your Random Song: " << endl;
	cout << "--- " << randomSongV.at(rand() % randomSongV.size()) << " ---" << endl;
	cout << "Enjoy!" << endl;
}
//=========================================================================================================================================



//This is the brain of the main menu. We tried to keep this as simple as possible with all the work being done in functions. ==============
void menuSwitch(vector<Media *> v, ofstream& eL) {
	cout << "Welcome to your Media Manager! Please select one of the following options." << endl;
	char actionChar = ' ';

	while (actionChar != 'Q') {
		try {
			actionChar = 'x';
			printMenu();
			cin >> actionChar;
			actionChar = toupper(actionChar);
			switch (actionChar) {
			case 'M':
				PrintMovieList(v);
				break;
			case 'B':
				PrintBookList(v);
				break;
			case 'S':
				PrintSongList(v);
				break;
			case 'A':
				PrintMedia(v);
				break;
			case 'F':

				break;
			case 'G':

				break;
			case 'T':
				PrintMediaCount(v);
				break;
			case '1':
				RandomSong(v);
				break;
			case '2':
				RandomMovie(v);
				break;
			case '3':
				RandomBook(v);
				break;
			case '4':
				PrintSortedMedia(v);
				break;
			case 'Q':
				cout << "------------------------------------" << endl;
				cout << "   E X I T I N G  P R O G R A M      " << endl;
				cout << "------------------------------------" << endl;
				cout << endl << "Thank you for using the Media Manager! Have a great day!" << endl << endl;
				break;
			default:
				throw runtime_error("Invalid Entry! Please select from one of the following options.");
			}
		}
		catch (runtime_error& error) {
			cout << error.what() << endl << endl;
			continue;
		}
		catch (invalid_argument) {
			cout << "Invalid Entry! Please select from one of the following options." << endl << endl;
			continue;
		}
		cout << endl << endl;
	}
}
//=========================================================================================================================================