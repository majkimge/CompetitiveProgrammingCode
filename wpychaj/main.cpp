#include <bits/stdc++.h>

#define lld long long
#define INF 100000000000
using namespace std;

lld n,c;
lld tab[1000009];

lld wynik=INF;
lld tempwyn;
lld bin(lld x, lld a,lld b){
lld l=a;
lld p=b;
lld s=(l+p)/2;
lld roz=INF;
while(l<=p){
    s=(l+p)/2;
    if(tab[s]==x){
        return tab[s];
        break;
    }else
    if(tab[s]<x){
        if(abs(tab[s]-x)<roz){
            roz=abs(tab[s]-x);
        }
        l=s+1;
    }else{
        if(abs(tab[s]-x)<roz){
            roz=abs(tab[s]-x);
        }
        p=s-1;
    }
}
//cout<<roz;
return roz;
}
int main()
{
    scanf("%lld",&n);
    scanf("%lld",&c);
    for(int i=0;i<n;++i){
        scanf("%lld",&tab[i]);
    }
    sort(tab,tab+n);
    for(int i=0;i<n;++i){
        if(tab[i]<0){
            tempwyn=bin(-c-tab[i],i+1,n-1);
            if(i>0){
                if(c+abs(tab[i-1]+tab[i])<tempwyn){
                    if(wynik>c+abs(tab[i-1]+tab[i])){
                        wynik=c+abs(tab[i-1]+tab[i]);
                    }
                }else{
                    if(wynik>tempwyn){
                        wynik=tempwyn;
                    }
                }
            }else{
                if(wynik>tempwyn){
                    wynik=tempwyn;
                }
            }
        }else if(tab[i]>0){
            tempwyn=bin(-c-tab[i],0,i-1);
            if(i<n-1){
                if(c+abs(tab[i+1]+tab[i])<tempwyn){
                    if(wynik>c+abs(tab[i+1]+tab[i])){
                        wynik=c+abs(tab[i+1]+tab[i]);
                    }
                }else{
                    if(wynik>tempwyn){
                        wynik=tempwyn;
                    }
                }
            }else{
                if(wynik>tempwyn){
                    wynik=tempwyn;
                }
            }
        }else if(tab[i]==0){
            if(i>0&&i<n-1){
            if(c+abs(tab[i+1])<c+abs(tab[i-1])){
                    if(wynik>c+abs(tab[i+1])){
                        wynik=c+abs(tab[i+1]);
                    }
                }else{
                    if(wynik>c+abs(tab[i-1])){
                        wynik=c+abs(tab[i-1]);
                    }
                }
        }else if(i>0&&i==n-1){
            if(wynik>c+abs(tab[i-1])){
                wynik=c+abs(tab[i-1]);
            }
        }else if(i==0&&i<n-1){
            if(wynik>c+abs(tab[i+1])){
                wynik=c+abs(tab[i+1]);
            }
        }
    }

    }
    printf("%lld",wynik);
    return 0;
}
