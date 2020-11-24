#include <bits/stdc++.h>
#define lld long long
#define pb push_back
#define mp make_pair
#define MAX 1000009
#define f first
#define s second

using namespace std;

int n,m,a,b,c,przyps;
int tab[MAX];
vector<pair<int,int> >kraw[MAX];
int pref[MAX];
int wyniki[MAX];
int odw[MAX];

void dfs(int from,int war){
    odw[from]=1;
    pref[from]=war;
    for(int i=0;i<kraw[from].size();++i){
        if(!odw[kraw[from][i].f]){
            dfs(kraw[from][i].f,(war^kraw[from][i].s));
        }
    }
}

int main()
{
    scanf("%d",&n);
    scanf("%d",&m);
    for(int i=0;i<m;++i){
        scanf("%d",&a);
        scanf("%d",&b);
        scanf("%d",&c);
        kraw[a-1].pb(mp(b,c));
        kraw[b].pb(mp(a-1,c));
    }
    for(int i=0;i<=n;++i){
        pref[i]=-1;
    }
    dfs(0,0);
    for(int i=1;i<=n;++i){
        if(pref[i]<0){
            przyps=1;
            break;
        }else{
            wyniki[i]=(pref[i]^pref[i-1]);
        }
    }
    if(przyps){
        printf("NIE\n");
    }else{
        for(int i=1;i<=n;++i){
            printf("%d ",wyniki[i]);
        }
    }
    return 0;
}
