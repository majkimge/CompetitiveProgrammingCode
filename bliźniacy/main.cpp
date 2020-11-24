#include <bits/stdc++.h>
#define lld long long
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define MOD 10007
#define MAX 209

using namespace std;

int n,dl;
char s[MAX];
char sd[MAX*2];
int dwum[MAX][MAX];
int dp[MAX][MAX][30];
int sil[MAX],wynik;

int main()
{

    scanf("%d",&n);
    dl=n*2-1;
    scanf("%s",s);
    dwum[0][0]=1;
    dwum[1][0]=1;
    dwum[1][1]=1;
    for(int i=0;i<=n;++i){
        dwum[i][0]=1;
    }
    for(int i=2;i<MAX;++i){
        for(int j=1;j<i;++j){
            dwum[i][j]=dwum[i-1][j-1]+dwum[i-1][j];
            dwum[i][j]%=MOD;
        }
        dwum[i][i]=1;
    }
    for(int i=0;i<dl;++i){
        sd[i]=s[i%n];
        sd[i]-='a';
    }
    for(int i=0;i<dl;++i){
        dp[i][i][sd[i]]=1;
    }

    //cout<<dwum[0][0];
    for(int i=3;i<=n;i+=2){
        for(int j=0;j<=dl-i;++j){
            for(int k=1;k<=i-2;k+=2){
                for(int p=1;p+k<=i-1;p+=2){
                    int sumiks=0;
                    for(int d=0;d<='z'-'a';++d){
                        sumiks+=((dp[j][j+k-1][d]*dp[j+k+p][j+i-1][d])%MOD*((dwum[(i-1)/2-1][(k-1)/2])%MOD))%MOD*((dwum[(i-k-1)/2][(i-p-k-1)/2])%MOD);
                        //sumiks+=((dp[j+k+p+1][j+i-1][d]*dwum[(n-1)/2][(n-k-p-1)/2])%MOD)*sil[(n-k-p-1)/2];
                        sumiks%=MOD;
                    }
                    //cout<<sumiks;
                    //if(i==7&&j==0&&k==1&&p==1)cout<<sumiks<<endl;
                    for(int d=0;d<='z'-'a';++d){
                        //sumiks+=((dp[j][j+k-1][d]*dp[j+k][j+k+p-1][d])%MOD*((dwum[(n-1)/2][(k-1)/2]*sil[(k-1)/2])%MOD))%MOD*((dwum[(n-k)/2][(p-1)/2]*sil[(p-1)/2])%MOD);
                        dp[j][j+i-1][d]+=sumiks*(dp[j+k][j+k+p-1][d])%MOD;
                        dp[j][j+i-1][d]%=MOD;

                    }


                }
            }
        }
    }
    //cout<<dp[0][6][0]<<endl;
    if(n%2){
        for(int i=0;i<=n;++i){
            for(int d=0;d<='z'-'a';++d){
                wynik+=dp[i][i+n-1][d];
                wynik%=MOD;
            }
        }
        printf("%d",wynik);
        return 0;
    }
    for(int i=0;i<n;++i){
        for(int j=1;j<=n;j+=2){
            for(int d=0;d<='z'-'a';++d){
                for(int x=0;x<='z'-'a';++x){
                    wynik+=((dp[i][i+j-1][d]*dp[i+j][i+n-1][x])%MOD*((dwum[(n-1)/2][j/2])%MOD));
                    wynik%=MOD;
                }
            }
        }
    }
    printf("%d",(wynik*5004)%MOD);

    return 0;
}
