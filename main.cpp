#include "bubbleSort.h"
#include "contactsList.h"
#include "heapSort.h"
#include "insertionSort.h"
#include "heapSort.h"
#include "selectionSort.h"
#include "Song.h"
using namespace std;

void stabilityTest();

void writeToCSV(const std::string& filename, int numReads, int numWrites){
    std::ofstream outFile(filename);
    if (outFile){
        outFile << numReads << "," << numWrites << endl;
    }
    else{
        cout << "Could not write to file" << endl;
    }
}

int main() {
    int numReads, numWrites;
    // Create a vector of 1000+ songs
    vector<Song> songs;

    // Read data from CSV into the vector
    getDataFromFile(songs);


    stabilityTest();
    return 0;
}

void stabilityTest() {
    ContactsList people;
    people.readContactsFromFile("../names.csv");
    cout << "People (Default ordering)" << endl;
    people.printList();

    int numReads = 0;
    int numWrites = 0;

    // Reset numReads and numWrites before each sort
    numReads = 0; numWrites = 0;
    cout << endl << "Bubble Sort" << endl;
    people.sortAndPrint(bubbleSort, numReads, numWrites);

    numReads = 0; numWrites = 0;
    cout << endl << "Heap Sort" << endl;
    people.sortAndPrint(heapSort, numReads, numWrites);

    numReads = 0; numWrites = 0;
    cout << endl << "Insertion Sort" << endl;
    people.sortAndPrint(insertionSort, numReads, numWrites);

    numReads = 0; numWrites = 0;
    cout << endl << "Selection Sort" << endl;
    people.sortAndPrint(selectionSort, numReads, numWrites);

    writeToCSV("test.csv", numReads, numWrites);
}