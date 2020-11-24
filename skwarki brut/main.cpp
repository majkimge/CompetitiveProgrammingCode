#include <bits/stdc++.h>
#define lld long long
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define MAX 1009


using namespace std;

lld n,k,p,siz,po,wyn;
lld tab[MAX];
lld tab1[MAX][15];

int main()
{
    scanf("%lld%lld%lld",&n,&k,&p);
    for(int i=1;i<=n;++i){
        tab[i]=i;
    }

    do{
        siz=n;
        po=0;
        for(int i=1;i<=n;++i){
            tab1[i][0]=tab[i];
        }
        tab1[n+1][0]=0;
        while(siz>1){

            int kt=1;
            tab1[siz+1][po]=0;
            for(int i=1;i<=siz;++i){
                if(tab1[i][po]>tab1[i-1][po]&&tab1[i][po]>tab1[i+1][po]){
                    tab1[kt][po+1]=tab1[i][po];
                    kt++;
                }
            }
            siz=kt-1;
            po++;
        }
        if(po==k){
            wyn++;
            wyn%=p;
        }
    }while(next_permutation(tab+1,tab+n+1));
    printf("%lld",wyn);
    return 0;
}
