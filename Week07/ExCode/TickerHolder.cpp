#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <array>
#include <vector>
#include <list>
#include <unordered_map>

using namespace std;

///================== TICKER HOLDER TEST =========================
/// You are given a stream of stock exchange transactions events
/// (MCFT, 25), (INTC, 49), (GOGL, 55), (APPL, 100)
/// You are to design a thread - safe DS that supports insert, remove, and find operations.
/// Remove must be in the arrival order(FIFO)
/// Also, if a new event that already exists in the DS comes in, you simply update its price without inserting it into the DS.
/// For example, if a(GOGL, 65) arrives, we simply update the existing(GOGL, 55) to(GOGL, 65) without inserting a new event into the DS.
/// All operations must run in O(1).
///
struct Ticker {
	string name;
	int price;

	Ticker(string _name, int _price) { name = _name; price = _price; }
};

///--------------------------------------------------------------------------------------
/// In this version of the DS, we store all information related to the ticker inside an unordered_map.
///
struct TickerHolder1 {
	list<string> Q;                  // Queue of string keys
	unordered_map<string, int> map;  // A map of Tickers

	bool empty() {
		return Q.size() == 0;
	} //end-empty

	void insert(Ticker& ticker) {
		// Look it up in the map
		auto mapIter = map.find(ticker.name);
		if (mapIter == map.end()) {
			// Insert the ticker to the map
			map.insert(make_pair(ticker.name, ticker.price));

			// Append the name of the ticker to the end of the queue
			Q.push_back(ticker.name);

		}
		else {
			// Already exists. Update the price
			mapIter->second = ticker.price;
		} //end-else
	} //end-insert

	Ticker remove() {
		if (empty()) throw exception("Ticker queue is empty");

		string name = *Q.begin();
		Q.pop_front();   // Remove the element at the front

		// Find the price in the map
		auto mapIter = map.find(name);
		Ticker ticker(name, mapIter->second);

		map.erase(mapIter);  // Erase the ticker from the map

		return ticker;
	} //end-remove

	Ticker find(string name) {
		auto mapIter = map.find(name);

		if (mapIter == map.end()) throw exception("Ticker does not exist in the queue");

		Ticker ticker(name, mapIter->second);
		return ticker; // return the ticker
	} //end-find
};

///--------------------------------------------------------------------------------------
/// In this version of the DS, we store all information related to the ticker inside
/// the FIFO queue. We will then store <tickerName, ListIterator> inside the map.
/// Thus, we will have a pointer from the map to the corresponding node in the list
/// During find operation, we will use the map to reach to a node in the list in O(1) time
///
struct TickerHolder2 {
	list<Ticker> Q;   // Queue of tickers
	unordered_map<string, list<Ticker>::iterator> map;  // A map that points to the queue

	bool empty() {
		return Q.size() == 0;
	} //end-empty

	void insert(Ticker& ticker) {
		// Look it up in the map
		auto mapIter = map.find(ticker.name);
		if (mapIter == map.end()) {
			// Append the new ticker to the end of the queue
			auto listIter = Q.insert(Q.end(), ticker);

			// Add the <ticker.name, listIterator> pair to the map
			map.insert(make_pair(ticker.name, listIter));

		}
		else {
			// Already exists. Simply update the price
			auto listIter = mapIter->second;
			listIter->price = ticker.price;
		} //end-else
	} //end-insert

	Ticker remove() {
		if (empty()) throw exception("Ticker queue is empty");

		Ticker ticker = *Q.begin();
		Q.pop_front();   // Remove the element at the front

		// Also remove the ticker from the map
		map.erase(ticker.name);

		return ticker;
	} //end-remove

	Ticker find(string name) {
		auto mapIter = map.find(name);

		if (mapIter == map.end()) throw exception("Ticker does not exist in the queue");

		return *(mapIter->second); // return the ticker
	} //end-find
};

///------------------------------------------------------------
/// Test for Ticker Holder class
///
void TickerHolderTest() {
	try {
//		TickerHolder1 tickerHolder;
		TickerHolder2 tickerHolder;

		vector<Ticker> tickers = { Ticker("MCFT", 25), Ticker("INTC", 49),
								  Ticker("GOGL", 55), Ticker("APPL", 100) };

		for (size_t i = 0; i < tickers.size(); i++) {
			printf("Inserting ticker: name: %s, price: %d\n", tickers[i].name.c_str(), tickers[i].price);
			tickerHolder.insert(tickers[i]);
		} //end-for

		printf("--------------------------------------------\n");

		// Find all tickers
		for (size_t i = 0; i < tickers.size(); i++) {
			Ticker ticker = tickerHolder.find(tickers[i].name);
			printf("Ticker: name: %s, price: %d\n", ticker.name.c_str(), ticker.price);
		} //end-for

		printf("--------------------------------------------\n");

		// Update the value of an existing ticker
		Ticker ticker("MCFT", 30);
		printf("Updating ticker. name: %s, new price: %d\n", ticker.name.c_str(), ticker.price);
		tickerHolder.insert(ticker);

		ticker.name = "GOGL";
		ticker.price = 65;
		printf("Updating ticker. name: %s, new price: %d\n", ticker.name.c_str(), ticker.price);
		tickerHolder.insert(ticker);

		printf("--------------------------------------------\n");

		// Remove all tickers one after the other
		printf("Removing the tickers...\n");
		while (!tickerHolder.empty()) {
			Ticker ticker = tickerHolder.remove();
			printf("Ticker: name: %s, price: %d\n", ticker.name.c_str(), ticker.price);
		} //end-while

	}
	catch (exception& e) {
		cout << "Exception occurred: " << e.what() << endl;
	} // end-catch
} //end-TickerHolderTest
