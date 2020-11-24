#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define MAX 1009
#define INF 100000000009
#define llu unsigned long long
#define lld long long

using namespace std;

int n,k,a,b,wynik;
vector<int>kraw[MAX];
int ile[MAX];
int wyny[MAX];
int odw[MAX];

void dfs(int from,int korz,int gleb){
    odw[from]=1;
    wyny[gleb]++;
    if(from==korz){
        ile[from]=kraw[from].size();
    }else{
        ile[from]=kraw[from].size()-1;
    }
    for(int i=0;i<kraw[from].size();++i){
        if(!odw[kraw[from][i]]){
            dfs(kraw[from][i],korz,gleb+1);
        }
    }

}

int solve(int kor){
    for(int i=0;i<=n+1;++i){
        odw[i]=ile[i]=wyny[i]=0;
    }
    dfs(kor,kor,1);

    for(int i=1;i<=n+1;++i){
        wyny[i]+=wyny[i-1];
    }
}

int main()
{
    scanf("%d",&n);
    scanf("%d",&k);
    for(int i=0;i<n-1;++i){
        scanf("%d",&a);
        scanf("%d",&b);
        kraw[a].pb(b);
        kraw[b].pb(a);
    }
    return 0;
}
