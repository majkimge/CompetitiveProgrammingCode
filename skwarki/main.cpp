#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define lld long long

using namespace std;

lld n,k,p,kk=1,wynik;

lld dp[1009][15][2][2];
lld pref[1009][15][2][2];
lld dwu[1009][1009];

lld pot(lld co,lld dok){
    if(dok==0){
        return 1;
    }else if(dok%2==0){
        lld temp=pot(co,dok/2);
        return (temp*temp)%p;

    }else{
        return (co*pot(co,dok-1))%p;
    }



}

int main()
{
    scanf("%lld%lld",&n,&k);
    p=1000000007;
    for(int i=1;i<k;++i){
        kk<<=1;
    }
    ++kk;
    for(int i=0;i<=n;++i){
        dwu[i][0]=1;
        for(int j=1;j<=i;++j){
            dwu[i][j]=((dwu[i][j-1]*(i-j+1))%p)*pot(j,p-2);
            dwu[i][j]%=p;
        }
    }
    if(kk>n){
        printf("0");
    }else if(n==1&&k==0){
        printf("1");
    }else if(n==2&&k==1){
        printf("2");
    }else if(n>2){
        dp[1][0][0][1]=1;
        dp[1][0][1][0]=1;
        dp[0][0][1][1]=1;
        dp[2][1][1][0]=1;
        dp[2][1][0][1]=1;
        dp[3][1][0][1]=1;
        dp[3][1][1][0]=1;
        dp[3][1][0][0]=2;
        dp[3][2][1][1]=2;
        pref[3][1][0][1]=1;
        pref[3][1][1][0]=1;
        pref[3][1][0][0]=2;
        pref[3][2][1][1]=2;
        pref[1][0][1][1]=1;
        pref[0][0][1][1]=1;
        pref[2][1][1][0]=1;
        pref[2][1][0][1]=1;
        for(int i=4;i<=n;++i){
            for(int j=2;j<i;++j){
                lld mno=dwu[i-1][j];
                //cout<<mno<<endl;
                for(int z=1;z<=k;++z){

                    if(j==i-2){
                        dp[i][z][1][0]+=dp[j][z-1][1][0]*mno;cout<<dp[3][2][1][0]<<endl;
                        //dp[i][z][1][0]+=dp[j][z-1][1][0]*mno;
                        dp[i][z][1][0]+=dp[j][z][1][1]*mno;
                        //dp[i][z][1][0]+=dp[j][z][1][1]*mno;

                        dp[i][z][0][0]+=dp[j][z-1][0][0]*mno;
                        //dp[i][z][0][0]+=dp[j][z-1][0][0]*mno;
                        dp[i][z][0][0]+=dp[j][z][0][1]*mno;
                        //dp[i][z][0][0]+=dp[j][z][0][1]*mno;


                        dp[i][z][0][1]+=dp[j][z][1][1]*mno;
                        //dp[i][z][0][1]+=dp[j][z][1][1]*mno;
                        dp[i][z][0][1]+=dp[j][z-1][0][1]*mno;
                        //dp[i][z][0][1]+=dp[j][z-1][0][1]*mno;

                        dp[i][z][0][0]+=dp[j][z][1][0]*mno;
                        //dp[i][z][0][0]+=dp[j][z][1][0]*mno;
                        dp[i][z][0][0]+=dp[j][z-1][0][0]*mno;
                        //dp[i][z][0][0]+=dp[j][z-1][0][0]*mno;

                        dp[i][z][1][0]%=p;
                        dp[i][z][0][0]%=p;
                        dp[i][z][0][1]%=p;
                        //cout<<dp[i][z][0][0];


                    }else if(j==i-1){
                        dp[i][z][1][1]+=dp[j][z-1][1][0];
                        //dp[i][z][1][1]+=dp[j][z-1][1][0];
                        dp[i][z][1][1]+=dp[j][z][1][1];
                        //dp[i][z][1][1]+=dp[j][z][1][1];

                        dp[i][z][0][1]+=dp[j][z-1][0][0];
                       // dp[i][z][0][1]+=dp[j][z-1][0][0];
                        dp[i][z][0][1]+=dp[j][z][0][1];
                        //dp[i][z][0][1]+=dp[j][z][0][1];

                        dp[i][z][1][0]+=dp[j][z][1][0];
                        //dp[i][z][1][0]+=dp[j][z][1][0];
                        dp[i][z][1][0]+=dp[j][z-1][0][0];
                        //dp[i][z][1][0]+=dp[j][z-1][0][0];

                        dp[i][z][1][1]+=dp[j][z][1][1];
                        //dp[i][z][1][1]+=dp[j][z][1][1];
                        dp[i][z][1][1]+=dp[j][z-1][0][1];
                        //dp[i][z][1][1]+=dp[j][z-1][0][1];

                        dp[i][z][1][0]%=p;
                        dp[i][z][1][1]%=p;
                        dp[i][z][0][1]%=p;

                    }else{

                        dp[i][z][1][0]+=((dp[j][z-1][1][0]*pref[i-j-1][max(0,z-1)][1][0])%p)*mno;
                        dp[i][z][1][0]+=((dp[j][z-1][1][0]*pref[i-j-1][max(0,z-2)][0][0])%p)*mno;
                        dp[i][z][1][0]+=((dp[j][z][1][1]*pref[i-j-1][max(0,z-1)][1][0])%p)*mno;
                        dp[i][z][1][0]+=((dp[j][z][1][1]*pref[i-j-1][max(0,z-2)][0][0])%p)*mno;

                        dp[i][z][1][0]+=((dp[j][z][1][0]*pref[i-j-1][max(0,z-2)][1][0])%p)*mno;
                        dp[i][z][1][0]+=((dp[j][z][1][0]*pref[i-j-1][max(0,z-1)][1][1])%p)*mno;
                        dp[i][z][1][0]+=((dp[j][z-1][0][0]*pref[i-j-1][max(0,z-2)][1][0])%p)*mno;
                        dp[i][z][1][0]+=((dp[j][z-1][0][0]*pref[i-j-1][max(0,z-1)][1][1])%p)*mno;
                        dp[i][z][1][0]%=p;



                        dp[i][z][1][1]+=((dp[j][z-1][1][0]*pref[i-j-1][max(0,z-1)][1][1])%p)*mno;
                        dp[i][z][1][1]+=((dp[j][z-1][1][0]*pref[i-j-1][max(0,z-2)][0][1])%p)*mno;
                        dp[i][z][1][1]+=((dp[j][z][1][1]*pref[i-j-1][max(0,z-1)][1][1])%p)*mno;
                        dp[i][z][1][1]+=((dp[j][z][1][1]*pref[i-j-1][max(0,z-2)][0][1])%p)*mno;

                        dp[i][z][1][1]+=((dp[j][z][1][1]*pref[i-j-1][max(0,z-2)][1][0])%p)*mno;
                        dp[i][z][1][1]+=((dp[j][z][1][1]*pref[i-j-1][max(0,z-1)][1][1])%p)*mno;
                        dp[i][z][1][1]+=((dp[j][z-1][0][1]*pref[i-j-1][max(0,z-2)][1][0])%p)*mno;
                        dp[i][z][1][1]+=((dp[j][z-1][0][1]*pref[i-j-1][max(0,z-1)][1][1])%p)*mno;
                        dp[i][z][1][1]%=p;



                        dp[i][z][0][1]+=((dp[j][z-1][0][0]*pref[i-j-1][max(0,z-1)][1][1])%p)*mno;
                        dp[i][z][0][1]+=((dp[j][z-1][0][0]*pref[i-j-1][max(0,z-2)][0][1])%p)*mno;
                        dp[i][z][0][1]+=((dp[j][z][0][1]*pref[i-j-1][max(0,z-1)][1][1])%p)*mno;
                        dp[i][z][0][1]+=((dp[j][z][0][1]*pref[i-j-1][max(0,z-2)][0][1])%p)*mno;

                        dp[i][z][0][1]+=((dp[j][z][1][1]*pref[i-j-1][max(0,z-2)][0][0])%p)*mno;
                        dp[i][z][0][1]+=((dp[j][z][1][1]*pref[i-j-1][max(0,z-1)][0][1])%p)*mno;
                        dp[i][z][0][1]+=((dp[j][z-1][0][1]*pref[i-j-1][max(0,z-2)][0][0])%p)*mno;
                        dp[i][z][0][1]+=((dp[j][z-1][0][1]*pref[i-j-1][max(0,z-1)][0][1])%p)*mno;
                        dp[i][z][0][1]%=p;



                        dp[i][z][0][0]+=((dp[j][z-1][0][0]*pref[i-j-1][max(0,z-1)][1][0])%p)*mno;
                        dp[i][z][0][0]+=((dp[j][z-1][0][0]*pref[i-j-1][max(0,z-2)][0][0])%p)*mno;
                        dp[i][z][0][0]+=((dp[j][z][0][1]*pref[i-j-1][max(0,z-1)][1][0])%p)*mno;
                        dp[i][z][0][0]+=((dp[j][z][0][1]*pref[i-j-1][max(0,z-2)][0][0])%p)*mno;

                        dp[i][z][0][0]+=((dp[j][z][1][0]*pref[i-j-1][max(0,z-2)][0][0])%p)*mno;
                        dp[i][z][0][0]+=((dp[j][z][1][0]*pref[i-j-1][max(0,z-1)][0][1])%p)*mno;
                        dp[i][z][0][0]+=((dp[j][z-1][0][0]*pref[i-j-1][max(0,z-2)][0][0])%p)*mno;
                        dp[i][z][0][0]+=((dp[j][z-1][0][0]*pref[i-j-1][max(0,z-1)][0][1])%p)*mno;
                        dp[i][z][0][0]%=p;

                    }

                }
            }
            for(int j=1;j<=k;++j){
                pref[i][j][0][0]=pref[i][j-1][0][0]+dp[i][j][0][0];
                pref[i][j][0][1]=pref[i][j-1][0][1]+dp[i][j][0][1];
                pref[i][j][1][0]=pref[i][j-1][1][0]+dp[i][j][1][0];
                pref[i][j][1][1]=pref[i][j-1][1][1]+dp[i][j][1][1];

                pref[i][j][0][0]%=p;
                pref[i][j][0][1]%=p;
                pref[i][j][1][0]%=p;
                pref[i][j][1][1]%=p;
            }
        }
        wynik=dp[n][k][0][0]+dp[n][k][0][1]+dp[n][k][1][0]+dp[n][k][1][1];
        //cout<<dp[n][k][1][1];
        wynik%=p;
        printf("%lld",wynik);
    }
    return 0;
}
