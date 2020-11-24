#include <bits/stdc++.h>
#define lld long long
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define MAX 2000009
#define INF 1000000000009

using namespace std;

lld n,k,wynik=INF;
vector<lld> dziel;
vector<lld> dziel1;
lld wyny[MAX];
map<lld,lld> m;

int main()
{
    scanf("%lld",&n);
    scanf("%lld",&k);
    for(lld i=1;i*i<=n;++i){
        if(i*i!=n&&i!=1){
            if(n%i==0){
                dziel.pb(i);
                dziel.pb(n/i);
            }

        }else{
            dziel.pb(i);
        }
    }
    m[1]=1;
    wynik=min(wynik,n);
    sort(dziel.begin(),dziel.end());
    for(lld i=1;i<dziel.size();++i){
        //cout<<dziel[i];
        dziel1.clear();
        for(lld j=1;j*j<=dziel[i];++j){
            if(j*j!=dziel[i]&&j!=1){
                if(dziel[i]%j==0){
                    dziel1.pb(j);
                    dziel1.pb(dziel[i]/j);

                }

            }else{
                dziel1.pb(j);
            }
        }
        sort(dziel1.begin(),dziel1.end());
        lld mini=dziel[i];
        wynik=min(wynik,dziel[i]+k+n/dziel[i]);
        for(lld j=1;j<dziel1.size();++j){
            //cout<<dziel1[j]<<" ";
            mini=min(mini,m[dziel1[j]]+dziel[i]/dziel1[j]);
        }
        //cout<<endl;
        m[dziel[i]]=mini+k;
        wynik=min(wynik,mini+k+n/dziel[i]);
    }
    printf("%lld",wynik);

    return 0;
}
