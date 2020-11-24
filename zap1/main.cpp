#include <bits/stdc++.h>

#define lld long long
using namespace std;

lld n,m;

lld piece[200009];
lld kl[200009];
lld maxi, wynik;
int main()
{
    scanf("%lld",&n);
    scanf("%lld",&m);
    for(int i=0;i<n;i++){
        scanf("%lld",&kl[i]);
    }
    for(int i=0;i<m;i++){
        scanf("%lld",&piece[i]);
    }
    for(int i=0;i<m;i++){
        maxi=0;
        wynik=0;
        for(int j=0;j<n;j++){
            if(kl[j]-piece[i]>=maxi){
                maxi=kl[j];
            }else{
                wynik+=piece[i]-kl[j]+maxi;
                maxi=maxi+piece[i];
            }

        }printf("%lld\n",wynik);
    }
    return 0;
}
