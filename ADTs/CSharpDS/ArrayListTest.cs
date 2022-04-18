using System;
using System.Collections.Generic;
using System.Collections;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CSharpDS
{
    public class ArrayListTest
    {
        /// <summary>
        /// Prints the list elements on the screen
        /// </summary>
        /// <param name="list"></param>
        public static void PrintList(List<int> list)
        {
            Console.Write("List has <" + list.Count + "> elements. They are: ");
            foreach (int i in list)
            {
                Console.Write(i);
                Console.Write(", ");
            } //end-foreach

            Console.Write("\n------------------------------------------------\n");
        } //end-PrintList

        /// <summary>
        /// Test method for ArrayList class
        /// </summary>
        public static void Test()
        {
            List<int> list = new List<int>();

            Console.WriteLine("Appending 3");
            list.Add(3);           // List: 3

            Console.WriteLine("Appending 5");
            list.Add(5);           // List: 3, 5

            Console.WriteLine("Adding 7 at the beginning");
            list.Insert(0, 7);     // List: 7, 3, 5

            Console.WriteLine("Adding 9 at index 1");
            list.Insert(1, 9);     // List: 7, 9, 3, 5

            Console.WriteLine("Appending 8");
            list.Add(8);     // List: 7, 9, 3, 5, 8

            PrintList(list);

            Console.WriteLine("Removing the item at index 2");
            list.RemoveAt(2);

            PrintList(list);

            Console.WriteLine("Sorting the elements of the array.");
            list.Sort();
            PrintList(list);

            Console.WriteLine("Removing item 8");
            list.Remove(8);
            PrintList(list);
        } //end-ArrayListTest
    }
}
