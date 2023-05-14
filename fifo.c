#include<stdio.h>
int main(){
	printf("Enter no. page references\n");
	int m;
	scanf("%d",&m);
	int pr[m];
	printf("Enter page references sequence\n");
	for(int i=0;i<m;i++){
		scanf("%d",&pr[i]);
	}
	int n;
	printf("Enter frame size\n");
	scanf("%d",&n);
	int f[n];
	for(int i=0;i<n;i++){
		f[i] = pr[i];
	}
	int c=n;
	int k=0;
	for(int i=n;i<m;i++){
		int flag;
		for(int j=0;j<n;j++){
			if(pr[i]!=f[j]){
				flag = 1;
			}
			else{
				flag=0;
				break;
			}
		}
		if(flag==1){
			c++;
			f[k] = pr[i];
			if(k==n-1){
				k=-1;
			}
			k++;
		}
	}
	printf("The page fault is: %d\n",c);
	return 0;
}

