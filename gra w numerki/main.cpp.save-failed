#include <bits/stdc++.h>

#define MAX 500001
#define lld long long
using namespace std;

int n;
lld wynik=0;
lld tab[MAX];
lld mini(lld tab[],int l,int p){
    lld minimum=100000000000;
    for(int i=l;i<p;i++){
        if(tab[i]<minimum){
            minimum=tab[i];
        }
    }
    return minimum;
}
int main()
{
    scanf("%i",&n);
    for(int i=0;i<n;i++){
        scanf("%i",&tab[i]);
    }
    for(int l=0;l<n;l++){
        for(int p=1;p<=n;p++){
            if((p-l)*mini(tab,l,p)>wynik){
                wynik=(p-l)*mini(tab,l,p);
            }
        }
    }
    printf("%lld",wynik);

    return 0;
}
