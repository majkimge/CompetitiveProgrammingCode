#include <bits/stdc++.h>
#define lld long long
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define MAX 1009
#define MOD 1000000007
using namespace std;

lld z,n;
lld poile[MAX];
lld razy[MAX];
lld modul[MAX];
lld wyn[MAX];

int main()
{
    scanf("%d",&z);
    for(int xx=0;xx<z;++xx){
        scanf("%d",&n);
        lld ter=0;
        for(int i=1;i<=n;++i){
            scanf("%d",&poile[i]);
        }
        for(int i=1;i<=n-1;++i){
            scanf("%d",&razy[i]);
        }
        modul[1]=poile[1];
        ter=poile[1];
        wyn[1]=modul[1];
        wyn[1]+=min(modul[1],razy[1])*poile[2];

        for(int i=2;i<=n-1;++i){

            ter*=razy[i-1];
            ter%=MOD;
            wyn[i]+=min(modul[i-1],ter)*min(poile[i],razy[i])+wyn[i-1];
            wyn[i]%=MOD;
            wyn[i]*=poile[i+1];
            wyn[i]%=MOD;
            modul[i]=modul[i-1]*poile[i];
            modul[i]%=MOD;
        }
        printf("%d\n",wyn[n-1]+1);
    }
    return 0;
}
