#include <bits/stdc++.h>
#define pb push_back
#define lld long long
#define mp make_pair
#define f first
#define s second
#define MAX 209

using namespace std;

int n,tab[MAX];
int dp[MAX][MAX];

int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;++i){
        scanf("%d",&tab[i]);
    }
    for(int i)
    for(int i=0;i<n;++i){
        dp[i][i]=1;
    }
    for(int i=2;i<=n;++i){
        for(int j=0;j<=n-i;++j){
            int pocz=j;
            int kon=j;
            for(int z=j;z<=j+i-1;++z){
                int temp=tab[z];
                pocz=z;
                kon=z;
                while(z<=j+1-2&&tab[z+1]==temp){
                    ++z;
                }
                kon=z;

            }
        }
    }
    return 0;
}
