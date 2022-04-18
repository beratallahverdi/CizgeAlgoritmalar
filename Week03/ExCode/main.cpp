#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <array>
#include <vector>

using namespace std;

void SortTest();

///------------------------------------------------------------------
/// Main function
///
int main() {
    SortTest();
    return 0;
} //end-main

///===================== SORT TEST ==================================
/// Sort Test
///
struct Foo {
    string name;
    int age;

    Foo(string _name, int _age) { name = _name; age = _age; }
};

void Print(array<int, 10> &s) {
    for (auto a : s) {
        printf("%d, ", a);
    } //end-for
    printf("\n");
    printf("------------------------------------------------\n");
} //end-Print

void Print(vector<int> &v) {
    for (auto a : v) {
        printf("%d, ", a);
    } //end-for
    printf("\n");
    printf("------------------------------------------------\n");
} //end-Print

void Print(vector<Foo>& v) {
    for (auto a : v) {
        printf("<%8s, %d>\n", a.name.c_str(), a.age);
    } //end-for
    printf("------------------------------------------------\n");
} //end-Print

void SortTest() {
#if 0
    // array is a fixed size contiguous array of elements
//    array<int, 10> A = { 5, 7, 4, 2, 8, 6, 1, 9, 0, 3};

    // vector is a variable size contiguous array of elements
    vector<int> A = { 5, 7, 4, 2, 8, 6, 1, 9, 0, 3 };

    /// Sort in ascending order
    /// For details on how C++ sort function works, look into 
    /// https://www.geeksforgeeks.org/internal-details-of-stdsort-in-c/
    /// According to this page, sort utility is a hybrid sorting algorithm
    /// For very small data, it uses InsertionSort
    /// For moderate-size data, it uses HeapSort
    /// For large-sized data, it uses QuickSort with MedianOfThree heuristic
    ///
//    sort(A.begin(), A.end());
//    sort(A.begin(), A.end(), std::less<int>());   // Same as above

    Print(A);
#endif

#if 0
    ///----------------------------------------------------------
    /// Sort in descending order
    ///
//    array<int, 10> A = { 5, 7, 4, 2, 8, 6, 1, 9, 0, 3 };
        vector<int> A = { 5, 7, 4, 2, 8, 6, 1, 9, 0, 3 };

    sort(A.begin(), A.end(), std::greater<int>());

    Print(A);
#endif

#if 0
    // We can also supply our own comparison function, which has the following prototype:
    // bool cmp(const Type1 &a, const Type2 &b);
    auto cmp1 = [](int first, int second) { return (first < second); };
    vector<int> v = { 3, 2, 2, 5, 6, 8, 7, 5, 8, 7, 1, 2, 1, 4, 3 };

    // Sort in ascending order
    sort(v.begin(), v.end(), cmp1);

    Print(v);
#endif

#if 0
    // We can also supply our own comparison function, which has the following prototype:
    // bool cmp(const Type1 &a, const Type2 &b);
    auto cmp1 = [](int first, int second) { return (first > second); };
    vector<int> v = { 3, 2, 2, 5, 6, 8, 7, 5, 8, 7, 1, 2, 1, 4, 3 };

    // Sort in descending order
    sort(v.begin(), v.end(), cmp1);

    Print(v);
#endif

#if 1
    /// Sort an array of objects
    vector<Foo> v = { Foo("Veli", 20), Foo("Ali", 20), Foo("Ayse", 18),
                      Foo("Cem", 20), Foo("Fatma", 22), Foo("Zerrin", 18),
                      Foo("Ceren", 20), Foo("Oya", 22)};

    // Sort in ascending order wrt name
    auto cmp1 = [](Foo& first, Foo& second) { return (first.name < second.name); };
    sort(v.begin(), v.end(), cmp1);

    Print(v);

    // Now, sort wrt to age
    auto cmp2 = [](Foo& first, Foo& second) { return (first.age < second.age); };
    sort(v.begin(), v.end(), cmp2);

    Print(v);
#endif
} // end-SortTest
