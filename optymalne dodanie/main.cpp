#include <bits/stdc++.h>
#define lld long long
#define mp make_pair
#define pb push_back
#define f first
#define s second

using namespace std;

lld a,b,wyn,wynik;

int main()
{
    scanf("%lld%lld",&a,&b);
    if(a<b)swap(a,b);
    ++a;
    ++b;
    wyn=a*b/__gcd(a,b);
    wynik=0;
    for(int i=1;i*i<=a-b;++i){
        if((a-b)%i==0){
            lld dok=(b+i-1)/i*i;
            if(wyn>(a+dok-b)*dok/__gcd((a+dok-b),dok)){
                wyn=(a+dok-b)*dok/__gcd((a+dok-b),dok);
                wynik=dok-b;
            }else if(wyn==(a+dok-b)*dok/__gcd((a+dok-b),dok)){
                wynik=min(wynik,dok-b);
            }

            dok=(b+((a-b)/i)-1)/((a-b)/i)*((a-b)/i);
            if(wyn>(a+dok-b)*dok/__gcd((a+dok-b),dok)){
                wyn=(a+dok-b)*dok/__gcd((a+dok-b),dok);
                wynik=dok-b;
            }else if(wyn==(a+dok-b)*dok/__gcd((a+dok-b),dok)){
                wynik=min(wynik,dok-b);
            }
        }

    }
    printf("%lld",wynik+1);
    return 0;
}
