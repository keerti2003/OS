#include <stdio.h>
#include <limits.h>

struct Proc {
	int at;
	int bt;
	int ct;
	int tat;
	int wt;
    int rem;
};

int allproc(struct Proc a[], int n) {
    int i;
    for(i=0; i<n; i++) {
        if(a[i].rem > 0) {
            return 1;
        }
    }
    return 0;
}

int main() {
	int n, time=0, i, j, q, minidx, curr, quantum;
	scanf("%d", &n);
	struct Proc process[n+1];
    process[n].bt = INT_MAX;
	for(i=0; i<n; i++) { // Input loop
		scanf("%d %d", &process[i].at, &process[i].bt);
        process[i].rem = process[i].bt;
        process[i].ct = 0;
	}
    scanf("%d", &quantum);
    curr = 0;
    minidx = n;
    while(allproc(process, n)) {
        minidx = minidx % n;
        for(j=0; j<n; j++) {
            if(q < quantum && process[j].at <= time && process[j].rem > 0) {
                minidx = j;
                q = quantum;
            }
        }
        q--;
        time++;
        process[minidx].rem = process[minidx].rem - 1;
        process[minidx].ct = time;
        process[minidx].tat = process[minidx].ct - process[minidx].at;
        process[minidx].wt = process[minidx].tat - process[minidx].bt;
        minidx++;
    }
	printf("\n%d\n", time);
	for(i=0; i<n; i++) {
		printf("%d %d %d %d %d\n", process[i].at, process[i].bt, process[i].ct, process[i].tat, process[i].wt);
	}
	float avg_tat=0;
	float avg_wt=0;
	for(i=0; i<n; i++) {
		avg_tat += process[i].tat;
		avg_wt += process[i].wt;
	}
	avg_tat = avg_tat/n;
	avg_wt = avg_wt/n;
	printf("Average tat: %.2f\n", avg_tat);
	printf("Average wt: %.2f\n", avg_wt);
	return 0;
}
/*
5
2 6
5 2
1 8
0 3
4 4
Avg tat =
Avg wt =
*/
