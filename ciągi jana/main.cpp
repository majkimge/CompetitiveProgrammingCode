#include <bits/stdc++.h>
#define lld long long
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define MAX 1000009
#define pii pair<int,int>
#define MOD 1000000007
using namespace std;

lld pot(lld co, lld dok){
    if(dok==0)return 1;
    if(dok%2){
        lld temp=pot(co,dok-1);
        return (temp*co)%MOD;
    }
    lld temp=pot(co,dok/2);
    return (temp*temp)%MOD;
}

lld n,k;
vector<lld> pier;
vector<lld> dziel;
lld kto[MAX];
lld wyny[MAX];

int main()
{
    scanf("%lld%lld",&n,&k);
    //printf("%lld",pot(n,k));
    for(int i=1;i*i<=n;++i){
        if(n%i==0){
            dziel.pb(i);
            if(i*i!=n){
                dziel.pb(n/i);
            }
        }

    }
    sort(dziel.begin(),dziel.end());
    for(int i=1;i<dziel.size();++i){
        int czy=0;
        for(int j=0;j<pier.size();++j){
            if(dziel[i]%pier[j]==0){
                kto[i]=pier[j];
                czy=1;
                break;
            }
        }
        if(!czy){
            pier.pb(dziel[i]);
            kto[i]=dziel[i];
        }
    }
    wyny[0]=k;
    for(int i=0;i<dziel.size();++i){
        //cout<<dziel[i]<<" "<<kto[i]<<endl;
    }
    for(int i=1;i<dziel.size();++i){
        lld ter=dziel[i];


        lld pierw=1;
        lld dru=ter;
        while(dru%kto[i]==0){
            dru=dru/kto[i];
            pierw*=kto[i];
        }
        if(pierw==dziel[i])pierw/=kto[i];
        if(dru==dziel[i])dru=1;
        cout<<pierw<<" "<<dru<<endl;
        wyny[i]=(((pot(k,(dziel[i]+1)/2)-pot(k,(pierw+1)/2)-pot(k,(dru+1)/2)+k+(lld)10*MOD)%MOD)*(n/dziel[i]))%MOD;
    }
    lld wynik=0;
    for(int i=0;i<dziel.size();++i){
        wynik+=wyny[i];
        wynik%=MOD;
    }
    printf("%lld",wynik);
    //for(int i=0;i<pier.size();++i)cout<<pier[i];
    return 0;
}
