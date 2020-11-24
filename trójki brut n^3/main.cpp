#include<bits/stdc++.h>
#define lld long long
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define MAX 2009
#define MOD 1000000007
using namespace std;

lld n,dp[MAX][MAX],tab[MAX],it=0,potywys[MAX][MAX],dp1[MAX][MAX],ter[MAX];

lld wynik;

void rob(lld kt){
    if(kt==n){
        lld temp=1;
        for(int i=0;i<n-2;++i){
            temp*=tab[max(ter[i],max(ter[i+1],ter[i+2]))];
            temp%=MOD;
        }
        wynik+=temp;
    }else{
        for(int i=0;i<n;++i){
            ter[kt]=i;
            rob(kt+1);
        }
    }
}

int main()
{
    scanf("%lld",&n);
    for(int i=0;i<n;++i){
        scanf("%lld",&tab[i]);
    }
    dp[0][2]=tab[0];
    for(int i=0;i<n;++i){
        potywys[i][0]=1;
        for(int j=1;j<=n;++j){
            potywys[i][j]=(potywys[i][j-1]*tab[i])%MOD;
        }
    }
    dp[0][0]=1;
    dp[0][1]=1;
    for(int i=3;i<n;++i){
        dp[0][i]=(dp[0][i-1]*tab[0])%MOD;
    }
    //cout<<dp[0][3];
    for(int i=1;i<n;++i){
        dp[i][2]=tab[i]*(i+1)*(i+1);
        dp[i][2]%=MOD;
        dp[i][0]=1;
        dp[i][1]=(i+1);
        dp1[i][1]=(i);
        dp1[i][2]=((tab[i]*((i+1)*(i+1)-i*i))%MOD)*i;
        dp1[i][2]%=MOD;
        for(int j=3;j<n;++j){
            for(int k=-1;k<=j-1;++k){
                if(k==-1){
                    dp[i][j]+=dp[i-1][j-1]*tab[i];
                    dp[i][j]%=MOD;

                }else{
                    if(j-k==1){
                        dp[i][j]+=dp[i][k]*potywys[i][min(3,j-k)];
                        dp[i][j]%=MOD;
                        dp1[i][j]+=((dp[i][k]*tab[i])%MOD)*i;
                        dp1[i][j]%=MOD;
                        //cout<<i<<" "<<dp[i][j]<<endl;
                    }else if(j-k==2){

                            dp[i][j]+=((dp[i][k]*potywys[i][min(3,j-k)])%MOD)*i;
                            dp[i][j]%=MOD;
                            dp1[i][j]+=((((((dp[i][k]*tab[i])%MOD)*tab[i])%MOD)*i)%MOD)*i;
                            dp1[i][j]%=MOD;



                    }else if(j-k==3){

                        if(k==0){
                            dp[i][j]+=((dp[i][k]*potywys[i][min(3,j-k-1)])%MOD)*i*i;
                            dp[i][j]%=MOD;
                            dp1[i][j]+=((dp[i][k]*dp[i-1][2])%MOD)*tab[i];
                            dp1[i][j]%=MOD;

                        }else{
                            dp[i][j]+=((dp[i][k]*potywys[i][min(3,j-k)])%MOD)*i*i;
                            dp[i][j]%=MOD;
                            dp1[i][j]+=((((dp[i][k]*tab[i])%MOD)*dp[i-1][2])%MOD)*tab[i];
                            dp1[i][j]%=MOD;
                        }

                    }else{
                        if(k==0){
                            dp[i][j]+=((dp[i][k]*potywys[i][min(2,j-k-1)])%MOD)*dp[i-1][j-k-2];
                            dp[i][j]%=MOD;
                            dp1[i][j]+=((dp[i][k]*dp[i-1][j-k-1])%MOD)*tab[i];
                            dp1[i][j]%=MOD;
                             //cout<<i<<" "<<j<<" "<<dp[i][j]<<endl;
                        }else{
                            dp[i][j]+=((dp[i][k]*potywys[i][min(3,j-k)])%MOD)*dp[i-1][j-k-2];
                            dp[i][j]%=MOD;
                            dp1[i][j]+=((((dp[i][k]*tab[i])%MOD)*dp[i-1][j-k-1])%MOD)*tab[i];
                            dp1[i][j]%=MOD;
                        }
                    }

                }
            }
        }

        for(int j=2;j<n;++j){//cout<<i<<" "<<j<<" "<<dp[i][j]<<endl;
            dp[i][j]+=dp[i-1][j]+dp1[i][j];
            dp[i][j]%=MOD;
        }
    }
    printf("%lld",dp[n-1][n-1]);
    //rob(0);
    //cout<<" "<<wynik;
    return 0;
}

//MMOD
