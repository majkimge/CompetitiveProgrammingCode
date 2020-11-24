#include <bits/stdc++.h>
#define lld long long
#define ld double
#define MAX 100009
#define LOG 18
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define INF 1000000000

using namespace std;

lld t,n;
lld xp1,x2,yp1,y2,x3,y3;



void policz(ld xz1,ld yz1,ld xz2,ld yz2,ld x,ld y){
    ld a=(yz1-yz2)/(xz1-xz2);

    ld b=yz1-a*xz1;
    ld c=y+a*x;
    ld tempx=(c-b)/(2*a);
    ld tempy=-a*tempx+c;
    ld wynx=x+(tempx-x)*2;
    ld wyny=y+(tempy-y)*2;
    //cout<<a<<" "<<b<<" "<<c<<" "<<tempx<<" "<<tempy<<" "<<tempx<<" "<<tempy<<" "<<endl;
    printf("%lf ",wynx);
    printf("%lf\n",wyny);

}

int main()
{
    scanf("%lld",&t);
    for(int i=0;i<t;++i){
        scanf("%lld",&xp1);
        scanf("%lld",&yp1);
        scanf("%lld",&x2);
        scanf("%lld",&y2);
        scanf("%lld",&n);
        for(int j=0;j<n;++j){
            scanf("%lld",&x3);
            scanf("%lld",&y3);
            policz((xp1),(ld)(yp1),(ld)(x2),(ld)(y2),(ld)(x3),(ld)(y3));
        }
    }
    return 0;
}
