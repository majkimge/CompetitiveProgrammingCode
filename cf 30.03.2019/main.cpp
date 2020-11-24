#include <bits/stdc++.h>
#define lld long long
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define MAX 300009
#define INF 1000000000

using namespace std;

int n,m,q,a,b;
int per[MAX];
int arr[MAX];
int cogdz[MAX];
set<int> ss[MAX];
int najp[MAX];
vector<int> v[MAX];

int main()
{
    scanf("%d%d%d",&n,&m,&q);
    for(int i=1;i<=n;++i){
        scanf("%d",&per[i]);
        cogdz[per[i]]=i;
    }
    for(int i=1;i<=m;++i){
        scanf("%d",&arr[i]);
    }
    for(int i=1;i<=m;++i){
        ss[arr[i]].insert(i);
        v[arr[i]].pb(i);
    }
    for(int j=0;j<v[per[n-2]].size();++j){
        if(ss[per[n-1]].end())
        najp[v[per[n-2]][j]]=(*ss[per[n-1].lower_bound(j))
    }
    for(int i=n-3;i>=0;--i){
        for(int j=0;j<v[per[i]].size();++j){
            najp[v[per[i]][j]]=najp[(*ss[per[i+1].lower_bound(j))]
        }
    }
    return 0;
}
