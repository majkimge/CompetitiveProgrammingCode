#include <bits/stdc++.h>

#define lld long long
using namespace std;

lld a;
lld suma=0;
lld temp;
int main()
{
    scanf("%lld",&a);
    for(int i=1;i<=a;i++){
        scanf("%lld",&temp);
        if(temp%2==1){
            suma+=temp;
        }else{
            suma-=temp;
        }
    }
    if(suma>0){
        printf("NIEPARZYSTE");
    }else if(suma<0){
        printf("PARZYSTE");
    }else{
        printf("ROWNE");
    }
    return 0;
}
