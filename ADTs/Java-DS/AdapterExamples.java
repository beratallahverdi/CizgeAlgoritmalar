///------------------------------------------------------------------------------------
/// For further reference, see: https://www.javatpoint.com/collections-in-java
///------------------------------------------------------------------------------------
/// Broadly speaking, the containers in Java are divided into 4 broad categories:
/// 1. Sequence Containers (a.k.a. lists): ArrayList, LinkedList
/// 2. Associative Containers (a.k.a. balanced trees): TreeSet [Stores just the key values], TreeMap [Stores <key, value> pairs]
/// 3. Unordered Associative Containers (a.k.a. hash tables): HashSet, HashMap
/// 4. Container Adapters: Stack, ArrayDeque, PriorityQueue (a.k.a., binary heap)

import java.util.*;

class AdapterExamples {
	static public void main(String argv[]){
  	    AdapterExamples();   // Stack, Queue, PriorityQueue
	} //end-main

	///====================================== CONTAINER ADAPTERS ================================================
	/// Container adapters are stack, queue (fifo-queue), and priority_queue (binary heap)
	///
	public static void AdapterExamples() {
		///--------------------------------- Stack ----------------------------------------
		System.out.println("Creating a lilo Stack...");

		Stack<Integer> S = new Stack<Integer>();

		System.out.println("push(4)");
		S.push(4);

		System.out.println("push(3)");
		S.push(3);

		System.out.println("push(7)");
		S.push(7);

		System.out.println("push(1)");
		S.push(1);

		System.out.println("push(9)");
		S.push(9);

		System.out.println("Number of elements in the stack: " + S.size());
		System.out.println("Element at the top of the stack: " + S.peek());
		System.out.println("Removing the top element of the stack.");
		System.out.println("Element at the top of the stack now: " + S.pop());
		System.out.println("Is the stack empty? " + (S.empty()? "Yes" : "No"));

		System.out.println("Removing the stack elements in order: ");
		while (!S.empty()) {
			System.out.print(S.pop() + ", ");
		} //end-while
		System.out.println();
		System.out.println("Is the stack empty? " + (S.empty() ? "Yes" : "No"));
		System.out.println("----------------------------------------------------------");

		///------------------------ queue ---------------------------------
		System.out.println("Creating a fifo queue...");

		Queue<Integer> Q = new LinkedList<>();

		System.out.println("Enqueue(4)");
		Q.add(4);

		System.out.println("Enqueue(3)");
		Q.add(3);

		System.out.println("Enqueue(7)");
		Q.add(7);

		System.out.println("Enqueue(1)");
		Q.add(1);

		System.out.println("Enqueue(9)");
		Q.add(9);
		System.out.println("Number of elements in the queue: " + Q.size());
		System.out.println("Element at the front of the queue: " + Q.peek());
		System.out.println("Removing the front element of the queue.");
		System.out.println("Element at the front of the queue now: " + Q.remove());
		System.out.println("Is the queue empty? " + (Q.isEmpty() ? "Yes" : "No"));

		System.out.print("Removing the queue elements in order: ");
		while (!Q.isEmpty()) {
			System.out.print(Q.remove() + ", ");
		} //end-while
		System.out.println();
		System.out.println("Is the queue empty? " + (Q.isEmpty() ? "Yes" : "No"));
		System.out.println("----------------------------------------------------------");

		///------------------------ deque ---------------------------------
		System.out.println("Creating a deque...");
		Deque<Integer> dq = new LinkedList<Integer>();

		System.out.println("addLast(4)");
		dq.addLast(4);

		System.out.println("addLast(7)");
		dq.addLast(7);

		System.out.println("addFirst(9)");
		dq.addFirst(9);

		System.out.println("addFirst(11)");
		dq.addFirst(11);

		System.out.println("Number of elements in the deque: " + dq.size());
		System.out.println("Element at the front of the deque: " + dq.peekFirst());
		System.out.println("Element at the end of the deque: " + dq.peekLast());
		System.out.println("Removing the front element of the deque.");
		dq.removeFirst();
		System.out.println("Element at the front of the deque now: " + dq.peekFirst());

		System.out.println("Removing the last element of the deque.");
		dq.removeLast();
		System.out.println("Element at the front of the deque now: " + dq.peekLast());		
		System.out.println("Is the deque empty? " + (dq.isEmpty() ? "Yes" : "No"));

		System.out.print("Removing the deque elements from the front end: ");
		while (!dq.isEmpty()) {
			System.out.print(dq.removeFirst() + ", ");
		} //end-while
		System.out.println();
		System.out.println("Is the deque empty? " + (dq.isEmpty() ? "Yes" : "No"));
		System.out.println("----------------------------------------------------------");			

		///------------------------ priority queue ---------------------------------
		System.out.println("Creating a min-heap...");
		PriorityQueue<Integer> H = new PriorityQueue<>();

		System.out.println("Insert(4)");
		H.add(4);

		System.out.println("Insert(3)");
		H.add(3);

		System.out.println("Insert(7)");
		H.add(7);

		System.out.println("Insert(1)");
		H.add(1);

		System.out.println("Insert(9)");
		H.add(9);
		System.out.println("Number of elements in the heap: " + H.size());
		System.out.println("Element at the top of the heap: " + H.peek());
		System.out.println("Removing the top element of the heap.");
		System.out.println("Element at the top of the heap now: " + H.poll());
		System.out.println("Is the heap empty? " + (H.size() == 0 ? "Yes" : "No"));

		System.out.print("Removing the heap elements in order: ");
		while (H.size() > 0) {
			System.out.print(H.poll() + ", ");
		} //end-while
		System.out.println();
		System.out.println("Is the heap empty? " + (H.size() == 0 ? "Yes" : "No"));
		System.out.println("----------------------------------------------------------");

		///----------------------------------------------------------
		System.out.println("Creating a max-heap...");
		PriorityQueue<Integer> H2 = new PriorityQueue<>((x, y) -> Integer.compare(y, x)); // Lambda comparator

		System.out.println("Insert(4)");
		H2.add(4);

		System.out.println("Insert(3)");
		H2.add(3);

		System.out.println("Insert(7)");
		H2.add(7);

		System.out.println("Insert(1)");
		H2.add(1);

		System.out.println("Insert(9)");
		H2.add(9);
		System.out.println("Number of elements in the heap: " + H2.size());
		System.out.println("Element at the top of the heap: " + H2.peek());
		System.out.println("Removing the top element of the heap.");
		System.out.println("Element at the top of the heap now: " + H2.poll());
		System.out.println("Is the heap empty? " + (H2.size() == 0 ? "Yes" : "No"));

		System.out.print("Removing the heap elements in order: ");
		while (H2.size() > 0) {
			System.out.print(H2.poll() + ", ");
		} //end-while
		System.out.println();
		System.out.println("Is the heap empty? " + (H2.size() == 0 ? "Yes" : "No"));
		System.out.println("----------------------------------------------------------");
	} //end-AdapterExamples

};