#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	//input 
	int n; 
	scanf("%d",&n);
	
	int arr[n+1];
	int k;
	for(k=1; k<=n; k++)	scanf("%d",&arr[k]);
		
	
	//2차원 배열 dp
	int dp[n+1][n+1]; 	
	int i; int j;
	for(i=1; i<=n; i++)
		for(j=1; j<=n; j++) dp[i][j]=0; 
	
	//length 1 : 2  	
	for(i=1; i<=n;i++)
	{
		dp[i][i]=1;
		if(arr[i]==arr[i+1]) dp[i][i+1]=1;		
	} 
	
	//length 3 : 
	for(i=3; i<=n; i++)
	{		
		for(j=1; j<=n-i+1; j++)
		{
			if(dp[j+1][i+j-2] == 1 && arr[j] == arr[j+i-1] ) dp[j][j+i-1] = 1;  
			else dp[j][j+i-1] = 0;
		}
			
	}
	
	//output  
	int m;
	scanf("%d",&m);
	for(i=1;i<=m;i++)
	{
		int a; int b;
		scanf("%d %d",&a,&b);
		printf("%d\n",dp[a][b]);
	}	 
	return 0;
}
