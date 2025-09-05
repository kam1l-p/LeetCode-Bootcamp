/*
  rec01.cpp
  Kamil Paczkowski
  CS 2124 Lab 1
*/

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;


//
// main
//
int main() { // Yes, it has to have an int for the return type
    //
    // Output
    //

    // Task 1. Printing hello ...  No use of "using namespace"

    std::cout << "Hello, World";

    // Task 2  Printing hello ...  Using "using namespace"

    cout << "Hello, World";

    //
    // Types and variables
    //

    // Task 3  Displaying uninitialized variable

    int x;
    cout << x << endl;
    
    // Task 4 Use the sizeof function to see the size in bytes of
    //        different types on your machine.

    int y = 17;
    int z = 2000000017;
    double pie = 3.14159;
    cout << "y size: " << sizeof(y) << endl; 
    cout << "z size: " << sizeof(z) << endl;
    cout << "pie size: " << sizeof(pie) << endl;
    // int have a byte size of 4, double will have a size of 8

    // Task 5  Attempt to assign the wrong type of thing to a variable

    // x = "felix";
    // compilation error, assigning a string to 'int'

    //
    // Conditions
    //

    // Task 6  Testing for a range

    if (y <= 20 && y >= 10) {
      cout << "Y is between 10 and 20" << endl;
    } else {
      cout << "Y is not between 10 and 20" << endl;
    }

    //
    // Loops and files
    //

    // Task 7  Looping, printing values 10 to 20 inclusive

    // First with a for loop

    for (int i = 10; i <= 20; i++) {
      cout << i << " ";
    }
    cout << endl;

    // Then with a while loop

    int i = 10;
    while (i <= 20) {
      cout << i << " ";
      i++;
    }
    cout << endl;

    // Finally with a do-while loop

    i = 10;
    do {
      cout << i << " ";
      i++;
    } while (i <= 20);
    cout << endl;
    
    // Task 8  Looping to successfully open a file, asking user for the name
    
    ifstream ifs;
    do {
      string filename;
      cout << "input filename: ";
      cin >> filename;
      ifs.open(filename);
    } while (!ifs);

    // Task 9  Looping, reading file word by "word".

    string word;
    while (ifs >> word) {
      cout << word << endl;
    }
    ifs.close();

    // Task 10 Open a file of integers, read it in, and display the sum.

    ifstream ints("integers.txt");
    if (!ints) {
      cout << "Couldn't open file." << endl;
    } else {
      int val, sum = 0;
      while (ints >> val) {
        sum += val;
      }
      cout << "Sum: " << sum << endl;
      ints.close();
    }

    // Task 11 Open and read a file of integers and words. Display the sum.

    ifstream mixed("mixed.txt");
    if (!mixed) {
      cout << "Couldn't open file." << endl;
    } else {
      int val, mixsum = 0;
      while (mixed >> val) {
        mixsum += val;
      }
      cout << "Mixed Sum: " << mixsum << endl;
      mixed.close();
    }

    //
    // Vectors
    //

    // Task 12 Filling a vector of ints

    vector<int> ints_even;
    for (int i = 10; i <= 100; i +=2) {
      ints_even.push_back(i);
    }

    // Task 13 Displaying the vector THREE times
    //         a) using the indices,

    cout << "With indices: ";
    for (size_t i = 0; i < ints_even.size(); i++) {
      cout << ints_even[i] << " ";
    }

    //         b) using a "ranged for"

    cout << "With ranged-for: ";
    for (int values : ints_even) {
      cout << values << " "; 
    }

    //         c) using indices again but backwards

    cout << "In reverse with indices: ";
    for (size_t i = 0; i < ints_even.size(); i++) {
      cout << ints_even[ints_even.size() - i - 1] << " ";
    }
    // do it other way on exam

    // Task 14. Initialize a vector with the primes less than 20. 

    vector<int> primes{2, 3, 5, 7, 11, 13, 17, 19};
    for (int value : primes) {
      cout << value << " ";
    }

} // main
