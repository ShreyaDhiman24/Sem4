#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Process {
    int pid; // process ID
    int at; // arrival time
    int bt; // burst time
    int ct; // completion time
    int tat; // turnaround time
    int wt; // waiting time
};

bool compare(Process a, Process b) {
    return a.at < b.at;
}

void findCompletionTime(vector<Process> &proc) {
    int n = proc.size();
    int currTime = 0;
    for(int i=0; i<n; i++) {
        if(currTime < proc[i].at) currTime = proc[i].at;
        currTime += proc[i].bt;
        proc[i].ct = currTime;
    }
}

void findTurnAroundTime(vector<Process> &proc) {
    int n = proc.size();
    for(int i=0; i<n; i++) {
        proc[i].tat = proc[i].ct - proc[i].at;
    }
}

void findWaitingTime(vector<Process> &proc) {
    int n = proc.size();
    for(int i=0; i<n; i++) {
        proc[i].wt = proc[i].tat - proc[i].bt;
    }
}

void printTable(vector<Process> proc) {
    int n = proc.size();
    cout << "Process\tAT\tBT\tCT\tTAT\tWT" << endl;
    for(int i=0; i<n; i++) {
        cout << proc[i].pid << "\t"
             << proc[i].at << "\t"
             << proc[i].bt << "\t"
             << proc[i].ct << "\t"
             << proc[i].tat << "\t"
             << proc[i].wt << endl;
    }
}

int main() {
    vector<Process> proc {
        {1, 0, 6},
        {2, 2, 4},
        {3, 4, 3},
        {4, 6, 7},
        {5, 8, 2}
    };
    sort(proc.begin(), proc.end(), compare);
    findCompletionTime(proc);
    findTurnAroundTime(proc);
    findWaitingTime(proc);
    printTable(proc);
    return 0;
}