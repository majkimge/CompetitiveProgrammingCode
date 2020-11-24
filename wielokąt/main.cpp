#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define lld long long
#define MAX 300009

using namespace std;

int n;
int war[109];
char dzial[109];
int maxik=0;
int wyny[59];
int dp[59][59][2];
char xd;

int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;++i){
        //if()
        cin>>dzial[i];
        cin>>war[i];
        dzial[i+n]=dzial[i];
        war[i+n]=war[i];
    }
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            for(int xx=0;xx<n;++xx){
                dp[j][xx][1]=-MAX;
                dp[j][xx][0]=MAX;
            }
        }
        for(int j=0;j<n;++j){
            dp[j][j][0]=war[i+j];
            dp[j][j][1]=war[i+j];
            //cout<<dp[j][j]<<" ";
        }
        //cout<<endl;
        for(int j=1;j<n;++j){
            for(int a=i;a<n+i-j;++a){
                for(int b=0;b<j;++b){
                    if(dzial[a+b+1]=='t'){
                        dp[a-i][a-i+j][1]=max(dp[a-i][a-i+j][1],dp[a-i][a+b-i][1]+dp[a+b-i+1][a-i+j][1]);
                        dp[a-i][a-i+j][1]=max(dp[a-i][a-i+j][1],dp[a-i][a+b-i][1]+dp[a+b-i+1][a-i+j][0]);
                        dp[a-i][a-i+j][1]=max(dp[a-i][a-i+j][1],dp[a-i][a+b-i][0]+dp[a+b-i+1][a-i+j][1]);
                        dp[a-i][a-i+j][1]=max(dp[a-i][a-i+j][1],dp[a-i][a+b-i][0]+dp[a+b-i+1][a-i+j][0]);
                        dp[a-i][a-i+j][0]=min(dp[a-i][a-i+j][0],dp[a-i][a+b-i][1]+dp[a+b-i+1][a-i+j][1]);
                        dp[a-i][a-i+j][0]=min(dp[a-i][a-i+j][0],dp[a-i][a+b-i][1]+dp[a+b-i+1][a-i+j][0]);
                        dp[a-i][a-i+j][0]=min(dp[a-i][a-i+j][0],dp[a-i][a+b-i][0]+dp[a+b-i+1][a-i+j][1]);
                        dp[a-i][a-i+j][0]=min(dp[a-i][a-i+j][0],dp[a-i][a+b-i][0]+dp[a+b-i+1][a-i+j][0]);
                    }else{
                        dp[a-i][a-i+j][1]=max(dp[a-i][a-i+j][1],dp[a-i][a+b-i][1]*dp[a+b-i+1][a-i+j][1]);
                        dp[a-i][a-i+j][1]=max(dp[a-i][a-i+j][1],dp[a-i][a+b-i][0]*dp[a+b-i+1][a-i+j][1]);
                        dp[a-i][a-i+j][1]=max(dp[a-i][a-i+j][1],dp[a-i][a+b-i][0]*dp[a+b-i+1][a-i+j][0]);
                        dp[a-i][a-i+j][1]=max(dp[a-i][a-i+j][1],dp[a-i][a+b-i][1]*dp[a+b-i+1][a-i+j][0]);
                        dp[a-i][a-i+j][0]=min(dp[a-i][a-i+j][0],dp[a-i][a+b-i][1]*dp[a+b-i+1][a-i+j][1]);
                        dp[a-i][a-i+j][0]=min(dp[a-i][a-i+j][0],dp[a-i][a+b-i][0]*dp[a+b-i+1][a-i+j][1]);
                        dp[a-i][a-i+j][0]=min(dp[a-i][a-i+j][0],dp[a-i][a+b-i][0]*dp[a+b-i+1][a-i+j][0]);
                        dp[a-i][a-i+j][0]=min(dp[a-i][a-i+j][0],dp[a-i][a+b-i][1]*dp[a+b-i+1][a-i+j][0]);
                    }
                }

            }
        }
        /*for(int j=0;j<n;++j){
            for(int a=0;a<n;++a){
                if(j<=a){
                    cout<<j<<" "<<a<<" "<<dp[j][a]<<endl;
                }

            }
        }*/
        wyny[i]=dp[0][n-1][1];
        //cout<<wyny[i]<<endl;
        maxik=max(wyny[i],maxik);
    }
    printf("%d\n",maxik);
    for(int i=0;i<n;++i){
        if(wyny[i]==maxik){
            printf("%d ",i+1);
        }
    }
    return 0;
}
