#include <bits/stdc++.h>


using namespace std;

int t,r,c,h,v,suma,wyn;
int tab[109][109];
int prefyr[109];
int prefyc[109];
char a[109];

int main()
{
    scanf("%d",&t);
    for(int i=0;i<t;++i){
        for(int j=0;j<105;++j){
            for(int z=0;z<105;++z){
                tab[j][z]=0;
                prefyr[j]=0;
                prefyc[j]=0;
            }
        }
        suma=0;
        wyn=0;
        scanf("%d",&r);
        scanf("%d",&c);
        scanf("%d",&h);
        scanf("%d",&v);
        for(int j=0;j<r;++j){

                scanf("%s",a);
                for(int z=0;z<c;++z){
                if(a[z]=='.'){
                    tab[j+1][z+1]=0;
                }else{
                    tab[j+1][z+1]=1;
                    prefyr[j]++;
                    prefyc[z]++;
                    suma++;
                }
                }
        }
        for(int j=1;j<r;++j){

                prefyr[j]+=prefyr[j-1];

        }
        for(int j=1;j<c;++j){

                prefyc[j]+=prefyc[j-1];
        }
        for(int j=0;j<r;++j){


                for(int z=0;z<c;++z){
                    tab[j+1][z+1]+=tab[j][z+1]+tab[j+1][z]-tab[j][z];//cout<<tab[j+1][z+1];
                }
        }
        for(int j=0;j<r;++j){


                for(int z=0;z<c;++z){
                    if(tab[j+1][z+1]==suma/4&&prefyr[j]-tab[j+1][z+1]==suma/4&&prefyc[z]-tab[j+1][z+1]==suma/4){
                        wyn=1;
                    }
                }
        }
        if(wyn&&suma%4==0){
            printf("Case #%d: POSSIBLE\n",i+1);
        }else{
            printf("Case #%d: IMPOSSIBLE\n",i+1);
        }

    }
    return 0;
}
