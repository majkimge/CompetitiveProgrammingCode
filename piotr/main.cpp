#include <bits/stdc++.h>
#define lld long long
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define MAX 200009
#define pii pair<int,int>

using namespace std;

int n,m,a,b,ileus;
vector<pii>kraw[MAX];
int odw[MAX];
int wych[MAX];
lld wart[MAX];
int ojc[MAX];
int stop[MAX];
int usy[MAX];
lld wyny[MAX];

void dfs(int from,int kt,int pocz,int warto){
    odw[from]=1;

    if(kt%2==0){
        warto+=wart[from];
    }else{
        warto-=wart[from];
    }//cout<<warto<<endl;
    if(kt==n-ileus-1){
        for(int i=0;i<kraw[from].size();++i){
        if(kraw[from][i].f==pocz){
            wyny[kraw[from][i].s]+=warto;

            wart[pocz]-=warto/2;
            return;
        }
    }
    }


    for(int i=0;i<kraw[from].size();++i){
        if(!odw[kraw[from][i].f]&&!usy[kraw[from][i].f]){
            dfs(kraw[from][i].f,kt+1,pocz,warto);
        }
    }
}

void dfs1(int from,int pocz){
    odw[from]=2;
    for(int i=0;i<kraw[from].size();++i){
        if(odw[kraw[from][i].f]<2&&!usy[kraw[from][i].f]){
            wyny[kraw[from][i].s]+=wart[from]*2;
            wart[kraw[from][i].f]-=wart[from];
            dfs1(kraw[from][i].f,pocz);
        }
    }
}

void rob(int from){
    if(stop[from]==1){
        stop[from]--;
        usy[from]=1;
        ileus++;
        for(int i=0;i<kraw[from].size();++i){

            if(!usy[kraw[from][i].f]){
                wyny[kraw[from][i].s]+=wart[from]*2;
                wart[kraw[from][i].f]-=wart[from];
                stop[kraw[from][i].f]--;
                rob(kraw[from][i].f);
                return;
            }
        }
    }
    return;
}



int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;++i){
        scanf("%lld",&wart[i]);
    }
    if(m>n){
        printf("0");
        return 0;
    }
    for(int i=0;i<m;++i){
        scanf("%d%d",&a,&b);
        kraw[a].pb(mp(b,i));
        kraw[b].pb(mp(a,i));
    }
    for(int i=1;i<=n;++i){
        stop[i]=kraw[i].size();
    }
    for(int i=1;i<=n;++i){
        rob(i);
    }
    if((n-ileus)%2==0){
        printf("0");
        return 0;
    }

    for(int i=1;i<=n;++i){
        if(!usy[i]){
            dfs(i,0,i,0);
            dfs1(i,i);//cout<<"A";
            break;
        }
    }
    for(int i=0;i<m;++i){
        printf("%lld\n",wyny[i]);
    }
    return 0;
}
/*
3
3
4 3 5
1 2
2 3
3 1
*/
