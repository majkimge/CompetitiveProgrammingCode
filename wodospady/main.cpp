#include <bits/stdc++.h>

#define lld long long
#define mp make_pair
#define f first
#define s second
#define INF 1000000000000

using namespace std;

lld ucz[209][20009];
lld miasta[209];
lld n,k,q, wynik, lastwyn,zap,gzap;
pair<lld,lld> pary[2000009];
lld bin(lld a, lld co){
    lld wyn=INF;
    lld l=0;
    lld p=n*k-1;
    lld s=(l+p)/2;
    while(p>=l&&(s>=0&&s<=n*k-1)){
        s=(l+p)/2;
        //cout<<s<<endl;
        if(!(s>=0&&s<=n*k-1)) break;
        //cout<<pary[s].f;
        if(pary[s].f>=co){
                //cout<<"B";
            if(wyn>s){
                wyn=s;
            }
            p=s-1;
        }else{
            l=s+1;
        }
    }
    //cout<<wyn;
    return wyn;
}

bool cmp(pair<lld,lld> a, pair<lld,lld>b){
    return a.f<b.f;
}

int main()
{
    scanf("%lld",&n);
    scanf("%lld",&k);
    scanf("%lld",&q);
    for(int i=0;i<k;++i){
        for(int j=0;j<n;++j){
            scanf("%lld",&ucz[i][j]);
            pary[i*n+j]=mp(ucz[i][j],i);
        }
    }

    sort(pary,pary+n*k);

    for(int i=n*k-1;i>=0;i--){
        miasta[pary[i].s]++;
        pary[i]=mp(pary[i].f,0);
        for(int j=0;j<k;j++){
            pary[i]=mp(pary[i].f,pary[i].s^miasta[j]);
        }
    }
/*for(int i=0;i<n*k;++i){
        cout<<pary[i].f<<pary[i].s<<endl;
    }*/
    scanf("%lld",&zap);
    if(bin(0,zap)!=INF){
        wynik=pary[bin(0,zap)].s;
        printf("%lld\n",wynik);
    }else{
        wynik=0;
        printf("%lld\n",wynik);
    }



    lastwyn=wynik;
    for(int i=1;i<q;i++){
            wynik=0;
        scanf("%lld",&zap);
        gzap=lastwyn^zap;
    //cout<<"B"<<gzap;
            if(bin(0,gzap)!=INF){
                wynik=pary[bin(0,gzap)].s;
            }else{
                wynik=0;
            }


    printf("%lld\n",wynik);
    lastwyn=wynik;
    }
    return 0;
}
