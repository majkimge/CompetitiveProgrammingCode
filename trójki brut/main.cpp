#include <bits/stdc++.h>
#define lld long long
#define mp make_pair
#define f first
#define pb push_back
#define s second
#define MOD 1000000007
#pragma GCC optimize ("Ofast")

using namespace std;

int n;
lld tab[100009];
lld wyn;

int rob(int kt, lld ter, lld p1, lld p2){
    if(kt==n){
        wyn+=ter;
        //cout<<ter;
        wyn%=MOD;
    }else{
        for(int i=0;i<n;++i){
            rob(kt+1,(ter*tab[max(max((lld)i,p1),p2)])%MOD,p2,i);
        }
    }
}

int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;++i){
        scanf("%lld",&tab[i]);
    }
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            rob(2,1,i,j);
        }
    }

    printf("%lld",wyn);
    return 0;
}
