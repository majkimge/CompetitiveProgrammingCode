#include <bits/stdc++.h>
#define lld long long
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define MAX 66009
#define MAX1 131072
#define INF 1000000000

using namespace std;

int n,m,dp[MAX][109],tab[109][20],poty[20],sumpoty[20],sumix[MAX][109];



void rozl1(int kt,int sum,int ziom, int wyny){
	if(kt>=m){
		sumix[sum][ziom]=wyny;
		if(sum)sumix[sum][ziom]+=tab[ziom][0];
		return;
	}
	rozl1(kt+1,sum+poty[kt],ziom,wyny+tab[ziom][kt+1]);
	rozl1(kt+1,sum,ziom,wyny);
}

int main(){
	scanf("%d%d",&n,&m);
	
	for(int i=1;i<=n;++i){
		for(int j=0;j<=m;++j){
			scanf("%d",&tab[i][j]);
		}
	}
	poty[0]=1;
	sumpoty[0]=1;
	for(int i=1;i<20;++i){
		poty[i]=poty[i-1]*2;
		sumpoty[i]=poty[i]+sumpoty[i-1];
	}
	dp[0][0]=0;
	for(int i=0;i<17;++i){
		for(int j=0;j<MAX;++j)dp[j][i]=INF;
	}
	/*for(int i=1;i<=m;++i){
		for(int j=1;j<=n;++j){
			for(int k=1;k<=i/2;++k){
				rozl(0,k,0,0,j,0,i)
			}
			
		}
	}*/
	
	dp[0][0]=0;
	for(int i=1;i<=n;++i){
		dp[0][i]=0;
		rozl1(0,0,i,0);
	}
	for(int i=1;i<=n;++i){
		for(int j=0;j<poty[m];++j){
			//dp[j][i]=dp[j][i-1];
			for(int k=0;k<poty[m];++k){
				
				dp[(j|k)][i]=min(dp[(j|k)][i],dp[j][i-1]+sumix[k][i]);
			}
		}
	}
	printf("%d",dp[poty[m]-1][n]);
	
	return 0;
}
