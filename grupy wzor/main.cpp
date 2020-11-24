#include <bits/stdc++.h>
#include <bits/stdc++.h>
#define lld long long
#define mp make_pair
#define s second
#define f first
#define MAX 301
#define INF 1000000000
#define MOD 1000000007
#define pb push_back
#define pii pair<int,int>


using namespace std;

uint_fast32_t n,m;

uint_fast32_t dp[MAX][MAX][MAX],a,b,g,wynik;
vector<pii> v[303];

int main()
{
    scanf("%u%u",&n,&m);
    for(int i=0;i<m;++i){
        scanf("%u%u%u",&a,&b,&g);
       // zak[i]=mp(mp(a,b),g);
        v[b].pb(mp(a,g));
    }

    dp[0][0][0]=1;
    //n=min(n,MAX-10);
    for(short i=0;i<n;++i){
        for(short j=0;j<n;++j){
            if(i==j&&i!=0)continue;
            for(short k=0;k<n;++k){
                //if(!i&&!j&&!k)cout<<"X";
                //if((!(j!=0&&i==0&&k==0))&&(!(j==0&&i!=0&&k==0))&&(!(j==0&&i==0&&k!=0))&&(!(j==0&&i==0&&k==0))&&((j==i)||(k==i)||(j==k)))continue;
                uint_fast32_t w=dp[i][j][k];//cout<<"X";
                short maxi=max(i,max(j,k))+1;

                bool przyps=0;
                char ilek=1;
                for(short p=0;p<v[maxi].size();++p){
                    //int ilek=1;
                    ilek=1;
                    ilek+=(j>=v[maxi][p].f);
                    ilek+=(k>=v[maxi][p].f);
                    if(ilek!=v[maxi][p].s){
                        przyps=1;
                        break;
                    }
                }
                if(!przyps){
                    dp[maxi][j][k]+=w;
                    //cout<<"X";
                    if(dp[maxi][j][k]>MOD)dp[maxi][j][k]-=MOD;
                    }

                przyps=0;
                for(short p=0;p<v[maxi].size();++p){
                    ilek=1;
                    ilek+=(i>=v[maxi][p].f);
                    ilek+=(k>=v[maxi][p].f);
                    if(ilek!=v[maxi][p].s){
                        przyps=1;
                        break;
                    }
                }
                if(!przyps){dp[i][maxi][k]+=w;
                if(dp[i][maxi][k]>MOD)dp[i][maxi][k]-=MOD;}


                przyps=0;
                for(short p=0;p<v[maxi].size();++p){
                    ilek=1;
                    ilek+=(j>=v[maxi][p].f);
                    ilek+=(i>=v[maxi][p].f);
                    if(ilek!=v[maxi][p].s){
                        przyps=1;
                        break;
                    }
                }
                if(!przyps){dp[i][j][maxi]+=w;
                if(dp[i][j][maxi]>MOD)dp[i][j][maxi]-=MOD;
                }
            }

        }
    }
    //cout<<"X";
    //cout<<dp[0][1][0]<<endl;
    for(short i=0;i<n;++i){
        for(short j=0;j<n;++j){
            if(i==j&&j)continue;
            wynik+=dp[n][i][j];
            wynik+=dp[i][n][j];
            wynik+=dp[i][j][n];
            wynik%=MOD;
        }
    }
    printf("%u",wynik);
    return 0;
}
