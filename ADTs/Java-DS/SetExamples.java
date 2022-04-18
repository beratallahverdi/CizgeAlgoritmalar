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

class SetExamples {
	static public void main(String argv[]){
		SetExamples();       // TreeSet, HashSet
	} //end-main

	///====================================== ASSOCIATIVE CONTAINERS: SET ================================================
	/// Associative Containers: TreeSet [O(logn)], HasSet [expected O(1)]
	///
	public static void PrintSet(Set<Integer> set){
		Iterator<Integer> iter = set.iterator();

		while (iter.hasNext()){
			Object o = iter.next();
			System.out.print(o + ", ");
		} // end-while

		System.out.println();
	} //end-PrintSet

	public static void SetExamples(){
		System.out.println("ordered set example...");

		TreeSet<Integer> os = new TreeSet<Integer>();

		System.out.println("Insert(4)");
		os.add(4);

		System.out.println("Insert(3)");
		os.add(3);

		System.out.println("Insert(7)");
		os.add(7);

		System.out.println("Insert(1)");
		os.add(1);

		System.out.println("Insert(9)");
		os.add(9);

		System.out.println("Number of elements in the set: " + os.size());
		PrintSet(os);

		System.out.println("Erasing 7...");
		os.remove(7);
		PrintSet(os);

		System.out.println("Inserting 2...");
		os.add(2);
		PrintSet(os);

		System.out.println("Inserting 2 again!");
		os.add(2);
		PrintSet(os);
		System.out.println("------------------------------------------------------------");

		/* Normally, the elements in a HashSet are not stored in sorted order.
		   But when we iterate over the elements of a HashSet in this example,
		   the set elements are returned in sorted order. It is therefore the Iterator
		   that sorts the elements before returning them
		  */
		System.out.println("unordered_set example...");

		HashSet<Integer> uos = new HashSet<Integer>();

		System.out.println("Insert(4)");
		uos.add(4);

		System.out.println("Insert(3)");
		uos.add(3);

		System.out.println("Insert(7)");
		uos.add(7);

		System.out.println("Insert(1)");
		uos.add(1);

		System.out.println("Insert(9)");
		uos.add(9);

		System.out.println("Number of elements in the set: " + uos.size());
		PrintSet(uos);

		System.out.println("Erasing 7...");
		uos.remove(7);
		PrintSet(uos);

		System.out.println("Inserting 2...");
		uos.add(2);
		PrintSet(uos);

		System.out.println("Inserting 2 again!");
		uos.add(2);
		PrintSet(uos);
		System.out.println("------------------------------------------------------------");
	} //end-SetExamples
};