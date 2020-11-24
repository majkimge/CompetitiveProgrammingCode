#include <bits/stdc++.h>
#define lld long long

#define pb push_back
#define mp make_pair
#define f first
#define s second
#define MAX 100009
#define MOD 1000000009

using namespace std;

int n, t;
int tab[MAX];

int main()
{
    scanf("%d%d",&n,&t);
    for(int i=1;i<=n;++i){
        scanf("%d",&tab[i]);

    }

    for(int i=0;i<t;++i){
        pair<int,int> maxi=mp(0,0);
        tab[0]=tab[1];
        tab[n+1]=tab[n];
        for(int j=1;j<=n;++j){
            if(tab[j]-tab[j-1]>maxi.f||tab[j]-tab[j+1]>maxi.f){
                maxi=mp(max(tab[j]-tab[j-1],tab[j]-tab[j+1]),j);
            }
        }
        tab[maxi.s]--;
    }
    for(int i=1;i<=n;++i){
        printf("%d ",tab[i]);
    }
    return 0;
}
