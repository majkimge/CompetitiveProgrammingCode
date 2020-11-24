#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define lld long long
#define MOD 1000000007
#define MAX 300009

using namespace std;

int n,k,a,b,wyn;
int tab[22][MAX];

int main()
{
    scanf("%d",&n);
    scanf("%d",&k);
    scanf("%d",&a);
    scanf("%d",&b);
    tab[1][1]=a+b;
    int dok=1;
    for(int i=2;i<=n;++i){
        dok*=2;
        for(int j=0;j<dok;++j){
            scanf("%d",&a);
            scanf("%d",&b);
            tab[1][dok+j]=a+b;
        }
    }
    for(int i=n-1;i>0;--i){

        for(int j=dok/2;j<dok;++j){
            for(int x=2;x<=k/2;++x){
                tab[x][j]=tab[x-1][j*2]+tab[1][j];
                for(int z=0;z<x;++z){
                    tab[x][j]=max(tab[x][j],tab[z][j*2]+tab[max(x-1-z,0)][j*2+1]+tab[1][j]);
                }
            }
        }
        dok/=2;
    }
    for(int i=0;i<=k/2;++i){
            //cout<<tab[i][1]<<" ";
        wyn=max(wyn,tab[i][1]);
    }
    printf("%d",wyn);
    return 0;
}
/*
4 5
3 0
2 0
-2 0
4 0
5 0
8 0
-9 0
1 0
7 0
4 0
-5 0
7 0
4 0
10 0
14 0
*/
