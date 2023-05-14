#include <stdio.h>
#include <limits.h>

struct Proc {
	int at;
	int bt;
	int ct;
	int tat;
	int wt;
    int pri;
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
	int n, time=0, i, j, minidx, curr, prev=n;
	scanf("%d", &n);
	struct Proc process[n+1];
    process[n].bt = INT_MAX;
    process[n].pri = INT_MAX;

    int a[] = {4, 1, 0, 3, 2};
    int b[] = {2, 1, 8, 4, 5};
    int p[] = {2, 4, 4, 1, 2};

	for(i=0; i<n; i++) { // Input loop
		// scanf("%d %d %d", &process[i].at, &process[i].bt, &process[i].pri);
        process[i].at = a[i];
        process[i].bt = b[i];
        process[i].pri = p[i];
        process[i].rem = process[i].bt;
        process[i].ct = 0;
	}
    curr = 0;
    prev = n;
    while(allproc(process, n)) {
        minidx = n;
        for(j=0; j<n; j++) {
            if(process[j].at <= time && process[j].rem > 0 && process[j].pri < process[minidx].pri) {
                if(process[j].pri == process[prev].pri) {
                    minidx = prev;
                } else {
                    minidx = j;
                }
            }
        }
        time++;
        printf("%d ", minidx+1);
        process[minidx].rem = process[minidx].rem - 1;
        process[minidx].ct = time;
        process[minidx].tat = process[minidx].ct - process[minidx].at;
        process[minidx].wt = process[minidx].tat - process[minidx].bt;
        prev = minidx;
    }
	printf("\n%d\n", time);
	for(i=0; i<n+1; i++) {
		printf("%d %d %d %d %d %d\n", process[i].at, process[i].bt, process[i].pri, process[i].ct, process[i].tat, process[i].wt);
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
