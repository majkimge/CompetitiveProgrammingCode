#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define lld long long

using namespace std;

lld n,k,a,b;
lld tab[1000009];
int main()
{
    scanf("%lld",&n);
    for(int i=1;i<=n;++i){
        scanf("%lld",&a);
        scanf("%lld",&b);
        if(a!=1){
        for(int i=1;i<=a;++i){
            tab[i]=0;
        }
        lld temp=b/(2*a-2);
        lld ter=b%(2*a-2);
        lld ite=1;
        /*while(ter>0&&ite<a){
            tab[ite]++;
            ite++;
            ter--;
        }
        ite=a;
        while(ter>0&&ite>0){
            tab[ite]++;
            ite--;
            ter--;
        }*/
        printf("%lld ",temp+(ter>=1));
        for(int i=2;i<a;++i){
            printf("%lld ",2*temp+(ter>=i)+(ter>=a+(a-i)));
        }
        printf("%lld\n",temp+(ter>=a));
        }else{
            printf("%lld\n",b);
        }
    }
    return 0;
}
