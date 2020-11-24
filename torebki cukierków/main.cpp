#include <bits/stdc++.h>
#define lld long long
#define MOD 1000000009
using namespace std;

int n,m,a,dl;
lld wyn=1;
int main()
{
    scanf("%d",&n);
    scanf("%d",&m);
    for(int i=0;i<m;++i){
        scanf("%d",&dl);
        for(int j=0;j<dl;++j){
            scanf("%d",&a);
        }
    }
    for(int i=0;i<=m;++i){
        wyn<<=1;
        wyn%=MOD;
    }
    printf("%lld",wyn);
    return 0;
}
