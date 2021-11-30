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
    newEntry(myLib, holdingArea);

    /*
    for (int i = 0; i < (myLib.size()-1); i++) {
        myLib.at(i)->print(outFile);
    }
    */

    //(*myLib.at(0)).print(outFile);

    for (int i = 0; i < holdingArea.size(); i++) {
        for (int j = 0; j < holdingArea.at(i).size(); j++) {
            cout << holdingArea.at(i).at(j) << " ";
        }
        cout << endl;
    }

    cout << endl << holdingArea.size();
    cout << endl << myLib.size();
}
