#include <bits/stdc++.h>

using namespace std;

int lw,lk,b,wyn,suma;
int tab[59][59];

int main()
{
    scanf("%d",&lw);
    scanf("%d",&lk);
    scanf("%d",&b);
    for(int i=0;i<lw;++i){
        for(int j=0;j<lk;++j){
            scanf("%d",&tab[i][j]);

        }
    }
    for(int i=0;i<=lw-b;++i){
        for(int j=0;j<=lk-b;++j){
            suma=0;
            for(int x=0;x<b;++x){
                for(int y=0;y<b;++y){
                    suma+=tab[i+x][j+y];

                }
            }
        wyn=max(wyn,suma);

        }
    }
    printf("%d",wyn);
    return 0;
}
