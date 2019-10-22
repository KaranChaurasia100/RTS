#include<bits/stdc++.h>
using namespace std;
void main(){
int n;
float e[20],p[20];
int 

Skip to content
Using Gmail with screen readers

2 of 1,402
RTS
Inbox
x

Yogeshwar Chaturvedi
Attachments
11:50 AM (0 minutes ago)
to magicalanmol100, me


Attachments area

#include<bits/stdc++.h>
using namespace std;

struct Process
{
    int pid;
    int bt;
    int priority;
};

bool sortProcesses(Process a, Process b)
{
    return (a.priority > b.priority);
}

void findWaitingTime(Process proc[], int n, int wt[])
{
    wt[0] = 0;
    for (int  i = 1; i < n ; i++ )
    wt[i] =  proc[i-1].bt + wt[i-1];
}

void findTurnAroundTime( Process proc[], int n, int wt[], int tat[])
{
    for (int  i = 0; i < n ; i++)
    tat[i] = proc[i].bt + wt[i];
}

void findavgTime(Process proc[], int n)
{
    int wt[n], tat[n], total_wt = 0, total_tat = 0;
    findWaitingTime(proc, n, wt);
    findTurnAroundTime(proc, n, wt, tat);
    cout << "\nProcesses  "<< " Burst time  "<< " Waiting time  " << " Turn around time\n";
    for (int  i=0; i<n; i++)
    {
        total_wt = total_wt + wt[i];
        total_tat = total_tat + tat[i];
        cout << "   " << proc[i].pid << "\t\t"<< proc[i].bt << "\t    " << wt[i] << "\t\t  " << tat[i] <<endl;
    }
    cout << "\nAverage waiting time = "<< (float)total_wt / (float)n;
    cout << "\nAverage turn around time = "<< (float)total_tat / (float)n;
}

void priorityScheduling(Process proc[], int n)
{
    sort(proc, proc + n, sortProcesses);
    cout<< "Order in which processes gets executed\n";
    for (int  i = 0 ; i <  n; i++)
    cout << proc[i].pid <<" " ;
    findavgTime(proc, n);
}

int main()
{
    Process proc[] = {{1, 10, 2}, {2, 5, 0}, {3, 8, 1}};
    int n = sizeof proc / sizeof proc[0];
    priorityScheduling(proc, n);
    return 0;
}
schedule.cpp
Displaying schedule.cpp.i;
clrscr(); 
print
