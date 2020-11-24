#include <bits/stdc++.h>
#define lld long long
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define MAX 1000009

using namespace std;

int n,m,tree[2100000],a,b,odw[MAX],pocz[MAX],kon[MAX],kk=1,cogdz[MAX];
pair<int,int>wynik;
vector<int> kraw[MAX],odwkraw[MAX],topo;

int tdfs(int gdz){
    odw[gdz]=1;
    for(int i=0;i<kraw[gdz].size();++i){
        if(!odw[kraw[gdz][i]]){
            tdfs(kraw[gdz][i]);
        }
    }
    cogdz[gdz]=topo.size();
    topo.pb(gdz);
}

void ust(int l, int p, int co){
    if(l>p)return;
    l+=kk;
    p+=kk;
    tree[l]=max(tree[l],co);
    tree[p]=max(tree[p],co);
    while(l/2!=p/2){
        if(l%2==0){
            tree[l+1]=max(tree[l+1],co);
        }
        if(p%2==1){
            tree[p-1]=max(tree[p-1],co);
        }
        l>>=1;
        p>>=1;
    }
}

int poda(int gdz){
    gdz+=kk;
    int ret=0;
    while(gdz){
        ret=max(ret,tree[gdz]);
        gdz>>=1;
    }
    return ret;
}

int main()
{
    scanf("%d%d",&n,&m);
    while(kk<n)kk<<=1;
    for(int i=0;i<m;++i){
        scanf("%d%d",&a,&b);
        kraw[a].pb(b);
        odwkraw[b].pb(a);
    }
    for(int i=1;i<=n;++i){
        if(!odw[i])tdfs(i);
    }
    for(int i=topo.size()-1;i>=0;--i){
        //cout<<topo[i];
        int maxi=-1;
        for(int j=0;j<odwkraw[topo[i]].size();++j){
            maxi=max(maxi,kon[odwkraw[topo[i]][j]]);
        }
        kon[topo[i]]=maxi+1;
        //ust(i+1,n-1,kon[topo[i]]);
        ust(0,i-1,kon[topo[i]]);
    }

    for(int i=0;i<topo.size();++i){
        int maxi=-1;
        for(int j=0;j<kraw[topo[i]].size();++j){
            maxi=max(maxi,pocz[kraw[topo[i]][j]]);
        }
        pocz[topo[i]]=maxi+1;
        ust(i+1,n-1,pocz[topo[i]]);
    }
    //for(int i=1;i<=n;++i)cout<<kon[i]<<" ";
    for(int i=topo.size()-1;i>=0;--i){
        //int maxi=-1;
        for(int j=0;j<odwkraw[topo[i]].size();++j){
            ust(i+1,cogdz[odwkraw[topo[i]][j]]-1,kon[odwkraw[topo[i]][j]]+pocz[topo[i]]+1);
        }
        //kon[topo[i]]=maxi+1;
        //ust(i+1,n-1,kon[topo[i]]);
    }//cout<<poda(0);
    wynik.f=MAX*3;
    for(int i=0;i<n;++i){
        pair<int,int> ter=mp(poda(i),i);
        wynik=min(wynik,ter);
    }
    printf("%d %d",topo[wynik.s],wynik.f);
    return 0;
}
