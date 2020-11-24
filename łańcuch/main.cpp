#include <bits/stdc++.h>
#define lld long long
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define MAX 1000009

using namespace std;

lld n,m,l[MAX],c[MAX],tab[MAX],il[MAX],ilt[MAX],ilep,dll,wynik;

int main()
{
    scanf("%lld%lld",&n,&m);
    for(lld i=0;i<m;++i){
        scanf("%lld",&l[i]);
        dll+=l[i];
    }
    if(dll>n){
        printf("0");
        return 0;
    }
    for(lld i=0;i<m;++i){
        scanf("%lld",&c[i]);
        ilt[c[i]]=l[i];
    }
    for(lld i=0;i<n;++i){
        scanf("%lld",&tab[i]);
    }
    for(lld i=0;i<dll;++i){
        il[tab[i]]++;
    }
    for(lld i=1;i<=n;++i){
        if(il[i]==ilt[i])++ilep;
    }
    if(ilep==n)++wynik;
    for(lld i=dll;i<n;++i){
        if(il[tab[i-dll]]==ilt[tab[i-dll]])ilep--;
        il[tab[i-dll]]--;
        if(il[tab[i-dll]]==ilt[tab[i-dll]])ilep++;

        if(il[tab[i]]==ilt[tab[i]])ilep--;
        il[tab[i]]++;
        if(il[tab[i]]==ilt[tab[i]])ilep++;
        if(ilep==n)++wynik;
    }
    printf("%lld",wynik);
    return 0;
}
