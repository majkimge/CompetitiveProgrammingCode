#include<bits/stdc++.h>
#define lld long long
#define lld1 long long
#define pb push_back
#define mp make_pair
#define MAX 200009
#define f first
#define s second

using namespace std;

lld n;
lld1 wyn;
lld gleb[MAX];
lld oczy;
lld prod[MAX];
vector<lld> v[MAX];

bool cmp(pair<pair<lld,lld>,lld > a,pair<pair<lld,lld>,lld > b){
    if(a.f.f!=b.f.f) return a.f.f>b.f.f;
    if(a.f.s!=b.f.s) return a.f.s<b.f.s;
    return 1;
}

void dfs(lld from,lld1 gleby){
    gleb[from]=gleby;
    wyn+=prod[from]*gleby;
    for(int i=0;i<v[from].size();++i){
        dfs(v[from][i],gleby+1);
    }
}

pair<pair<lld,lld>,lld > dfs2(lld from){
    if(v[from].size()==0){

        return mp(mp(1,prod[from]),from);
    }
    lld najm=MAX;
    lld najm1=MAX;
    lld snajm=MAX;
    lld snajm1=MAX;
    lld big=0;
    lld sbig=0;
    lld suma=0;
    for(int i=0;i<v[from].size();++i){
        pair<pair<lld,lld>,lld > temp=dfs2(v[from][i]);
        if(temp.f.s<najm){
            najm1=najm;
            snajm1=snajm;
            najm=temp.f.s;
            snajm=temp.s;
        }else if(temp.f.s<najm1){
            najm1=temp.f.s;
            snajm1=temp.s;

        }
        if(temp.f.f>big){
            big=temp.f.f;
            sbig=temp.s;
        }
        //cout<<temp.f.f;
        suma+=temp.f.f;
    }
    //cout<<suma;
    if(big>suma-big){
        if(sbig==snajm){
            wyn+=(big*2-suma)*najm;
        }else{
            wyn+=(big*2-suma)*najm;
        }
    }else{
        if(suma%2){
            wyn+=najm;
        }
    }
    return mp(mp(suma+1,min(najm,prod[from])),from);

}

pair<pair<lld,lld>,lld1 > dfs3(lld from){
    if(v[from].size()==0) return mp(mp(1,prod[from]),from);
    vector<pair<pair<lld,lld1>,lld > >poz;
    vector<pair<pair<lld1,lld>,lld > >najm;
    for(int i=0;i<v[from].size();++i){
        pair<pair<lld,lld1>,lld > temp=dfs3(v[from][i]);
        poz.pb(temp);
        najm.pb(mp(mp(temp.f.s,temp.f.f),temp.s));
    }
    sort(poz.begin(),poz.end(),cmp);
    sort(najm.begin(),najm.end());
    lld ile=0;
    lld ter=0;
    lld suma=0;
    lld wyn1=0;
    for(int i=0;i<najm.size();++i){

        suma+=najm[i].f.s;
    }
    if(poz[0].f.f>suma-poz[0].f.f){
        if(poz[0].s==najm[0].s){
            wyn+=(poz[0].f.f*2-suma)*najm[1].f.f;
        }else{
            wyn+=(poz[0].f.f*2-suma)*najm[0].f.f;
        }
    }else{
        if(suma%2){
            wyn+=najm[0].f.f;
        }
    }
    return mp(mp(suma+1,min((lld1)najm[0].f.f,prod[from])),from);

}

int main()
{
    scanf("%lld",&n);
    for(int i=2;i<=n;++i){
        scanf("%lld",&oczy);
        v[oczy].pb(i);
    }
    bool prpr=1;
    for(int i=2;i<=n;++i){
        scanf("%lld",&prod[i]);
        if(prod[i]!=1) prpr=0;
    }
    dfs(1,0);
    if(prpr){
        dfs2(1);
    }else{
        dfs3(1);
    }

    printf("%lld",wyn);
    return 0;
}
