#include<bits/stdc++.h>
#define lld long long
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define MAX 100009
#define pii pair<lld,lld>
#define pdd pair<double,double>
#define C 1000

using namespace std;

int k,q,ile,a,b,c;
lld tab[MAX],ile1;
pii tab1[MAX];
lld poty[40];
vector<pii> prefy[MAX/2];
/*void rob(int from, int ocz, int gl, int spec){
    if(gl==k){
        tab[ile]=ocz;
        ++ile;
        return;
    }
    rob(from*2,from,gl+1,0);
    if(spec){
        tab[ile]=from*2+1;
        ++ile;
    }
    rob(from*2+1,from,gl+1,spec);
    if(!spec){
        tab[ile]=ocz;
        ++ile;
    }
    return;
}*/

void rob(pii from, pii ocz, int gl){
    if(gl==k/2){
        tab1[ile]=ocz;
        ++ile;
        return;
    }
    rob(mp(from.f*2,from.s*2),from,gl+1);
    rob(mp(from.f*2,from.s*2+1),from,gl+1);
    if(from.f!=1){
        tab1[ile]=ocz;
        ++ile;
    }


    return;
}


void rob1(lld from, lld ocz, int gl){
    if(gl==k/2){
        if()
    }
    rob(mp(from.f*2,from.s*2),from,gl+1);
    rob(mp(from.f*2,from.s*2+1),from,gl+1);
    if(from.f!=1){
        tab1[ile]=ocz;
        ++ile;
    }


    return;
}

int main()
{
    scanf("%d%d",&k,&q);
    rob(1,0,1,1);
    poty[0]=1;
    for(int i=1;i<35;++i){
        poty[i]=poty[i-1]*2;
    }
    //for(int i=0;i<ile;++i)cout<<tab[i]<<" ";
    rob(mp(1,0),mp(0,0),1);
    for(int i=0;i<q;++i){
        scanf("%d%d%d",&a,&b,&c);
        for(int i=0;i<ile;++i){
            prefy[i%b].pb(mp(tab1[i]));
        }


        for(int i=0;i<=b;++i)prefy[i].clear();
    }
    return 0;
}
