#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define lld long long
#define MAX 309

using namespace std;

int n,k,m,a,b,wynik=309;
vector<int> krawy[MAX];
int usy[MAX];
int odw[MAX];
int dp[MAX];
vector<int> lan[5];

int bfs(){
    for(int i=n;i>=1;--i){
        int maxi=0;
        if(usy[i]){
            dp[i]=0;
            continue;
        }
        for(int j=0;j<krawy[i].size();++j){
            if(!usy[krawy[i][j]]){
                maxi=max(maxi,dp[krawy[i][j]]);
            }

        }
        dp[i]=maxi+1;
    }
}

int solve(int kk, int kto){
    if(kk==k){
        usy[kto]=1;
        bfs();
        //int pocz=0;
        int maxi=0;
        for(int i=1;i<=n;++i){
            maxi=max(maxi,dp[i]);
        }
        usy[kto]=0;
        wynik=min(wynik,maxi);
        return maxi;
    }else{
        int mini=MAX;
        lan[kk].clear();
        int pocz=0;
        int maxi=0;
        usy[kto]=1;
        bfs();
        for(int i=1;i<=n;++i){
            if(dp[i]>maxi){
                maxi=dp[i];
                pocz=i;
            }
        }
        int gdz=pocz;
        lan[kk].pb(pocz);
        for(int i=0;i<maxi-1;++i){
            for(int j=0;j<krawy[gdz].size();++j){
                if(!usy[krawy[gdz][j]]&&dp[krawy[gdz][j]]==maxi-i-1){
                    lan[kk].pb(krawy[gdz][j]);
                    gdz=krawy[gdz][j];
                    break;
                }
            }
        }
        for(int i=0;i<lan[kk].size();++i){
            mini=min(mini,solve(kk+1,lan[kk][i]));
        }
        usy[kto]=0;
        return mini;
    }
}

int main()
{
    scanf("%d%d%d",&n,&m,&k);
    for(int i=0;i<m;++i){
        scanf("%d%d",&a,&b);
        krawy[a].pb(b);
    }
    if(k==n){
        printf("0");
    }else{
        solve(0,0);
        printf("%d",wynik);
    }

    return 0;
}
