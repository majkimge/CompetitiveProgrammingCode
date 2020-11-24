#include <bits/stdc++.h>
#define lld long long

using namespace std;

int n,m,k,x,y;
int tab[509][509];

int main()
{
    scanf("%d",&n);
    scanf("%d",&m);
    scanf("%d",&k);
    for(int i=0;i<k;++i){
        scanf("%d",&x);
        scanf("%d",&y);
        tab[x][y]=1;
    }
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j){
            if(tab[i][j]){
                printf("X");
            }else{
                printf(".");
            }
        }
        printf("\n");
    }
    return 0;
}
