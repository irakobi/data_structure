/* Internal documentation
Author name: Obed Irakoze
Author andrewId: oirakoze
Author class: MS-ECE class of 2025 

*/

#include<iostream>
#include<fstream>

using namespace std;

// Define a structure to hold the data for each input line
struct Data {
    int identifier;
    int x_coordinate;
    int y_coordinate;
};

int eyeTracker() {
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

    // printing my andrewId
    outputFile << "oirakoze" << endl;

    // Outer loop for each test case
    for (int caseNum = 0; caseNum < test_case; ++caseNum) {
        
        // Assumed size array to store fixation points
        const int MAX_ROWS = 1000; 
        Data data[MAX_ROWS];

        // Temporary variables to hold values while reading
        int id, x, y;
        int rowCount = 0; 

        // Inner loop to read data for each test case
        while (inputFile >> id >> x >> y) {
            // Check for termination condition
            if (x < 0 && y < 0)
                break;

            // Checking if we don't exceed  the assumed maximum number of fixation point per test case
            if (rowCount >= MAX_ROWS) {
            cout << "Exceeded maximum number of rows. Increase MAX_ROWS." << endl;
            break;
            }

            //  Check if that input is not duplicated
            bool isUnique = true;
            for (int i = 0; i < rowCount; i++){
                if (data[i].x_coordinate == x && data[i].y_coordinate == y){
                    isUnique = false;
                    break;
                }
            }

            if (isUnique){
                 // Write data to output file
                outputFile << rowCount + 1 << " " << x << " " << y << endl;
                data[rowCount].identifier = id;
                data[rowCount].x_coordinate = x;
                data[rowCount].y_coordinate = y;
                rowCount++;
            } 
        }
        // Print separator line after each test case
        outputFile << "*************" << endl;
    }

    // Close the files
    inputFile.close();
    outputFile.close();

    cout << "Data written to output.txt" << endl;

    return 0;
}
