#include<stdio.h>

int main(){
	int n;
	printf("Enter the total number of processes\n");
	scanf("%d",&n);
	
	int x[n],pid[n],at[n],bt[n],ct[n],tat[n],wt[n];
	
	for(int i=0;i<n;i++){
		x[i] = 0;
	}
	
	for(int i=0;i<n;i++){
		pid[i] = i+1;
	}
	
	for(int i=0;i<n;i++){
		printf("Enter the Arrival time of %d: ",i+1);
		scanf("%d",&at[i]);
	}
	
	for(int i=0;i<n;i++){
		printf("Enter the Burst time of %d: ",i+1);
		scanf("%d",&bt[i]);
	}
	
//	int min1;
	int time=0,j=0;
	while (j>=0 && j<n){
		int min1 = 1000;
		//int indx1 = 10;
		for(int i=0;i<n;i++){
			if(at[i]<min1 && x[i]!=1){
				min1 = at[i];
				//indx1 = i;
			}
		}
		//printf("%d \n",min1);
		int indx1;
		//printf("%d \n",indx1);
		for(int i=0;i<n;i++){
			if(at[i]==min1){
				indx1 = i;
			}
		}
		x[indx1] = 1;
		ct[indx1] = time+bt[indx1];
		time = time + bt[indx1];
		j++;
	}
	
	for(int i=0;i<n;i++){
		tat[i] = ct[i]-at[i];
	}
	
	for(int i=0;i<n;i++){
		wt[i] = tat[i]-bt[i];
	}
	
	printf("PID \t AT \t BT \t CT \t TAT \t WT \n");
	for(int i=0;i<n;i++){
		printf("%d \t %d \t %d \t %d \t %d \t %d \n",pid[i],at[i],bt[i],ct[i],tat[i],wt[i]) ;
	}
	return 0;
}
	
