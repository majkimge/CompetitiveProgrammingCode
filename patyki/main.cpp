#include <bits/stdc++.h>

#define lld long long
#define MAX 100009
#define MLN 1000009
using namespace std;

lld n;
lld tab[MLN];
long double suma=0;
long double sumac=0;
long double Newton( lld n, lld k)
{
long double Wynik = 1;

for( unsigned int i = 1; i <= k; i++)
{
Wynik = Wynik * ( n - i + 1 ) / i;
}

return Wynik;      // Zwróæ Wynik
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin>>n;
    for(int i=0;i<n;++i){
        cin>>tab[i];
    }

    sort(tab,tab+n);
    for(lld i=0;i<n-1;++i){



        suma+=(i+1)*tab[i];
        sumac+=i+1;

    }
    cout<<suma/sumac<<endl;

    //cout<<sumac;
    return 0;
}
