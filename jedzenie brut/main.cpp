#include <bits/stdc++.h>
#define lld long long
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define MAX 1002
#define MOD 1000000009

using namespace std;

lld wyn,wynik;
lld tab[100];
lld sil[MAX];
lld n,m;
lld dwum[1002][1002];
lld odwr[1002];
lld odwrsil[MAX];
lld wyny[MAX],wyny1[MAX];


void check(int l, int ile, int na){
    if(l==ile){
        int czyk=1;
        for(int i=1;i<=na;++i){
            if(!tab[i])czyk=0;
        }
        wyn+=czyk;
    }else{
        for(int i=0;i<=na;++i){
            tab[i]++;
            check(l+1, ile, na);
            tab[i]--;
        }
    }
}

lld pot(lld cok, lld dok){
    if(dok==0)return 1;
    if(dok%2==0){
        lld temp=pot(cok,dok/2);
        return (temp*temp)%MOD;
    }else{
        lld temp=pot(cok,dok-1);
        return (temp*cok)%MOD;
    }

}

int main()
{
    scanf("%lld%lld",&n,&m);
    //check(0,n/3,m);
    sil[0]=1;
    odwrsil[0]=1;
    for(int i=1;i<MAX;++i){
        sil[i]=sil[i-1]*i;
        sil[i]%=MOD;
        odwr[i]=pot(i,MOD-2);
        odwrsil[i]=pot(sil[i],MOD-2);
    }//cout<<wyn*(m+1)/sil[m+1]<<endl;
    for(int i=0;i<MAX;++i){
        for(int j=0;j<=i;++j){
            dwum[i][j]=(((sil[i]*odwrsil[j])%MOD)*odwrsil[i-j])%MOD;
        }
    }
    //cout<<dwum[2][0]<<endl;
    wyny[0]=1;
    wyny1[0]=1;
    for(int i=1;i<=n/3;++i){
        lld temp=pot((i+1),n/3);
        for(int j=0;j<i;++j){
            temp-=(((wyny1[j]*sil[j+1])%MOD)*((odwr[j+1]*dwum[i+1][j+1])%MOD))%MOD;
            temp+=MOD;
            temp%=MOD;

        }
        temp*=odwrsil[(i+1)];
        temp%=MOD;
        temp*=(i+1);
        temp%=MOD;
        wyny1[i]=temp;
        temp+=(wyny1[i-1])*odwr[i];
        temp%=MOD;
        wyny[i]=temp;

    }
    wyny[n/3]=1;
    //cout<<wyny[m];
    for(int i=max((lld)0,m-n/3*2);i<=min(n/3,m);++i){
        //cout<<i<<" ";
        for(int j=max((lld)0,m-n/3-i);j<=min(n/3,m-i);++j){
            wynik+=(((wyny[i]*wyny[j])%MOD)*wyny[m-i-j])%MOD;
            wynik%=MOD;
        }
    }
    printf("%lld",wynik);
    return 0;
}
