#include <iostream>
#include <algorithm>
using namespace std;

struct Process
{
    int pid;             // process id
    int arrival_time;    // arrival time
    int burst_time;      // burst time
    int remaining_time;  // remaining time
    int completion_time; // completion time
    int waiting_time;    // waiting time
    int turnaround_time; // turnaround time
};

int main()
{
    int n; // number of processes
    cout << "Enter the number of processes: ";
    cin >> n;

    // array to store the processes
    Process processes[n];

    // input arrival time and burst time for each process
    for (int i = 0; i < n; i++)
    {
        processes[i].pid = i + 1;
        cout << "Enter arrival time and burst time for process " << i + 1 << ": ";
        cin >> processes[i].arrival_time >> processes[i].burst_time;
        processes[i].remaining_time = processes[i].burst_time;
    }

    int current_time = 0;
    int completed = 0;
    while (completed < n)
    {
        int shortest = -1;
        for (int i = 0; i < n; i++)
        {
            if (processes[i].arrival_time <= current_time && processes[i].remaining_time > 0)
            {
                if (shortest == -1 || processes[i].remaining_time < processes[shortest].remaining_time)
                {
                    shortest = i;
                }
            }
        }

        if (shortest == -1)
        {
            current_time++;
            continue;
        }

        processes[shortest].remaining_time--;
        current_time++;

        if (processes[shortest].remaining_time == 0)
        {
            completed++;
            processes[shortest].completion_time = current_time;
            processes[shortest].waiting_time = processes[shortest].completion_time - processes[shortest].burst_time - processes[shortest].arrival_time;
            processes[shortest].turnaround_time = processes[shortest].completion_time - processes[shortest].arrival_time;
        }
    }

    // output the turnaround time, waiting time, and completion time in a tabular form
    cout << "Process ID\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time\tCompletion Time" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << processes[i].pid << "\t\t" << processes[i].arrival_time << "\t\t" << processes[i].burst_time << "\t\t" << processes[i].waiting_time << "\t\t" << processes[i].turnaround_time << "\t\t" << processes[i].completion_time << endl;
    }

    return 0;
}
