///------------------------------------------------------------------------------------
/// For further reference, see: https://www.javatpoint.com/collections-in-java
///------------------------------------------------------------------------------------
/// Broadly speaking, the containers in Java are divided into 4 broad categories:
/// 1. Sequence Containers (a.k.a. lists): ArrayList, LinkedList
/// 2. Associative Containers (a.k.a. balanced trees): TreeSet [Stores just the key values], TreeMap [Stores <key, value> pairs]
/// 3. Unordered Associative Containers (a.k.a. hash tables): HashSet, HashMap
/// 4. Container Adapters: Stack, ArrayDeque, PriorityQueue (a.k.a., binary heap)

import java.io.*;
import java.util.*;
import java.util.function.*;

class ListExamples {
	static public void main(String argv[]){
		ListExamples();      // ArrayList, LinkedList
	} //end-main

	///============================================= LISTS ================================================
	/// A list or sequence is an abstract data type that represents a countable number of ORDERED values,
	/// where the same value may occur more than once.If the same value occurs multiple times,
	/// each occurrence is considered a distinct item. Unlike fixed-size arrays, lists grow and shrink dynamically.
	///
	/// Java offers 2 different implementation of lists:
	/// 1. Using arrays: ArrayList
	/// 2. Using linked lists: LinkedList
	///
	static void PrintList(List list){
		System.out.print(list.size() + " elements in forward order: ");


		Iterator iter = list.iterator();
		while (iter.hasNext()){
			Object o = iter.next();
			System.out.print(o + ", ");
		} // end-while

//		list.forEach(o->System.out.print(o + ", "));   // The same loop using a lambda expression
		System.out.println();
	} //end-PrintList

	static void ListExamples(){
		List<Integer> list = new ArrayList<Integer>(5);  // 5 is the initial capacity
//        List<Integer> list = new LinkedList<Integer>();

		System.out.println("list.size(): " + list.size());


		System.out.println("Appending 3");
		list.add(3); // Append at the end. List content: 3

		System.out.println("Appending 2");
		list.add(2); // Append at the end. List content: 3, 2

		System.out.println("Appending 5");
		list.add(5); // Append at the end. List content: 3, 2, 5

		System.out.println("Appending 7");
		list.add(7); // Append at the end. List content: 3, 2, 5, 7

		System.out.println("Appending 1");
		list.add(1); // Append at the end. List content: 3, 2, 5, 7, 1

		System.out.println("Appending 9");
		list.add(9); // Append at the end. List content: 3, 2, 5, 7, 1, 9

		System.out.println("Inserting 6 at the beginning");
		list.add(0, 6); // Append at the end. List content: 6, 3, 2, 5, 7, 1, 9

		PrintList(list);


		// Access ArrayList elements
		System.out.println("al[2]: " + list.get(2) + ", al[5]: " + list.get(5));

		// Delete the last element
		System.out.println("After deleting the last element:");
		list.remove(list.size()-1);  // Need to specify the index
		PrintList(list);

		System.out.println("After deleting the element at index 3:");
		list.remove(3);
		PrintList(list);

		// Insert at an arbitrary index
		System.out.println("After inserting 4 at index 2:");
		list.add(2, Integer.valueOf(4));
		PrintList(list);
	} // end-ListExamples

};