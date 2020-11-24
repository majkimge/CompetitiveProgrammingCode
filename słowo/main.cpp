#include <bits/stdc++.h>
#include <bits/stdc++.h>
#define lld long long
#define mp make_pair
#define s second
#define f first
#define MAX 100009
#define MOD 1000000007
#define pb push_back
#define pii pair<int,int>

using namespace std;

int n=1;
int prefy[MAX];
char s[MAX];
int ost[3];
int dp[MAX];

int main()
{
    //scanf("%d",&n);
    scanf("%s",&s[1]);
    while(s[n])++n;
    n--;
    for(int i=1;i<=n;++i){
        prefy[i]=prefy[i-1]+s[i]-'a'+1;
        prefy[i]%=3;
    }
    int czyab=1;
    for(int i=1;i<=n;++i){
        if((i%2&&s[i]=='b')||(!(i%2)&&s[i]=='a'))czyab=0;
    }
    //cout<<czyab;
    int czyba=1;
    for(int i=1;i<=n;++i){
        if((i%2&&s[i]=='a')||(!(i%2)&&s[i]=='b'))czyba=0;
    }

    if(czyab||czyba){
        printf("1");
        return 0;
    }
    //cout<<"A";
    for(int i=1;i<=n;++i){
        if(prefy[i])dp[i]++;
        dp[i]+=dp[i-1];
        if(s[i]=='a'){
            dp[i]+=ost[(prefy[i]-2+3)%3];
        }else{
            dp[i]+=ost[(prefy[i]-1+3)%3];
        }
        dp[i]%=MOD;
        ost[prefy[i]]=dp[i];
    }
    printf("%d",dp[n]);
    return 0;
}
