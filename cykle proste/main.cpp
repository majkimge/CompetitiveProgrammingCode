#include <bits/stdc++.h>
#define lld long long
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define MAX 1000009
#define INF 1000000000000000

using namespace std;

int odw[MAX];
int wcykl[MAX];
int zrob[MAX];
int gleby[MAX];
int ojciec[MAX];
vector<int> ter;
vector<int> kraw;
int l,n,m,a,b,przyps;

void oznacz(int from, int ocz){


}

void dfs(int from,int oczy,int gleb){
    odw[from]=1;
    gleby[from]=gleb;
    ojciec=oczy;
    for(int i=0;i<kraw[from].size();++i){
        if(!odw[kraw[from][i]]&&kraw[from][i]!=oczy){
            dfs(kraw[from][i],from,gleb+1);
        }else if(!wcykl[kraw[from][i]]&&kraw[from][i]!=oczy&&gleb<gleby[]){
            oznacz(from,kraw[from][i]);
        }else if(kraw[from][i]!=oczy){
            przyps=1;
        }
    }
}

int main()
{
    scanf("%d",&l);

    for(int xx=0;xx<l;++xx){
        scanf("%d",&n);
        for(int i=0;i<n;++i){
            odw[i]=0;
            wcykl[i]=0;
            zrob[i]=0;
            kraw[i].clear();
        }
        ter.clear();
        scanf("%d",&m);
        for(int i=0;i<m;++i){
            scanf("%d",&a);
            scanf("%d",&b);
            kraw[a].pb(b);
            kraw[b].pb(a);
        }
    }
    return 0;
}
