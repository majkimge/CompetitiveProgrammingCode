#include <bits/stdc++.h>
#define lld long long
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define MAX 2009
#define MOD 301

using namespace std;

int dp[MAX],n,czyk[5],cok[5];

int main()
{
    dp[0]=0;
    dp[1]=1;
    dp[2]=1;
    dp[3]=1;
    scanf("%d",&n);
    for(int i=4;i<=n;++i){
        for(int j=0;j<5;++j)czyk[j]=0;

        for(int j=1;j<=i;++j){
            for(int j=0;j<5;++j)cok[j]=0;
            /*dp[i]=(dp[i]|(!(dp[max(0,j-3)]^dp[max(0,i-j-2)])));
            if(i==12)cout<<dp[i]<<" ";
            if(dp[max(0,j-3)]==2||dp[max(0,i-j-2)]==2){
                czy2=1;
            }else{
                int sum=(dp[max(0,j-3)]^dp[max(0,i-j-2)]);
                if(sum){
                    czy0=1;
                }else{
                    czy1=1;
                }
            }*/
            cok[dp[max(0,j-3)]]++;
            cok[dp[max(0,i-j-2)]]++;
            if(cok[2]==2||cok[3]==2){
                czyk[2]=1;
                //if(i==22)cout<<j<<endl;
            }else if(cok[2]){
                czyk[3]=1;
            }else if(cok[3]&&cok[0]){
                czyk[2]=1;
            }else if(cok[3]&&cok[1]){
                czyk[3]=1;
            }else if(cok[1]==2||cok[0]==2){
                czyk[1]=1;
            }else{
                czyk[0]=1;
            }


        }
        /*if(czy2||(czy0&&czy1)){
            dp[i]=2;
        }else if(czy1){
            dp[i]=1;
        }
        cout<<dp[i]<<" ";*/
        if(czyk[2]||(czyk[0]&&czyk[1])){
            dp[i]=2;
        }else if(czyk[0]){
            dp[i]=0;
        }else if(czyk[1]){
            dp[i]=1;
        }else if(czyk[3]){
            dp[i]=3;
        }
        //dp[6]=3;
        cout<<dp[i];
    }
    if(dp[n]==1||dp[n]==2){
        printf("ADAM");
    }else{
        printf("BASIA");
    }
    return 0;
}
