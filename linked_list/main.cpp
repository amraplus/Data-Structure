#include <iostream>
using namespace std;

// Node class representing a single node in the linked list
template <class type>
class Node {
public:
    type info; // Data stored in the node
    Node* next; // Pointer to the next node
    Node() : next(NULL) {} // Constructor initializing next to NULL
};

// LinkedList class representing a linked list
template <class type>
class LinkedList {
public:
    Node<type>* head; // Pointer to the head of the list

    LinkedList() : head(NULL) {} // Constructor initializing head to NULL

    // Function to check if the list is empty
    bool isEmpty() {
        return (head == NULL);
    }

    // Function to traverse and display the elements of the linked list
    void traverse() {
        if (isEmpty()) {
            cout << "The Linked List is Empty.\n";
        } else {
            Node<type>* temp = head; // Start from the head
            while (temp != NULL) {
                cout << temp->info << " "; // Print node data
                temp = temp->next; // Move to the next node
            }
            cout << endl;
        }
    }

    // Function to insert an element at the beginning of the list
    void insertFirst(type item) {
        Node<type>* newNode = new Node<type>();
        newNode->info = item;
        newNode->next = head; // Point new node to the current head
        head = newNode; // Update head to the new node
        cout << "successfully added.\n";
    }

    // Function to insert an element at the end of the list
    void insertLast(type item) {
        if (isEmpty()) {
            insertFirst(item); // If list is empty, insert at the beginning
        } else {
            Node<type>* newNode = new Node<type>();
            newNode->info = item;
            Node<type>* temp = head; // Start from the head
            while (temp->next != NULL) {
                temp = temp->next; // Traverse to the last node
            }
            temp->next = newNode; // Link the last node to the new node
            cout << "successfully added.\n";
        }
    }

    // Function to insert an element at a specific index
    void insertAt(int index, type item) {
        if (index < 0 || index > count()) { // Check for invalid index
            cout << "out of range.\n";
            return;
        }
        if (index == 0) {
            insertFirst(item); // Insert at the beginning
        } else if (index == count()) {
            insertLast(item); // Insert at the end
        } else {
            Node<type>* newNode = new Node<type>();
            newNode->info = item;
            Node<type>* temp = head;
            for (int pos = 0; pos < index - 1; pos++) {
                temp = temp->next; // Traverse to the position before the index
            }
            newNode->next = temp->next; // Link new node to the next node
            temp->next = newNode; // Link previous node to the new node
            cout << "successfully added.\n";
        }
    }

    // Function to count the number of nodes in the list
    int count() {
        int counter = 0;
        Node<type>* temp = head;
        while (temp != NULL) {
            counter++;
            temp = temp->next;
        }
        return counter;
    }

    // Function to check if a specific element exists in the list
    bool isFound(type item) {
        Node<type>* temp = head;
        while (temp != NULL) {
            if (temp->info == item) {
                return true; // Element found
            }
            temp = temp->next;
        }
        return false; // Element not found
    }

    // Function to delete a specific element from the list
    void Delete(type item) {
        if (isEmpty()) {
            cout << "This Linked List Is Empty.\n";
            return;
        }
        if (!isFound(item)) {
            cout << "This Element Not Found.\n";
            return;
        }
        Node<type>* temp = head;
        if (head->info == item) { // If the element is at the head
            head = head->next;
            delete temp;
        } else {
            Node<type>* ptr;
            while (temp->next->info != item) {
                temp = temp->next; // Traverse to the node before the target
            }
            ptr = temp->next; // Target node to delete
            temp->next = ptr->next; // Update link to skip target node
            delete ptr;
        }
        cout << "successfully deleted.";
    }

    // Function to sort the linked list using bubble sort
    void sort() {
        bool swapped;
        do {
            swapped = false;
            Node<type>* temp = head;
            while (temp->next != NULL) {
                if (temp->info > temp->next->info) { // Swap if out of order
                    type tempData = temp->info;
                    temp->info = temp->next->info;
                    temp->next->info = tempData;
                    swapped = true;
                }
                temp = temp->next;
            }
        } while (swapped);
    }
};

// Main function to test the LinkedList class
int main() {
    LinkedList<int> list;

    // Test inserting elements at the beginning
    list.insertFirst(10);
    list.insertFirst(20);
    list.insertFirst(30);
    list.traverse();

    // Test inserting elements at the end
    list.insertLast(40);
    list.insertLast(50);
    list.traverse();

    // Test inserting at a specific index
    list.insertAt(2, 25);
    list.traverse();

    // Check element existence
    cout << (list.isFound(20) ? "Yes, it found.\n" : "No, it not found.\n");

    // Delete an element
    list.Delete(50);
    cout<< endl;
    list.traverse();

    // Sort the list
    list.sort();
    list.traverse();

    return 0;
}
