#include <bits/stdc++.h>
#define mp make_pair
#define lld long long
#define f first
#define s second
#define MAX 300009
#define MOD 1000000009
#define pb push_back

using namespace std;

lld n,m,k,wynik,tempwyn,a,b,czy,ost;
lld odw[MAX];

vector<lld> topo;
pair<lld,lld> krawy[MAX];
vector<lld> dagkraw[MAX];
vector<pair <lld,lld> >kraw[MAX];
vector<pair <lld,lld> >odwrkraw[MAX];
vector<lld> sss[MAX];
lld dag[MAX];
lld wktorymsss[MAX];
lld ktorysss;



void dfs(int x, int glebo,lld czas){

    odw[x]=1;
    //gleb[x]=glebo;
    for(int i=0;i<kraw[x].size();i++){
        if(!odw[kraw[x][i].f]&&kraw[x][i].s<=czas){
            dfs(kraw[x][i].f,glebo+1,czas);
        }
    }
    topo.pb(x);
}

void dfs1(int x, int glebo,lld czas){

    odw[x]=1;
    sss[ktorysss].pb(x);
    wktorymsss[x]=ktorysss;
    //dag[ktorysss]=1;
    //gleb[x]=glebo;
    for(int i=0;i<odwrkraw[x].size();i++){
        if(!odw[odwrkraw[x][i].f]&&odwrkraw[x][i].s<=czas){
            dfs1(odwrkraw[x][i].f,glebo+1,czas);
        }
    }

}

void komp(lld dok){
    for(int i=0;i<dok;++i){
        if(wktorymsss[krawy[i].f]!=wktorymsss[krawy[i].s]){
            dagkraw[wktorymsss[krawy[i].f]].pb(wktorymsss[krawy[i].s]);
           // cout<<wktorymsss[krawy[i].f]<<" "<<wktorymsss[krawy[i].s];

        }
    }
}

void topodag(int x, int glebo){

    odw[x]=1;
    //gleb[x]=glebo;
    for(int i=0;i<dagkraw[x].size();i++){
        if(!odw[dagkraw[x][i]]){
            topodag(dagkraw[x][i],glebo+1);
        }
    }
    topo.pb(x);
}

lld path(int x, int glebo){

    odw[x]=1;
    lld ww=0;

    //gleb[x]=glebo;
    for(int i=0;i<dagkraw[x].size();i++){
        if(!odw[dagkraw[x][i]]){
            ww=max(ww,path(dagkraw[x][i],glebo+1));

        }
    }
    return ww+dag[x];

}

void clearodw(){
    for(int i=0;i<=n;++i){
        odw[i]=0;
    }
}

bool czyjest(lld dokiedy){
    for(int i=1;i<=n;++i){
        if(!odw[i]){
            dfs(i,0,dokiedy);
        }
    }
    clearodw();
    for(int i=topo.size()-1;i>=0;--i){
        if(!odw[topo[i]]){
            dfs1(topo[i],0,dokiedy);
            ktorysss++;
        }
    }
    //cout<<dokiedy;
    /*for(int i=1;i<=n;++i){

        cout<<topo[i-1]<<" ";
    }
    cout<<endl;
    for(int i=1;i<=n;++i){

        cout<<wktorymsss[i]<<" ";
    }
    cout<<endl;*/

        topo.clear();

    clearodw();
    komp(dokiedy);
   // cout<<"B";
    for(int i=1;i<=n;++i){
        dag[i-1]=sss[i-1].size();
       // cout<<dag[i-1]<<" ";
    }
    //cout<<endl;

    for(int i=0;i<=n;++i){
        if(!odw[i]){
            topodag(i,0);
        }
    }

    clearodw();
    lld tempwyn=0;
    for(int i=topo.size()-1;i>=0;--i){
        if(!odw[i]){
            tempwyn=max(tempwyn,path(topo[i],0));
        }
    }
    ktorysss=0;
    clearodw();

        topo.clear();

    for(int i=0;i<=n;++i){
        sss[i].clear();
    }
    for(int i=0;i<=n;++i){
        wktorymsss[i]=0;
    }
    for(int i=0;i<=n;++i){
        dag[i]=0;
    }
    for(int i=0;i<=n;++i){
        dagkraw[i].clear();
    }
    if(tempwyn>=k){
        return 1;
    }
    return 0;

}

lld bin(lld l,lld p){
    lld s=(l+p)/2;
    lld wyn=-1;
    while(l<=p){
        s=(l+p)/2;
        if(czyjest(s)){
            wyn=s;
            p=s-1;
        }else{
            l=s+1;
        }
    }
    return wyn;
}


int main()
{
    scanf("%lld",&n);
    scanf("%lld",&m);
    scanf("%lld",&k);
    for(int i=1;i<=m;++i){
        scanf("%lld",&a);
        scanf("%lld",&b);
        kraw[a].pb(mp(b,i));
        krawy[i-1]=mp(a,b);
        odwrkraw[b].pb(mp(a,i));
        //cout<<i;

    }
    wynik=bin(0,m);
    if(wynik>=0){
        printf("%lld",wynik);
    }else{
        printf("NIE");
    }

    return 0;
}

/*
7 9 4
2 5
4 3
3 4
5 6
3 2
1 2
6 7
7 6
5 4
*/
