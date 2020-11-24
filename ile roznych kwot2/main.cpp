#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define MAX 1009
#define INF 100000000009
#define MOD 1000000007
#define llu unsigned long long
#define lld long long

using namespace std;

lld p,n,oile[MAX],ile[MAX],wynik,modi,modek[MAX],doda,coto=1,dlug,ostat,pom[MAX],pom1[MAX];

int main()
{
    scanf("%lld",&p);
    for(int xd=0;xd<p;++xd){
        scanf("%lld",&n);
        for(int i=0;i<n;++i){

            //scanf("%lld",&ile[i]);
            pom[i]=ile[i]=1000000000;
        }

        for(int i=0;i<n-1;++i){
            //scanf("%lld",&oile[i]);
            pom1[i]=oile[i]=1000000000;
        }
        ostat=0;

        for(int i=0;i<n;++i){
            //++i;
            lld teraz=i;
            lld sumix=ile[i];
            int czyk=0;
            while(i==teraz||oile[i-1]==1){
                if(i!=teraz){
                    sumix+=ile[i];
                    sumix%=MOD;
                    czyk=1;
                }

                i++;
            }
            //cout<<"A"<<sumix;
            pom[ostat]=sumix;
            pom1[ostat]=oile[i-1];
            --i;
            ostat++;
        }
        for(int i=0;i<ostat;++i){
            //cout<<"B"<<pom[i]<<" "<<pom1[i];
        }
        wynik=pom[0];
        modi=1;
        doda=0;
        coto=1;
        for(int i=1;i<ostat;++i){
                coto*=pom1[i-1];
        coto%=MOD;
            if(pom[i-1]>=pom1[i-1]-1){
                //modek[i]=modek[i-1]*oile[i-1];
                doda=modi*((pom[i-1]+1)%pom1[i-1]);
                doda%=MOD;
                modi=pom1[i-1]*modi;
                pom[i]+=(pom[i-1]-1)/pom1[i-1];
                modi%=MOD;

            }else{
                modi=(modi*(pom[i-1]+1)%MOD)%MOD+doda;
                doda=0;
                modi%=MOD;
            }
        }
        //cout<<modi;
        printf("%lld\n",((((pom[ostat-1]+1)%MOD)*modi)%MOD+doda)%MOD);
    }

    return 0;
}
/*
4
4
1 1 1 1
1 1 2
*/
