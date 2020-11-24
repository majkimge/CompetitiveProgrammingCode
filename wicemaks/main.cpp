#include <bits/stdc++.h>

#define lld long long
#define MAX 100009
#define MLN 1000009
using namespace std;
lld n;
lld tab[MLN];
lld maxi;
lld wice;
double suma=0;
int main()
{
    ios_base::sync_with_stdio(0);

    cin>>n;
    for(int i=0;i<n;++i){
        cin>>tab[i];
    }
    for(int i=0;i<n;++i){
        for(int j=i;j<n;++j){
            if(j==i){
                maxi=tab[j];
            }else if(j==i+1){
                if(tab[j]>maxi){
                    wice=maxi;
                    maxi=tab[j];
                }else{
                    wice=tab[j];
                }
                suma+=wice;
            }else{
                if(tab[j]>maxi){
                    wice=maxi;
                    maxi=tab[j];
                }else if(tab[j]<maxi&&tab[j]>wice){
                    wice=tab[j];
                }
                suma+=wice;
            }
        }
    }
    printf("%.14f",suma/(n*(n-1)/2));
    return 0;
}
