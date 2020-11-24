#include <bits/stdc++.h>
#define lld long long
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define MAX 400009
#define INF 1000000000

using namespace std;

vector<int> kraw[MAX];
int n,a,b,wynik;
int m[MAX];
pair<int,int> skal[MAX];
int praw[MAX];
pair<int,int> zap[MAX];
pair<int,int> wyn;

pair<int,int> dfs(int from, int ojc){
    m[from]=1;
    //int ile=0;
    pair<int,int> ret=mp(from,from);
    pair<int,int> tempor=mp(INF,-1);
    for(int i=0;i<kraw[from].size();++i){
        if(m[kraw[from][i]]==0){//cout<<from;
            tempor=dfs(kraw[from][i],ojc);
            ret.s=max(ret.s,tempor.s);
            ret.f=min(ret.f,tempor.f);
            //ile++;
        }
    }
    //wynik=max(wynik,praw[from]-praw[ojc]);
    return ret;
    //return ret;
}

int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;++i){
        scanf("%d",&a);
        //pocz.pb(a);
        skal[i*2]=mp(a,i);
        scanf("%d",&b);
        //kraw[a].pb(b+1);
        skal[i*2+1]=mp(b+1,i);
        zap[i]=mp(a,b+1);
        //kraw[b].pb(a);
    }
    //sort(pocz.begin(),pocz.end());
    sort(skal,skal+2*n);
    int ite=1;
    for(int i=0;i<2*n;++i){
        int ter=skal[i].f;
        praw[ite]=ter;
        if(zap[skal[i].s].f==ter){
            zap[skal[i].s].f=ite;
        }else{
            zap[skal[i].s].s=ite;
        }
        ++i;
        while(skal[i].f==ter){
            if(zap[skal[i].s].f==ter){
                zap[skal[i].s].f=ite;
            }else{
                zap[skal[i].s].s=ite;
            }
            ++i;
        }
        i--;
        ite++;
    }
    sort(zap,zap+n);
    for(int i=0;i<n;++i){
        kraw[zap[i].f].pb(zap[i].s);
        kraw[zap[i].s].pb(zap[i].f);
    }

    for(int i=0;i<n;++i){
        //cout<<zap[i].f<<" "<<zap[i].s<<endl;
        if(!m[zap[i].f]){
            wyn=dfs(zap[i].f,zap[i].f);
            wynik=max(wynik,praw[wyn.s]-praw[wyn.f]);
        }

    }
    printf("%d",wynik);
    return 0;
}
