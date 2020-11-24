#include <bits/stdc++.h>
#define lld long long
#define mp make_pair
#define f first
#define s second
#define pb push_back
#define MAX 2009
#define pii pair<int,int>
#define MOD 1000000007

using namespace std;

lld dp[MAX][MAX][2],dpt[MAX];
lld tab[MAX],n,wynik;

int main()
{
    scanf("%lld",&n);
    for(int i=0;i<n;++i){
        scanf("%lld",&tab[i]);
    }
    int ite=1;
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j)dp[i][j][0]=1;
    }

    for(int kt=2;kt<n;++kt){
        for(int i=0;i<n;++i){
            for(int j=0;j<n;++j){
                    int tm=max(i,j);
                    dp[i][j][ite]+=dp[tm][0][ite^1]*tab[tm]+dpt[tm];
                    dp[i][j][ite]%=MOD;

            }
        }

        //cout<<wynik<<endl;
        ite=ite^1;
        for(int i=0;i<n;++i){
            for(int j=0;j<n;++j){
                    dp[i][j][ite]=0;

            }
        }

        if(kt!=n-1)
        for(int i=n-2;i>=0;--i){
            dpt[i]=0;
        }

        if(kt!=n-1)
        for(int i=0;i<n;++i){
            if(i)dpt[i]+=dp[i][0]*tab[i]
            for(int j=1;j<n;++j){
                    dp[i][0][ite^1]+=dp[i][j][ite^1];
                    dp[i][0][ite^1]%=MOD;
            }
        }



        if(kt!=n-1)
        for(int i=n-1;i>0;--i){
            for(int j=i;j>=0;--j){
                dpt
            }
        }
    }
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j)wynik+=dp[i][j][ite^1];
    }
    printf("%lld",wynik%MOD);
    return 0;
}
