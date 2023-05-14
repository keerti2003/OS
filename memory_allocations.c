#include<stdio.h>
int main(){
	int n,m;
	printf("Enter number of processes :\n");
	scanf("%d",&n);
	printf("Enter number of memory allocations :\n");
	scanf("%d",&m);
	int psize[n],memsize[m];
	printf("Enter the process req size: \n");
	for(int i=0;i<n;i++){
		scanf("%d",&psize[i]);
	}
	printf("Enter free memory space size: \n");
	for(int j=0;j<m;j++){
		scanf("%d",&memsize[j]);
	}
	
	//first fit allocation stratergy
	printf("FIRST FIT MEMORY ALLOCATION STRATERGY\n");
	int fdone[m],p1[n];
	for(int i=0;i<m;i++){
		fdone[i] = 0;
	}
	for(int i=0;i<n;i++){
		p1[i] = 0;
	}
	int indx;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(psize[i]<=memsize[j] && fdone[j]!=1){
				indx = j;
				p1[i] = 1;
				fdone[j]=1;
				break;
			}
			else{
				p1[i] = 0;
			}
		}
		if(p1[i]!=0){
			printf("Process %d is allocated to memory of size %d\n",i+1,memsize[indx]);
		}
		if (p1[i]==0){
			printf("Process %d cannot be allocated\n",i+1);
		}
	}
		
	//best fit allocation stratergy
	int p2[n];
	for(int i=0;i<n;i++){
		p2[i] = 0;
	}
	printf("BEST FIT MEMORY ALLOCATION STRATERGY\n");
	int memsize1[m];
	for(int i=0;i<m;i++){
		memsize1[i] = memsize[i];
	}
	int temp1;
	for(int i=0;i<m;i++){
		for(int j=i+1;j<m;j++){
			if(memsize1[i]>memsize1[j]){
				temp1 = memsize1[i];
				memsize1[i] = memsize1[j];
				memsize1[j] = temp1;
			}
		}
	}
	int bdone[m];
	for(int i=0;i<m;i++){
		bdone[i]=0;
	}
	int indx1;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(psize[i]<=memsize1[j] && bdone[j]!=1){
				p2[i] = 1;
				indx1 = j;
				bdone[j]=1;
				break;
			}
			else{
				p2[i] = 0;
			}	
		}
		if(p2[i]!=0){
			printf("Process %d is allocated to memory of size %d\n",i+1,memsize1[indx1]);
		}
		if(p2[i]==0){
			printf("Process %d cannot be allocated\n",i+1);
		}
	
	}
	//worst fit allocation stratergy
	int p3[n];
	for(int i=0;i<n;i++){
		p3[i] = 0;
	}
	printf("WORST FIT MEMORY ALLOCATION STRATERGY\n");
	int memsize2[m];
	for(int i=0;i<m;i++){
		memsize2[i] = memsize[i];
	}
	int temp2;
	for(int i=0;i<m;i++){
		for(int j=i+1;j<m;j++){
			if(memsize2[i]<memsize2[j]){
				temp2 = memsize2[i];
				memsize2[i] = memsize2[j];
				memsize2[j] = temp2;
			}
		}
	}
	int wdone[m];
	for(int i=0;i<m;i++){
		wdone[i]=0;
	}
	int indx2;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(psize[i]<=memsize2[j] && wdone[j]!=1){
				p3[i]= 1;
				indx2 = j;
				wdone[j]=1;
				break;
			}
			else{
				p3[i] = 0;
			}	
		}
		if(p3[i]!=0){
			printf("Process %d is allocated to memory of size %d\n",i+1,memsize2[indx2]);
		}
		if(p3[i]==0){
			printf("Process %d cannot be allocated\n",i+1);
		}
	}
	return 0;	
}
