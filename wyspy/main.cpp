#include <bits/stdc++.h>
#define lld long long
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define MAX 250009
#define INF 2000000000

using namespace std;

lld n,a,b;
lld odl[MAX];
lld odw[MAX];
queue<lld> q;
lld wyspy[MAX][2];
vector<lld>kraw[MAX];
lld wyny[MAX];

void bfs(){
    while(!q.empty()){
        lld z=q.front();
        q.pop();
        for(int i=0;i<kraw[z].size();++i){
            if(odl[kraw[z][i]]>odl[z]+1){
                odl[kraw[z][i]]=odl[z]+1;
                q.push(kraw[z][i]);
            }
        }
    }
}

int main()
{
    scanf("%lld",&n);
    for(int i=1;i<=n;++i){
        scanf("%lld",&a);
        scanf("%lld",&b);
        wyspy[i][0]=a;
        wyspy[i][1]=b;
    }
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j){
        if(wyspy[j][0]>wyspy[i][0]&&wyspy[j][1]>wyspy[i][1]){
            kraw[i].pb(j);
            kraw[j].pb(i);
        }
    }
    }
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j){
        odl[j]=INF;
    }
    odl[i]=0;
    q.push(i);
    bfs();
    for(int j=1;j<=n;++j){
        wyny[i]+=odl[j];
    }
    printf("%lld\n",wyny[i]);
    }
    return 0;
}
