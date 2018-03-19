/*
Consider a scheduling approach which is non pre-emptive similar to shortest job next in nature.
The priority of each job is dependent on its estimated run time, and also the amount of time it has spent waiting.
Jobs gain higher priority the longer they wait, which prevents indefinite postponement.
The jobs that have spent a long time waiting compete against those estimated to have short run times.
The priority can be computed as : Priority = 1+ Waiting time / Estimated run time
Write a program to implement such an algorithm.
*/
// for non-premptive systems Waiting Time = Start Time - Arrival Time

#include<stdio.h>
#include <stdlib.h>
int main()
{
  printf("\t\t\t----------------------- Scheduling -----------------------\n\n\n\n");
  long int n,i=0;
  printf("Enter Number of Processes : ");
  scanf("%ld",&n );
  long int burstTime[n],arrivalTime[n],priority[n],waitingTime[n],turnaroundTime[n];

  for(i=0;i<n;i++)
  {
    printf("\nEnter Arrival Time for Process [%d] : ", i+1 );
    scanf("%ld", &arrivalTime[i]);
    printf("Enter Burst Time for Process [%d] : ", i+1 );
    scanf("%ld", &burstTime[i] );
  }

  printf("\n\n\t\t\t -------------- Entered Values are --------------\n\n");
  printf("\t\t\t---------------------------------------\n");
  printf("\t\t\t| Process | Arrival Time | Burst Time |\n");
  printf("\t\t\t---------------------------------------\n");
for(i=0;i<n;i++)
{
  printf("\t\t\t|  P[%ld]   |       %ld      |     %ld      |\n",i+1,arrivalTime[i],burstTime[i]);
}
  printf("\t\t\t---------------------------------------\n");

  

  return 0;
}
