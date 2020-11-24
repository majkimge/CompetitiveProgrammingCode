#include <bits/stdc++.h>
#define lld long long
#define pb push_back
#define MAX 1000009
#define pii pair<int,int>
#define mp make_pair
#define f first
#define s second

using namespace std;

int n,m,a,b;
vector<int> kraw[MAX];
vector<int> odwkraw[MAX];
vector<int> topo;
int normaxi[MAX];
int odwmaxi[MAX];
int normaxipref[MAX];
int odwmaxipref[MAX];
int odw[MAX];
int wtopo[MAX];
priority_queue<pii> q;
pii wynik;

int dfs(int from){
    odw[from]=1;
    for(int i=0;i<kraw[from].size();++i){
        if(!odw[kraw[from][i]]){
            dfs(kraw[from][i]);
        }
    }
    wtopo[from]=topo.size();
    topo.pb(from);
}

int dfs1(int from){
    odw[from]=2;
    int maxi=0;
    for(int i=0;i<kraw[from].size();++i){
        if(odw[kraw[from][i]]<2){
            dfs1(kraw[from][i]);
        }
        maxi=max(maxi,normaxi[kraw[from][i]]);
    }
    maxi++;
    normaxi[from]=maxi;
}

int dfs2(int from){
    odw[from]=3;
    int maxi=0;
    for(int i=0;i<odwkraw[from].size();++i){
        if(odw[odwkraw[from][i]]<3){
            dfs2(odwkraw[from][i]);
        }
        maxi=max(maxi,odwmaxi[odwkraw[from][i]]);
    }
    maxi++;
    odwmaxi[from]=maxi;
}

int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;++i){
        scanf("%d%d",&a,&b);
        kraw[a].pb(b);
        odwkraw[b].pb(a);
    }
    wynik=mp(MAX,1);
    for(int i=1;i<=n;++i){
        if(!odw[i])dfs(i);
    }
    for(int i=topo.size()-1;i>=0;--i){

        if(odw[topo[i]]<2)dfs1(topo[i]);

    }
    //cout<<endl;
    for(int i=topo.size()-1;i>=0;--i){
        if(odw[topo[i]]<3)dfs2(topo[i]);

    }
    normaxipref[0]=normaxi[topo[0]];
    for(int i=1;i<topo.size();++i){
        normaxipref[i]=max(normaxipref[i-1],normaxi[topo[i]]);

    }

    //cout<<topo[i]<<" "<<normaxi[topo[i]]<<endl;
    odwmaxipref[topo.size()-1]=odwmaxi[topo[topo.size()-1]];
    for(int i=topo.size()-2;i>=0;--i){
        odwmaxipref[i]=max(odwmaxipref[i+1],odwmaxi[topo[i]]);
    }
    /*for(int i=0;i<topo.size();++i){
        //cout<<odwmaxipref[i]<<" ";
        cout<<topo[i]<<" ";
    }
    cout<<endl;*/
    for(int i=0;i<topo.size();++i){
        int wyn=0;
        if(i!=0)wyn=normaxipref[i-1]-1;

        if(i!=topo.size()-1)wyn=max(wyn,odwmaxipref[i+1]-1);

        if(i!=0){
            int temp=normaxi[topo[i-1]]-1;
            int dod=0;
            for(int j=0;j<odwkraw[topo[i-1]].size();++j){
                q.push(mp(odwmaxi[odwkraw[topo[i-1]][j]]+temp,wtopo[odwkraw[topo[i-1]][j]]));
            }
        }
        while(!q.empty()&&q.top().s<=i)q.pop();
        if(!q.empty())wyn=max(wyn,q.top().f);
        if(wyn<wynik.f){
            wynik=mp(wyn,topo[i]);
        }
        //cout<<wyn<<" ";
    }
    printf("%d %d",wynik.s,wynik.f);
    return 0;
}
