								/*Program to solve Job Sequencing Problem using Greedy Method*/
#include<bits/stdc++.h>
using namespace std;

//Template of the job
class job
{
	public:
		int serial_no;
		int profit;
		int deadline;
};

//Template of the slots
class sequence
{
	public:
		int slot;
		int occupied;
};

//Function block acting as the sorting parameter
bool parameter(job j1,job j2)
{
	return (j1.profit>j2.profit);
}

//Function block to calculate the maximum deadline among the given jobs
int find_max(job j[],int n)
{
	int max=0;
	
	for(int i=0;i<n;i++)
	{
		if(j[i].deadline>max)
			max=j[i].deadline;
	}
	
	return max;
}

//Function block to perform the sequencing of jobs and calculate the maximum profit
void jobsequence(job j[],int n)
{
	sort(j,j+n,parameter); //List of jobs sorted on the basis of decreasing order of profit
	
	int m=find_max(j,n);
	int maxprofit=0,count=0;
	cout<<"\nMaximum deadline is-"<<m;
	
	sequence s[m]={0,0};   //Array type object of class sequence is created and both fields of each element is initialised to 0 
	
	
	for(int i=0;i<n && count<m;i++)
	{
		int d=j[i].deadline;
		//If the slot is not occupied that is the current job can be performed within its deadline
		if(!(s[d-1].occupied))
		{
			s[d-1].occupied=1;
			s[d-1].slot=j[i].serial_no;
			maxprofit+=j[i].profit;
			count++;
		}
	}
	
	cout<<"\nThe maximum profit is-"<<maxprofit;
	cout<<"\nThe sequence of job will be-";
	
	for(int i=0;i<m;i++)
		cout<<s[i].slot<<"\t";
}

//Driver Code
int main(void)
{
	int n;//No of jobs
	cout<<"\nEnter the number  of jobs under consideration-";
	cin>>n;
	
	job j[n]; // Array type object of class job
	
	for(int i=0;i<n;i++)
	{
		cout<<"\nSample input "<<i+1<<endl;
		cout<<"\tEnter the serial number of the job-";
		cin>>j[i].serial_no;
		cout<<"\n\tEnter the profit of the job-";
		cin>>j[i].profit;
		cout<<"\n\tEnter the deadline of the job-";
		cin>>j[i].deadline;
	}
	
	jobsequence(j,n); 

	return 0;
}
