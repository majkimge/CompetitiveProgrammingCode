#include <bits/stdc++.h>
#define lld long long
#define MAX 100009
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define INF 1000000000
#define MOD 1000696969

using namespace std;

int n,m,a,b,wynik,akt;
int kolor[MAX];
pair<int,int>kraw[MAX];
vector<int> krawy[MAX];
int dp[1029];

lld pot(lld co,lld dok){
    if(dok==0){
        return 1;
    }else
    if(dok==1){
        return co;
    }else if(dok%2==0){
        lld temp=pot(co,dok/2);
        temp%=MOD;
        return (temp*temp)%MOD;
    }else{
        return ((pot(co,dok-1)%MOD)*co)%MOD;
    }
}

int main()
{
    scanf("%d",&n);
    for(int i=0;i<n-1;++i){
        scanf("%d",&a);
        scanf("%d",&b);
        kraw[i]=mp(a,b);
        a.pb(b);
        b.pb(a);
    }
    int k=1;
    k<<=(n-1);
    for(int i=1;i<k;++i){
        dp[i]=INF;
    }
    for(int i=0;i<k;++i){
        for(int j=0;j<n-1;++j){
            if(kol)
        }
    }
}
