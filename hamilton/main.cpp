#include <bits/stdc++.h>
#define lld long long
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define MAX 100009
#define INF 1000000009
#define MOD 1000696969

using namespace std;

lld n,wynik;
lld a,b,c,c1,c2;
vector<pair<lld,lld> >kraw[MAX];
map<pair<lld,lld> ,lld>wagi;
lld odw[MAX];
lld iles[MAX];
lld oczy[MAX];
lld odw1[MAX];
lld czyd=0;
lld mini=INF;
lld dfs(lld from,lld moc){
    odw[from]=1;
    lld wyn=0;
    for(lld i=0;i<kraw[from].size();++i){
        if(!odw[kraw[from][i].f]){
            oczy[kraw[from][i].f]=from;
            wyn+=dfs(kraw[from][i].f,moc);
        }
    }

    iles[from]=wyn;
    if(from!=c1&&moc==c1){
        cout<<from<<" "<<oczy[from]<<" "<<min(iles[from]+1,n-iles[from]-1)<<endl;
        wynik+=(lld)2*wagi[mp(from,oczy[from])]*min(iles[from]+1,n-iles[from]-1);

    }
    return wyn+1;
}

void check(lld what){
    lld czy=1;
    lld suma=0;
    for(int i=0;i<kraw[what].size();++i){
        if(iles[kraw[what][i].f]+1>n/2&&oczy[what]!=kraw[what][i].f) czy=0;
        if(oczy[what]!=kraw[what][i].f){
            suma+=iles[kraw[what][i].f]+1;
        }

    }
    //cout<<suma;
    if(czy&&n-suma-1<=n/2){
        czyd=1;
        cout<<what<<" ";
        wynik-=wagi[mp(c1,what)];
    }
}

void dfs2(lld from){
    odw1[from]=1;
    int czy=1;
    for(int i=0;i<kraw[from].size();++i){
        if(!odw1[kraw[from][i].f]&&iles[kraw[from][i].f]+1>n/2){
            czy=0;
            dfs2(kraw[from][i].f);
        }
    }

    if(czy){
        c1=from;
        for(int i=0;i<kraw[from].size();++i){
            //cout<<from<<" ";
            if(kraw[from][i].f!=oczy[from]&&n%2==0){
                check(kraw[from][i].f);
            }


    }
    }
}



int main()
{
    scanf("%lld",&n);
    for(lld i=0;i<n-1;++i){
        scanf("%lld%lld%lld",&a,&b,&c);
        kraw[a].pb(mp(b,c));
        kraw[b].pb(mp(a,c));
        wagi[mp(a,b)]=c;
        wagi[mp(b,a)]=c;
        mini=min(mini,c);
    }
    dfs(1,1);
    dfs2(1);
    for(int i=0;i<=n;++i){
        odw[i]=0;
        iles[i]=0;
    }
    dfs(c1,c1);
    //dfs1(1);
    if(czyd){
        printf("%lld",wynik);
    }else{
        mini=INF;
        for(int i=0;i<kraw[c1].size();++i){
            mini=min(mini,wagi[mp(kraw[c1][i].f,c1)]);
        }
        printf("%lld",wynik-mini);
    }
    return 0;
}
/*
4
1 2 1
1 3 3
3 4 5


7
2 1 8
3 1 10
4 2 9
5 3 4
6 3 8
7 4 5
170
*/
