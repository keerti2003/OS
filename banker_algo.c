#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define MAX_RESOURCES 5

int available[MAX_RESOURCES];
int maximum[][MAX_RESOURCES];
int allocation[][MAX_RESOURCES];
int need[][MAX_RESOURCES];
int n, m;

void inputData() {
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    printf("Enter the number of resources: ");
    scanf("%d", &m);

    printf("Enter the available resources: ");
    for(int i = 0; i < m; i++) {
        scanf("%d", &available[i]);
    }

    printf("Enter the maximum resources required by each process: \n");
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            scanf("%d", &maximum[i][j]);
        }
    }

    printf("Enter the resources already allocated to each process: \n");
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            scanf("%d", &allocation[i][j]);
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            need[i][j] = maximum[i][j] - allocation[i][j];
        }
    }
}

bool isSafe() {
    int work[MAX_RESOURCES];
    for(int i = 0; i < m; i++) {
        work[i] = available[i];
    }

    bool finish[n];
    for(int i = 0; i < n; i++) {
        finish[i] = false;
    }

    int count = 0;
    while(count < n) {
        bool found = false;
        for(int i = 0; i < n; i++) {
            if(!finish[i]) {
                int j;
                for(j = 0; j < m; j++) {
                    if(need[i][j] > work[j]) {
                        break;
                    }
                }

                if(j == m) {
                    for(int k = 0; k < m; k++) {
                        work[k] += allocation[i][k];
                    }
                    finish[i] = true;
                    found = true;
                    count++;
                }
            }
        }

        if(!found) {
            return false;
        }
    }

    return true;
}

int main() {
    inputData();
    if(isSafe()) {
        printf("The system is in a safe state\n");
    }
    else {
        printf("The system is in a deadlock state\n");
    }

    return 0;
}

