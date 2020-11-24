#include <bits/stdc++.h>
#define lld long long
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define MAX 909
#define INF 1000000009

using namespace std;

int n;
int tab[MAX];
vector<int> wyny;

void solve(int dl,int kt,int gdzie,int wynix){
    if(kt==dl){
        wyny.pb(wynix+tab[gdzie]);
        return;
    }
    int wyn=0;
    for(int i=gdzie+1;i<=n-(dl-kt);++i){
        solve(dl,kt+1,i,wynix+tab[gdzie]);
    }
    //return wyn+tab[gdzie];
}

int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;++i){
        scanf("%d",&tab[i]);
    }
    sort(tab,tab+n);
    for(int i=1;i<=n;++i){
        for(int j=0;j<=n-i;++j){
            solve(i,1,j,0);
        }

    }
    int gdz=1;
    gdz<<=(n-1);
    sort(wyny.begin(),wyny.end());
    printf("%d",wyny[gdz-1]);
    return 0;
}
