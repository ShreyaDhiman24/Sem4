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
    //(a)  insert node at the start of the list
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
    // (b)  insert node at the end of the list
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
    // (c) insert node at the specific position in the list
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
    // (d) delete node from the start of the list
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
    // (e) delete node from the end of the list
    void deleteFromEnd()
    {
        if (head == NULL)
        {
            cout << "List is empty. Deletion not possible." << endl;
            return;
        }
        else if (head->next == head) // only one node in the list
        {
            delete head;
            head = NULL;
        }
        else
        {
            Node *temp = head->prev;
            temp->prev->next = head;
            head->prev = temp->prev;
            delete temp;
        }
        cout << "Node deleted from end." << endl;
    }

    // (f)  delete a node from specified position
    void deleteAtPosition(int pos)
    {
        if (head == NULL)
        {
            cout << "List is empty, deletion not possible." << endl;
            return;
        }

        Node *temp = head;
        Node *prevNode, *nextNode;

        // If position is 1, delete the head node
        if (pos == 1)
        {
            prevNode = head->prev;
            nextNode = head->next;

            // If the list has only one node
            if (head == head->next)
            {
                head = NULL;
            }
            else
            {
                prevNode->next = nextNode;
                nextNode->prev = prevNode;
                head = nextNode;
            }
            cout << "Node at position " << pos << " deleted." << endl;
            delete temp;
            return;
        }

        // Traverse the list to find the node at the specified position
        for (int i = 1; i < pos; i++)
        {
            temp = temp->next;

            // If position is greater than the number of nodes in the list
            if (temp == head)
            {
                cout << "Position " << pos << " is greater than the number of nodes in the list." << endl;
                return;
            }
        }

        // Delete the node at the specified position
        prevNode = temp->prev;
        nextNode = temp->next;
        prevNode->next = nextNode;
        nextNode->prev = prevNode;
        cout << "Node at position " << pos << " deleted." << endl;
        delete temp;
    }

    // (g) Displaying elements in linkedlist
    void printList()
    {
        if (head == NULL)
        {
            cout << "List is empty." << endl;
            return;
        }
        Node *current = head;
        do
        {
            cout << current->data << " ";
            current = current->next;
        } while (current != head);
        cout << endl;
    }
};

int main()
{
    CircularDoublyLinkedList list;

    // Insert some nodes at the start
    list.insertAtStart(10);
    list.printList();

    list.insertAtStart(20);
    list.printList();

    list.insertAtStart(30);
    list.printList();

    // Insert some nodes at the end
    list.insertAtEnd(40);
    list.printList();

    list.insertAtEnd(50);
    list.printList();

    list.insertAtEnd(60);
    list.printList();

    // Insert some nodes at the specified positions
    list.insertAtPosition(6, 2);
    list.printList();

    list.insertAtPosition(55, 6);
    list.printList();

    list.insertAtPosition(3, 5);
    list.printList();

    // Delete a node from start
    list.deleteAtStart();
    list.printList();

    // Delete a node from end
    list.deleteFromEnd();
    list.printList();

    // Delete a node at position 3
    list.deleteAtPosition(3);

    // Print the list after deletion
    list.printList();
    return 0;
}