/*
  rec02.cpp
  Kamil Paczkowski
  9/12/25
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

struct Hydrocarbon {
    vector<string> name;
    int carbon;
    int hydrogen;
};

void openFile(ifstream& file);
void noteFormula(ifstream& file, vector<Hydrocarbon>& vectorChem);
void sortList(vector<Hydrocarbon>& vectorChem);
void display(const vector<Hydrocarbon>& vectorChem);
void printWhole(const Hydrocarbon& h);

int main() {
  ifstream file;
  vector<Hydrocarbon> vectorChem;
  openFile(file);

  noteFormula(file, vectorChem);
  cout << "Unsorted:\n";
  display(vectorChem);

  sortList(vectorChem);
  cout << "\nSorted:\n";
  display(vectorChem);

  return 0;
}

void openFile(ifstream& file) {
  do {
    string filename;
    cout << "File name? ";
    cin >> filename;
    file.clear();
    file.open(filename);
    if (!file) {
      cout << "File couldn't be opened. Enter a new name.\n";
    }
  } while (!file);
}

void noteFormula(ifstream& file, vector<Hydrocarbon>& vectorChem) {
  string name;
  char c;
  int carbon, hydrogen;
  while (file >> name >> c >> carbon >> c >> hydrogen) {
    int search = 0;
    for (int i = 0; i < vectorChem.size(); i++) {
      if (vectorChem[i].carbon == carbon && vectorChem[i].hydrogen == hydrogen) {
        vectorChem[i].name.push_back(name);
        search = 1;
      }
    }
    if (search == 0) {
      Hydrocarbon h;
      h.carbon = carbon;
      h.hydrogen = hydrogen;
      h.name.push_back(name);
      vectorChem.push_back(h);
    }
  }
}

void sortList(vector<Hydrocarbon>& vectorChem) {
  for (int start = 0; start < vectorChem.size(); start++) {
    int minInd = start;
    for (int chInd = start + 1; chInd < vectorChem.size(); chInd++) {
      if (vectorChem[chInd].carbon < vectorChem[minInd].carbon || 
        vectorChem[chInd].carbon == vectorChem[minInd].carbon &&
        vectorChem[chInd].hydrogen < vectorChem[minInd].hydrogen) {
          minInd = chInd;
        }
    }
    if (minInd != start) {
      Hydrocarbon tval = vectorChem[start];
      vectorChem[start] = vectorChem[minInd];
      vectorChem[minInd] = tval;
    }
  }
}

void display(const vector<Hydrocarbon>& vectorChem) {
  for (int i = 0; i < vectorChem.size(); i++) {
    printWhole(vectorChem[i]);
  }
}

void printWhole(const Hydrocarbon& h) {
  cout << "C" << h.carbon << "H" << h.hydrogen;
  for (int i = 0; i < h.name.size(); i++) {
    cout << " " << h.name[i];
  }
  cout << "\n";
}