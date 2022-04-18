#ifndef _Q1_H_
#define _Q1_H_

#include <list>
#include <map>

using namespace std;

// You may assume that the "key"s will be unique
struct Q1DS {
	list<int> myList;
	map<int, list<int>::iterator> myMap;
	list<int>::iterator medianIter;
	int noItemsLeftOfMedian;

	Q1DS() {
		medianIter = myList.end();
		noItemsLeftOfMedian = 0;
	} //end-Q1DS

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

#endif _Q1_H_