#include <iostream> 
#include <algorithm> 
#include <iterator> 
#include <string> 
#include <vector>
#include <map>
#include <unordered_map>
using namespace std;  // If you omit this, then you have to refer to classes imported from std as std::, e.g., std::cout, std:array etc.

///====================================== ASSOCIATIVE CONTAINERS: MAP ================================================
/// Associative Containers: map, multimap [both O(logn)], unordered_map, unordered_multimap [both expected O(1)]
///
void PrintMap(map<int, string> &map1) {
	cout << "Map elements: ";
	for (auto iter : map1) {
		cout << "[" << iter.first << ", " << iter.second << "], ";
	} //end-for
	cout << endl;
} //end-PrintMap

void PrintMap(multimap<int, string> &map1) {
	cout << "Map elements: ";
	for (auto iter : map1) {
		cout << "[" << iter.first << ", " << iter.second << "], ";
	} //end-for
	cout << endl;
} //end-PrintMap

void PrintMap(unordered_map<int, string> &map1) {
	cout << "Map elements: ";
	for (auto iter : map1) {
		cout << "[" << iter.first << ", " << iter.second << "], ";
	} //end-for
	cout << endl;
} //end-PrintMap

void PrintMap(unordered_multimap<int, string> &map1) {
	cout << "Map elements: ";
	for (auto iter : map1) {
		cout << "[" << iter.first << ", " << iter.second << "], ";
	} //end-for
	cout << endl;
} //end-PrintMap

void MapExamples() {
#if 0
	cout << "ordered map example..." << endl;

	map<int, string> om;

	cout << "Insert(4, Ali)" << endl;
	om.insert(make_pair(4, "Ali"));

	cout << "Insert(3, Veli)" << endl;
	om.insert(make_pair(3, "Veli"));

	cout << "Insert(7, Ayse)" << endl;
	om.insert(make_pair(7, "Ayse"));

	cout << "Insert(1, Gul)" << endl;
	om.insert(make_pair(1, "Gul"));

	cout << "Insert(9, Cem)" << endl;
	om.insert(make_pair(9, "Cem"));

	cout << "Number of elements in the map: " << om.size() << endl;
	PrintMap(om);

	cout << "Erasing 7..." << endl;
	om.erase(7);
	PrintMap(om);

	cout << "Inserting (2, Hasan)..." << endl;
	om.insert(make_pair(2, "Hasan"));
	PrintMap(om);

	cout << "Inserting (2, Huseyin)!" << endl;
	om.insert(make_pair(2, "Huseyin"));
	PrintMap(om);

	cout << "Does the map contain 1? ";
	auto it = om.find(1);
	if (it == om.end()) cout << "No" << endl;
	else                cout << "Yes. [1, " << it->second << "]" << endl;

	cout << "--------------------------------------------------------" << endl;
#endif

#if 0
	cout << "ordered multimap example..." << endl;

	multimap<int, string> omm;

	cout << "Insert(4, Ali)" << endl;
	omm.insert(make_pair(4, "Ali"));

	cout << "Insert(3, Veli)" << endl;
	omm.insert(make_pair(3, "Veli"));

	cout << "Insert(7, Ayse)" << endl;
	omm.insert(make_pair(7, "Ayse"));

	cout << "Insert(1, Gul)" << endl;
	omm.insert(make_pair(1, "Gul"));

	cout << "Insert(9, Cem)" << endl;
	omm.insert({ 9, "Cem" });  // {} is the same as make_pair

	cout << "Number of elements in the set: " << omm.size() << endl;
	PrintMap(omm);

	cout << "Erasing 7..." << endl;
	omm.erase(7);
	PrintMap(omm);

	cout << "Inserting (2, Hasan)..." << endl;
	omm.insert(make_pair(2, "Hasan"));
	PrintMap(omm);

	cout << "Inserting (2, Huseyin)..." << endl;
	omm.insert(make_pair(2, "Huseyin"));
	PrintMap(omm);

	cout << "Inserting (9, Oya)..." << endl;
	omm.insert(make_pair(9, "Oya"));
	PrintMap(omm);

	cout << "Inserting (9, Kadir)..." << endl;
	omm.insert(make_pair(9, "Kadir"));
	PrintMap(omm);

	cout << "Looking for 2: ";
	for (auto it = omm.find(2); it != omm.end(); it++) {
		if (it->first != 2) break;
		cout << "[2, " << it->second << "], ";
	} //end-for
	cout << endl;

	cout << "-----------------------------------------------------" << endl;
#endif

#if 0
	cout << "unordered map example..." << endl;

	unordered_map<int, string> uom;

	cout << "Insert(4, Ali)" << endl;
	uom.insert(make_pair(4, "Ali"));

	cout << "Insert(3, Veli)" << endl;
	uom.insert(make_pair(3, "Veli"));

	cout << "Insert(7, Ayse)" << endl;
	uom.insert(make_pair(7, "Ayse"));

	cout << "Insert(1, Gul)" << endl;
	uom.insert(make_pair(1, "Gul"));

	cout << "Insert(9, Cem)" << endl;
	uom.insert(make_pair(9, "Cem"));

	cout << "Number of elements in the map: " << uom.size() << endl;
	PrintMap(uom);

	cout << "Erasing 7..." << endl;
	uom.erase(7);
	PrintMap(uom);

	cout << "Inserting (2, Hasan)..." << endl;
	uom.insert(make_pair(2, "Hasan"));
	PrintMap(uom);

	cout << "Inserting (2, Huseyin)!" << endl;
	uom.insert(make_pair(2, "Huseyin"));
	PrintMap(uom);

	cout << "Does the map contain 1? ";
	auto it3 = uom.find(1);
	if (it3 == uom.end()) cout << "No" << endl;
	else                  cout << "Yes. [1, " << it3->second << "]" << endl;

	cout << "-------------------------------------------------------" << endl;
#endif

#if 1
	cout << "unordered multimap example..." << endl;

	unordered_multimap<int, string> umm;

	cout << "Insert(4, Ali)" << endl;
	umm.insert(make_pair(4, "Ali"));

	cout << "Insert(3, Veli)" << endl;
	umm.insert(make_pair(3, "Veli"));

	cout << "Insert(7, Ayse)" << endl;
	umm.insert(make_pair(7, "Ayse"));

	cout << "Insert(1, Gul)" << endl;
	umm.insert(make_pair(1, "Gul"));

	cout << "Insert(9, Cem)" << endl;
	umm.insert({ 9, "Cem" });  // {} is the same as make_pair

	cout << "Number of elements in the set: " << umm.size() << endl;
	PrintMap(umm);

	cout << "Erasing 7..." << endl;
	umm.erase(7);
	PrintMap(umm);

	cout << "Inserting (2, Hasan)..." << endl;
	umm.insert(make_pair(2, "Hasan"));
	PrintMap(umm);

	cout << "Inserting (2, Huseyin)..." << endl;
	umm.insert(make_pair(2, "Huseyin"));
	PrintMap(umm);

	cout << "Inserting (9, Oya)..." << endl;
	umm.insert(make_pair(9, "Oya"));
	PrintMap(umm);

	cout << "Inserting (9, Kadir)..." << endl;
	umm.insert(make_pair(9, "Kadir"));
	PrintMap(umm);

	cout << "Looking for 9: ";
	for (auto it = umm.find(9); it != umm.end(); it++) {
		if (it->first != 9) break;
		cout << "[9, " << it->second << "], ";
	} //end-for
	cout << endl;
#endif
} //end-MapExamples
