
#include <stdio.h>
#include <stdlib.h>


int assignWorkloads(int cap[], 
                    int nServers, 
                    int work[], 
                    int nTasks, 
                    int current)
{   
    if (current >= nTasks)    return 1;
    
    int i;
    for (i = 0; i < nServers; ++i) {
        if (cap[i] >= work[current]) {
            cap[i] -= work[current];
            if (assignWorkloads(cap, nServers, work, nTasks, current + 1))
                return 1;
            else
                cap[i] += work[current];
        }
    }
    return 0;
}



int main()
{
//    int capacities[] = {8, 16, 8, 32};
//    int workloads[] = {18, 4, 8, 4, 6, 6, 8, 8};

    int capacities[] = {1, 3};
    int workloads[] = {4};


    int nServers = sizeof(capacities) / sizeof(capacities[0]);
    int nTasks = sizeof(workloads) / sizeof(workloads[0]);
    
    if (assignWorkloads(capacities, nServers, workloads, nTasks, 0))
        printf("yes\n");
    else
        printf("no\n");
    
    return 0;
}