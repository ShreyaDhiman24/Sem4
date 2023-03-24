/*Producer Consumer problem: using mutex and semaphore
INITIALISATION:
1 mutex --> used for providing mutual exclusion
2 semaphores for critical section:
    one semaphore: empty -->number of empty slots in the buffer
    2nd semaphore: full -->no. of filled slots
2 index to track user to produce item
    int in =0; --> index at which producer will produce the data
    int out=0; --> index from which the consumer will consume next item
Buffer of size N

PRODUCER PSEUDOCODE:

while(1){
    //produce an item
   wait(if buffer==full empty); -->wait or sleep when there are no empty slots
   wait(mutex); -->if there is no producer inside the cs it has to wait here

   buffer[in] = item
   in= (in+1)%buffersize --> so that it will be reinitailised to 0 whenever full

   signal(mutex);
   signal(full); --> wakes the consumer that buffer has
}

CONSUMER CODE:
while(1){
    wait(buffer==empty ---full) -->when there are no full slots
    wait(mutex);

    item = buffer[out];
    out= (out+1)%buffersize;

    signal(mutex);
    signal(empty); -->signal to wake up producer that buffer is empty
    //consume the items

}

*/

#include <bits/stdc++.h>
using namespace std;

void wait(int &x)
{
    if (x > 0)
        x--;
}
void signal(int &x)
{
    x++;
}

void del(int arr[]) {
    for(int i = 4; i >= 0; i--) {
        if(arr[i] != 0) {
            arr[i] = 0;
            break;
        }
    }
}


void print(int a[])
{
    for (int i = 0; i < 5; i++)
    {
        cout << a[i] << " ";
    }
}

int main()
{
    int a[5];
    int empty = 5;
    int full = 0;
    int mutex = 1;
    while (1)
    {
        cout << "\n---------------------------------------------------------" << endl;
        cout << "empty: " << empty << " full: " << full << " mutex: " << mutex << endl
             << "Enter your choice \n 1.Produce \n 2.Consume" << endl;
        int x;
        cin >> x;
        switch (x)
        {
        case 1:
            if (empty != 0 && mutex == 1)
            {
                cout << "Enter data: " << endl;
                wait(empty);
                wait(mutex);
                cin >> a[full];
                signal(mutex);
                signal(full);

                print(a);
            }
            else
            {
                cout << "Buffer is full" << endl;
                print(a);
            }

            break;

        case 2:
            if (full > 0 && mutex == 1)
            {
                wait(full);
                wait(mutex);
                // cout << "Data is " << a[full] << endl;
                del(a);
                print(a);

                signal(mutex);
                signal(empty);
            }
            else
            {
                cout << "Buffer is empty" << endl;
                print(a);
            }

            break;

        default:
            cout << "Not a valid input" << endl;
            break;
        }
    }
    return 0;
}