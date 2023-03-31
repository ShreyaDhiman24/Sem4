// II.	Write a c++ program to implement QUEUE using Linked List that performs following operations
// INSERT - Inserts an element at the end of the queue.
// DELETE - Removes the element from the front of the queue.
// DISPLAY - Displays the elements in the queue.
#include<iostream>
using namespace std;

// Node class for Linked List implementation
class Node {
public:
    int data;
    Node* next;
};

// Queue class
class Queue {
private:
    Node* front;
    Node* rear;
public:
    Queue() {
        front = NULL;
        rear = NULL;
    }

    // Insert operation
    void insert(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = NULL;

        if (front == NULL) {
            front = nrear = newNode;
            ewNode;
        }
        else {
            rear->next = newNode;
            rear = newNode;
        }
        cout << "Inserted " << value << " in the queue." << endl;
    }

    // Delete operation
    void remove() {
        if (front == NULL) {
            cout << "Queue is empty." << endl;
        }
        else {
            Node* temp = front;
            cout << "Removed " << front->data << " from the queue." << endl;
            front = front->next;
            delete temp;
        }
    }

    // Display operation
    void display() {
        if (front == NULL) {
            cout << "Queue is empty." << endl;
        }
        else {
            Node* temp = front;
            while (temp != NULL) {
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << endl;
        }
    }
};

// Main function
int main() {
    Queue q;
    int choice, value;

    do {
        cout << "1. Insert element" << endl;
        cout << "2. Delete element" << endl;
        cout << "3. Display queue" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter the value to be inserted: ";
            cin >> value;
            q.insert(value);
            break;
        case 2:
            q.remove();
            break;
        case 3:
            q.display();
            break;
        case 4:
            cout << "Exiting program..." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 4);

    return 0;
}
