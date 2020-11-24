#include <bits/stdc++.h>
#define MAX 5009

using namespace std;

int n;
int pier[MAX];
int ilexor[MAX];
int tab[MAX];
int dyn[MAX][MAX];
int xory[MAX][MAX];

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;++i){
        scanf("%d",&tab[i]);
    }
    xory[1][1]=tab[1];
    ilexor[tab[1]]++;
    for(int i=2;i<=n;++i){
        for(int j=1;j<=i;++j){
            if(j!=1){
                ilexor[tab[j-1]]--;
                if(ilexor[tab[j-1]]==0){
                    xory[j][i]=xory[j-1][i-1]^tab[j-1];
                }else{
                    xory[j][i]=xory[j-1][i-1];
                }

                if(ilexor[tab[i]]==0){
                    xory[j][i]^=tab[i];
                }
                //ilexor[tab[i]]++;
            }else{
                xory[j][i]=xory[j][i-1];
                if(ilexor[tab[i]]==0){
                    xory[j][i]^=tab[i];
                }
            }

        }
        for(int z=1;z<=n;++z){
            ilexor[z]=0;
        }
        ilexor[tab[i]]++;
    }

    for(int i=1;i<=n;++i){
        if(pier[tab[i]]==0){
            pier[tab[i]]=i;
        }
    }
       dyn[1][1]=tab[1];

    for(int i=2;i<=n;++i){
        for(int j=1;j<=i;++j){
            if(pier[tab[i]]==i){
                dyn[j][i]=dyn[j][i-1]+tab[i];
                cout<<xory[j][i]<<" ";
            }else{
                dyn[j][i]=max(tab[i]+dyn[j][pier[tab[i]]-1],max(xory[pier[tab[i]]][i]+dyn[j][pier[tab[i]]-1],dyn[pier[tab[i]]+1][i-1]+dyn[j][pier[tab[i]]-1]));
                cout<<xory[j][i]<<" ";
            }


        }
    }
    printf("%d",dyn[1][n]);

    return 0;
}
