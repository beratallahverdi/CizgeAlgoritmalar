/*
 * www.cppquiz.com: Contains many quizzes in C++
 */
#include <stdio.h>
#include <iostream> 
#include <stdlib.h>
#include <algorithm> 
#include <array> 
#include <iterator> 
#include <string> 
#include <vector>
#include <stack>
#include <queue>
using namespace std;  // If you omit this, then you have to refer to classes imported from std as std::, e.g., std::cout, std:array etc.

///------------------------------------------------------------------------------------
/// For further reference, see: https://en.cppreference.com/w/cpp/container
///------------------------------------------------------------------------------------
/// Broadly speaking, the containers in C++ are divided into 4 broad categories:
/// 1. Sequence Containers (a.k.a. lists): vector, deque, forward_list, list
/// 2. Associative Containers (a.k.a. balanced trees): set, multiset [Stores just the key values], map, multimap [Stores <key, value> pairs]  
/// 3. Unordered Associative Containers (a.k.a. hash tables): unordered_set, unordered_multiset, unordered_map, unordered_multipmap
/// 4. Container Adapters: stack, queue, priority_queue (a.k.a., binary heap)

void ArrayExamples(); // C-Style arrays, array
void ListExamples(); // vector, deque, forward_list, list
void AdapterExamples(); // stack, queue, priority queue
void SetExamples(); // set, multiset [Insert, delete, search all run in O(logn) time], unordered_set, unordered_multiset [Insert, delete, search all run in expected O(1) time]
void MapExamples(); // map, multimap [Insert, delete, search all run in O(logn) time], unordered_map, unordered_multimap [Insert, delete, search all run in expected O(1) time]

void main() {
//	ArrayExamples(); // C-Style arrays, std::array
	ListExamples();  // vector, forward_list, list
//	AdapterExamples(); // stack, queue, deque, priority_queue
//	SetExamples(); // set, multiset [Insert, delete, search all run in O(logn) time], unordered_set, unordered_multiset [Insert, delete, search all run in expected O(1) time]
//	MapExamples(); // map, multimap [Insert, delete, search all run in O(logn) time], unordered_map, unordered_multimap [Insert, delete, search all run in expected O(1) time]

} //end-main
