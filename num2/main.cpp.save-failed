#include <bits/stdc++.h>

#define MAX 500001
#define lld long long
using namespace std;

priority_queue <int> kol[MAX];
int n;
lld wynik=0;
int tab[MAX];
lld mini(int tab[],int l,int p){
    lld minimum=10000000;
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
        kol.push(-tab[i]);
    }
    for(int l=0;l<n;l++){
        for(int p=1;p<=n;p++){
            if((p-l)*-kol.top()>wynik){
                wynik=-(p-l)*kol.top();
            }
        }
    }
    printf("%lld",wynik);

    return 0;
}
