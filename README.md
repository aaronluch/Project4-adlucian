# CS2240 Project 4 - Aaron Luciano
**Sorting Algorithms**<br />
*11/6/2023*

* **Information about your data set**<br />
  * The data was all accumulated from my own personal playlists on spotify. They were not all one large playlist,
    but rather I had to convert the multiple CSV files into one general CSV file called "merged-playlists.csv"
    through the use of windows' built in terminal. To acquire all the CSV files, I used https://exportify.net,
    more information on the website. *Note*: When sorting this data for the project, 
    I chose to sort the release years only.<br />
    <br />

* **Analyze the data. Graph the number of reads and writes, and compare and contrast.**<br />
  * All Songs Sorted:
  ![All Songs Sorted](data_images/all_songs_sorted.png)
    * _Note: it is hard to read exactly which line is which, so more graphs will provided for each
    sorting algorithm. The x-axis represents the size of the vector at a given point, and the y-axis
    represents the total amount of either reads or writes (hence two lines for each)_<br><br>
  * Bubble Sort:
    ![Bubble Sorted](data_images/bubbleSorted.png)
    * Reads and writes grow quadratically with the size of the vector.
    * For a vector of size 100, it performs 11,754 reads and 4,671 writes.
    * For a vector of size 1000, it performs 1,443,546 reads and 706,917 writes.
    * The quadratic growth is consistent with the O(n^2) time complexity of Bubble Sort.<br><br>
  * Selection Sort:
    ![Selection Sorted](data_images/selectionSorted.png)
    * The number of reads grows quadratically, but the number of writes remains relatively low compared to reads.
    * Reads grow from 594 to 6,946, while writes only grow from 297 to 2,997.
    * This suggests that while Selection Sort also has an O(n^2) time complexity, it does fewer writes 
    than the other sorting algorithms, potentially making it more efficient in scenarios where writes are 
    more expensive than reads.<br><br>
  * Insertion Sort:
    ![Insertion Sorted](data_images/insertionSorted.png)
    * The number of reads and writes also grows quadratically.
    * Starts at 4,869 reads and 1,755 writes and goes up to 708,915 reads and 237,637 writes.
    * Insertion Sort is typically more efficient than Bubble Sort and Selection Sort for small or 
    nearly sorted datasets because it can terminate early if the elements are already sorted, 
    but this advantage diminishes with larger random datasets.
      * You can see with this dataset, while it did perform better than bubble sort, it still was very expensive
      with both its amount of reads and writes--especially compared to selection sort.<br><br>
  * Heap Sort:
    ![Heap Sorted](data_images/heapSorted.png)
    * The number of reads and writes grows more slowly than the other sorting algorithms.
    * For a vector size of 100, there are 3,578 reads and 297 writes, growing to 160,360 reads 
    and 2,997 writes for a vector size of 1000.
    * Heap Sort has a time complexity of O(n log n), which explains the slower growth rate 
    compared to the other sorting algorithms.
    * In this instance, Heap Sort performed identically with the amount of writes to selection sort, however
    it had a _significant_ amount more of reads comparatively.<br><br>
  * Conclusions with this information:
    * In general, Heap Sort _is_ more efficient than the other algorithms for larger datasets since it has a lower 
    time complexity (O(n log n) vs O(n^2)), however in this instance, selection performed better than all others.
      * The data only being in a range of 45 years (1977-2022) is the most likely reason as to why selection performed much
      better than others. On top of that, selection being unstable means that it doesn't have to check value
      against another if they end up being the same year, and having so much overlap in years from the song data
      helped it perform the quickest of all others. Additionally, the data-set may have been partially sorted
      beforehand, as the csv file of all the songs and their data is based on the order in which the user added
      them to the playlist. In this regard, they may have added songs and or albums all from one year, which
      would therefore cause partially sorted segments of the dataset.
    * The quadratic complexities (O(n^2)) of Bubble, Selection, and Insertion Sorts make them inefficient for 
    large datasets as the number of operations increases dramatically with the size of the input. Again though,
    this particular dataset had a very glaring exception as mentioned previously.<br><br>
  * Table of the data and times:
  ![Table](data_images/sorted_table.png)<br><br>
* **Analyzing stabilityTest function**
  * How are the names sorted by default?
    * By default, the first names in the list are sorted alphabetically, starting with a first name beginning with
    an "A", ascending up to  the final name ending in an "S". The last names however are unsorted, with no clearly
    recognizable pattern. So only the first name column of the csv is partially sorted for the entire dataset.
  * How is the output from the two stable sorting algorithms different from the two unstable ones?
    * ![Contact Lists Reads / Writes](/data_images/contactList_sorted.png)
    * Here you can see a representation of the sorting methods resulting reads and writes. We see that the two
    stable methods, (Bubble & Insertion) have very different resulting amounts of reads. Bubble sort had the greatest
    amounts of reads at 114, however insertion remained low at only 18 reads. Additionally, the unstable methods,
    (Selection & Heap) also had a similar outcome, with selection only having 18 reads, and Heap having 91 reads.
    * When it came to the writes, Insertion had the overall least amount, with 18 writes in total. Trailing that,
    both Heap and Selection had 27 writes, and Bubble Sort in last place with 45 writes.
    * Insertion Sort, against the 3 other sorting algorithms, performed best in this scenario.
  * Implications: 
    * In terms of stability, Bubble and Insertion Sorts maintained the original order of items with equal keys, 
    which is not guaranteed by the unstable algorithms.
    * The efficiency of Insertion Sort in this data set suggests that it 
    benefited from the partially pre-sorted first names column.
  * Conclusions:
    * Assuming we want stability because the original order was significant, we would opt for insertion in this case,
    seeing as it was the overall best, but also because it is a stable sorting algorithm. This also shows that insertion
    will be the best choice for nearly sorted and or small list datasets. 
    * Because this was a list of names, we would've certainly wanted a sorting algorithm that was stable. As we saw from
    the accumulation of read and write data, we were able to find the best sorting algorithm to accommodate this (Insertion).<br><br>
* **Additional Questions:**
  * If you need to sort a contacts list on a mobile app, which sorting algorithm(s) would you use and why?
    * For a contacts list on a mobile app, which typically has a relatively small number of entries and is frequently 
    accessed and updated by the user, I would prioritize algorithms that are efficient for small datasets and offer 
    stability to preserve the order of contacts with the same sort key.
    * With that being said, as we previously saw, Insertion Sort should be the best option for that task.
  * What about if you need to sort a database of 20 million client files that are stored in a datacenter in the cloud?
    * For such a large database, you would want to use something scalable like Heap Sort. Due to Heap Sort having a
    consistent time complexity of O(n log n) for both the worst and average cases, this makes it very scalable when
    dealing with large datasets, and provides a guaranteed level of performance as the complexity will not change.
    * Additionally, Heap Sort sorts in place, requiring no additional memory allocation beyond what it is already sorting.
    This makes it significantly more memory efficient when working with large datasets.
    * It does have drawbacks though, as it is still an unstable sorting algorithm. If stability is required due to 
    secondary sorting keys or if the original order carries semantic significance, this could be a limitation.
    * The other two stable algorithms I covered would not be suitable for a dataset this large, as their time complexities
    would be a major negative factor causing them to be inefficient. So if you need something more stable, you would need
    to look elsewhere.
      * Overall, Heap seems to be the best option for this scenario based on my findings.
<br><br>

* **Additional Sources**<br />
  * Timing Algorithms Reference (Chrono): https://www.geeksforgeeks.org/measure-execution-time-function-cpp/
