#include <bits/stdc++.h>
#define lld long long
#define MAX 300009
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define pii pair<lld,lld>

using namespace std;

lld czy=1,n,m,a,b,pocz,zost,q;
lld tab[MAX];
lld dodl[MAX];
set<pair<lld,pii> >s;
lld INF=2000000000000000001;

int main()
{
    cin>>n;
    for(int i=0;i<n;++i){
        cin>>tab[i];
    }
    sort(tab,tab+n);
    for(int i=0;i<n-1;++i){
        dodl[i]=tab[i+1]-tab[i];
    }
    pocz=n;
    zost=n;
    sort(dodl,dodl+n-1);
    lld mamy=0;
    lld poprz=0;
    for(int i=0;i<n-1;++i){
        if(dodl[i]==0){
            pocz--;
            zost--;
            continue;
        }
        lld sumik=1;
        while(i<n-2&&dodl[i]==dodl[i+1]){
            ++i;
            sumik++;
        }
        //cout<<dodl[i]<<" "<<mamy<<" "<<poprz<<" "<<sumik<<" "<<zost<<endl;
        s.insert(mp(dodl[i],mp(mamy+zost*(dodl[i]-poprz),zost-sumik)));
        mamy+=zost*(dodl[i]-poprz);
        zost-=sumik;
        poprz=dodl[i];
    }
    s.insert(mp(0,mp(0,pocz)));
    cin>>q;
    for(int i=0;i<q;++i){
        cin>>a;
        cin>>b;
        lld dl=b-a+1;
        pair<lld,pii> ter=(*(--s.upper_bound(mp(dl,mp(INF,INF)))));
        //cout<<ter.s.s;
        cout<<ter.s.f+(ter.s.s*(dl-ter.f))<<" ";
    }
    return 0;
}
