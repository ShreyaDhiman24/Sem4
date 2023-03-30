#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

class LinkedList
{
private:
    Node *head;

public:
    LinkedList()
    {
        head = NULL;
    }
    void insertFront(int val)
    {
        Node *newNode = new Node();
        newNode->data = val;
        newNode->next = head;
        head = newNode;
        cout << "Node with value " << val << " inserted at the front." << endl;
    }
    void insertEnd(int val)
    {
        Node *newNode = new Node();
        newNode->data = val;
        newNode->next = NULL;
        if (head == NULL)
        {
            head = newNode;
            cout << "Node with value " << val << " inserted at the end." << endl;
            return;
        }
        Node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
        cout << "Node with value " << val << " inserted at the end." << endl;
    }
    void insertPosition(int val, int pos)
    {
        Node *newNode = new Node();
        newNode->data = val;
        if (pos == 1)
        {
            newNode->next = head;
            head = newNode;
            cout << "Node with value " << val << " inserted at position " << pos << "." << endl;
            return;
        }
        Node *temp = head;
        for (int i = 1; i < pos - 1 && temp != NULL; i++)
        {
            temp = temp->next;
        }
        if (temp == NULL)
        {
            cout << "Invalid position." << endl;
            return;
        }
        newNode->next = temp->next;
        temp->next = newNode;
        cout << "Node with value " << val << " inserted at position " << pos << "." << endl;
    }
    void deleteFront()
    {
        if (head == NULL)
        {
            cout << "Linked List is empty." << endl;
            return;
        }
        Node *temp = head;
        head = head->next;
        delete temp;
        cout << "First Node deleted." << endl;
    }
    void deleteEnd()
    {
        if (head == NULL)
        {
            cout << "Linked List is empty." << endl;
            return;
        }
        if (head->next == NULL)
        {
            delete head;
            head = NULL;
            cout << "Last Node deleted." << endl;
            return;
        }
        Node *temp = head;
        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = NULL;
        cout << "Last Node deleted." << endl;
    }

    void deleteAfterPosition(int pos)
    {
        if (head == NULL)
        {
            cout << "Linked List is empty." << endl;
            return;
        }
        Node *temp = head;
        for (int i = 1; i <= pos && temp != NULL; i++)
        {
            if (i == pos && temp->next != NULL)
            {
                Node *delNode = temp->next;
                temp->next = temp->next->next;
                delete delNode;
                cout << "Node after position " << pos << " deleted." << endl;
                return;
            }
            temp = temp->next;
        }
        cout << "Invalid position or no node after the position." << endl;
    }

    void display()
    {
        if (head == NULL)
        {
            cout << "Linked List is empty." << endl;
            return;
        }
        Node *temp = head;
        cout << "Elements of the Linked List are: ";
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    LinkedList list;
    int choice, val, pos;
    do {
        cout << "Please select an option:" << endl;
        cout << "1. Insert a node at the front of the linked list" << endl;
        cout << "2. Insert a node at the end of the linked list" << endl;
        cout << "3. Insert a node at a given position in the linked list" << endl;
        cout << "4. Delete the first node of the linked list" << endl;
        cout << "5. Delete the last node of the linked list" << endl;
        cout << "6. Delete a node after a specified position in the linked list" << endl;
        cout << "7. Display the elements of the linked list" << endl;
        cout << "8. Exit" << endl;
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter the value to insert at the front of the list: ";
                cin >> val;
                list.insertFront(val);
                break;
            case 2:
                cout << "Enter the value to insert at the end of the list: ";
                cin >> val;
                list.insertEnd(val);
                break;
            case 3:
                cout << "Enter the value to insert: ";
                cin >> val;
                cout << "Enter the position to insert the value: ";
                cin >> pos;
                list.insertPosition(val, pos);
                break;
            case 4:
                list.deleteFront();
                break;
            case 5:
                list.deleteEnd();
                break;
            case 6:
                cout << "Enter the position after which the node should be deleted: ";
                cin >> pos;
                list.deleteAfterPosition(pos);
                break;
            case 7:
                list.display();
                break;
            case 8:
                cout << "Exiting program..." << endl;
                break;
            default:
                cout << "Invalid choice. Please enter a number between 1 and 8." << endl;
                break;
        }
    } while (choice != 8);
    return 0;
}
