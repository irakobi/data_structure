/*       Internal documentation
       --------------------------
Author name: Obed Irakoze
Author andrewId: oirakoze
Author class: MS-ECE class of 2025

Code testing Summary
--------------------
The code was tested using the 4 test cases or scanpath in the input.txt file. How to run it is firstly by creating the required build folder,
--> into build: cmake ..
--> into build: cmake --build .
--> navigate into the bin folder created there is a file named: ASSIGNMENT1.exe and run it like: ./ASSIGNMENT1
then the output will be written into thhe output file found into the data folder. and see the message in terminal saying that "Data written to output.txt"

Functionality of the program
----------------------------
This program perform eye eye tracking system implemented in C++ by accepting the fixation points in different test cases as input and modify them by removing the duplicate
in each instances, each instances is terminated by the row of -1,-1. so that row is removed and separate the testcase with the star line. and those selected fixation
are reordered ascending on the first column of identification number. this program contains three files, 1. assignment1.cpp which contain the implementation 
of the program using function called""eyeTracker()" 2. main.cpp which run this implementation file through calling it. and lastly header.h which is telling us and compiler
the function to compile, input expected and the intended return.

Format of input and output
--------------------------
This program is reading the (.txt) file as input using fstream library and the output is the file(.txt) which is being written and both saved into data folder.

Algorithm and strategy for implementing the solution
----------------------------------------------------
This program was performed using the Hash table algorithm and struct array. efficiently is processes input data, detects and removes duplicates using a hash table with chaining,
and writes the unique data points to the output file for each test case. the following is the pseudo-code to explain the process:

Function eyeTracker():
    Open input.txt file for reading
    If unable to open input file, print error message and return 1

    Read the first line from input file and store it as test_case
    If test_case is less than 1 or greater than 10, print error message and return 1

    Open output.txt file for writing
    If unable to open output file, print error message and return 1

    Write "oirakoze" to the output file

    For each test case from 1 to test_case:
        Initialize a hash table of size HASH_TABLE_SIZE, with each entry pointing to null
        Initialize newId to 1

        While there are lines remaining in the input file:
            Read identifier, x_coordinate, and y_coordinate from the input file
            If x_coordinate and y_coordinate are both negative, break out of the loop

            Compute hashValue using the hashFunction based on x_coordinate and y_coordinate

            Check for duplicate entries in the hash table:
                Traverse the linked list at hashTable[hashValue]
                If an entry with the same x_coordinate and y_coordinate exists, set isUnique to false and break

            If the entry is unique:
                Write newId, x_coordinate, and y_coordinate to the output file
                Create a new Data node with identifier, x_coordinate, and y_coordinate
                Point its next pointer to the current head of the linked list at hashTable[hashValue]
                Update hashTable[hashValue] to point to the new Data node
                Increment newId

        Write a separator line "*************" to the output file

    Close the input and output files
    Print a success message

Description of the test cases used
-----------------------------------
In my input.txt file I have 4 testcases, the first contains 20 fixation points, the row with zeros and it test the duplications
The second has the high values of x and y coordinate and also it test the duplications, the third test case has the similar x and y coordinate,
for teting our program and the last test the program with many fixation points arround 999 including the several duplicates.

Complexity analysis
-------------------
- Outer loop complexity: O(test_case)
- Inner loop complexity:
    Let n be the total number of fixation points across all test cases.
    A ssuming each test case has m fixation points on average.
    Overall, the complexity of the inner loop is O(n).
- Hash table insertion and duplicate checking:
    For each fixation point, the time complexity for inserting into the hash table and checking for duplicates is O(1) on average due to the use of hash tables.
    Therefore, the overall complexity of this part is O(n) where n is the total number of fixation points across all test cases.

Overall Complexity: Considering the outer loop and all the inner operations, the overall time complexity of the program is O(test_case * n).

*/

#include <iostream>
#include <fstream>

using namespace std;

// Define a structure to hold the data for each input line and the pointer to handle collisions as duplicates
struct Data {
    int identifier;
    int x_coordinate;
    int y_coordinate;
    Data* next; 
};

// Define the size of the hash table assuming to be 1000
const int HASH_TABLE_SIZE = 1000;

// Define a hash function to compute the hash value
int hashFunction(int x, int y) {
    return (x * HASH_TABLE_SIZE + y) % HASH_TABLE_SIZE;
}

int eyeTracker() {
    /*
    The function to process the input file and handle the duplicates and arrange new fixation points
    separated into different test cases wit the star line.

    input: .txt file
    output: .txt file

    parameter: struct data(linked array to store coordinates)

    function calling: hashFunction()
    */

    ifstream inputFile("../data/input.txt"); // Open input.txt file
    if (!inputFile) {
        cout << "Error opening input file!" << endl;
        return 1;
    }
    // Read the first line (test_case)
    int test_case;
    inputFile >> test_case;

    // Validate test_case
    if (test_case < 1 || test_case > 10) {
        cout << "Invalid test_case value. It should be between 1 and 10." << endl;
        return 1;
    }

    // Open the output file
    ofstream outputFile("../data/output.txt");

    if (!outputFile) {
        cout << "Error opening output file!" << endl;
        return 1;
    }

    // printing my andrewId as first row in output file
    outputFile << "oirakoze" << endl;

    // Outer loop for each test case
    for (int caseNum = 0; caseNum < test_case; ++caseNum) {
        
        // Assumed size array to store fixation points
        Data* hashTable[HASH_TABLE_SIZE] = {nullptr}; // Initialize hash table

        // Temporary variables to hold values while reading
        int id, x, y;

        // Counter for generating new identifiers
        int newId = 1;

        // Inner loop to read data for each test case
        while (inputFile >> id >> x >> y) {
            // Check for termination condition
            if (x < 0 && y < 0)
                break;

            // Compute hash value
            int hashValue = hashFunction(x, y);

            // Check for duplicate in the hash table
            Data* current = hashTable[hashValue];
            bool isUnique = true;
            while (current != nullptr) {
                if (current->x_coordinate == x && current->y_coordinate == y) {
                    isUnique = false;
                    break;
                }
                current = current->next;
            }

            // If not a duplicate, insert into hash table and write to output file
            if (isUnique) {
                outputFile << newId << " " << x << " " << y << endl;

                // Create a new data node
                Data* newData = new Data;
                newData->identifier = id;
                newData->x_coordinate = x;
                newData->y_coordinate = y;
                newData->next = hashTable[hashValue];

                // Update hash table
                hashTable[hashValue] = newData;
                // Increment newId for the next fixation point
                newId++;
            }
        }
        // Print separator line after each test case
        outputFile << "*************" << endl;
    }

    // Close the files
    inputFile.close();
    outputFile.close();
    // The success message
    cout << "Data written to output.txt" << endl;

    return 0;
}
