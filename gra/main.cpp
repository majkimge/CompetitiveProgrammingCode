#include <bits/stdc++.h>
#define lld long long
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define MAX 109
#define MOD 1000000007
#define INF 1000696969

using namespace std;

int n,m,wyn,sum;
int tab[MAX];

int main()
{
    scanf("%d",&n);
    scanf("%d",&m);
    for(int i=0;i<n;++i){
        scanf("%d",&tab[i]);
    }
    sum=0;
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            for(int t=0;t<n;++t){
                sum=tab[i]+tab[j]+tab[t];
                if(sum<=m&&i!=j&&j!=t&&i!=t){
                    wyn=max(wyn,sum);
                }
            }
        }
    }
    printf("%d",wyn);
    return 0;
}
