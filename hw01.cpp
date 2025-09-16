/*
  hw01.cpp
  Kamil Paczkowski - 9/15/25
  Decrypts text in a file encrypted with a caesar cypher algorithm.
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

char decryptChar(char ch, int step);
void decryptString(string& line, int step);

int main() {
    ifstream inputFile("encrypted.txt");
    if (!inputFile) {
        cout << "encrypted.txt could not be opened.\n";
        return 0;
    }
    int step = 0;
    inputFile >> step;
    
    // removes line with step integer
    string delLine;
    getline(inputFile, delLine); 

    // reads rest of lines
    vector<string> lines;
    string line;
    while (getline(inputFile, line)) {
        lines.push_back(line);
    }

    // loop through vector in reverse
    for (size_t lineInd = lines.size(); 0 < lineInd; --lineInd) {
        size_t currLine = lineInd - 1;
        decryptString(lines[currLine], step); 
        cout << lines[currLine] << endl;
    }
    return 0;
}

// decrypts only one character, taking note of the step / rotation distance
char decryptChar(char ch, int step) {
    if ('A' <= ch && ch <= 'Z') {
        int encryptIndex = ch - 'A';
        // how many steps/places to move back by
        int newIndex = encryptIndex - step;
        if (newIndex < 0) {
            newIndex += 26;
        } 
        else if (newIndex >= 26) {
            newIndex -= 26;
        }  
        ch = 'A' + newIndex;
    }
    return ch;
}

// decrypts a string that is passed in
void decryptString(string& line, int step) {
    for (size_t charInd = 0; charInd < line.size(); ++charInd) {
        line[charInd] = decryptChar(line[charInd], step);
    }
}
