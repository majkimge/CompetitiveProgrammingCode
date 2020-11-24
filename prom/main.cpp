#include <bits/stdc++.h>
#define MAX 100009

using namespace std;

int n,wyn;
int tab[MAX];

int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;++i){
        scanf("%d",&tab[i]);
    }
    sort(tab,tab+n);
    for(int i=n;i>=0;--i){
        if((n-i-1)%3!=2){
            wyn+=tab[i];
        }

    }
    printf("%d",wyn);
    return 0;
}
