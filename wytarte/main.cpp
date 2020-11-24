#include <bits/stdc++.h>
#define lld long long
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define MAX 100009
#define INF 100000000
#define MOD 1000000009

using namespace std;

int n,suma,wyn,a;
bitset<128> czy[50009];
int ile[109];
int odw[109];
int iler,iler1;

int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;++i){
        scanf("%d",&a);
        if(ile[a]==0)iler++;
        ile[a]++;
        suma+=a;
    }
    odw[0]=1;
    czy[0][0]=1;
    for(int i=1;i<=100;++i){
        if(ile[i]){
            for(int j=1;j<=8000;++j){
                odw[j]=0;
                for(int xd=0;xd<128;++xd){

                }
            }
            for(int j=1;j<=100;++j){
                if(ile[j]&&j!=i){
                    for(int zz=suma;zz>=0;--zz){
                        if(odw[zz]){
                            for(int xx=ile[j];xx>=1;--xx){
                                odw[zz+xx*j]=1;
                                czy[xx*j+zz]=((czy[zz]<<xx)|czy[xx*j+zz]);
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
    printf("%d",wyn);
    return 0;
}
