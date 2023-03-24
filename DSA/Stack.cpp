// C++ Program to implement stack having push,pop,peep and display functions, and then finding infix to postfix, evaluate postfix.
#include<iostream>
using namespace std;

class StackNode {
  public:
    int data;
    StackNode* next;

    StackNode(int data) { // constructor
      this->data = data;
      this->next = nullptr;
    }
};

class Stack {
  private:
    StackNode* top; // top node of stack

  public:
    Stack() { // constructor
      top = nullptr; // initialize top node to null
    }

    bool isEmpty() { // check if stack is empty
      return top == nullptr;
    }

    void push(int element) { // push element onto stack
      StackNode* newNode = new StackNode(element); // create new node
      newNode->next = top; // set next of new node to current top node
      top = newNode; // set top to new node
      cout << "Pushed element: " << element << endl;
    }

    int pop() { // pop element from stack
      if(isEmpty()) {
        cout << "Stack is empty!" << endl;
        return -1;
      }
      int poppedElement = top->data; // store data of top node
      StackNode* temp = top; // store top node temporarily
      top = top->next; // set top to next node
      delete(temp); // delete temporary node
      cout << "Popped element: " << poppedElement << endl;
      return poppedElement;
    }

    int peek() { // peek at top element of stack
      if(isEmpty()) {
        cout << "Stack is empty!" << endl;
        return -1;
      }
      int topElement = top->data; // store data of top node
      cout << "Top element: " << topElement << endl;
      return topElement;
    }

    void display() { // display elements of stack
      if(isEmpty()) {
        cout << "Stack is empty!" << endl;
        return;
      }
      cout << "Stack elements: ";
      StackNode* currentNode = top; // start from top node
      while(currentNode != nullptr) { // traverse the stack
        cout << currentNode->data << " ";
        currentNode = currentNode->next;
      }
      cout << endl;
    }
};

int main() {
  Stack stack; // create stack object
  stack.push(10);
  stack.push(20);
  stack.push(30);
  stack.display();
  stack.peek();
  stack.pop();
  stack.display();
  return 0;
}

