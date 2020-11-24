#include <bits/stdc++.h>
#define lld long long

using namespace std;

lld n,k,nkw,wynik,ile,done;


int main()
{
    scanf("%lld%lld",&n,&k);
    if(k>2*n){
        printf("0");
        done=1;
    }else{
        lld pocz=max((lld)1,k-n);
        if(k>n){
            ile=(n-pocz+1)*(n-pocz+2)/2;
        }else{
            if(k<=2){
                printf("1");
                done=1;
            }else{
                ile=(n-k+2)*n+(n-1)*n/2-(n-1-(k-2))*(n-1-(k-2)+1)/2;
            }
        }
    }
    if(!done){
        printf("%.16lf",(double)ile/(n*n));
    }
    return 0;
}
