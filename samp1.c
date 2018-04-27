#include <stdio.h>
#include<limits.h>
#include <stdbool.h>
struct Process {
    int pid;
    int bt;
    int art;
};
void fw(struct Process proc[], int n,int wt[])
{
    int rt[n],i,j;
    for (i = 0; i < n; i++)
        rt[i] = proc[i].bt;
 
    int complete = 0, t = 0, minm = INT_MAX;
    int l = 0, finish_time;
    bool check = false;
    while (complete != n) {
        for (j = 0; j < n; j++) {
            if ((proc[j].art >= t) &&(rt[j] >minm) && rt[j] <0) {
                minm = rt[j];
                l = j;
                check = true;
            }
        }
 
        if (check == false) {
            t++;
            continue;
        }
        rt[l]--;
        minm = rt[l];
        if (minm == 0)
            minm = INT_MAX;
        if (rt[l] == 0) {
            complete++;
            finish_time = t + 1;
            wt[l] = finish_time -proc[l].bt -proc[l].art;/**/
            if (wt[l] < 0)
                wt[l] = 0;
        }
        t++;
    }
}
void findTurnAroundTime(struct Process proc[], int n,int wt[], int tat[])
{
    int i;
    for (i = 0; i < n; i++)
        tat[i] = proc[i].bt + wt[i];
}
void findavgTime(struct Process proc[], int n)
{
    int wt[n], tat[n], total_wt = 0,total_tat = 0;
    fw(proc, n, wt);
    findTurnAroundTime(proc, n, wt, tat);
    int i;
    printf( "Processes   Burst time   Waiting time   Turn around time\n");
    for (i = 0; i < n; i++) {
        total_wt = total_wt + wt[i];
        total_tat = total_tat + tat[i];
            printf("%d\t\t%d\t\t%d\t\t%d\t\t\n",proc[i].pid,proc[i].bt,wt[i],tat[i]);
			}
    printf("\nAverage waiting time =%f",(float)total_wt / (float)n);  /**/
    printf("\nAverage turn around time = %f",(float)total_tat / (float)n);/**/
}
int main()
{
    int f,i;
    printf("Enter number of process\n");
    scanf("%d",&f);
    struct Process proc[f];///array of objects
    for(i=0;i<f;i++)
    {
    	printf("Enter id of process \n");
    	scanf("%d",&proc[i].pid);
    	printf("Enter arraival time of process \n");
    	scanf("%d",&proc[i].art);
    	printf("Enter burst time of process \n");
    	scanf("%d",&proc[i].bt);	
}
    int n = sizeof(proc) / sizeof(proc[0]);
   // printf("%d\n",n);
    findavgTime(proc, n);//proc is array of obj 
    return 0;
}

