#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};

void insert(Node*& head, int data) {
    Node* newNode = new Node(data);
    if (head == nullptr) {
        head = newNode;
    }
    else {
        Node* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
    }
}

void delete_duplicates(Node* head) {
    if (head == nullptr) {
        return;
    }
    Node* current = head;
    while (current->next != nullptr) {
        if (current->data == current->next->data) {
            Node* temp = current->next;
            current->next = temp->next;
            delete temp;
        }
        else {
            current = current->next;
        }
    }
}

void display(Node* head) {
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    Node* head = nullptr;

    insert(head, 11);
    insert(head, 11);
    insert(head, 11);
    insert(head, 21);
    insert(head, 43);
    insert(head, 43);
    insert(head, 60);

    cout << "Original List: ";
    display(head);

    delete_duplicates(head);

    cout << "List after removing duplicates: ";
    display(head);

    return 0;
}
