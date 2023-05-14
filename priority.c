#include<stdio.h>

int main(){
	int n;
	printf("Enter the total number of processes\n");
	scanf("%d",&n);
	
	int x[n],pid[n],ct[n],tat[n],wt[n];
	int at[] = {2,5,1,0,4};
	int bt[] = {6,2,8,3,4};
	int pty[] = {5,4,1,2,3};
	
	for(int i=0;i<n;i++){
		x[i] = 0;
	}
	
	for(int i=0;i<n;i++){
		pid[i] = i+1;
	}
	
	/*for(int i=0;i<n;i++){
		printf("Enter the Arrival time of %d: ",i+1);
		scanf("%d",&at[i]);
	}
	
	for(int i=0;i<n;i++){
		printf("Enter the Burst time of %d: ",i+1);
		scanf("%d",&bt[i]);
	}
	
	for(int i=0;i<n;i++){
		printf("Enter the Priority of %d: ",i+1);
		scanf("%d",&pty[i]);
	}*/
	
	int min = at[0];
	int mindx = 1000;
	for(int i=0;i<n;i++){
		if(min>at[i]){
			min = at[i];
			mindx = i;
		}
		else if(min==at[i]){
			if(pty[mindx]>pty[i]){
				min = at[i];
				mindx = i;
			}
		}
	}
	
	ct[mindx] = bt[mindx];
	int time = bt[mindx];
	x[mindx] = 1;
	int k = 9999;
				
	int j;	
	//int pmin = 10000; 
	while(j>=0 && j<n-1){
		int pmin = 1000; 
		for(int i=0;i<n;i++){
			if(pty[i]<=pmin && at[i]<=time && x[i]!=1){
				//pmindx = i;
				pmin = pty[i];
			}
			/*if(pty[i]==pmindx && at[i]<=time && x[i]!=1){
				pmindx = i;
			}*/
		}
		int pmindx;
		for(int i=0;i<n;i++){
			if(pty[i]==pmin){
				pmindx = i;
			}
		}
		x[pmindx] = 1;
		ct[pmindx] = time+bt[pmindx];
		time = time+bt[pmindx];
		j++;
	}
	
	for(int i=0;i<n;i++){
		tat[i] = ct[i]-at[i];
	}
	
	for(int i=0;i<n;i++){
		wt[i] = tat[i]-bt[i];
	}
	
	printf("PID \t AT \t BT \t PRIORITY \t CT \t TAT \t WT \n");
	for(int i=0;i<n;i++){
		printf("%d \t %d \t %d \t %d \t \t %d \t %d \t %d \n",pid[i],at[i],bt[i],pty[i],ct[i],tat[i],wt[i]) ;
	}
	return 0;
}
	
		

		
	
	
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
