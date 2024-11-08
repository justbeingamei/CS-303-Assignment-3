// CS-303-Assignment-3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <vector>
#include "Assignment3.h"
using namespace std;

int main() {
    //////////////////////////////////////////////////////////
    // Question 1: Template Queue Class Demonstration
    //////////////////////////////////////////////////////////
    cout << "Question 1: Queue Operations\n";
    Queue<int> queue;

    // Push 10 integer values into the queue
    for (int i = 1; i <= 10; i++) {
        queue.push(i);
    }

    // Display the elements in the queue
    cout << "Queue elements: ";
    queue.display();

    // Move the front element to the rear
    queue.move_to_rear();
    cout << "After moving front element to rear: ";
    queue.display();
    cout << endl;

    //////////////////////////////////////////////////////////
    // Question 2: Recursive Linear Search in a Vector
    //////////////////////////////////////////////////////////
    cout << "Question 2: Recursive Last Occurrence Search\n";
    vector<int> vec = { 1, 2, 3, 4, 3, 5, 3 };
    int target = 3;

    // Find the last occurrence of target in the vector
    int index = recursiveLastOccurrence(vec, target, vec.size() - 1);

    // Display the result
    if (index != -1)
        cout << "Last occurrence of " << target << " is at index " << index << endl;
    else
        cout << "Element not found" << endl;
    cout << endl;

    //////////////////////////////////////////////////////////
    // Question 3: Linked List Insertion Sort
    //////////////////////////////////////////////////////////
    cout << "Question 3: Linked List Insertion Sort\n";
    LinkedList list;

    // Add values to the list
    list.push(3);
    list.push(1);
    list.push(4);
    list.push(2);
    list.push(5);

    // Display original list
    cout << "Original list: ";
    list.display();

    // Sort the list using insertion sort
    list.insertionSort();
    cout << "Sorted list: ";
    list.display();

    return 0;
}


