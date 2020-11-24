#include <bits/stdc++.h>

#define lld long long
#define mp make_pair
#define f first
#define s second
#define MAX 1009
#define MOD 1000000007

using namespace std;

lld n,last;
lld tab[MAX];
lld lastdyn[MAX*2];
lld dyn[MAX*2];
int main()
{
    scanf("%lld",&n);
    for(int i=0;i<n;++i){
        scanf("%lld",&tab[i]);
    }
    lastdyn[0]=1;
    for(int i=1;i<=tab[0];++i){
        lastdyn[i]=lastdyn[i-1]+1;
    }
    last=tab[0];
    for(int i=1;i<n;++i){
            //cout<<"B";
        if(tab[i]>last){
            for(int j=last;j>=0;j--){
                dyn[j+tab[i]-last]=lastdyn[j];
            }
            for(int j=0;j<tab[i]-last;j++){
                dyn[j]=0;
            }
            for(int j=tab[i]-last;j<=tab[i];j++){
                dyn[j]=dyn[j]+dyn[j-1];
                dyn[j]%=MOD;
            }
            for(int j=0;j<2009;++j){
                lastdyn[j]=dyn[j];
                dyn[j]=0;
            }
            last=tab[i];
        }else{
            for(int j=tab[i];j>=0;j--){
                dyn[j]=lastdyn[j];
            }
            for(int j=1;j<=tab[i];j++){
                dyn[j]=dyn[j]+dyn[j-1];
                dyn[j]%=MOD;
            }
            for(int j=0;j<2009;++j){
                lastdyn[j]=dyn[j];
                dyn[j]=0;
            }
            last=tab[i];
        }
        if(i==n-1){
            printf("%lld",lastdyn[tab[i]]%MOD);
        }
    }

    return 0;
}
