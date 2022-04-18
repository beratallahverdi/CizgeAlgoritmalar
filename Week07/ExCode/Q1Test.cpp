#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include "Time.h"
#include "Q1.h"

using namespace std;

///-----------------------------------
/// Test 1
///
int Q1Test1() {
	try {
		vector<int> keys1 = { 1, 3, 14, 11, 7};
		vector<double> medians1 = { 1, 2, 3, 7, 7 };
		Q1DS ds;

		for (size_t i = 0; i < keys1.size(); i++) {
			ds.insert(keys1[i]);

			if (ds.median() != medians1[i]) return 0;
		} //end-for

		// Delete in random order
		vector<int> keys2 = { 11, 3, 7, 1, 14 };
		vector<double> medians2 = { 5, 7, 7.5, 14};

		for (size_t i = 0; i < keys1.size()-1; i++) {
			ds.erase(keys2[i]);

			if (ds.median() != medians2[i]) return 0;
		} //end-for

		ds.erase(keys2[keys2.size() - 1]);
		if (ds.empty() == false) return 0;

	} catch (exception & e) {
		cout << "Error: " << e.what() << endl;
		return 0;
	} // end-catch

	return 7;
} //end-Q1Test1


///-----------------------------------
/// Test 2
///
int Q1Test2() {
	try {
		vector<int> keys;
		Q1DS ds;

		srand(time(NULL));
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

			if (ds.median() != median) return 0;

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
			size_t middle =  noItems / 2;
			if (noItems % 2) median = keys[middle];
			else median = (keys[middle - 1] + keys[middle]) / 2.0;

			if (ds.median() != median) return 0;

#if 0
			for (auto iter : keys) printf("%d, ", iter);
			printf("median: %.1lf\n", median);
			printf("--------------------------------------------\n");
#endif
		} //end-while

	} catch (exception& e) {
		cout << "Error: " << e.what() << endl;
		return 0;
	} // end-catch

	return 13;
} //end-Q1Test2

///------------------------
/// Q1 Test
///
int Q1Test() {
	int grade = 0;
	
	grade += Q1Test1();
	grade += Q1Test2();

	return grade;
} //end-Q1Test