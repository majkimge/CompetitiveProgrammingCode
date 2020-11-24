#include <bits/stdc++.h>
#define lld long long
#define MAX 1009
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define INF 1000000000

using namespace std;

int n,m,a,b,wyn;
int tab[MAX];

int main()
{
    scanf("%d",&n);
    scanf("%d",&m);
    for(int i=0;i<m;++i){
        scanf("%d",&a);
        scanf("%d",&b);
        tab[a]++;
        tab[b]++;
    }
    for(int i=1;i<=n;++i){
        wyn+=tab[i]*(n-1-tab[i]);
    }
    printf("%d",n*(n-1)*(n-2)/6-wyn/2);
    return 0;
}
