
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;

    cout<<"Enter number of processes: ";
    cin>>n;

    int processId[n],burstTime[n],completionTime[n],turnaroundTime[n],waitingTime[n];

    // Input Burst Time
    for(int i=0;i<n;i++)
    {
        processId[i]=i+1;
        cout<<"Enter Burst Time for P"<<processId[i]<<": ";
        cin>>burstTime[i];
    }

    // FCFS - First Come First Serve
    // Processes execute in input order

    // Display Scheduling Order
    cout<<"\nScheduling Order: ";

    for(int i=0;i<n;i++)
    {
        cout<<"P"<<processId[i];

        if(i<n-1)
        {
            cout<<" -> ";
        }
    }

    cout<<endl;

    // Calculate Completion Time
    completionTime[0]=burstTime[0];

    for(int i=1;i<n;i++)
    {
        completionTime[i]=completionTime[i-1]+burstTime[i];
    }

    // Calculate Turnaround Time
    // Arrival Time = 0
    // Turnaround Time = Completion Time - Arrival Time
    for(int i=0;i<n;i++)
    {
        turnaroundTime[i]=completionTime[i];
    }

    // Calculate Waiting Time
    // Waiting Time = Turnaround Time - Burst Time
    for(int i=0;i<n;i++)
    {
        waitingTime[i]=turnaroundTime[i]-burstTime[i];
    }

    // Display Result
    cout<<"\nProcess ID\tBurst Time\tCompletion Time\tTurnaround Time\tWaiting Time\n";

    for(int i=0;i<n;i++)
    {
        cout<<"P"<<processId[i]<<"\t\t"
            <<burstTime[i]<<"\t\t"
            <<completionTime[i]<<"\t\t"
            <<turnaroundTime[i]<<"\t\t"
            <<waitingTime[i]<<endl;
    }

    // Calculate Average Waiting Time
    float totalWaitingTime=0;

    for(int i=0;i<n;i++)
    {
        totalWaitingTime=totalWaitingTime+waitingTime[i];
    }

    float averageWaitingTime=totalWaitingTime/n;

    // Calculate Average Turnaround Time
    float totalTurnaroundTime=0;

    for(int i=0;i<n;i++)
    {
        totalTurnaroundTime=totalTurnaroundTime+turnaroundTime[i];
    }

    float averageTurnaroundTime=totalTurnaroundTime/n;

    // Display Average Times
    cout<<"\nAverage Waiting Time = "
        <<averageWaitingTime<<endl;

    cout<<"Average Turnaround Time = "
        <<averageTurnaroundTime<<endl;

    // Gantt Chart
    cout<<"\nGantt Chart:\n";

    for(int i=0;i<n;i++)
    {
        cout<<"| P"<<processId[i]<<" ";
    }
    cout<<"|\n";

    cout<<"0";

    for(int i=0;i<n;i++)
    {
        cout<<"\t"<<completionTime[i];
    }

    return 0;
}
