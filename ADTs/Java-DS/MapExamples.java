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

class MapExamples {
	static public void main(String argv[]){
		MapExamples();       // TreeMap, HashMap
	} //end-main

	///====================================== ASSOCIATIVE CONTAINERS: MAP ================================================
	/// Associative Containers: TreeMap [both O(logn)], HashMap [both expected O(1)]
	///
	public static void PrintMap(Map<Integer, String> map) {
		System.out.print("Map elements: ");

		Set<Map.Entry<Integer, String>> setOfEntries = map.entrySet();
		Iterator<Map.Entry<Integer, String>> iter = setOfEntries.iterator();

		while (iter.hasNext()){
			Map.Entry<Integer, String> o = iter.next();
			System.out.print("[" + o.getKey() + ", " + o.getValue() + "], ");
		} // end-while

		System.out.println();
	} //end-PrintMap

	public static void MapExamples() {
		System.out.println("ordered map example...");

		TreeMap<Integer, String> om = new TreeMap<Integer, String>();

		System.out.println("Insert(4, Ali)");
		om.put(4, "Ali");

		System.out.println("Insert(3, Veli)");
		om.put(3, "Veli");

		System.out.println("Insert(7, Ayse)");
		om.put(7, "Ayse");

		System.out.println("Insert(1, Gul)");
		om.put(1, "Gul");

		System.out.println("Insert(9, Cem)");
		om.put(9, "Cem");

		System.out.println("Number of elements in the map: " + om.size());
		PrintMap(om);

		System.out.println("Erasing 7...");
		om.remove(7);
		PrintMap(om);

		System.out.println("Inserting (2, Hasan)...");
		om.put(2, "Hasan");
		PrintMap(om);

		System.out.println("Inserting (2, Huseyin)!");
		om.put(2, "Huseyin");
		PrintMap(om);

		System.out.println("Does the map contain 1? ");
		String s = (String)om.get(1);
		if (s == null) System.out.println("No");
		else           System.out.println("Yes. [1, " + s + "]");

		System.out.println("------------------------------------------------------------");
		/* Normally, the elements in a HashMap are not stored in sorted order.
		   But when we iterate over the elements of a HashMap in this example,
		   the set elements are returned in sorted order with respect to the key value.
		   It is the map.entrySet() method that sorts the elements before returning them.
		  */

		System.out.println("unordered map example...");

		HashMap<Integer, String> uom = new HashMap<Integer, String>();

		System.out.println("Insert(4, Ali)");
		uom.put(4, "Ali");

		System.out.println("Insert(3, Veli)");
		uom.put(3, "Veli");

		System.out.println("Insert(7, Ayse)");
		uom.put(7, "Ayse");

		System.out.println("Insert(1, Gul)");
		uom.put(1, "Gul");

		System.out.println("Insert(9, Cem)");
		uom.put(9, "Cem");

		System.out.println("Number of elements in the map: " + uom.size());
		PrintMap(uom);

		System.out.println("Erasing 7...");
		uom.remove(7);
		PrintMap(uom);

		System.out.println("Inserting (2, Hasan)...");
		uom.put(2, "Hasan");
		PrintMap(uom);

		System.out.println("Inserting (2, Huseyin)!");
		uom.put(2, "Huseyin");
		PrintMap(uom);

		System.out.println("Does the map contain 1? ");
		String s1 = (String)uom.get(1);
		if (s1 == null) System.out.println("No");
		else            System.out.println("Yes. [1, " + s1 + "]");

		System.out.println("------------------------------------------------------------");
	} //end-MapExamples
};