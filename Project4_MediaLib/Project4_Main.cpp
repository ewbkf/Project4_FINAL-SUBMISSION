#include <iomanip>
#include <vector>
#include "P4_Functions.h"
#include <string>
#include <sstream>
#include <fstream>
#include <iostream>
#include <vector>
#include "Media.h"
#include "Book.h"
#include "Music.h"
#include "Movie.h"

using namespace std;

int main() {
    ifstream inFile;
    ofstream outFile;
    vector <Media*> myLib;
    vector <vector <string>> holdingArea; 

    try {
        inFile.exceptions(ifstream::failbit);
        inFile.open("mediaList.txt");
        outFile.exceptions(ifstream::failbit);
        outFile.open("mediaReport.txt");
    }
    catch (ifstream::failure& fail) {
        cout << "Could not open input file" << endl;
        cout << fail.what() << endl;
        cout << fail.code() << endl;
        exit(1);
    }

    csvToVector(holdingArea, inFile);
}