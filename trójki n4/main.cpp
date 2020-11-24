#include <bits/stdc++.h>
#define lld long long
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define MAX 109
#define MOD 1000000007

using namespace std;

int n;
lld dp[109][109][109][2];
lld tab[MAX];
lld wynik;
int ite=0;

int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;++i){
        scanf("%lld",&tab[i]);
    }
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            dp[0][i][j][1]=1;
        }
    }
    for(int i=2;i<n;++i){

        for(int j=0;j<n;++j){
            for(int x=0;x<n;++x){
                for(int d=0;d<n;++d){
                    dp[j][x][d][0]=dp[0][j][x][1]*tab[max(j,max(x,d))];
                    dp[j][x][d][0]%=MOD;

                }
            }
        }
        for(int x=0;x<n;++x){
            for(int d=0;d<n;++d){
                dp[0][x][d][1]=0;

            }
        }
        for(int j=0;j<n;++j){
            for(int x=0;x<n;++x){
                for(int d=0;d<n;++d){
                    dp[0][x][d][1]+=dp[j][x][d][0];
                    dp[0][x][d][1]%=MOD;

                }
            }
        }

    }
     for(int x=0;x<n;++x){
        for(int d=0;d<n;++d){
            wynik+=dp[0][x][d][1];
            wynik%=MOD;
        }
    }
    printf("%lld",wynik);
    return 0;
}
