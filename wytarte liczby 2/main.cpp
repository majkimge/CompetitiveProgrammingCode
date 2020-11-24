#include <bits/stdc++.h>
#define lld long long
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define MAX 1000009
#define INF 100000000
#define MOD 1000000009

using namespace std;

int n,suma,wyn;
bitset<128> czy[50009];
int ile[10900];
int odw[10900];
int odwi[10009];
int iler=0;

int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;++i){
        scanf("%d",&odw[i]);
        ile[odw[i]]++;
        if(ile[odw[i]]==1)iler++;
        suma+=odw[i];
    }
    //sort(odw,odw+n);
    czy[0][0]=1;
    odwi[0]=1;
    for(int i=1;i<=100;++i){

        if(ile[i]){
            //cout<<i;
            for(int j=1;j<=suma;++j){
                odwi[j]=0;
                czy[j].reset();
                //cout<<czy[j];
                //czyj[j].reset();
            }

            for(int j=1;j<=100;++j){
                if(ile[j]&&j!=i){
                    for(int z=suma;z>=0;--z){
                        if(odwi[z]){
                            for(int x=ile[j];x>0;--x){
                                czy[z+j*x]=((czy[z]<<x)|czy[z+j*x]);
                                odwi[z+j*x]=1;
                            }
                        }

                    }
                }
            }
            int temp=0;
            for(int j=1;j<=ile[i];++j){
                if(!czy[i*j][j]){
                    temp++;
                }else{
                    //wyn=max(wyn,temp);
                    break;
                }
            }
            wyn=max(wyn,temp);
        }
    }
    if(iler>2){
        printf("%d",wyn);
    }else{
        printf("%d",n);
    }

    return 0;
}
/*
10
5
5
5
5
1 14
1 14
2
28
*/
