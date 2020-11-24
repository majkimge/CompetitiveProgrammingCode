#include <bits/stdc++.h>

#define lld long long

using namespace std;
lld n,xp,yp,xk,yk,odl;
int main()
{
    scanf("%lld",&xp);
    scanf("%lld",&yp);
    scanf("%lld",&xk);
    scanf("%lld",&yk);
    scanf("%lld",&n);
    odl=abs(xk-xp)+abs(yk-yp);
    //cout<<yk<<yp;
    if(n-odl<0||(n-odl)%2==1){
        printf("0");
    }else if(n-odl>=0&&(n-odl)%2==0){
        printf("%lld",(n-odl)/2+1);
    }
    return 0;
}
