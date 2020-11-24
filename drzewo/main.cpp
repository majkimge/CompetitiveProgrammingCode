#include <bits/stdc++.h>
#define lld long long
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define MAX 100009
#define pii pair<int,int>
#define piii pair<pii,int>

using namespace std;

int n,a,b,wynik,kk;
vector<int> kraw[MAX];
priority_queue<pii >q;
int odw[MAX],usy[MAX],stop[MAX],ojc[MAX],rep[MAX],gl[MAX],dok[MAX], kt[MAX];

void dfs(int from, int oczy,int gleb){
    odw[from]=1;
    ojc[from]=oczy;
    gl[from]=gleb;
    for(int i=0;i<kraw[from].size();++i){
        if(!odw[kraw[from][i]]){
            dfs(kraw[from][i],from,gleb+1);
        }
    }
}

int Find(int x){
    if(rep[x]!=x)rep[x]=Find(rep[x]);
    return rep[x];
}

int Union(int x, int y){
    int rx=Find(x);
    int ry=Find(y);

    if(rx!=ry){
        if(gl[rx]>gl[ry])swap(rx,ry);
        rep[ry]=rx;
        return 1;
    }
    return 0;
}




int main()
{
    scanf("%d",&n);
    for(int i=0;i<n-1;++i){
        scanf("%d%d",&a,&b);
        kraw[a].pb(b);
        kraw[b].pb(a);

    }

    dfs(1,1,0);
    for(int i=1;i<=n;++i){
        stop[i]=kraw[i].size();
        rep[i]=i;
    }

    for(int i=2;i<=n;++i){
        if(stop[i]==1){
            q.push(mp(-1,i));
            ++wynik;
        }
    }
    kk=1;
    while(!q.empty()){

        pii ter=q.top();
        q.pop();
        if(usy[ter.s])continue;
        ter.f=-ter.f;
        //cout<<kk<<" "<<ter.s<<" "<<ter.f<<endl;
        if(kt[ter.s]<kk){
            int gdz=Find(ter.s);
            int czy=1;
            while(ojc[gdz]!=1&&stop[ojc[gdz]]<=2&&czy){
                czy=Union(gdz,ojc[gdz]);
                gdz=Find(gdz);
            }
            ter.f=gl[gdz]-gl[ter.s]-1;
            kt[ter.s]=kk;
            q.push(ter);
        }else{
            if(stop[ojc[ter.s]]>2||ojc[ter.s]==1)wynik--;
            --stop[ojc[ter.s]];
            usy[ter.s]=1;
            ++kk;
            if(stop[ojc[ter.s]]==1&&ojc[ter.s]!=1)q.push(mp(-1,ojc[ter.s]));
            printf("%d\n",wynik);
        }



    }

    return 0;
}
