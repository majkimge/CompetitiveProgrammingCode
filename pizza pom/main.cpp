#include <bits/stdc++.h>
#define lld long long
#define mp make_pair
#define f first
#define s second
#define pb push_back
#define piii pair<int,pair<int,int> >
#define pii pair<int,int>
#define MAX 300009
#pragma GCC optimalize ("ofast")


using namespace std;

int n,m,pot=1,a,b,sum;
int kraw[23];
int dp[1100000];
int poty[23];

int main()
{
    poty[0]=1;
    for(int i=1;i<23;++i){
        poty[i]=poty[i-1]*2;
    }
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;++i){
        scanf("%d%d",&a,&b);
        a--;
        b--;
        kraw[a]+=poty[b];
        kraw[b]+=poty[a];

    }
    for(int i=0;i<poty[n];++i){
        for(int j=0;j<n;++j){
            if((i&poty[j])==poty[j]&&(kraw[j]&i)){
                dp[i]=1;
                //cout<<i;
            }
        }
    }
    for(int i=0;i<poty[n];++i){
        sum+=dp[i];
    }
    cout<<poty[n]-sum;
    return 0;
}
