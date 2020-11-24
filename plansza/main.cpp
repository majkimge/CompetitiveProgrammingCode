#include <bits/stdc++.h>
#define lld long long
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define MAX 100009
#define MOD 1000000007
#define INF 1000696969

using namespace std;

int n,m;

lld pot(lld dok,lld co){
    if(dok==0)return 1;
    if(dok%2){
        return (pot(dok-1,co)*co)%MOD;
    }
    lld xd=pot(dok/2,co);
    xd*=xd;
    xd%=MOD;
    return xd;
}

int main()
{
    scanf("%d%d",&n,&m);
    //cout<<pot(4,1);
    printf("%lld",(pot(n,2)*pot(m-1,pot(n,2)-1))%MOD);
    return 0;
}
