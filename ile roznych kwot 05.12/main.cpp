#include <bits/stdc++.h>
#define lld long long
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define MAX 1000009
#define MOD 1000000007
#define INF 1000000000000000

using namespace std;

lld z,n,ile[1009],mno[1009],sum,wynik;
vector<lld> wyny;

int main()
{
    scanf("%lld",&z);
    for(int xx=0;xx<z;++xx){
        scanf("%lld",&n);
        for(int i=0;i<n;++i){
            scanf("%lld",&ile[i]);
        }
        for(int i=0;i<n-1;++i){
            scanf("%lld",&mno[i]);
        }
        wyny.clear();
        for(int i=0;i<n;++i){
            lld curr=ile[i];
            lld mn=(lld)1;

            while(i<n-1&&mno[i]<=ile[i]+(lld)1){
                curr+=(((mn*mno[i])%MOD)*(ile[i+1]%MOD))%MOD;
                mn*=mno[i];
                curr%=MOD;
                mn%=MOD;
                ile[i+1]+=max((lld)0,(ile[i]-mno[i]+1)/mno[i]);
                ++i;
            }
            //cout<<curr;
            wyny.pb(curr);
            //--i;
        }//cout<<"X";
        wynik=wyny[0]+(lld)1;
        for(int i=1;i<wyny.size();++i){
            wynik*=(wyny[i]+(lld)1);
            wynik%=MOD;
        }
        printf("%lld\n",wynik);
    }
    return 0;
}
