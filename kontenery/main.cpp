#include <bits/stdc++.h>
#define lld long long
#define MAX 100009
#define PIER 318
#define pb push_back
#define mp make_pair
#define f first
#define s second

using namespace std;

lld n,k,a,l,d,temp,ws1,doda;
vector<pair<lld,lld> > tab[MAX];
lld tab1[MAX];
lld mocarz[PIER][PIER];
int main()
{
    scanf("%lld",&n);
    scanf("%lld",&k);
    for(int i=0;i<k;++i){
        scanf("%lld",&a);
        scanf("%lld",&l);
        scanf("%lld",&d);
        if(d<PIER){
            tab[a].pb(mp(d,a%d));
            tab[a+(l-1)*d+1].pb(mp(-d,a%d));
        }else{
            temp=l;
            ws1=a;
            while(temp>0){
                tab1[ws1]++;
                ws1+=d;
                temp--;
            }
        }

    }
    for(int i=1;i<=n;++i){
        for(int j=0;j<tab[i].size();++j){
            if(tab[i][j].f>0){
                mocarz[tab[i][j].f][tab[i][j].s]++;
            }else{
                mocarz[-tab[i][j].f][tab[i][j].s]--;
            }
        }
        doda=0;
        for(int j=1;j<PIER;++j){
            doda+=mocarz[j][i%j];
        }
        printf("%lld ",doda+tab1[i]);
    }
    return 0;
}
