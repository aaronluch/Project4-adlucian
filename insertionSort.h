#ifndef SORTING_INSERTIONSORT_H
#define SORTING_INSERTIONSORT_H

#include "printVec.h"

template<typename Comparable>

vector<Comparable> insertionSort(vector<Comparable>& vec, int& numReads, int& numWrites) {
    int unsortedStartIndex, insertIndex;
    Comparable toBeInserted;
    numReads = 0;
    numWrites = 0;

    for (unsortedStartIndex = 1; unsortedStartIndex < vec.size(); ++unsortedStartIndex) {
        toBeInserted = vec[unsortedStartIndex];
        numReads += 1; // reads vec[unsortedStartIndex] into toBeInserted
        numWrites += 1; // writes from vec[unsortedStartIndex]

        // Loop to shift over the larger elements
        insertIndex = unsortedStartIndex - 1;

        while (insertIndex >= 0 && vec[insertIndex] > toBeInserted) {
            vec[insertIndex + 1] = vec[insertIndex];
            --insertIndex;
            numReads += 3; // one read for vec[insertIndex], one for vec[insertIndex] and one for toBeInserted
            numWrites += 1; // writes from vec[insertIndex] into vec[insertIndex + 1]
        }
        // Put toBeInserted back into vec
        vec[insertIndex + 1] = toBeInserted;
        numReads += 1; // reads toBeInserted into the vec[insertIndex + 1]
        numWrites += 1; // writes toBeInserted to vec[insertIndex + 1}

        // Uncomment this line if you want to see each iteration
        //printVec(vec);
    }
    cout << "Number of Reads: " << numReads << endl;
    cout << "Number of Writes: " << numWrites << endl;
    return vec;
}

#endif
