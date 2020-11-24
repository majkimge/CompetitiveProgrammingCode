#include <bits/stdc++.h>
#define pbpush_back
#define mp make_pair
#define lld long long
#define f first
#define s second
#define MAX 1000009
#define INF 2000000009

using namespace std;

lld n,k1,l,k2,suma,wynik;
priority_queue<pair<pair<int,int>,int> >bloki[6];
pair<pair<lld,lld>,pair<lld,lld> > wszy[MAX];
pair<pair<lld,lld>,pair<lld,lld> > wszy1[MAX];
int odw[MAX];


lld solve(lld kt){
    lld wyn=0;
    wynik+=wszy[kt].f.f;
    int ll=wszy[kt].s.f;
    int pp=wszy[kt].s.s;
    while(1){
        int zm=0;
        while(!bloki[ll].empty()&&odw[bloki[ll].top().f.s]){
            bloki[ll].pop();
        }
        if(bloki[ll].empty()){
            break;
        }else{
            odw[bloki[ll].top().f.s]=1;
            wyn+=bloki[ll].top().f.f;
            ll=bloki[ll].top().f.s;
            bloki[ll].pop();
        }

    }
    while(1){
        int zm=0;
        while(!bloki[pp].empty()&&odw[bloki[pp].top().f.s]){
            bloki[pp].pop();
        }
        if(bloki[pp].empty()){
            break;
        }else{
            odw[bloki[pp].top().f.s]=1;
            wyn+=bloki[pp].top().f.f;
            pp=bloki[pp].top().f.s;
            bloki[pp].pop();
        }

    }
    return wyn;
}

int main()
{
    scanf("%lld",&n);
    for(int i=0;i<n;++i){
        scanf("%lld%lld%lld",&k1,&l,&k2);
        if(k1>k2) swap(k1,k2);
        bloki[k1].push(mp(mp(i,k2),l));
        bloki[k2].push(mp(mp(i,k1),l));
        wszy[i]=mp(mp(l,i),mp(k1,k2));
        wszy1[i]=wszy[i];
        //suma+=l;
    }
    sort(wszy,wszy+n);
    for(int i=n-1;i>=0;--i){
        if(!odw[wszy[i].f.s]){
            wynik=max(wynik,solve(i));
        }
    }
    printf("%d",wynik);
    return 0;
}
