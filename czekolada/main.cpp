#include <bits/stdc++.h>

#define MAX 1000009
#define INF 10000000000
#define lld long long

using namespace std;

lld n,m;
lld kol[MAX];
lld wier[MAX];
lld w=1;
lld s=1;
lld maxi=0;
lld wynik=0;
bool koniec=false;
int main()
{
    std::ios_base::sync_with_stdio(0);
    cin>>n;
    cin>>m;
    for(int i=1;i<n;i++){
        cin>>kol[i];
    }
    for(int i=1;i<m;i++){
        cin>>wier[i];
    }

    sort(&kol[0],&kol[n]);
    sort(&wier[0],&wier[m]);
    if(n>=m){
        maxi=n;
    }else {
        maxi=m;
    }
    lld wierwsk=m-1;
    lld kolwsk=n-1;
    while(!koniec){

        if(kolwsk==0&&wierwsk==0){
            koniec=true;
            break;
        }
        if(kol[kolwsk]>wier[wierwsk]){
            wynik+=kol[kolwsk]*w;
            s++;
            kolwsk--;
        }else if(kol[kolwsk]<=wier[wierwsk]){
            wynik+=wier[wierwsk]*s;
            w++;
            wierwsk--;
        }
    }

    cout<<wynik;
    return 0;
}
