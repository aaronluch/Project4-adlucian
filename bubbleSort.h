#ifndef SORTING_BUBBLESORT_H
#define SORTING_BUBBLESORT_H

#include "printVec.h"

template<typename Comparable>
vector<Comparable> bubbleSort(vector<Comparable>& vec, int& numReads, int& numWrites) {
    int numPasses = 0, i;
    Comparable temp;
    numReads = 0;
    numWrites = 0;
    bool haveSwapped = true;

    while (haveSwapped) {
        haveSwapped = false;
        for (i = 0; i+1 < vec.size()-numPasses; ++i) {
            // Compare items at indices i and i+1 and swap if necessary
            numReads += 2; // if you swap at these indicies, there would be two reads
            if (vec[i] > vec[i+1]) {
                temp = vec[i];
                numReads += 1; // reads vec[i]
                numWrites += 1; // writes to temp

                vec[i] = vec[i+1];
                numReads += 1; // reads vec[i+1]
                numWrites += 1; // writes to vec[i]

                vec[i+1] = temp; // not a read from vec
                numWrites += 1; // writes to vec[i+1]

                // Update haveSwapped
                haveSwapped = true;
            }
        }
        // Update numPasses
        ++numPasses;

        // Uncomment this line if you want to see each iteration
        //printVec(vec);
    }
    return vec;
}

#endif
