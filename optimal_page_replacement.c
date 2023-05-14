#include<stdio.h>

int main(){
	int m,n;
	printf("Enter number of page references: ");
	scanf("%d",&m);
	int pr[m];
	printf("Enter page references: ");
	for(int i=0;i<m;i++){
		scanf("%d",&pr[i]);
	}
	printf("Enter frame size: ");
	scanf("%d",&n);
	int f[n],q[n];
	//enterning first n size pr to f
	for(int i=0;i<n;i++){
		f[i] = pr[i];
		q[i] = pr[i];
	}
	int c=n;
	//printf("cnt: %d\n",c);
	int cnt[n],pos[n];
	for(int i=n;i<m;i++){
		for(int k=0;k<n;k++){
			cnt[k]=0;
		}
		for(int k=0;k<n;k++){
			pos[k]=0;
		}
		int flag;
		for(int j=0;j<n;j++){
			if(pr[i]!=f[j]){
				flag=1;
			}
			else{
				flag=0;
				break;
			}
		}
		if(flag==1){
			//c++;
			for(int j=i+1;j<m;j++){ 
				for(int k=0;k<n;k++){
					if(pr[j]==f[k]){
						cnt[k]++; //counting the occurrence of f array elements wrt pr elements
						
					}
				}
			}
			int o=0;
			while(o<n){
				int ch=f[o];
				for(int j=i+1;j<m;j++){
					if(ch==pr[j]){
						pos[o]=j;
						break;
					}
				}
				o++;
			}
			int fl;
			int cn=0;
			for(int j=0;j<n;j++){
				if(cnt[j]==0){
					fl=0;
					break;
				}
				else{
					cn++;
					//if none of the count array elements are 0 then f = 1					
					if(cn==n){
						fl = 1;
					}
				}
				
			}
			if(fl==1){
				c++;
				int max=-10;
				for(int l=0;l<n;l++){
					if(max<pos[l]){
						max = pos[l];
					}
				}
				int del = pr[max];
				for(int j=0;j<n;j++){
					if(f[j]==del){
						f[j] = pr[i];
						for(int l=j+1;l<n;l++){
							q[l-1] = q[l];
						}
						q[n-1] = pr[i];
						break;
					}
				}
				
			}
			//int indxc[n],s=-1;
			else{
				//if count=0
				c++;
				int indxc[n],s=-1;
				for(int j=0;j<n;j++){
					if(cnt[j]==0){
						indxc[++s] = j;
					}
				}
				//if only one element will not come in the further sequence
				if(s<1){
					int t = indxc[0];
					f[t] = pr[i];
					//c++;
					for(int j=t+1;j<n;j++){
						q[j-1] = q[j];
					}
					q[n-1] = pr[i];
				}
				//if more than one element will not come in future
				else{
					int que[s],t=0,indx=-1;
					for(int j=0;j<n;j++){
						if(q[j]==f[indxc[t]]){
							que[++indx] = j;
							t++;
						}
					}
					int min = 100;
					for(int j=0;j<t;j++){
						if(que[j]<min){
							min = que[j];
						}
					}
					f[min] = pr[i];
					for(int j=min-1;j<n;j++){
						q[j-1] = q[j];
					}
					q[n-1] = pr[i];
					//c++;
				}
				/*for(int p=0;p<n;p++){
					printf("frame: %d ",f[p]);
				}
				printf("\n");
				for(int p=0;p<n;p++){
					printf("queue: %d ",q[p]);
				}
				printf("\n");
				printf("cnt: %d\n",c);*/
			}
		}
	}
	printf("Page faults: %d\n",c);
	return 0;
}
				
				
				
				
				
				
				
				
				
				
