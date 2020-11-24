#include <bits/stdc++.h>
#define lld long long
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define MAX 200009
#define pii pair<int,int>
#define piii pair<pii,int>

using namespace std;

int t,n,s,m,wynik,a,b;
vector<int> kraw[MAX];
int odw[MAX],ojc[MAX],gl[MAX],czyspr[MAX],czyl[MAX];
int LCA[MAX][30];
vector<int> leaf;
vector<pii> leafgl;
set<int> rozp;

void dfs(int from, int oczy,int gleb){
    odw[from]=1;
    ojc[from]=oczy;
    gl[from]=gleb;
    LCA[from][0]=oczy;
    if(kraw[from].size()==1&&from!=s&&from!=m){
        leaf.pb(from);
        leafgl.pb(mp(gleb,leafgl.size()));
        czyl[from]=1;
    }
    for(int i=0;i<kraw[from].size();++i){
        if(!odw[kraw[from][i]]){
            dfs(kraw[from][i],from,gleb+1);
        }
    }
}

int policz(int x, int y){
    int zam=0;
    int ret=0;
    if(gl[x]<gl[y]){
        swap(x,y);
        zam=1;
    }
    //if(zam)cout<<"X"<<" "<<x<<" "<<y<<" ";
    int tx=x;
    int ty=y;
    for(int i=23;i>=0;--i){
        if(gl[LCA[tx][i]]>=gl[ty]){
            tx=LCA[tx][i];
        }
    }
    if(!zam){
        ret+=gl[x]-gl[tx];
    }
    if(tx==ty)return ret;
    for(int i=23;i>=0;--i){
        if(LCA[tx][i]!=LCA[ty][i]){
            tx=LCA[tx][i];
            ty=LCA[ty][i];
        }
    }
    ret+=y-ty+1;
    return ret;
}

void wycz(){
    for(int i=1;i<=n;++i){
        kraw[i].clear();
        odw[i]=0;
        ojc[i]=0;
        czyl[i]=0;
        czyspr[i]=0;
        for(int j=0;j<30;++j){
            LCA[i][j]=0;
        }
    }
    leaf.clear();
    leafgl.clear();
    rozp.clear();
}

int main()
{
    scanf("%d",&t);
    for(int xdd=0;xdd<t;++xdd){
        scanf("%d%d%d",&n,&s,&m);
        for(int i=0;i<n-1;++i){
            scanf("%d%d",&a,&b);
            kraw[a].pb(b);
            kraw[b].pb(a);

        }
        dfs(m,m,0);
        rozp.insert(-1);
        rozp.insert(n+1);
        for(int i=1;i<25;++i){
            for(int j=1;j<=n;++j){
                LCA[j][i]=LCA[LCA[j][i-1]][i-1];
            }
        }
        if(gl[s]==n-1){
            printf("%d\n",n-1);
            wycz();
            continue;
        }
        if(czyl[s])czyspr[s]=1;
        sort(leafgl.begin(),leafgl.end());
        wynik=gl[s]+leafgl[leafgl.size()-1].f;
        //cout<<wynik;
        int akt=gl[s];
        for(int i=leafgl.size()-1;i>=0;--i){

            int ktl=leafgl[i].s;

            int ll=(*(--rozp.lower_bound(ktl)));
            int rr=(*(rozp.lower_bound(ktl)));
            int mini=3*n;
            if(ll!=-1){
                mini=min(mini,policz(leaf[ktl],leaf[ll]));
            }
            if(rr!=n+1){
                mini=min(mini,policz(leaf[ktl],leaf[rr]));
            }
            mini=min(mini,policz(leaf[ktl],s));
            if(mini==gl[leaf[ktl]])break;
            akt+=mini*2;
            rozp.insert(ktl);
            //cout<<mini<<" "<<wynik<<endl;
            if(i){
                wynik=min(wynik,akt+leafgl[i-1].f);
            }else{
                wynik=min(wynik,akt);
            }

        }

        printf("%d\n",wynik);
        wycz();
    }

    return 0;
}
/*
1
8 6 6
1 2
2 3
3 4
4 5
4 8
5 6
5 7
*/
