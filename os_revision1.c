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
#include<unistd.h>
#include <stdlib.h>
int main()
{
  printf("\t\t\t----------------------- Scheduling -----------------------\n\n\n\n");
  long int n,i=0,j=0;
  printf("Enter Number of Processes : ");
  scanf("%ld",&n );
  long int burstTime[n],arrivalTime[n],priority[n],waitingTime[n],turnaroundTime[n], process[n], temp; 
  for(i=0;i<n;i++)
  {
    printf("\nEnter Burst Time for Process [%d] : ", i+1 );
    scanf("%ld", &burstTime[i]);
    printf("Enter Arrival Time for Process [%d] : ", i+1 );
    scanf("%ld", &arrivalTime[i] );
    process[i]=i+1;
  }

  printf("\n\n\t\t\t -------------- Entered Values are --------------\n\n");
  printf("\t\t\t---------------------------------------\n");
  printf("\t\t\t| Process | Arrival Time | Burst Time |\n");
  printf("\t\t\t---------------------------------------\n");
  for(i=0;i<n;i++)
  {
    printf("\t\t\t|  P[%ld]   |       %ld      |     %ld      |\n",process[i],arrivalTime[i],burstTime[i]);
  }
    printf("\t\t\t---------------------------------------\n");

  //Sorting processes according to arrivalTime
  printf("\n\n\t\t\t-------- Sorting processes according to Arrival Time --------\n");

  for(i=0;i<n;i++)
  {
    for(j=0;j<n;j++)
    {
      if(arrivalTime[i]<arrivalTime[j])
      {
        temp = process[j];
        process[j] = process[i];
        process[i] = temp;

        temp = arrivalTime[j];
        arrivalTime[j] = arrivalTime[i];
        arrivalTime[i] = temp;

        temp = burstTime[j];
        burstTime[j] = burstTime[i];
        burstTime [i] = temp;
      }
    }
  }
  printf("\n\n\t\t\t -------------- Now Values are --------------\n\n");
  printf("\t\t\t---------------------------------------\n");
  printf("\t\t\t| Process | Arrival Time | Burst Time |\n");
  printf("\t\t\t---------------------------------------\n");
  for(i=0;i<n;i++)
  {
    printf("\t\t\t|  P[%ld]   |       %ld      |     %ld      |\n",process[i],arrivalTime[i],burstTime[i]);
  }
    printf("\t\t\t---------------------------------------\n");
  /*Arranging the table according to Burst time,
Execution time and Arrival Time
Arrival time <= Execution time
*/


  long int k = 1;
  long int b_time = 0;
  for(j=0;j<n;j++)
  {
    b_time = b_time + burstTime[j];
    min = burstTime[k];

    for(i=k;i<n;i++)
    {
      if((b_time >= arrivalTime[i])&&(burstTime[i]<min))
      {
        temp = process[k];
        process[k] = process[i];
        process[i] = temp;

        temp = arrivalTime[k];
        arrivalTime[k] = arrivalTime[i];
        arrivalTime[i] = temp;

        temp = burstTime[k];
        burstTime[k] = burstTime[i];
        burstTime[i] = temp;
      }
    }
    k++;
  }
  waitingTime[0] = 0;
  for(i=1;i<n;i++)
  {
    sum += burstTime[i-1];
    waitingTime[i] = sum - arrivalTime[i];
    wait_final += waitingTime[i]; 
  }

  for(i=0;i<n;i++)
  {
    sum2 += burstTime[i];
    turnaroundTime[i] = sum2 - arrivalTime[i];
    turnaround_final += turnaroundTime[i];
  }

printf("\n\n\t\t\t -------------- Now Values are --------------\n\n");
  printf("\t\t\t-----------------------------------------------------------------------------\n");
  printf("\t\t\t| Process | Arrival Time | Burst Time |  Waiting Time  |  Turn Around Time  |\n");
  printf("\t\t\t-----------------------------------------------------------------------------\n");
  for(i=0;i<n;i++)
  {
    printf("\t\t\t|  P[%ld]   |       %ld      |     %ld      |        %ld       |         %ld          |\n",process[i],arrivalTime[i],burstTime[i],waitingTime[i],turnaroundTime[i]);
  }
    printf("\t\t\t-----------------------------------------------------------------------------\n");



  
  
  return 0;
}
