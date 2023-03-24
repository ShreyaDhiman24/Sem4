/*implement circular doubly linked list  having following functions:
1. insertion from start
2. insertion from end
3. insertion from specified position
4. deletion from start
5. deletion from end
6. deletion from specified position
7. main function asking users for the input(menu driven program) using switch case displaying result after every case*/

#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;
    Node(int d)
    {
        data = d;
        next = NULL;
        prev = NULL;
    }
};

class CircularDoublyLinkedList
{
private:
    Node *head;

public:
    CircularDoublyLinkedList()
    {
        head = NULL;
    }
    // insert node at the start of the list
    void insertAtStart(int data)
    {
        Node *newNode = new Node(data);
        if (head == NULL)
        {
            head = newNode;
            head->next = head;
            head->prev = head;
        }
        else
        {
            Node *last = head->prev;
            newNode->next = head;
            newNode->prev = last;
            head->prev = newNode;
            last->next = newNode;
            head = newNode;
        }
        cout << "Node with data " << data << " inserted at the start." << endl;
    }
    // insert node at the end of the list
    void insertAtEnd(int data)
    {
        Node *newNode = new Node(data);
        if (head == NULL)
        {
            head = newNode;
            head->next = head;
            head->prev = head;
        }
        else
        {
            Node *last = head->prev;
            newNode->next = head;
            newNode->prev = last;
            head->prev = newNode;
            last->next = newNode;
        }
        cout << "Node with data " << data << " inserted at the end." << endl;
    }
    // insert node at the specific position in the list
    void insertAtPosition(int data, int position)
    {
        Node *newNode = new Node(data);
        if (head == NULL)
        {
            head = newNode;
            head->next = head;
            head->prev = head;
            cout << "Node with data " << data << " inserted at position " << position << "." << endl;
            return;
        }
        Node *temp = head;
        for (int i = 1; i < position - 1; i++)
        {
            temp = temp->next;
        }
        newNode->prev = temp;
        newNode->next = temp->next;
        temp->next->prev = newNode;
        temp->next = newNode;
        cout << "Node with data " << data << " inserted at position " << position << "." << endl;
    }
    // delete node from the start of the list
    void deleteAtStart()
    {
        if (head == NULL)
        {
            cout << "List is empty." << endl;
            return;
        }
        Node *last = head->prev;
        if (head == last)
        {
            delete head;
            head = NULL;
        }
        else
        {
            Node *temp = head;
            head = head->next;
            head->prev = last;
            last->next = head;
            delete temp;
        }
        cout << "Node deleted from the start." << endl;
    }
    // delete node from the end of the list
    void deleteAtEnd()
    {
        if (head == NULL)
        {
            cout << "List is empty." << endl;
            return;
        }
        Node *last = head->prev;
        if (head == last)
        {
            delete head;
            head = NULL;
        }
        else
        {
            Node *temp = last;
            last = last->prev;
        }
    }

    void deleteAtPosition(int data, int position){
          if (head == NULL)
        {
            cout << "List is empty." << endl;
            return;
        }
    }
};