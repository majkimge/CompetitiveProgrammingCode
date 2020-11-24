#include <bits/stdc++.h>
#define lld long long
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define MAX 200009
#define int uint_fast32_t
#define pii pair<int,int>

using namespace std;


pair<pii,int> tree[1000009];

int tab[MAX],prefy[MAX],dp[MAX],n,m,a,b,kk=1,wyn;
vector<int> kon[MAX];
vector<int> pocz[MAX];

void akt(int gdz){
    tree[gdz].f.f+=tree[gdz].f.s;
}
void push(int gdz){
    if(gdz<kk){
        tree[gdz*2].f.s+=tree[gdz].f.s;
        tree[gdz*2+1].f.s+=tree[gdz].f.s;
    }
    tree[gdz].f.s=0;
}

void dod(int gdz, int zakl, int zakp, int l, int p, int ile){
    if(l<=zakl&&p>=zakp){
        tree[gdz].f.s+=ile;
        akt(gdz);
        push(gdz);
    }else if(l>zakp||p<zakl){
        akt(gdz);
        push(gdz);
    }else{
        push(gdz);
        dod(gdz*2,zakl,(zakl+zakp)/2,l,p,ile);
        dod(gdz*2+1,(zakl+zakp)/2+1,zakp,l,p,ile);
        if(tree[gdz*2].f.f<tree[gdz*2+1].f.f){
            tree[gdz]=tree[gdz*2];
        }else{
            tree[gdz]=tree[gdz*2+1];
        }

    }
}

void ustaw(int gdz, int zakl, int zakp, int l, int p, int na, int z, int czyk){
    if(l<=zakl&&p>=zakp){
        akt(gdz);
        push(gdz);
        if(czyk||tree[gdz].f.f>na){
            tree[gdz]=mp(mp(na,0),z);
        }
        //tree[gdz].f=min(na,tree[gdz].f);
    }else if(l>zakp||p<zakl){
        akt(gdz);
        push(gdz);
    }else{
        push(gdz);
        ustaw(gdz*2,zakl,(zakl+zakp)/2,l,p,na,z,czyk);
        ustaw(gdz*2+1,(zakl+zakp)/2+1,zakp,l,p,na,z,czyk);
        //tree[gdz].f=min(tree[gdz*2].f,tree[gdz*2+1].f);
        if(tree[gdz*2].f.f<tree[gdz*2+1].f.f){
            tree[gdz]=tree[gdz*2];
        }else{
            tree[gdz]=tree[gdz*2+1];
        }
    }
}

pii mini(int gdz, int zakl, int zakp, int l, int p){
    if(l<=zakl&&p>=zakp){
        akt(gdz);
        push(gdz);
        return mp(tree[gdz].f.f,tree[gdz].s);
    }else if(l>zakp||p<zakl){
        akt(gdz);
        push(gdz);
        return mp(MAX,1);
    }else{
        push(gdz);
        pii ret=mp(MAX,1);
        ret=min(ret,mini(gdz*2,zakl,(zakl+zakp)/2,l,p));
        ret=min(ret,mini(gdz*2+1,(zakl+zakp)/2+1,zakp,l,p));
        if(tree[gdz*2].f.f<tree[gdz*2+1].f.f){
            tree[gdz]=tree[gdz*2];
        }else{
            tree[gdz]=tree[gdz*2+1];
        }
        return ret;
    }
}

int32_t main()
{
    scanf("%u",&n);
    while(kk<n)kk<<=1;
    for(int i=1;i<=n;++i){
        scanf("%u",&tab[i]);
    }
    for(int i=1;i<=n;++i){
        prefy[i]=prefy[i-1]+(tab[i]);
    }
    scanf("%u",&m);
    for(int i=0;i<m;++i){
        scanf("%u%u",&a,&b);
        //kon[b].pb(a);
        pocz[a].pb(b);
    }
    for(int i=1;i<=n;++i){
        sort(pocz[i].begin(),pocz[i].end());
        //sort(kon[i].begin(),kon[i].end());
        dp[i]=MAX;
    }
    for(int i=0;i<kk;++i){
        tree[i+kk].s=i;
        ustaw(1,0,kk-1,i,i,MAX,i,1);
    }
    for(int i=1;i<=n;++i){
        dp[i]=min(dp[i],dp[i-1]+tab[i]);
        //cout<<dp[i]<<" ";
        dod(1,0,kk-1,0,kk-1,(tab[i]^1));
        for(int j=0;j<pocz[i].size();++j){
            //ustaw(1,0,kk-1,pocz[i][j],pocz[i][j],dp[i-1]+(tab[i]^1),i,0);
            pii minek=mini(1,0,kk-1,i,pocz[i][j]);
            minek.f=min(minek.f,dp[i-1]+(tab[i]^1));
            dp[pocz[i][j]]=min(dp[pocz[i][j]],minek.f+(pocz[i][j]-i)-(prefy[pocz[i][j]]-prefy[i]));
            //cout<<"X "<<minek.f<<" "<<minek.s<<" "<<dp[pocz[i][j]]<<" Y ";
            ustaw(1,0,kk-1,pocz[i][j],pocz[i][j],minek.f,i,0);
        }
    }
    printf("%u",dp[n]);
    return 0;
}
