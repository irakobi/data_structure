#include <iostream>
#include <fstream>
#include "header.h"


int main(){

    //  Opening the input file
    std::ifstream inputFile("../data/input.txt");
    if (!inputFile) {
        std::cout << "Failed to open input.txt\n";
        return 1;
    }
    // Scanning the first line which in the testcase number
    int scanpath;
    if (!(inputFile >> scanpath)) {
        std::cout << "Failed to read testcase number from input.txt\n";
        return 1;
    }


    // // Validate scanpath
    // if (scanpath < 1 || scanpath > 10) {
    //     std::cout << "Invalid testcase value. It should be between 1 and 10." << endl;
    //     return 1;
    // }
    // Opening the output file
    std::ofstream outputFile("../data/output.txt");
    if (!outputFile) {
        std::cout << "Failed to create output.txt\n";
        return 1;
    }

    // printing my andrewId as first row in output file
    outputFile << "oirakoze" << endl;

    coordinate array[1000]; // Assuming a maximum of 1000 points per testcase as in the question
    int idx = 0;

    // the tempory variable to hold the points
    int index, x, y;

    while (inputFile >> index >> x >> y) {
        

        if (x == -1 && y == -1) {
            // End of testcase, sort and print the previous scan path
            if (idx > 0) {
                mergeSort(array, 0, idx - 1);
                for (int i = 0; i < idx; ++i)
                    outputFile << array[i].index << " " << array[i].x_coor << " " << array[i].y_coor << std::endl;
                idx = 0;
                outputFile << "*************" << std::endl;
            }
            continue;
        } 

        // Assign values to the coordinate structure
        array[idx].index = index;
        array[idx].x_coor = x;
        array[idx].y_coor = y;
        idx++;
    }  

    inputFile.close();
    outputFile.close();

    return 0;
    
}