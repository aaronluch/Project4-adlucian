#include "bubbleSort.h"
#include "contactsList.h"
#include "heapSort.h"
#include "insertionSort.h"
#include "selectionSort.h"
#include "Song.h"
#include "fstream"
#include "iostream"
#include "chrono"
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
    // Read data from CSV to populate vector
    getDataFromFile(songs);
    // Create a vector to hold only years
    vector<int> releaseYears;
    // Extract the year from each song and add it to the vector
    for (const Song& song : songs) {
        int year = getReleaseYear(song.getRelease());
        releaseYears.push_back(year);
    }

    vector<int> actualSortedData = releaseYears; // making a sorted vector for referencing
    int numReadsTest = 0;
    int numWritesTest = 0;
    selectionSort(actualSortedData, numReadsTest, numWritesTest);
    ofstream outFileTest("../output_data/actualSortedData.csv");
    for(const int& value: actualSortedData){
        outFileTest << value << ",";
    }
    outFileTest.close();

    // Header for sorting all 4 of these methods
    ofstream outFile("../output_data/sorted_song_data_TIMED.csv");
    outFile << "Vector Size,Bubble Reads,Bubble Writes,Bubble Time,Selection Reads,Selection Writes,Selection Time,"
               "Insertion Reads, Insertion Writes,Insertion Time,Heap Reads,Heap Writes,Heap Time" << endl;

    // We will be sorting the release years of each song in the entire vector
    // Sort each copy with a different sorting algorithm under a loop
    // Track reads and writes for each sorting method in increments of 100
    for (int size = 100; size <= 1000; size += 100){
        vector<int> currentReleaseYears(releaseYears.begin(), releaseYears.begin() + size);

        // Write the initial size for this row
        outFile << size;

        // Reset reads and writes to initialize process
        int numReads = 0, numWrites = 0;

        // Bubble Sort
        auto start = std::chrono::high_resolution_clock::now(); // starting clock
        vector<int> releaseYearsBubbleSort = currentReleaseYears; // make a copy for bubble sort
        bubbleSort(releaseYearsBubbleSort, numReads, numWrites);
        outFile << "," << numReads << "," << numWrites;

        // recording / writing time
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double, std::milli> bubbleTime = end - start;
        outFile << "," << bubbleTime.count();

        numReads = 0, numWrites = 0; // reset reads and writes

        // Selection Sort
        start = std::chrono::high_resolution_clock::now(); // starting clock
        vector<int> releaseYearsSelectionSort = currentReleaseYears; // make a copy for selection sort
        selectionSort(releaseYearsSelectionSort, numReads, numWrites);
        outFile << "," << numReads << "," << numWrites;
        // recording / writing time
        end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double, std::milli> selectionTime = end - start;
        outFile << "," << selectionTime.count();

        numReads = 0, numWrites = 0; // reset reads and writes

        // Insertion Sort
        start = std::chrono::high_resolution_clock::now(); // starting clock
        vector<int> releaseYearsInsertionSort = currentReleaseYears; // make a copy for insertion sort
        insertionSort(releaseYearsInsertionSort, numReads, numWrites);
        outFile << "," << numReads << "," << numWrites;

        // recording / writing time
        end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double, std::milli> insertionTime = end - start;
        outFile << "," << insertionTime.count();

        numReads = 0, numWrites = 0; // reset reads and writes

        // Heap Sort
        start = std::chrono::high_resolution_clock::now(); // starting clock
        vector<int> releaseYearsHeapSort = currentReleaseYears; // make a copy for heap sort
        heapSort(releaseYearsHeapSort, numReads, numWrites);
        outFile << "," << numReads << "," << numWrites;

        // recording / writing time
        end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double, std::milli> heapTime = end - start;
        outFile << "," << heapTime.count();
        // don't need to reset reads/writes; resets at beginning of loop

        outFile << endl;
    }

    outFile.close();

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

    // Sorting Contact List with Bubble Sort
    cout << endl << "Bubble Sort" << endl;
    people.sortAndPrint(bubbleSort<contact>, numReads, numWrites);
    writeToCSV("../output_data/ContactListBubbleSort.csv", numReads, numWrites);

    // Sorting Contact List with Heap Sort
    numReads = 0; numWrites = 0;
    cout << endl << "Heap Sort" << endl;
    people.sortAndPrint(heapSort<contact>, numReads, numWrites);
    writeToCSV("../output_data/ContactListHeapSort.csv", numReads, numWrites);

    // Sorting Contact List with Insertion Sort
    numReads = 0; numWrites = 0;
    cout << endl << "Insertion Sort" << endl;
    people.sortAndPrint(insertionSort<contact>, numReads, numWrites);
    writeToCSV( "../output_data/ContactListInsertionSort.csv", numReads, numWrites);

    // Sorting Contact List with Selection Sort
    numReads = 0; numWrites = 0;
    cout << endl << "Selection Sort" << endl;
    people.sortAndPrint(selectionSort<contact>, numReads, numWrites);
    writeToCSV("../output_data/ContactListSelectionSort.csv", numReads, numWrites);
}