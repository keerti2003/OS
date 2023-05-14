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
	int cnt[n];
	for(int l=0;l<n;l++){
		cnt[l] = 0;
	}
	int flag = 0;
	/*for(int i=0;i<m;i++){
		printf("%d ",pr[i]);
	}*/
	printf("\n");
	int bfindx=10;
	for(int i=n;i<m;i++){
		//int flag=0;
		//int indx;
		for(int j=0;j<n;j++){
			if(pr[i]!=f[j]){
				//printf("b\n");
				flag=1;
				//indx = j;
			}
			else{
				//printf("c\n");
				cnt[j]++;
				flag=0;
				break;
			}
		}
		//int k = i+1;
		if(flag==1){
			int min = 1000,minindx;
			for(int g = 0;g<n;g++){
				if(cnt[g]<min && g!=bfindx){
					//printf("f\n");
					min = cnt[g];
					minindx = g;
				}
			}
			bfindx = minindx;
			//printf("f:%d , n:%d\n",pr[i],minindx);
			f[minindx] = pr[i];
			cnt[minindx] = 0;
			c++;
		}
	}
	printf("Page fault: %d\n",c);
	return 0;
}

