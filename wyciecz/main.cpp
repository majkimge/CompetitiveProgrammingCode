#include <bits/stdc++.h>
#define lld long long
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define MAX 1000009

using namespace std;

int n,m,a,b,c,d;
vector<int> kraw[MAX];
queue<pair<int,int> > q;
int odw[MAX];
int nak[MAX];
int odl[MAX];
int zaka[MAX];
lld wynik;
vector<int> zost;

void bfsa(){
    while(!q.empty()){
        int ter=q.front().f;
        int od=q.front().s;
        odl[ter]=min(odl[ter],od);
        q.pop();
        odw[ter]=1;
        nak[ter]=0;
        for(int i=0;i<kraw[ter].size();++i){
            if(!nak[kraw[ter][i]]&&(!odw[kraw[ter][i]])){
                q.push(mp(kraw[ter][i],od+1));
                nak[kraw[ter][i]]=1;
            }
        }
    }
}

void bfsb(){
    while(!q.empty()){
        int ter=q.front().f;
        int od=q.front().s;
        odl[ter]=min(odl[ter],od);
        q.pop();
        odw[ter]=1;
        nak[ter]=0;

        for(int i=0;i<kraw[ter].size();++i){
            zaka[kraw[ter][i]]=ter;
        }
        for(int i=0;i<zost.size();++i){
            if(zaka[zost[i]]!=ter){
                q.push(mp(zost[i],od+1));
                swap(zost[i],zost[zost.size()-1]);
                zost.pop_back();
            }
        }
    }
}

int main()
{
    scanf("%d%d%d%d",&n,&m,&a,&b);
    for(int i=0;i<m;++i){
        scanf("%d%d",&c,&d);
        kraw[c].pb(d);
        kraw[d].pb(c);
    }
    for(int i=2;i<=n;++i){
        zost.pb(i);
        odl[i]=n+1;
    }
    odl[1]=0;
    if(a<b){
        q.push(mp(1,0));
        nak[1]=1;
        bfsa();
        wynik=(lld)odl[n]*a;
        int czyk=0;
        for(int i=0;i<kraw[1].size();++i){
            if(kraw[1][i]==n)czyk=1;
        }
        if(!czyk)wynik=min(wynik,(lld)b);
    }else{
        q.push(mp(1,0));
        nak[1]=1;
        bfsb();
        wynik=(lld)odl[n]*b;
        int czyk=0;
        for(int i=0;i<kraw[1].size();++i){
            if(kraw[1][i]==n)czyk=1;
        }
        if(czyk)wynik=min(wynik,(lld)a);
    }
    printf("%lld",wynik);
    return 0;
}
