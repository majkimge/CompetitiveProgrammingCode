#include <bits/stdc++.h>

#define lld long long
#define mp make_pair
#define f first
#define s second
#define N 110
#define M 20

using namespace std;

lld tab[N];
lld kan[M];
lld wyb[N][M];
lld usuny[M];
lld n, m, temp, k,maxi,wyn1,wyn2,ileus,tempi;
bool czy,czy1;
int main()
{
    scanf("%lld",&n);
    scanf("%lld",&m);
    scanf("%lld",&k);
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            scanf("%lld",&wyb[i][j]);

        }
    }
    for(int i=0;i<n;++i){
        //cout<<wyb[i][0];
        kan[wyb[i][0]]++;
    }
    for(int i=1;i<=m;++i){
        if(kan[i]>maxi){
            wyn1=i;
            maxi=kan[i];
        }
    }
    printf("%lld\n",wyn1);
    while(wyn1!=k){
            czy1=0;
            maxi=0;
            //cout<<wyn1;
        for(int i=0;i<=m;++i){
            kan[i]=0;
        }
        usuny[ileus]=wyn1;
        ileus++;
        for(int i=0;i<n;++i){
        //cout<<wyb[i][0];
        czy=1;
        lld q=0;
        while(czy){
            czy1=1;
            tempi=wyb[i][q];

            for(int j=0;j<m;++j){
                if(tempi==usuny[j]){
                    czy1=0;
                }
            }
             if(czy1==0){
                q++;
             }else{
                 //cout<<i<<q;
                kan[wyb[i][q]]++;
                czy=0;
             }

        }

        }
        for(int i=1;i<=m;++i){
        if(kan[i]>maxi){
            wyn1=i;
            maxi=kan[i];
        }
        }
    }
    printf("%lld",ileus);
    return 0;
}
