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

class ArrayExamples {
	static public void main(String argv[]){
		ArrayExamples();
	} //end-main


	///============================================ ARRAYS ================================================
	/// An array is a fixed-size contiguous set of elements. In Java, all arrays are dynamically created
	///
	static void ArrayExamples(){
		// Fixed size dynamic array
		int A[] = new int[] {1, 2, 3, 4, 5};

        int sum = 0;
		for (int i = 0; i < A.length; i++) sum += A[i];  // Add
		System.out.println("Sum of the elements in A: " + sum);
		System.out.println("-----------------------------------------------------------------------------------");

	} //end-ArrayExamples
};