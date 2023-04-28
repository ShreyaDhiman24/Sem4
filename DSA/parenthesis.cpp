#include <iostream>
using namespace std;

struct Node {
    char data;
    Node* next;
    Node(char data) {
        this->data = data;
        this->next = nullptr;
    }
};

class Stack {
    Node* top;
public:
    Stack() {
        this->top = nullptr;
    }
    bool isEmpty() {
        return top == nullptr;
    }
    void push(char c) {
        Node* newNode = new Node(c);
        newNode->next = top;
        top = newNode;
    }
    char pop() {
        if (isEmpty()) {
            return '\0';
        }
        char c = top->data;
        Node* temp = top;
        top = top->next;
        delete temp;
        return c;
    }
};

bool is_balanced(string exp) {
    Stack s;
    for (char c : exp) {
        if (c == '(' || c == '{' || c == '[') {
            s.push(c);
        }
        else if (c == ')' && s.pop() != '(') {
            return false;
        }
        else if (c == '}' && s.pop() != '{') {
            return false;
        }
        else if (c == ']' && s.pop() != '[') {
            return false;
        }
    }
    return s.isEmpty();
}

int main() {
    string exp;
    cout << "Enter an expression: ";
    cin >> exp;

    if (is_balanced(exp)) {
        cout << "balanced" << endl;
    }
    else {
        cout << "not balanced" << endl;
    }

    return 0;
}
