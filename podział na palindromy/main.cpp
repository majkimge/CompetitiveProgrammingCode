#include <bits/stdc++.h>
#define lld long long
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define MAX 200009

using namespace std;

int n=1,wynik,ter,ll,ite;
char s[MAX];
int dp[MAX];
int sum[MAX];
int ile[29];
int liter[2][29];

unordered_map<int,int> m;

int main()
{
    scanf("%s",&s[1]);
    ll='z'-'a'+1;
    while(s[n])++n;
    --n;
    ile[1]=1;
    for(int i=2;i<27;++i){
        ile[i]=ile[i-1]*2;
    }
    //cout<<osty['t'-'a'][0];
    dp[0]=0;
    m[0]=0;
    for(int i=1;i<=n;++i){
        dp[i]=MAX;
        for(int j=0;j<ll;++j){
            liter[ite][j]=liter[ite^1][j];
        }
        liter[ite][s[i]-'a']++;
        liter[ite][s[i]-'a']%=2;
        for(int j=0;j<ll;++j){
            sum[i]+=liter[ite][j]*ile[j+1];
        }
        //cout<<sum[i]<<" ";
        for(int j=0;j<27;++j){
            if(m[sum[i]^ile[j]]||(sum[i]^ile[j])==0){
                dp[i]=min(dp[i],m[(sum[i]^ile[j])]+1);
            }else{
                m.erase(sum[i]^ile[j]);
            }

        }
        m[sum[i]]=min(m[sum[i]],dp[i]);
        if(!m[sum[i]]&&sum[i]){
            m[sum[i]]=dp[i];
        }
        ite=ite^1;
    }
    printf("%d",dp[n]);
    return 0;
}
