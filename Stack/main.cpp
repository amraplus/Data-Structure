#include <iostream>

using namespace std;

template <class type>
class Node
{
public:
    type info;
    Node<type>* next;
    Node():next(NULL){}
};

template <class type>
class Stack
{
public:
    Node<type>* top;
    Stack():top(NULL){}
    bool isEmpty()
    {
        if (top==NULL)
        {
            return true;
        }
        return false;
    }
    void push(type item)
    {
        Node<type>* newnode = new Node<type>();
        newnode->info = item;
        if(isEmpty())
        {
            top = newnode;
        }
        else
        {
            newnode->next = top;
            top = newnode;
        }
    }
    void traverse()
    {
        Node<type>* temp = top;
        if(isEmpty())
        {
            cout<< "the stack is empty\n";
            return;
        }
        while(temp != NULL)
        {
            cout<< temp->info << " ";
            temp = temp->next;
        }
        cout<< endl;
    }
    type pop()
    {
        Node<type>* temp = top;
        type value = temp->info;
        top = top->next;
        delete temp;
        temp = NULL;
        return value;
    }
    void peek()
    {
        cout << "the top element in the stack is: "<< top->info<< endl;
    }
    bool isFound(type item)
    {
        Node<type>* temp = top;
        bool found = false;
        while(temp != NULL)
        {
            if (temp->info==item)
            {
                found = true;
                return found;
            }
            temp = temp->next;
        }
        return found;
    }
    int count()
    {
        Node<type>* temp = top;
        int counter = 0;
        while(temp!=NULL)
        {
            counter++;
            temp = temp->next;
        }
        return counter;
    }
};


int main()
{
    Stack<int> myStack;

    // Test isEmpty() on an empty stack
    if (myStack.isEmpty())
        cout << "The stack is empty.\n";

    // Push some elements onto the stack
    myStack.push(10);
    myStack.push(20);
    myStack.push(30);

    // Traverse and print the stack
    cout << "Stack elements after pushing: ";
    myStack.traverse();

    // Check the top element using peek()
    myStack.peek();

    // Test isFound()
    int searchValue = 20;
    if (myStack.isFound(searchValue))
        cout << "Value " << searchValue << " is found in the stack.\n";
    else
        cout << "Value " << searchValue << " is not found in the stack.\n";

    // Test count()
    cout << "Number of elements in the stack: " << myStack.count() << endl;

    // Pop an element and display it
    cout << "Popped element: " << myStack.pop() << endl;

    // Traverse the stack after popping
    cout << "Stack elements after popping: ";
    myStack.traverse();

    // Check the top element again
    myStack.peek();

    // Test isEmpty() after popping elements
    myStack.pop();
    myStack.pop();
    if (myStack.isEmpty())
        cout << "The stack is now empty.\n";

    return 0;
}
