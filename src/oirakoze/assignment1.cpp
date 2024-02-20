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

Complexity analysis of function called eyeTracker() which is for whole program
------------------------------------------------------------------------------
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

struct coordinate {
    int index;
    int x_coor;
    int y_coor;
};

void merge(coordinate arr[], int l, int mid, int r) {
    int n1 = mid - l + 1;
    int n2 = r - mid;

    // Create temporary arrays
    coordinate L[n1], R[n2];

    // Copy data to temporary arrays L[] and R[]
    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    // Merge the temporary arrays back into arr[l..r]
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        // Compare first by x-coordinate, then by y-coordinate, and finally by index
        if (L[i].x_coor < R[j].x_coor || (L[i].x_coor == R[j].x_coor && L[i].y_coor < R[j].y_coor) || (L[i].x_coor == R[j].x_coor && L[i].y_coor == R[j].y_coor && L[i].index < R[j].index)) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of L[], if any
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements of R[], if any
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(coordinate arr[], int l, int r) {
    if (l < r) {
        int mid = l + (r - l) / 2;
        mergeSort(arr, l, mid);
        mergeSort(arr, mid + 1, r);
        merge(arr, l, mid, r);
    }
}

int main(){
    // eyeTracker();

    std::ifstream inputFile("../data/input.txt");
    if (!inputFile) {
        std::cout << "Failed to open input.txt\n";
        return 1;
    }

    int scanpath;
    if (!(inputFile >> scanpath)) {
        std::cout << "Failed to read scanpath number from input.txt\n";
        return 1;
    }


    // Validate scanpath
    if (scanpath < 1 || scanpath > 10) {
        std::cout << "Invalid scanpath value. It should be between 1 and 10." << endl;
        return 1;
    }

    std::ofstream outputFile("../data/output.txt");
    if (!outputFile) {
        std::cout << "Failed to create output.txt\n";
        return 1;
    }

    // printing my andrewId as first row in output file
    outputFile << "oirakoze" << endl;

    coordinate arr[1000]; // Assuming a maximum of 1000 points
    int idx = 0;

    // the tempory variable to hold the points
    int index, x, y;

    while (inputFile >> index >> x >> y) {
        

        if (x == -1 && y == -1) {
            // End of scan path, sort and print the previous scan path
            if (idx > 0) {
                mergeSort(arr, 0, idx - 1);
                for (int i = 0; i < idx; ++i)
                    outputFile << arr[i].index << " " << arr[i].x_coor << " " << arr[i].y_coor << std::endl;
                idx = 0;
                outputFile << "*************" << std::endl;
            }
            continue;
        } 

        // Assign values to the coordinate structure
        arr[idx].index = index;
        arr[idx].x_coor = x;
        arr[idx].y_coor = y;
        idx++;
    }  

    inputFile.close();
    outputFile.close();

    return 0;
    
}

