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
This program was performed using the Hash table algorithm and struct arrayay. efficiently is processes input data, detects and removes duplicates using a hash table with chaining,
and writes the unique data points to the output file for each test case. the following is the pseudo-code to explain the process:

Description of the test cases used
-----------------------------------
In my input.txt file I have 4 testcases, the first contains 20 fixation points, the row with zeros and it test the duplications
The second has the high values of x and y coordinate and also it test the duplications, the third test case has the similar x and y coordinate,
for teting our program and the last test the program with many fixation points arrayound 999 including the several duplicates.

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
#include "header.h"

void merge(coordinate array[], int left_index, int middle_index, int right_index) {
    int n1 = middle_index - left_index + 1;
    int n2 = right_index - middle_index;

    // Create temporary sub arrayays, left and right  
    coordinate L[n1], R[n2];

    // Copy data to temporary arrayays L[] and R[]
    for (int i = 0; i < n1; i++)
        L[i] = array[left_index
     + i];
    for (int j = 0; j < n2; j++)
        R[j] = array[middle_index + 1 + j];

    // Merge the temporary arrayays back into array[left_index..right_index]
    int i = 0, j = 0, k = left_index
;
    while (i < n1 && j < n2) {
        // Compare first by x-coordinate, then by y-coordinate, and finally by index
        if (L[i].x_coor < R[j].x_coor || (L[i].x_coor == R[j].x_coor && L[i].y_coor < R[j].y_coor) || (L[i].x_coor == R[j].x_coor && L[i].y_coor == R[j].y_coor && L[i].index < R[j].index)) {
            array[k] = L[i];
            i++;
        } else {
            array[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of L[], if any
    while (i < n1) {
        array[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements of R[], if any
    while (j < n2) {
        array[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(coordinate array[], int left_index, int right_index) {
    if (left_index
 < right_index) {
        int middle_index = left_index
     + (right_index - left_index
    ) / 2;
        mergeSort(array, left_index
    , middle_index);
        mergeSort(array, middle_index + 1, right_index);
        merge(array, left_index
    , middle_index, right_index);
    }
}



