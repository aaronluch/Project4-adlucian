#include "bubbleSort.h"
#include "contactsList.h"
#include "heapSort.h"
#include "insertionSort.h"
#include "selectionSort.h"
#include "Song.h"
#include "fstream"
#include "iostream"
using namespace std;

void stabilityTest();

// Method to format a write of reads and writes to a csv file
void writeToCSV(const string& filename, int numReads, int numWrites){
    std::ofstream outFile(filename);
    if (outFile){
        outFile << std::left << std::setw(20) << "Number of Reads" <<
        std::setw(20) << "Number of Writes" << endl;
        outFile << std::left << std::setw(20) << numReads << std::setw(2) << numWrites << endl;
        outFile.close();
        cout << "Data written to " << filename << endl;
    }
    else{
        cout << "Could not write to file: " << filename << endl;
        return;
    }
}

int main() {
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

    cout << endl << "Bubble Sort" << endl;
    people.sortAndPrint(bubbleSort<contact>, numReads, numWrites);
    writeToCSV("../output_data/ContactListBubbleSort.csv", numReads, numWrites);

    numReads = 0; numWrites = 0;
    cout << endl << "Heap Sort" << endl;
    people.sortAndPrint(heapSort<contact>, numReads, numWrites);
    writeToCSV("../output_data/ContactListHeapSort.csv", numReads, numWrites);

    numReads = 0; numWrites = 0;
    cout << endl << "Insertion Sort" << endl;
    people.sortAndPrint(insertionSort<contact>, numReads, numWrites);
    writeToCSV( "../output_data/ContactListInsertionSort.csv", numReads, numWrites);

    numReads = 0; numWrites = 0;
    cout << endl << "Selection Sort" << endl;
    people.sortAndPrint(selectionSort<contact>, numReads, numWrites);
    writeToCSV("../output_data/ContactListSelectionSort.csv", numReads, numWrites);
}