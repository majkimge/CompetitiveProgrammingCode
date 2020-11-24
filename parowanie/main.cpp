#include <bits/stdc++.h>
#define lld long long
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define MAX 5009
#define MOD 1000000007

using namespace std;

lld n,a,b,c,wynik;

lld pot(lld dok,lld co){
    if(dok==0)return 1;
    if(dok%2){
        return (pot(dok-1,co)*co)%MOD;
    }
    lld xd=pot(dok/2,co);
    xd*=xd;
    xd%=MOD;
    return xd;
}

lld sil[MAX];
lld odwsil[MAX];

lld dwum(lld gor, lld dol){
    if(gor<=0||dol<=0)return 1;
    return (((sil[gor]*odwsil[dol])%MOD)*odwsil[gor-dol])%MOD;
}

int main()
{
    scanf("%lld%lld%lld%lld",&n,&a,&b,&c);
    sil[0]=1;
    odwsil[0]=1;
    for(int i=1;i<MAX;++i){
        sil[i]=sil[i-1]*i;
        sil[i]%=MOD;
        odwsil[i]=pot(MOD-2,sil[i]);
    }
    if(b%2||(b==0&&c%3&&a<c%3)){
        printf("0");
        return 0;
    }
    b>>=1;
    lld rozdw=dwum(b+a,a);

    //cout<<rozdw;
    for(int i=0;i<=min(a,c);++i){
        if(b){
            for(int j=0;j*3<=c-i;++j){
            lld temp=rozdw;
            temp*=dwum(j+a+b,a+b);

            temp%=MOD;
            temp*=dwum(c-i-j*3+b-1,b-1);//cout<<temp;
            temp%=MOD;
            temp*=dwum(a,i);
            temp%=MOD;
            wynik+=temp;
            wynik%=MOD;
        }
        }else{
            if(i%3)continue;
            for(int j=(c-i)/3;j*3<=c-i;++j){
            lld temp=rozdw;
            temp*=dwum(j+a+b,a+b);

            temp%=MOD;
            temp*=dwum(c-i-j*3+b-1,b-1);//cout<<temp;
            temp%=MOD;
            temp*=dwum(a,i);
            temp%=MOD;
            //cout<<temp<<endl;
            wynik+=temp;
            wynik%=MOD;
        }
        }



    }
    printf("%lld",wynik);
    return 0;
}
