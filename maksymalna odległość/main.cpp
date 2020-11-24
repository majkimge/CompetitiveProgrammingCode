#include<bits/stdc++.h>
#define lld long long
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define MAX 500009

using namespace std;

pair<lld,lld> tab[4][MAX];
lld wyny[MAX],n,a,b,c;

int main()
{
    scanf("%lld",&n);
    for(int i=0;i<n;++i){
        scanf("%lld%lld%lld",&a,&b,&c);
        tab[0][i]=mp(a+b+c,i);
        tab[1][i]=mp(-a+b+c,i);
        tab[2][i]=mp(a-b+c,i);
        tab[3][i]=mp(a+b-c,i);
    }
    for(int i=0;i<4;++i)sort(tab[i],tab[i]+n);

    for(int i=0;i<n;++i){
        for(int j=0;j<4;++j){
            wyny[tab[j][i].s]=max(wyny[tab[j][i].s],abs(tab[j][i].f-tab[j][0].f));
            wyny[tab[j][i].s]=max(wyny[tab[j][i].s],abs(tab[j][i].f-tab[j][n-1].f));
        }
    }
    for(int i=0;i<n;++i){
        printf("%lld\n",wyny[i]);
    }
    return 0;
}
