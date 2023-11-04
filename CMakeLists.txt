cmake_minimum_required(VERSION 3.15)
project(Project4)

set(CMAKE_CXX_STANDARD 17)

include_directories(.)

add_executable(Project4
        bubbleSort.h
        heapSort.h
        insertionSort.h
        mergeSort.h
        printVec.h
        quickSort.h
        radixSort.h
        selectionSort.h main.cpp contactsList.h)
