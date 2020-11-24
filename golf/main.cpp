#include <bits/stdc++.h>
#define lld long long
#define MOD 1000696969
#define pb push_back

using namespace std;

int n,m,t;

int main()
{
    scanf("%d%d%d",&n,&m,&t);
    poty[0]=29;
    for(int i=1;i<59;++i){
        poty[i]=poty[i-1]*29;
        poty[i]%=MOD;
    }
    for(int xd=0;xd<t;++xd){
        scanf("%lld",&n);

    }
    return 0;
}
