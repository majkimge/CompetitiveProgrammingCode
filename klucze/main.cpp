#include <bits/stdc++.h>
#define lld long long
#define mp make_pair
#define f first
#define s second
#define pb push_back
#define MAX 100009
#define MOD 1000696969

using namespace std;

int n,wynik;
char s[MAX];
lld hasze[MAX];
lld odhasze[MAX];

lld poty[MAX];
char ods[MAX];
pair<lld,pair<lld,lld> >slo[MAX*2];

int check(int dl){
    for(int i=1;i<=n-dl+1;++i){
        slo[i-1]=mp((((hasze[i+dl-1]-hasze[i-1]+MOD)%MOD)*poty[n-i])%MOD,mp(i,0));
        //if(dl==3)cout<<slo[i-1].f<<" ";
    }
    for(int i=1;i<=n-dl+1;++i){
        slo[n-dl+1+i-1]=mp((((odhasze[i+dl-1]-odhasze[i-1]+MOD)%MOD)*poty[n-i])%MOD,mp(i,1));
    }
    sort(slo,slo+n*2-dl*2+2);
    int czy=0;
    for(int i=0;i<n*2-dl*2+2;++i){

        lld ter=slo[i].f;
        int p0=-1;
        int p1=-1;
        int d0=-1;
        int d1=-1;
        if(slo[i].s.s==0){
            p0=slo[i].s.f;
            d0=slo[i].s.f;
        }else{
            d1=slo[i].s.f;
            p1=slo[i].s.f;
        }


        while(i<n*2-dl*2+1&&slo[i+1].f==ter){
            ++i;

            if(slo[i].s.s==0){
                d0=slo[i].s.f;
                if(p0==-1){
                    p0=slo[i].s.f;
                }
            }else{
                d1=slo[i].s.f;
                if(p1==-1){
                    p1=slo[i].s.f;
                }
            }
        }
        //if(dl==3)cout<<p0<<" "<<p1<<" "<<czy<<endl;
        if(p1!=-1&&p0!=-1&&((d1-p0>=dl)||(d0-p1>=dl))){
            czy=1;
            break;
        }
    }
    return czy;
}

int bin(){
    int l=0;
    int p=n/2;
    int s=(l+p)/2;
    int wyn=0;
    while(l<=p){
        s=(l+p)/2;
        if(check(s)){
            wyn=s;
            l=s+1;
        }else{
            p=s-1;
        }
    }
    return wyn;
}

int main()
{
    scanf("%d",&n);
    scanf("%s",&s[1]);
    for(int i=1;i<=n;++i){
        s[i]-='0';
        ods[i]=s[i]^1;
    }
    poty[0]=1;
    for(int i=1;i<=n;++i){
        poty[i]=poty[i-1]*2;
        poty[i]%=MOD;
    }
    for(int i=1;i<=n;++i){
        hasze[i]=(lld)hasze[i-1]+s[i]*poty[i];;
        hasze[i]%=MOD;
        odhasze[i]=(lld)odhasze[i-1]+ods[i]*poty[i];;
        odhasze[i]%=MOD;
    }
    //cout<<check(3);
    /*for(int i=1;i<=n;++i){
        //cout<<hasze[i]<<" ";
    }*/
    printf("%d",bin());

    return 0;
}
