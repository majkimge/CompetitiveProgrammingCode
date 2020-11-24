#include<bits/stdc++.h>
#define lld int
#define pb push_back
#define mp make_pair
#define MAX 100009
#define f first
#define s second
#define INF 1000000000

using namespace std;

lld p,n,d,b,wyn,wyn1,wyn2,kon,konl,konp;

lld tab[MAX*2];
int sumal,sumap;

int main()
{
    scanf("%d",&p);
    scanf("%d",&n);
    scanf("%d",&d);
    scanf("%d",&b);
    for(int i=1;i<=n;++i){
        scanf("%d",&tab[i]);
    }
    if(p==1){
            kon=1;
        for(int i=0;i<n/2;++i){

            for(int j=kon;j<=min(kon+d,n+1);++j){

                sumal+=tab[max(j,0)];
                //cout<<"A"<<j;
            }
            //cout<<sumal;
            kon=min(kon+d+1,n+1);

            if(sumal>=b){
                sumal-=b;
            }else{
                wyn++;
            }

        }
        printf("%d",wyn);
        }else{
            konl=1;
            konp=n;
            for(int i=0;i<(n+1)/2;++i){

                for(int j=konl;j<=min(konl+d,n+1);++j){

                sumal+=tab[max(j,0)];
                //cout<<"A"<<j;
                }
            if(sumal>=b){
                sumal-=b;
            }else{
                wyn1++;
            }
            konl=min(konl+d+1,n+1);


            }
            for(int i=n+1;i>(n+1)/2;--i){

            for(int j=konp;j>=max(konp-d,0);--j){

                sumap+=tab[max(j,0)];
                }
            if(sumap>=b){
                sumap-=b;
            }else{
                if(i!=(n+1)/2){
                    wyn2++;
                }

            }


            konp=max(konp-d-1,0);

            }
        //cout<<wyn1;
        printf("%d",max(wyn1,wyn2));
    }

    return 0;
}
