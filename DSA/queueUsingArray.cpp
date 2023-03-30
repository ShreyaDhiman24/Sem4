// I.	Write a c++ program to implement Circular QUEUE using Array that performs following operations
// (e)	INSERT 
// (f)	DELETE 
// (g)	DISPLAY
#include<iostream>
#define MAX_SIZE 5 // Define maximum size of the queue

using namespace std;

class CircularQueue {
  private:
    int front, rear;
    int arr[MAX_SIZE];

  public:
    CircularQueue() {
        front = -1;
        rear = -1;
    }

    bool isFull() {
        if ((front == 0 && rear == MAX_SIZE - 1) || (rear == front - 1))
            return true;
        else
            return false;
    }

    bool isEmpty() {
        if (front == -1)
            return true;
        else
            return false;
    }

    void enqueue(int item) {
        if (isFull()) {
            cout << "Queue is full, cannot insert element.\n";
            return;
        } else {
            if (front == -1)
                front = 0;
            rear = (rear + 1) % MAX_SIZE;
            arr[rear] = item;
            cout << "Inserted " << item << " into the queue.\n";
        }
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty, cannot delete element.\n";
            return;
        } else {
            int item = arr[front];
            if (front == rear)
                front = rear = -1;
            else
                front = (front + 1) % MAX_SIZE;
            cout << "Deleted " << item << " from the queue.\n";
        }
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty, cannot display elements.\n";
            return;
        } else {
            cout << "Elements of the queue are: ";
            int i;
            for (i = front; i != rear; i = (i + 1) % MAX_SIZE)
                cout << arr[i] << " ";
            cout << arr[i] << "\n";
        }
    }
};

int main() {
    CircularQueue q;

    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);
    q.enqueue(6); // Queue is full

    q.display(); // Elements of the queue are: 1 2 3 4 5

    q.dequeue();
    q.dequeue();

    q.display(); // Elements of the queue are: 3 4 5

    q.enqueue(6);
    q.enqueue(7);

    q.display(); // Elements of the queue are: 3 4 5 6 7

    return 0;
}
