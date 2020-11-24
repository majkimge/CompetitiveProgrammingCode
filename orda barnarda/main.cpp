#include<bits/stdc++.h>
#define lld long long
#define pb push_back
#define mp make_pair
#define MAX 1000009
#define f first
#define s second
#define INF 1000000000
#define MOD 1000696951
#define MOD1 1000000009

using namespace std;

int n,m;
int tab[MAX];
int dp[MAX];

int bin(int l,int p){
    int s=(l+p)/2;
    int wyn=INF;
    while(l<=p){
        s=(l+p)/2;
        dp[s+1]=0;
        dp[s+2]=0;
        int czy=0;
        for(int i=s;i>=0;--i){
            if(tab[i]==2){
                dp[i]=dp[i+1]+dp[i+2]+1;

            }else if(tab[i]==1){
                dp[i]=dp[i+1]*2+1;
            }else{
                dp[i]=dp[i+1];
            }
            if(dp[i]>=m){
                czy=1;
                break;
            }
        }
        if(dp[0]>=m||czy){
            p=s-1;
            wyn=min(wyn,s);
        }else{
            l=s+1;
        }

    }
    return wyn;
}

int main()
{
    scanf("%d",&n);
    scanf("%d",&m);
    for(int i=0;i<n;++i){
        scanf("%d",&tab[i]);
    }
    int temp=bin(0,n-1);
    if(temp!=INF){
        printf("%d",temp+1);
    }else{
        printf("NIE");
    }

    return 0;
}
