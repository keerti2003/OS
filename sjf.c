#include<stdio.h>

int main(){
	int n;
	printf("Enter the total number of processes\n");
	scanf("%d",&n);
	
	/*int x[n],pid[n],ct[n],tat[n],wt[n];
	int at[] = {2,5,1,0,4};
	int bt[] = {6,2,8,3,4};*/
	
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
	
	for(int i=0;i<n;i++){
		printf("Enter the Priority of %d: ",i+1);
		scanf("%d",&pty[i]);
	}
	
	int min = at[0];
	int mindx = 1000;
	for(int i=0;i<n;i++){
		if(min>at[i]){
			min = at[i];
			mindx = i;
		}
	}
	
	ct[mindx] = bt[mindx];
	int time = bt[mindx];
	x[mindx] = 1;
				
	int j;	
	//int smin = bt[0]; 
	while(j>=0 && j<n-1){
		int smin=1000; 
		for(int i=0;i<n;i++){
			if(bt[i]<smin && x[i]!=1 && at[i]<=time){
				smin = bt[i];
			}
		}
		int smindx;
		for(int i=0;i<n;i++){
			if(bt[i]==smin){
				smindx = i;
			}
		}
		//printf("%d\n",smindx);
		x[smindx] = 1;
		ct[smindx] = time+bt[smindx];
		time = time + bt[smindx];
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
	
		

		
	
	
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
