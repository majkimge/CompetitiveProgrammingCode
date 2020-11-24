#include <bits/stdc++.h>
#define lld long long
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define MAX 500009
#define INF 1000000009
#define MOD 1000696969

using namespace std;

char s[MAX];
lld s1[MAX];
lld n,suma;

int main()
{
    scanf("%s",s);
    while(s[n]){
        n++;
    }
    lld dod=0;
    for(lld i=n-1;i>=0;i--){
        suma+=(((lld)(s[i]-'0')*9)+dod)%10;
        s1[n-1-i]=(((lld)(s[i]-'0')*9)+dod)%10;
        dod=(((lld)(s[i]-'0')*9)+dod)/10;
        if(i==0&&dod){
            s1[n]=dod;
            suma+=dod;
            n++;
            break;
        }
    }
    for(int i=0;i<n;++i){
        //cout<<s1[i];
    }
    //cout<<suma<<" ";
    for(lld k=1;k<MAX-4;++k){
        lld cod=9;
        lld gdzie=0;
        while(cod){
            suma=suma+(s1[gdzie]+cod)%10-s1[gdzie];
            //cout<<suma<<" ";
            lld temp=cod;
            cod=(s1[gdzie]+cod)/10;
            s1[gdzie]=(s1[gdzie]+temp)%10;
            if(gdzie==n-1&&cod){
                s[n]++;
                suma++;
                n++;
                break;
            }
            gdzie++;
        }
        //cout<<suma<<" ";
        if(suma<=9*k){
            printf("%lld",k);
            break;
        }
    }
    return 0;
}
