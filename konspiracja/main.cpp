#include <bits/stdc++.h>
#define lld long long
#define mp make_pair
#define pb push_back
#define MAX 10009
#define f first
#define s second

using namespace std;

int n,kraw[MAX],wymy[MAX];
int a,b;

lld wynik

int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;++i){
        scanf("%d",&a);
        for(int j=0;j<a;++j){
            scanf("%d",&b);
            kraw[i].pb(b);
        }
        sort(kraw[i].begin(),kraw[i].end());
    }
    for(int i=0;i<n;++i){
        int x=0;
        for(int j=0;j<n;++j){
            if(x<kraw[i].size()&&kraw[i][x]==j){
                wymy[i].pb(n+j);
                ++x;
            }else{
                wymy[i+n].pb(j);
            }
        }
    }
    return 0;
}
