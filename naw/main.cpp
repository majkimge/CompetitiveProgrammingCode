#include <bits/stdc++.h>
#define lld long long
#define MAX 30009
#define MOD 1000000009

using namespace std;

lld n;
char naw[MAX];
lld dyn[MAX][2];
lld wyn;

int main()
{
    scanf("%lld",&n);
    scanf("%s",&naw);
    if(naw[0]==')'){
        printf("0");
    }else{
        dyn[1][0]=1;
        for(int i=1;i<n;++i){
            if(naw[i]=='('){
                if((i+1)%2==0){
                    dyn[0][1]=dyn[1][0]%MOD;
               }else{
                    dyn[1][1]=(dyn[0][0]%MOD+dyn[2][0]%MOD)%MOD;
               }
                for(int j=(i+1)%2+2;j<=(i+1);j+=2){
                    dyn[j][1]=(dyn[j-1][0]%MOD+dyn[j+1][0]%MOD)%MOD;
                }
               }else{
                    if((i+1)%2==0){
                    dyn[0][1]=dyn[1][0]%MOD;
               }else{
                    dyn[1][1]=dyn[2][0]%MOD;
               }
                for(int j=(i+1)%2+2;j<=(i+1);j+=2){
                    dyn[j][1]=dyn[j+1][0]%MOD;
                }
               }
               for(int j=(i+1)%2;j<=(i+1);j+=2){
                    dyn[j][0]=dyn[j][1]%MOD;
                    //cout<<dyn[j][0];
                }
        }
    }
    printf("%lld",dyn[0][1]%MOD);

    return 0;
}
