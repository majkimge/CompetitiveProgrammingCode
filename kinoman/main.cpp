#include <bits/stdc++.h>
#define lld long long
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define MAX 1000009

using namespace std;

int n,m;
lld tab[MAX];
lld faj[MAX];


int main()
{
    scanf("%d",&n);
    scanf("%d",&m);
    for(int i=1;i<=n;++i){
        scanf("%lld",&tab[i]);
    }
    for(int i=1;i<=m;++i){
        scanf("%lld",&faj[i]);
    }

    return 0;
}
