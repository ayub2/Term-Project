/* Simple C++ program for implementation 
of FCFS scheduling */

#include<iostream>

using namespace std;

struct Process
{
	int ccode;
	int duration;
	int priority;
	int arrival_time;
};

Process proc[] = {{2201,3,2,1}, {3401,2,3,2}, {1103,1,1,3}};

// function to find the waiting time for all processes
void findWaitingTime(int processes[], int n, int bt[], int wt[])
{
    // waiting time for first process will be 0
    wt[0] = 0;
 
    // calculating waiting time
    for (int i = 1; i < n ; i++)
    {
        wt[i] =  bt[i-1] + wt[i-1];
    }
}
 
// function to calculate turn around time
void findTurnAroundTime( int processes[], int n, int bt[], int wt[], int tat[])
{
    // calculating turnaround time by adding
    // bt[i] + wt[i]
    for (int i = 0; i < n ; i++)
    {
        tat[i] = bt[i] + wt[i];
    }
}
 
// function to calculate average time
void findAverageTime( int processes[], int n, int bt[])
{
    int wt[n], tat[n], total_wt = 0, total_tat = 0;
 
    // function to find waiting time of all processes
    findWaitingTime(processes, n, bt, wt);
 
    // function to find turn around time for all processes
    findTurnAroundTime(processes, n, bt, wt, tat);
 
    // display processes along with all details
    cout << "Processes  "<< " Burst time  "<< " Waiting time  " << " Turn around time\n";
 
    // calculate total waiting time and total turn around time
    for (int i = 0; i < n; i++)
    {
        total_wt = total_wt + wt[i];
        total_tat = total_tat + tat[i];
        cout << "   " << proc[i].ccode << "\t\t" << bt[i] <<"\t    "<< wt[i] <<"\t\t  " << tat[i] <<endl;
    }
    
	cout << endl;
    cout << "Average waiting time = "<< (float)total_wt / (float)n;
    cout << "\nAverage turn around time = "<< (float)total_tat / (float)n;	
}
 
// main function
int main()
{
    // course CSC2201 with priority 2 for 3 hours with prefered to start first
    // CSC3401 with priority 3 for 2 hours prefered to start second
    // and CSC1103 with priority 1 for 1 hour
    
    cout << "Details of classes :\n\n";
    cout << "Course Code\t" << "Duration\t" << "Priority\t" << "Arrival Time\t\n";
    for (int i = 0; i < 3; i++){
		cout << "   " << proc[i].ccode << "\t\t   " << proc[i].duration << "\t\t   " << proc[i].priority << "\t\t\t" << proc[i].arrival_time << "\n";
	}
	cout << endl;
	// process ids
    int processes[] = { 1, 2, 3};
    int n = sizeof processes / sizeof processes[0];
 
    // burst time of all processes
    int  burst_time[] = {3, 2, 1};
 
    findAverageTime(processes, n,  burst_time);
    
    return 0;
}
