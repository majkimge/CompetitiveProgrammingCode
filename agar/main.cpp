#include <bits/stdc++.h>
#define lld long long
#define pb push_back
#define mp make_pair
#define MAX 3009
#define f first
#define s second

using namespace std;

int n,k;
lld wielk[MAX][MAX];
lld tab[MAX];
double wyn[MAX][MAX];
double suma;

int main()
{
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;++i){
        scanf("%lld",&tab[i]);
        wielk[i][i]=tab[i];
    }
    for(int i=1;i<=n;++i){
        for(int j=i+1;j<=n;++j){
            wielk[i][j]=wielk[i][j-1]+tab[j];
            //cout<<i<<" "<<j<<" "<<wielk[i][j]<<endl;
        }
    }
    wyn[k][k]=1.0;
    for(int dl=2;dl<=n;++dl){

        for(int i=1;i<=n-dl+1;++i){
            for(int j=i;j<i+dl-1;++j){
                if(wielk[i][j]>wielk[j+1][i+dl-1]){

                    wyn[i][i+dl-1]+=(double)(1.0/(dl-1))*wyn[i][j];
                    //cout<<i<<" "<<dl<<" "<<j<<" "<<wyn[i][j]<<endl;
                }else{
                    wyn[i][i+dl-1]+=(double)(1.0/(dl-1))*wyn[j+1][i+dl-1];
                }

            }

        }
    }
    //cout<<wyn[1][2]<<endl;
    printf("%.14lf",wyn[1][n]);
    return 0;
}
