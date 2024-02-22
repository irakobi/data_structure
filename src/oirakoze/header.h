#ifndef ASSIGNMENT2_SRC_OIRAKOZE_H
#define ASSIGNMENT2_SRC_OIRAKOZE_H

struct coordinate {
    int index;
    int x_coor;
    int y_coor;
};
using namespace std;

void mergeSort(coordinate array[], int left_index, int right_index);
void merge(coordinate array[], int left_index, int middle_index, int right_index);

#endif