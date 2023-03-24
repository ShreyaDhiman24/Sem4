#include<iostream>

using namespace std;

const int MAX_SIZE = 100; // maximum size of stack

struct Stack {
  int top; // top element of stack
  int data[MAX_SIZE]; // array to store elements of stack

  Stack() { // constructor
    top = -1; // initialize top element to -1
  }

  bool isEmpty() { // check if stack is empty
    return top == -1;
  }

  bool isFull() { // check if stack is full
    return top == MAX_SIZE - 1;
  }

  void push(int element) { // push element onto stack
    if(isFull()) {
      cout << "Stack is full!" << endl;
      return;
    }
    top++; // increment top
    data[top] = element; // add element to stack
    cout << "Pushed element: " << element << endl;
  }

  int pop() { // pop element from stack
    if(isEmpty()) {
      cout << "Stack is empty!" << endl;
      return -1;
    }
    int poppedElement = data[top]; // store top element
    top--; // decrement top
    cout << "Popped element: " << poppedElement << endl;
    return poppedElement;
  }

  int peek() { // peek at top element of stack
    if(isEmpty()) {
      cout << "Stack is empty!" << endl;
      return -1;
    }
    int topElement = data[top]; // store top element
    cout << "Top element: " << topElement << endl;
    return topElement;
  }

  void display() { // display elements of stack
    if(isEmpty()) {
      cout << "Stack is empty!" << endl;
      return;
    }
    cout << "Stack elements: ";
    for(int i=top; i>=0; i--) { // traverse the stack
      cout << data[i] << " ";
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
