// #include <iostream>
// #include <fstream>
// #include "header.h"


// struct coordinate {
//     int index;
//     int x_coor;
//     int y_coor;
// };
// int main(){
//     // eyeTracker();

//     std::ifstream inputFile("input.txt");
//     if (!inputFile) {
//         std::cerr << "Failed to open input.txt\n";
//         return 1;
//     }

//     std::ofstream outputFile("output.txt");
//     if (!outputFile) {
//         std::cerr << "Failed to create output.txt\n";
//         return 1;
//     }

//     std::string line;
//     coordinate arr[1000]; // Assuming a maximum of 1000 points
//     int idx = 0;
//     while (std::getline(inputFile, line)) {
//         if (line.empty())
//             continue;

//         if (line == "-1 -1") {
//             // End of scan path, sort and print the previous scan path
//             if (idx > 0) {
//                 outputFile << "*************\n";
//                 mergeSort(arr, 0, idx - 1);
//                 for (int i = 0; i < idx; ++i)
//                     outputFile << arr[i].index << " " << arr[i].x_coor << " " << arr[i].y_coor << "\n";
//                 outputFile << "\n";
//                 idx = 0;
//             }
//             continue;
//         }

//         // Parse coordinates and index from the line
//         coordinate coord;
//         std::string index_str, x_coor_str, y_coor_str;
//         int pos1 = line.find(' ');
//         int pos2 = line.find(' ', pos1 + 1);
//         index_str = line.substr(0, pos1);
//         x_coor_str = line.substr(pos1 + 1, pos2 - pos1 - 1);
//         y_coor_str = line.substr(pos2 + 1);
//         coord.index = std::stoi(index_str);
//         coord.x_coor = std::stoi(x_coor_str);
//         coord.y_coor = std::stoi(y_coor_str);
//         arr[idx++] = coord;
//     }

//     inputFile.close();
//     outputFile << "cachebe\n";
//     outputFile.close();

//     return 0;
    
// }