#ifndef SORTING_SELECTIONSORT_H
#define SORTING_SELECTIONSORT_H

#include "printVec.h"

template<typename Comparable>

vector<Comparable> selectionSort(vector<Comparable>& vec, int& numReads, int &numWrites) {
    int swapIndex, i, minIndex;
    numReads = 0;
    numWrites = 0;
    Comparable temp;

    for (swapIndex = 0; swapIndex < vec.size()-1; ++swapIndex) {
        // Loop through vector starting at swapIndex and keep track of min
        minIndex = swapIndex;
        for (i = swapIndex+1; i < vec.size(); ++i) {
            if (vec[i] < vec[minIndex]) {
                // We have a new minimum
                minIndex = i;
                numReads += 2; // 2 reads in the if section
            }
        }

        // Swap min value into swapIndex spot in vector
        temp = vec[swapIndex];
        vec[swapIndex] = vec[minIndex];
        vec[minIndex] = temp; // not a read from vec, shouldn't count
        numReads += 2; // 2 reads when swapping
        numWrites += 3; // 3 writes during the swap

        // Uncomment this line if you want to see each iteration
        //printVec(vec);
    }
    return vec;
}

#endif
