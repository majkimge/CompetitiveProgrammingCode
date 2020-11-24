#include <bits/stdc++.h>
#define lld long long
#define mp make_pair
#define f first
#define s second
#define pb push_back
#define MAX 2009
#define INF 2000000009

using namespace std;

int dp[MAX][MAX],tab[MAX],n,pref[MAX],sr[MAX][MAX];

int bin(int l, int p){
    int ll=l;
    int pp=p;
    int s=0;
    int sum=pref[p]-pref[l-1];
    int ret=(p+l)/2;
    while(ll<=pp){
        s=(ll+pp)/2;
        if(pref[s]-pref[l-1]>=sum/2){
            ret=s;
            pp=s-1;
        }else{
            ll=s+1;
        }
    }
}

int main()
{
    scanf("%d",&n);
    srand(time(0));
    for(int i=1;i<=n;++i){
        //scanf("%d",&tab[i]);
        tab[i]=rand()%20+1;
    }
    for(int i=1;i<=n;++i){
        pref[i]=pref[i-1]+tab[i];
    }
    for(int i=1;i<=n;++i){
            sr[i][i]=i;
        for(int j=i;j<=n;++j){

            if(j>i)sr[i][j]=sr[i][j-1];
            int sumi=pref[j]-pref[i-1];
            while(pref[sr[i][j]-1]-pref[i-1]<pref[j]-pref[sr[i][j]]){
                sr[i][j]++;
            }
            //cout<<i<<" "<<j<<" "<<sr[i][j]<<endl;
        }
    }
    //cout<<sr[1][n];
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n-i+1;++j){
            dp[j][j+i-1]=INF;
            for(int z=j;z<j+i;++z){
                dp[j][j+i-1]=min(dp[j][j+i-1],tab[z]+max(dp[j][z-1],dp[z+1][j+i-1]));
            }
        }
    }
    for(int i=1;i<=n;++i){
        //if(dp[1][i-1]+tab[i]<dp[1][i-2]+tab[i-1])cout<<"XXXX"<<endl;
    }
    int w1=dp[1][n];
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n-i+1;++j){
            dp[j][j+i-1]=INF;
            for(int z=min(j+i/2,max(j,sr[j][j+i-1]-10));z<max(j+i/2,min(j+i,sr[j][j+i-1]+10));++z){
                dp[j][j+i-1]=min(dp[j][j+i-1],tab[z]+max(dp[j][z-1],dp[z+1][j+i-1]));
            }
        }
    }

    if(w1!=dp[1][n]){
        for(int i=0;i<n;++i){
            //cout<<tab[i+1]<<" ";
        }
        cout<<endl;
        cout<<w1<<" "<<dp[1][n];
    }
    return 0;
}
