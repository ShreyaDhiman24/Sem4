// II.	Write a c++ program to implement QUEUE using Linked List that performs following operations
// INSERT - Inserts an element at the end of the queue.
// DELETE - Removes the element from the front of the queue.
// DISPLAY - Displays the elements in the queue.
#include <iostream>

using namespace std;

// node structure for the linked list
struct Node {
    int data;
    Node* next;
};

// circular queue class
class CircularQueue {
    private:
        Node* rear; // pointer to the rear node of the queue
    public:
        CircularQueue() {
            rear = NULL;
        }

        // function to insert an element at the end of the queue
        void insert(int value) {
            Node* temp = new Node;
            temp->data = value;
            if (rear == NULL) {
                rear = temp;
                rear->next = rear;
            }
            else {
                temp->next = rear->next;
                rear->next = temp;
                rear = temp;
            }
            cout << "Element " << value << " inserted successfully." << endl;
        }

        // function to remove the element from the front of the queue
        void remove() {
            if (rear == NULL) {
                cout << "Queue is empty." << endl;
                return;
            }
            Node* temp = rear->next;
            if (rear->next == rear) {//1 element
                rear = NULL;
            }
            else {
                rear->next = rear->next->next;
            }
            cout << "Element " << temp->data << " removed successfully." << endl;
            delete temp;
        }

        // function to display the elements in the queue
        void display() {
            if (rear == NULL) {
                cout << "Queue is empty." << endl;
                return;
            }
            Node* temp = rear->next;
            cout << "Elements in the queue: ";
            while (temp != rear) {
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << temp->data << endl;
        }
};


// Main function
int main() {
    CircularQueue q;
    int choice, value;

     cout << "1. Insert element" << endl;
        cout << "2. Delete element" << endl;
        cout << "3. Display queue" << endl;
        cout << "4. Exit" << endl;

    do {
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
