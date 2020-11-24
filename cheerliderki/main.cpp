#include <bits/stdc++.h>

#define lld long long
#define MAX 100009
#define MLN 1000009
using namespace std;

lld n,k;
lld tab[MAX];
lld kubelki[MLN];
lld sorted[MAX];
lld a;
lld ile=1;
lld maxi=1;
int main()
{
    ios_base::sync_with_stdio(0);
    cin>>n;
    cin>>k;
    for(int i=0;i<n;++i){

        cin>>tab[i];
    }
    for(int i=0;i<n;++i){
        kubelki[tab[i]]++;
    }
    lld b=0;
    for(int i=0;i<MLN;++i){

        if(kubelki[i]>0){
            sorted[b]=i;
            b++;
        }
    }
    //sort(tab,tab+n);
    a=sorted[0];

    for(int i=1;i<n;++i){
        if(sorted[i]==a+1){
            ile++;
            a=sorted[i];
            if(ile>maxi){
                maxi=ile;
            }

        }else if(sorted[i]>a+1){
            ile=0;
            a=sorted[i];
        }
    }
    if(maxi>=k){
        cout<<"TAK";
    }else{
        cout<<"NIE";
    }
    return 0;
}
