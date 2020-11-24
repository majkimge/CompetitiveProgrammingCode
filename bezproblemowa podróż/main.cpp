#include <bits/stdc++.h>
#define lld long long
#define mp make_pair
#define f first
#define s second
#define pb push_back
#define MAX 500009

using namespace std;

int n,m,odw[MAX],a,b,cogdz[MAX],kk=1;
vector<int> kraw[MAX];
vector<int> odwkraw[MAX];
vector<int> topo,wynik;


pair<int,int> tree[2100000];

int dfs(int gdz){
    odw[gdz]=1;
    for(int i=0;i<kraw[gdz].size();++i){
        if(!odw[kraw[gdz][i]]){
            dfs(kraw[gdz][i]);
        }
    }
    cogdz[gdz]=topo.size();
    topo.pb(gdz);

}

void akt(int gdz){
    tree[gdz].f+=tree[gdz].s;

}

void push(int gdz){
    if(gdz<kk){
        tree[gdz*2].s+=tree[gdz].s;
        tree[gdz*2+1].s+=tree[gdz].s;
    }
    tree[gdz].s=0;
}

void add(int gdz, int l, int p, int kl, int kp, int ile){
    if(l<=kl&&p>=kp){
        tree[gdz].s+=ile;
        akt(gdz);
        push(gdz);
    }else if(l>kp||p<kl){
        akt(gdz);
        push(gdz);
    }else{
        akt(gdz);
        push(gdz);
        add(gdz*2,l,p,kl,(kl+kp)/2,ile);
        add(gdz*2+1,l,p,(kl+kp)/2+1,kp,ile);
        tree[gdz].f=min(tree[gdz*2].f,tree[gdz*2+1].f);
    }
}

int mini(int gdz, int l, int p, int kl, int kp){
    if(l<=kl&&p>=kp){
        akt(gdz);
        push(gdz);
        return tree[gdz].f;
    }else if(l>kp||p<kl){
        akt(gdz);
        push(gdz);
        return MAX;
    }else{
        akt(gdz);
        push(gdz);
        int ret=MAX;
        ret=min(ret,mini(gdz*2,l,p,kl,(kl+kp)/2));
        ret=min(ret,mini(gdz*2+1,l,p,(kl+kp)/2+1,kp));
        tree[gdz].f=min(tree[gdz*2].f,tree[gdz*2+1].f);
        return ret;
    }
}

int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;++i){
        scanf("%d%d",&a,&b);
        if(a!=b){
            kraw[a].pb(b);
            odwkraw[b].pb(a);
        }

    }
    while(kk<n)kk<<=1;

    dfs(1);
    wynik.pb(1);
    for(int i=topo.size()-2;i>=0;--i){
        cout<<topo[i]<<" ";
        int od=i;
        for(int j=0;j<odwkraw[topo[i]].size();++j){
            if(odw[odwkraw[topo[i]][j]])add(1,od+1,cogdz[odwkraw[topo[i]][j]],0,kk-1,1);

        }
        int tx=mini(1,od+1,topo.size()-1,0,kk-1);
        if(tx>1)wynik.pb(topo[i]);
        cout<<mini(1,4,4,0,kk-1)<<endl;
    }
    sort(wynik.begin(),wynik.end());
//cout<<"X";
    printf("%d\n",wynik.size());
    for(int i=0;i<wynik.size();++i){
        printf("%d ",wynik[i]);
    }
    return 0;
}
/*
6 9
1 2
1 2
2 3
3 4
3 4
3 5
2 5
4 6
5 6
*/
