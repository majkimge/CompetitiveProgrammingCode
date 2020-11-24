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
bitset<128> czyj[50009];
bitset<128> czy[50009];
bitset<128> kilk;
int ile[109];
int odw[109];
int odwi[109];

int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;++i){
        scanf("%d",&odw[i]);
        ile[odw[i]]++;
        suma+=odw[i];
    }
    //sort(odw,odw+n);
    czy[0][0]=1;
    czyj[0][0]=1;
    odwi[0]=1;
    /*for(int i=0;i<n;++i){
        for(int j=suma;j>=0;--j){
            if(odwi[j]){
                if(i==0||odw[i]!=odw[i-1]){
                    kilk=(((czy[j]^czyj[j])<<1)|(czy[j+odw[i]]^czyj[j+odw[i]]));
                    czyj[j+odw[i]]=((czyj[j]<<1)^czyj[j+odw[i]]^kilk);
                    czy[j+odw[i]]=((czy[j]<<1)|czy[j+odw[i]]);
                    odwi[j+odw[i]]=1;
                }else{


                }
            }
        }
    }
    */
    for(int i=0;i<101;++i){
        for(int j=suma;j>=0;--j){
            for(int z=ile[i];z>0;--z){
                if(odwi[j]){
                    kilk=(((czy[j]^czyj[j])<<z)|(czy[j+i*z]^czyj[j+i*z]));
                    czyj[j+i*z]=((czyj[j]<<z)^czyj[j+i*z]^kilk);
                    czy[j+i*z]=((czy[j]<<z)|czy[j+i*z]);
                    odwi[j+i*z]=1;
                }
            }
        }
    }
    /*if(czyj[4][2]){
        //printf("1");
    }
    cout<<czyj[1];
    //printf("%d",czyj[4][2]);
    */
    //cout<<czyj[16];
    for(int i=0;i<101;++i){
        for(int j=ile[i];j>=1;--j){
            if(czyj[i*j][j]){
                wyn=max(wyn,j);
            }
        }
    }
    printf("%d",wyn);
    return 0;
}
/*
10
3 3 3 3 3 3 10 2 4 6

*/
