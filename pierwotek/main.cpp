#include <bits/stdc++.h>
#define lld long long
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define MAX 1009
#define INF 1000000000
#define pii pair<int,int>

using namespace std;

int n,a,b,wynik,kt;
int odw[MAX];
int ile[MAX];
vector<int> kraw[MAX];
vector<int> silne[MAX];

int dfs(int from){
    silne[kt].pb(from);
    odw[from]=1;
    for(int i=0;i<kraw[from].size();++i){
        if(odw[kraw[from][i]]==-1){
            dfs(kraw[from][i]);
        }
    }
}

int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;++i){
        scanf("%d%d",&a,&b);
        kraw[a].pb(b);
        kraw[b].pb(a);
        odw[a]=-1;
        odw[b]=-1;
        ile[a]++;
        ile[b]--;
    }
    for(int i=1;i<MAX;++i){
        if(ile[i]>0){
            wynik+=ile[i];
        }
    }
    for(int i=1;i<MAX;++i){
        if(odw[i]==-1){
            dfs(i);
            ++kt;
        }
    }
    //cout<<kt;
    for(int i=0;i<kt;++i){
        int czyl=1;
        for(int j=0;j<silne[i].size();++j){
            if(ile[silne[i][j]]%2==1)czyl=0;
        }
        wynik+=czyl;
    }
    printf("%d",wynik+n);
    return 0;
}
