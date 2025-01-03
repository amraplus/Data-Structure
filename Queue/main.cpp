#include <iostream>
using namespace std;

// Template class for a Node in the queue
template <class type>
class Node
{
public:
    type info;               // Data stored in the node
    Node<type>* next;        // Pointer to the next node
    Node():next(NULL){}      // Constructor initializing the next pointer to NULL
};

// Template class for the Queue
template <class type>
class Queue
{
public:
    Node<type> *head, *rear; // Pointers to the front (head) and back (rear) of the queue
    Queue():head(NULL), rear(NULL){} // Constructor initializing head and rear to NULL

    // Function to check if the queue is empty
    bool isEmpty()
    {
        return head == NULL;
    }

    // Function to add an item to the queue
    void push(type item)
    {
        Node<type>* newNode = new Node<type>(); // Create a new node
        newNode->info = item;                  // Assign data to the new node
        if (isEmpty())                         // If the queue is empty, head and rear are the same
        {
            head = rear = newNode;
        }
        else                                   // Otherwise, add the node to the end
        {
            rear->next = newNode;
            rear = newNode;
        }
    }

    // Function to display the elements of the queue
    void traverse()
    {
        if (isEmpty())
        {
            cout<< "The Queue Is Empty.\n";
        }
        else
        {
            Node<type>* temp = head; // Temporary pointer for traversal
            while (temp != NULL)
            {
                cout << temp->info << " "; // Print each node's data
                temp = temp->next;
            }
            cout << endl;
        }
    }

    // Function to check if an item exists in the queue
    bool isFound(type item)
    {
        Node<type>* temp = head; // Temporary pointer for traversal
        while (temp != NULL)
        {
            if (temp->info == item) // If the item is found, return true
            {
                return true;
            }
            temp = temp->next;
        }
        return false; // If traversal completes without finding the item, return false
    }

    // Function to remove the first item in the queue
    void pop()
    {
        if (isEmpty())
        {
            cout << "The Queue Is Empty.\n";
        }
        else
        {
            Node<type>* temp = head; // Temporary pointer to the head
            cout << "Popped element: " << head->info << endl;
            head = head->next;       // Move the head to the next node
            delete temp;             // Delete the old head
        }
    }

    // Function to display the front element without removing it
    void peek()
    {
        if (isEmpty())
        {
            cout << "The Queue Is Empty.\n";
        }
        else
        {
            cout << "The Top Element Is: " << head->info << endl;
        }
    }

    // Function to delete a specific item from the queue
    void Delete(type item)
    {
        if (isEmpty())
        {
            cout << "The Queue Is Empty.\n";
        }
        else
        {
            if (isFound(item))
            {
                Node<type> *pre, *current = head;

                // Case 1: Item is at the head
                if (head->info == item)
                {
                    head = head->next;
                    if (head == NULL) // If queue becomes empty
                    {
                        rear = NULL;
                    }
                }
                // Case 2: Item is at the rear
                else if (rear->info == item)
                {
                    while (current->next != rear) // Traverse to the second-last node
                    {
                        current = current->next;
                    }
                    rear = current;
                    current->next = NULL;
                }
                // Case 3: Item is in the middle
                else
                {
                    while (current->next->info != item)
                    {
                        current = current->next;
                    }
                    pre = current->next;          // Pointer to the node to be deleted
                    current->next = pre->next;    // Bypass the node to be deleted
                }
                cout << "Successfully deleted.\n";
            }
            else
            {
                cout << "The Element Not Found.\n";
            }
        }
    }

    // Function to count the number of elements in the queue
    int count()
    {
        Node<type>* temp = head; // Temporary pointer for traversal
        int counter = 0;         // Counter variable
        while (temp != NULL)
        {
            counter++;
            temp = temp->next;
        }
        return counter; // Return the total count
    }
};

int main()
{
    // Create a Queue of integers
    Queue<int> myQueue;

    // Check if the queue is empty
    cout << "Is the queue empty? " << (myQueue.isEmpty() ? "Yes" : "No") << endl;

    // Push elements into the queue
    myQueue.push(10);
    myQueue.push(20);
    myQueue.push(30);

    // Display the queue
    cout << "Queue after pushing elements: ";
    myQueue.traverse();

    // Peek the top element
    myQueue.peek();

    // Check if an element is found
    cout << "Is 20 in the queue? " << (myQueue.isFound(20) ? "Yes" : "No") << endl;
    cout << "Is 40 in the queue? " << (myQueue.isFound(40) ? "Yes" : "No") << endl;

    // Pop an element from the queue
    myQueue.pop();

    // Display the queue after popping
    cout << "Queue after popping an element: ";
    myQueue.traverse();

    // Delete a specific element
    myQueue.Delete(20);
    cout << "Queue after deleting 20: ";
    myQueue.traverse();

    // Count the number of elements in the queue
    cout << "Number of elements in the queue: " << myQueue.count() << endl;

    // Delete all elements
    myQueue.pop();
    myQueue.pop(); // Attempting to pop an empty queue

    // Final state of the queue
    cout << "Queue after all operations: ";
    myQueue.traverse();

    return 0;
}
