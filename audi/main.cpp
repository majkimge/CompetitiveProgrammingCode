#include <bits/stdc++.h>
#define lld long long

using namespace std;

lld n,a,b,c,xa,xb,xc;
lld wynik;
lld tab1[1000009];
lld tab2[1000009];

int main()
{
    scanf("%lld",&n);
    scanf("%lld%lld%lld",&a,&b,&c);

    for(lld i=1;i<=n;++i){
        xb=b*i;
        xa=(xb+a-(lld)1)/a;
        xa--;
        while(xa*a>xb){
            xa--;
        }
        while(xa*a<=xb){
            xa++;
        }
        xc=(xb/c);
        xc++;
        while(xc*c<xb){
            xc++;
        }
        while(xc*c>=xb){
            xc--;
        }
        //cout<<xa*a<<" "<<xb<<" "<<xc*c<<endl;
        wynik+=max((lld)0,max((lld)0,(n-xa+(lld)1))*min((lld)n,xc));
    }
    printf("%lld",wynik);
    return 0;
}
