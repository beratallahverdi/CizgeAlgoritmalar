#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

using namespace std;

void FindEqualPairsTest();
void CountFrequencyTest();

///--------------------------------------------------
/// Main entry point
///
int main() {
	FindEqualPairsTest();
//	CountFrequencyTest();

	return 0;
} //end-main

///============================== FIND EQUAL PAIRS ==============================
/// Print all positive integer solutions to the equation a^3+b^3 = c^3+d^3
/// where a, b, c, and d are distinct integers between 1 and 1000
///
///--------------------------------------------------------------
/// Brute-force O(n^4) algorithm to find the equal pairs
///
void FindEqualPairs1(vector<pair<int, int>>& pairs) {
	int N = 50;

	for (int a = 1; a <= N; a++) {
		for (int b = a + 1; b <= N; b++) {
			for (int c = 1; c <= N; c++) {
				for (int d = c + 1; d <= N; d++) {
					if (c == a || c == b) continue;   // Skip the same pair
					if (d == a || d == b) continue;   // Skip the same pair

					if ((a * a * a + b * b * b) == (c * c * c + d * d * d)) {
						if (a < c) {
							pairs.push_back({ a, b });
							pairs.push_back({ c, d });
						} //end-if
					} // end-if
				} //end-for
			} //end-for
		} //end-for
	} //end-for
} //end-FindEqualPairs1

///--------------------------------------------------------------
/// O(n^3) algorithm to find the equal pairs
/// We want: a^3+b^3 = c^3+d^3
/// ===> d^3 = a^3+b^3-c^3
/// ===>   d = sqrt^{1/3}(a^3+b^3-c^3)
///
void FindEqualPairs2(vector<pair<int, int>>& pairs) {
	int N = 50;

	for (int a = 1; a <= N; a++) {
		for (int b = a + 1; b <= N; b++) {
			for (int c = 1; c <= N; c++) {
				if (c == a || c == b) continue;   // Skip the same pair

				int d1 = (int)pow(a * a * a + b * b * b - c * c * c, 1 / 3);

				int delta = 9;
				int min = d1 - delta;
				if (min < 1) min = 1;
				int max = d1 + delta;
				if (max > N) max = N;

				for (int d = min; d <= max; d++) {
					if ((a * a * a + b * b * b) == (c * c * c + d * d * d)) {
						if (d < c) {
							pairs.push_back({ a, b });
							pairs.push_back({ c, d });
						} // end-if
					} //end-if
				} //end-for
			} // end-for
		} //end-for
	} // end-for
} //end-FindEqualPairs2

///--------------------------------------------------------------
/// O(n^2) algorithm to find the equal pairs
///
void FindEqualPairs3(vector<pair<int, int>>& pairs) {
	int N = 50;

	unordered_map<int, vector<pair<int, int>>> uom;

	for (int a = 1; a <= N; a++) {
		for (int b = a + 1; b <= N; b++) {
			int key = a * a * a + b * b * b;

			auto iter = uom.find(key);
			if (iter == uom.cend()) {
				// Insert the pair the first time
				vector<pair<int, int>> list;
				list.push_back({ a, b });
				uom.insert(make_pair(key, list));

			} else {
				// There already is a pair that adds up to this key.
				// Simply append the new pair to the end
				iter->second.push_back({ a, b });
			} //end-else
		} //end-for
	} //end-for

	// Now, walk over the uom, and get all matching pairs
	for (auto iter : uom) {
		// If there is just one pair, skip it.
		if (iter.second.size() < 2) continue;

		// OK. More than one pair. Add them up to the output
		for (size_t i = 0; i < iter.second.size() - 1; i++) {
			for (size_t j = i + 1; j < iter.second.size(); j++) {
				pairs.push_back(iter.second[i]);
				pairs.push_back(iter.second[j]);
			} //end-for
		} //end-for
	} //end-for
} //end-FindEqualPairs3

///---------------------------------------------------------------
/// Code to test FindEqualPairs algorithms
///
void FindEqualPairsTest() {
	vector<pair<int, int>> pairs;

	FindEqualPairs1(pairs);
//	FindEqualPairs2(pairs);
//	FindEqualPairs3(pairs);

	int count = 1;
	for (size_t i = 0; i < pairs.size(); i += 2) {
		int a = pairs[i].first;
		int b = pairs[i].second;
		int r = a * a * a + b * b * b;
		printf("[%4d][%3d, %3d] [%3d, %3d] = %d\n",
			count++, a, b, pairs[i + 1].first, pairs[i + 1].second, r);
	} //end-for
} //end-FindEqualPairsTest

///======================= COUNT FREQUENCY ======================
/// Given an array of numbers, count the frequency of each number.
/// Return the result in decreasing order of their frequencies
/// Ex: Given A[] = [2, 1, 3, 2, 2, 2, 1, 4, 1, 4]
///     The result would be: [<2, 4>, <1, 3>, <3, 1>, <4, 2>]
///
///-------------------------------------------------------------------
/// Brute-force O(N^2) algorithm
///
void CountFrequency1(vector<int>& A, vector<pair<int, int>>& result) {
	for (auto& num : A) {
		// Search num in the result. If found, increment its frequency.
		bool found = false;
		for (auto iter = result.begin(); iter != result.end(); iter++) {
			if (num == iter->first) {
				found = true;
				iter->second++;
			} // end-if
		} // end-for

		if (!found) result.push_back({ num, 1 });
	} // end-for
} //end-CountFrequency1

///-------------------------------------------------------------------
/// Brute-force O(NlogN) algorithm with sorting
///
void CountFrequency2(vector<int>& A, vector<pair<int, int>>& result) {
	std::sort(A.begin(), A.end());
	for (auto& num : A) {
		if (result.size() > 0 && result.back().first == num) {
			result.back().second++;
		}
		else {
			result.push_back({num, 1});
		} // end-else
	} // end-for
} //end-CountFrequency2

  ///----------------------------------------------------------------------
/// Here is an O(N) version that makes use of an HashMap
///
void CountFrequency3(vector<int>& A, vector<pair<int, int>>& result) {
	// Insert the words into a map and count the number of times each occur
	unordered_map<int, int> map;   // <number, freq>
	for (auto& num : A) map[num]++;

	// Frequency computation is done
	// Walk over the map, and fill up the "result"
	for (auto iter : map) {
		result.push_back({ iter.first, iter.second });
	} //end-for
} //end-CountFrequency3

///--------------------------------------------------------------
/// Count the frequency of each number
///
void CountFrequencyTest() {
	vector<int> A{ 2, 1, 3, 2, 2, 2, 1, 4, 1, 4 };
	        // <num, freq>
	vector<pair<int, int>> result;  // result: [<2, 4>, <1, 3>, <3, 1>, <4, 2>]

	CountFrequency1(A, result);    // O(N^2)
//	CountFrequency2(A, result);    // O(NlogN)
//	CountFrequency3(A, result);    // O(N) with O(N) extra space

	printf("+------+-----+\n");
	printf("|Number|Freq |\n");
	printf("+------+-----+\n");

	for (auto iter = result.begin(); iter != result.end(); iter++) {
		printf("|%6d|%5d|\n", iter->first, iter->second);
	} //end-for

	printf("+------+-----+\n");
} //end-CountFrequencyTest