#include <bits/stdc++.h>
#define lld long long
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define MAX 1000009
#define MOD 301

using namespace std;

lld n,k,w,c;
pair<lld,lld> dp[309][309];
vector<lld> v[309];

int main()
{
    scanf("%lld%lld",&n,&k);
    for(int i=0;i<n;++i){
        scanf("%lld%lld",&w,&c);
        v[w].pb(-c);
    }
    for(int i=1;i<309;++i){
        sort(v[i].begin(),v[i].end());
    }
    for(int i=1;i<309;++i){
        for(int j=0;j<v[i].size();++j){
            v[i][j]=-v[i][j];
        }
    }
    for(int i=1;i<=k;++i){

        int gdz=0;
        int wsk=i%MOD;
        int maxi=dp[(wsk-1+MOD)%MOD][1].f;
        for(int j=1;j<=min(i,300);++j){
            int imj=(wsk-j+MOD)%MOD;
            if(dp[imj][j].s<v[j].size()){
                if(maxi<dp[imj][j].f+v[j][dp[imj][j].s]){
                    maxi=dp[imj][j].f+v[j][dp[imj][j].s];
                    gdz=j;
                }
            }

        }
        if(gdz){
            int imj=(wsk-gdz+MOD)%MOD;
            for(int j=0;j<=300;++j){
                dp[wsk][j]=dp[imj][j];
                dp[wsk][j].f=maxi;
            }
            dp[wsk][gdz].s++;
        }else{
            int imj=(wsk-1+MOD)%MOD;
            for(int j=0;j<=300;++j){
                dp[wsk][j]=dp[imj][j];
                //dp[wsk][j].f=maxi;
            }
            //dp[wsk][gdz].s++;
        }
        printf("%lld ",dp[wsk][1].f);
    }

    return 0;
}
