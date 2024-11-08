#ifndef ASSIGNMENT3_H
#define ASSIGNMENT3_H

#include <iostream>
#include <vector>
using namespace std;

//////////////////////////////////////////////////////////
// Question 1: Template Queue Class Implementation
//////////////////////////////////////////////////////////

template <typename T>
class Queue {
private:
    struct Node {
        T data;
        Node* next;
        Node(T value) : data(value), next(nullptr) {} // Node constructor
    };

    Node* headptr;  // Pointer to the front of the queue
    Node* tailptr;   // Pointer to the rear of the queue
    int count;        // Number of elements in the queue

public:
    Queue() : headptr(nullptr), tailptr(nullptr), count(0) {} // Constructor

    // Adds an element to the rear of the queue
    void push(T value) {
        Node* newNode = new Node(value);
        if (tailptr) tailptr->next = newNode;
        tailptr = newNode;
        if (!headptr) headptr = tailptr;
        count++;
    }

    // Removes the element from the front of the queue
    void pop() {
        if (empty()) return;
        Node* temp = headptr;
        headptr = headptr->next;
        if (!headptr) tailptr = nullptr;
        delete temp;
        count--;
    }

    // Returns the element at the front of the queue
    T front() {
        if (!empty()) return headptr->data;
        throw runtime_error("Queue is empty");
    }

    // Checks if the queue is empty
    bool empty() {
        return count == 0;
    }

    // Returns the number of elements in the queue
    int size() {
        return count;
    }

    // Moves the front element to the rear of the queue
    void move_to_rear() {
        if (empty()) return;
        T frontValue = front(); // Store the front element
        pop();                  // Remove the front element
        push(frontValue);       // Add it to the rear
    }

    // Displays all elements in the queue
    void display() {
        Node* current = headptr;
        while (current) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    ~Queue() {
        while (!empty()) pop();
    }
};

//////////////////////////////////////////////////////////
// Question 2: Recursive Linear Search in a Vector
//////////////////////////////////////////////////////////

// Recursive function to find the last occurrence of a target in a vector
int recursiveLastOccurrence(const vector<int>& vec, int target, int index) {
    if (index < 0) return -1;            // Base case for no occurrence
    if (vec[index] == target) return index; // Base case for match found
    return recursiveLastOccurrence(vec, target, index - 1); // Recursive case
}

//////////////////////////////////////////////////////////
// Question 3: Linked List with Insertion Sort
//////////////////////////////////////////////////////////

// Node structure for the linked list
struct Node {
    int data;
    Node* next;
    Node(int value) : data(value), next(nullptr) {} // Node constructor
};

// LinkedList class to manage nodes and sorting
class LinkedList {
private:
    Node* head;

public:
    LinkedList() : head(nullptr) {} // Constructor

    // Adds a new node at the end of the list
    void push(int value) {
        Node* newNode = new Node(value);
        if (!head) {
            head = newNode;
            return;
        }
        Node* current = head;
        while (current->next) {
            current = current->next;
        }
        current->next = newNode;
    }

    // Sorts the list using insertion sort
    void insertionSort() {
        Node* sorted = nullptr; // Start with an empty sorted list
        Node* current = head;

        // Traverse the original list
        while (current) {
            Node* next = current->next; // Store next node
            if (!sorted || sorted->data >= current->data) {
                // Insert current node in the beginning of sorted list
                current->next = sorted;
                sorted = current;
            }
            else {
                // Locate the node before the point of insertion
                Node* temp = sorted;
                while (temp->next && temp->next->data < current->data) {
                    temp = temp->next;
                }
                current->next = temp->next;
                temp->next = current;
            }
            current = next;
        }

        head = sorted; // Update head to point to sorted list
    }

    // Displays the linked list
    void display() {
        Node* current = head;
        while (current) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    ~LinkedList() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

#endif
