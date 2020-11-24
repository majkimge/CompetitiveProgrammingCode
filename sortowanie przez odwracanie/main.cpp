#include <bits/stdc++.h>

using namespace std;

int tab[32009],n;

int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;++i){
        scanf("%d",&tab[i]);
    }
    int czy=1;
    while(czy){
        czy=0;
        for(int i=0;i<n-1;++i){
            if(tab[i]>tab[i+1]){
                czy=1;
                printf("%d %d\n",i+1,i+2);
                swap(tab[i],tab[i+1]);
            }
        }
    }
    return 0;
}
