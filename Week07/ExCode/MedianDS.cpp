#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <exception>

using namespace std;

#include <list>
#include <map>

using namespace std;

// You may assume that the "key"s will be unique
struct MedianDS {
	list<int> myList;
	map<int, list<int>::iterator> myMap;
	list<int>::iterator medianIter;
	int noItemsLeftOfMedian;

	MedianDS() {
		medianIter = myList.end();
		noItemsLeftOfMedian = 0;
	} //end-MedianDS

	void updateMedian();

	// Returns "true" if the DS is empty
	bool empty();

	// Insert "key" in O(logn)
	void insert(int key);

	// Delete "key" in O(logn)
	void erase(int key);

	// Return the median in O(1)
	double median();
};

// Returns "true" if the DS is empty
bool MedianDS::empty() { return myList.size() == 0; }

void MedianDS::updateMedian() {
	// Update the medianIter
	if (medianIter == myList.end()) {
		medianIter = myList.begin();  // First item

	} else {
		size_t middle = myList.size() / 2;
		if (noItemsLeftOfMedian > middle) {
			noItemsLeftOfMedian--;
			medianIter--;

		} else if (noItemsLeftOfMedian < middle) {
			noItemsLeftOfMedian++;
			medianIter++;
		} //end-else
	} //end-else
} //end-updateMedian

// Insert "key" in O(logn)
void MedianDS::insert(int key) {
	// Insert into the DS
	list<int>::iterator listIter;
	auto mapIter = myMap.insert(make_pair(key, listIter)).first;

	// Get another iterator to the next element
	auto nextIter = mapIter;
	nextIter++;
	if (nextIter == myMap.end()) {
		// Insert the item at the end of the list
		myList.push_back(key);
		mapIter->second = --myList.end();

	} else {
		// Inserted somewhere in the middle of the list
		list<int>::iterator currIter = nextIter->second;
		list<int>::iterator newIter = myList.insert(currIter, key);
		mapIter->second = newIter;
	} //end-else

	if (medianIter != myList.end() && key < *medianIter) noItemsLeftOfMedian++;

	// Update the medianIter
	updateMedian();
} //end-insert

// Delete "key" in O(logn)
void MedianDS::erase(int key) {
	// Find the key first
	auto mapIter = myMap.find(key);
	if (mapIter == myMap.end()) throw exception("erase: Key not found");

	if (key == *medianIter) medianIter++;
	else if (key < *medianIter) noItemsLeftOfMedian--;

	// Delete from the list 
	myList.erase(mapIter->second);  // Erase the element from the list
	myMap.erase(key);               // Erase the element from the map
	
	if (myList.size() == 0) return;

	updateMedian();
} // end-erase

// Return the median in O(1)
double MedianDS::median() {
	if (myList.size() == 0) throw exception("median: No elements in DS");

	if (myList.size() % 2) return *medianIter;
	else {
		auto prev = medianIter;
		prev--;
		return (*prev + *medianIter) / 2.0;
	} //end-else
} //end-median


///========================== TEST CODE ==========================================
///-----------------------------------
/// Test 1
///
void MedianDSTest1() {
	try {
		vector<int> keys1 = { 1, 3, 14, 11, 7 };
		vector<double> medians1 = { 1, 2, 3, 7, 7 };
		MedianDS ds;

		for (size_t i = 0; i < keys1.size(); i++) {
			ds.insert(keys1[i]);

			if (ds.median() != medians1[i]) {
				printf("Test1 failed!");
				return;
			} // end-if
		} //end-for

		// Delete in random order
		vector<int> keys2 = { 11, 3, 7, 1, 14 };
		vector<double> medians2 = { 5, 7, 7.5, 14 };

		for (size_t i = 0; i < keys1.size() - 1; i++) {
			ds.erase(keys2[i]);

			if (ds.median() != medians2[i]) return;
		} //end-for

		ds.erase(keys2[keys2.size() - 1]);
		if (ds.empty() == false) {
			printf("Test1 failed!");
			return;
		} // end-if

	}
	catch (exception& e) {
		cout << "Test1 Error: " << e.what() << endl;
		return;
	} // end-catch

	printf("MedianDSTest1 passed.\n");
} //end-MedianDSTest1

///-----------------------------------
/// Test 2
///
void MedianDSTest2() {
	try {
		vector<int> keys;
		MedianDS ds;

		srand((uint32_t)time(NULL));
		int N = 1024;
		for (int i = 0; i < N; i++) {
			keys.push_back(rand());
		} //end-for

		// Eliminate the duplicates
		int k = 1;
		for (size_t i = 1; i < keys.size(); i++) {
			bool found = false;
			for (size_t j = 0; j < k; j++) {
				if (keys[j] == keys[i]) {
					found = true;
					break;
				} // end-if
			} // end-for

			if (!found) keys[k++] = keys[i];
		} // end-for
		keys.resize(k);

		for (size_t i = 0; i < keys.size(); i++) {
			ds.insert(keys[i]);

			size_t noItems = i + 1;
			sort(keys.begin(), keys.begin() + noItems);

			double median;
			size_t middle = noItems / 2;
			if (noItems % 2) median = keys[middle];
			else median = (keys[middle - 1] + keys[middle]) / 2.0;

			if (ds.median() != median) {
				printf("Test2 failed!");
				return;
			} // end-if

#if 0
			for (auto iter : keys) printf("%d, ", iter);
			printf("median: %.1lf\n", median);
			printf("--------------------------------------------\n");
#endif
		} //end-for

		// Delete in random order and check for correctness
		int count = 0;
		while (keys.size() > 1) {
			int index = rand() % keys.size();

			//			printf("[%4d] Deleting %8d, size: %4d\n", ++count, keys[index], keys.size());

						// Delete from the DS
			ds.erase(keys[index]);

			// Delete from the keys
			keys.erase(keys.begin() + index);

			// Compute the median
			double median;
			size_t noItems = keys.size();
			size_t middle = noItems / 2;
			if (noItems % 2) median = keys[middle];
			else median = (keys[middle - 1] + keys[middle]) / 2.0;

			if (ds.median() != median) {
				printf("Test2 failed.");
				return;
			} //end-if

#if 0
			for (auto iter : keys) printf("%d, ", iter);
			printf("median: %.1lf\n", median);
			printf("--------------------------------------------\n");
#endif
		} //end-while

	}
	catch (exception& e) {
		cout << "Test2 Error: " << e.what() << endl;
		return;
	} // end-catch

	printf("MedianDSTest2 passed.\n");
} //end-MedianDSTest2

///------------------------
/// MedianDSTest
///
void MedianDSTest() {
	MedianDSTest1();
	MedianDSTest2();
} //end-MedianDSTest
