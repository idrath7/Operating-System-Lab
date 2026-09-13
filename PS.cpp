#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cout<<"Enter number of processes: ";
    cin>>n;

    int process[n],burst[n],priority[n],waiting[n],turnaround[n];
    float totalWaiting=0,totalTurnaround=0;

    for(int i=0;i<n;i++) {
        process[i]=i+1;
        cout<<"Enter Burst Time for P"<<process[i]<<": ";
        cin>>burst[i];
        cout<<"Enter Priority for P"<<process[i]<<": ";
        cin>>priority[i];
    }
    //Sort by priority
    //Smaller number=Higher priority
    for(int i=0;i<n-1;i++) {
        for(int j=i+ 1;j<n;j++) {
            if(priority[i]>priority[j]){
                swap(priority[i],priority[j]);
                swap(burst[i],burst[j]);
                swap(process[i],process[j]);
            }
        }
    }

    // Waiting Time
    waiting[0]=0;
    for(int i=1;i<n;i++) {
        waiting[i]=waiting[i-1]+burst[i-1];
    }
    // Turnaround Time
    for(int i=0;i<n;i++) {
        turnaround[i]=waiting[i]+burst[i];
        totalWaiting=totalWaiting+waiting[i];
        totalTurnaround=totalTurnaround+turnaround[i];
    }

    cout<<"\nProcess\tBurst\tPriority\tWaiting\tTurnaround\n";
    for(int i=0;i<n;i++){
        cout<<"P"<<process[i]<<"\t"
             <<burst[i]<<"\t"
             <<priority[i]<<"\t\t"
             <<waiting[i]<<"\t"
             <<turnaround[i]<<endl;
    }

    cout<<"\nAverage Waiting Time = "<<totalWaiting/n<<endl;
    cout<<"Average Turnaround Time = "<<totalTurnaround/n<<endl;

    cout<<"\nScheduling Order: ";
    for(int i=0;i<n;i++){
        cout<<"P"<<process[i];
        if(i<n-1){
            cout<<" -> ";
        }
    }

    // Gantt Chart
    cout<<"\nGantt Chart:\n";
    for(int i=0;i<n;i++){
        cout<< "| P"<<process[i]<<" ";
    }
    cout<<"|\n";
    int time = 0;
    cout<<"0";
    for(int i =0;i<n;i++){
        time=time+burst[i];
        cout<<"\t"<<time;
    }
    return 0;
}