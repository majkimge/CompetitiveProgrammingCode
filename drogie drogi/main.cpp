#include <bits/stdc++.h>
#define lld unsigned long long
#define MAX 109
#define MOD 1000000009
#define mp make_pair
#define f first
#define s second

using namespace std;

lld n,m,k,a,b,wyn;
lld tab[MAX][MAX];
lld tab1[MAX][MAX];
lld wyni[MAX][MAX];

void mno(int jakie){
    if(jakie==0){
        for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j){
            for(int z=1;z<=n;++z){
                wyni[i][j]+=((tab[i][z]%MOD)*(tab[z][j]%MOD))%MOD;
                wyni[i][j]%=MOD;
            }
        }
    }
    }else if(jakie==1){
        for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j){
            tab1[i][j]=wyni[i][j];
            wyni[i][j]=0;
        }
    }
        for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j){
            for(int z=1;z<=n;++z){
                wyni[i][j]+=((tab1[i][z]%MOD)*(tab[z][j]%MOD))%MOD;
                wyni[i][j]%=MOD;
            }
        }
    }
    }else{
        for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j){

            tab1[i][j]=wyni[i][j];
            wyni[i][j]=0;
        //cout<<tab1[i][j];
        }
    }
        for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j){
            for(int z=1;z<=n;++z){
                wyni[i][j]+=((tab1[i][z]%MOD)*(tab1[z][j]%MOD))%MOD;
                wyni[i][j]%=MOD;
            }
        }
    }
    }

}

void pot(lld dok){
    if(dok==2){
        mno(0);
    }else if(dok%2==1){
        pot(dok-1);
        mno(1);
    }else{
        pot(dok/2);
        mno(2);
    }
}



int main()
{
    scanf("%llu",&n);
    scanf("%llu",&m);
    scanf("%llu",&k);
    for(int i=0;i<m;++i){
        scanf("%llu",&a);
        scanf("%llu",&b);
        tab[a][b]++;
        //tab[a][b]%=MOD;
    }
    if(k>=2){
        pot(k);
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j){
            //cout<<wyni[i][j]<<endl;
            wyn+=wyni[i][j];
            wyn%=MOD;
        }
    }
    printf("%llu",wyn);
    }else if(k==1){
        for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j){
            //cout<<wyni[i][j]<<endl;
            if(tab[i][j]>0){
                wyn++;
            }

            wyn%=MOD;
        }
    }
    printf("%llu",wyn);
    }else{
        printf("1");
    }

    return 0;
}
