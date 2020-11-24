#include <bits/stdc++.h>
#define lld long long
#define mp make_pair
#define pb push_back
#define MAX 300009
#define f first
#define s second
#define pii pair<lld,lld>

using namespace std;

int n,m,k,a,b;
int jaki[MAX];
vector<pii> kraw[MAX];
lld dp[MAX][65][6];
int odw[MAX];
int poty[6];
int roz[6];
lld wynik;
lld dlakr[MAX*2][6];

/*int dfs(int from,int ojc,int kt, int zk){
    odw[from]=kt;
    if(ojc==from){
        dp[from][poty[jaki[from]]]=1;
    }else{
        for(int i=0;i<33;++i){
            int kt=0;
            int temp=i;
            for(int j=0;j<6;++j)roz[j]=0;
            while(temp){
                roz[kt]=temp%2;
                temp>>=1;
                ++kt;
            }
            if(roz[jaki[from]]==0){
                dp[from][i+poty[jaki[from]]][kt]+=dp[ojc][i][kt-1]-kraw[ojc][zk].s;
                if(i!=0)wynik+=dp[ojc][i]-kraw[ojc][zk].s;
            }
        }
    }
    dp[from][0]=1;
    for(int i=0;i<kraw[from].size();++i){
        if(!odw[kraw[from][i]]){
            dfs(kraw[from][i],from);
        }
    }
}*/

int main()
{
    scanf("%d%d%d",&n,&m,&k);
    poty[0]=1;
    for(int i=1;i<6;++i){
        poty[i]=poty[i-1]*2;
    }
    for(int i=1;i<=n;++i){
        scanf("%d",&jaki[i]);
        --jaki[i];
        dp[i][poty[jaki[i]]][1]=1;
    }


    for(int i=0;i<m;++i){
        scanf("%d%d",&a,&b);
        kraw[a].pb(mp(b,i));
        kraw[b].pb(mp(a,i+300001));
    }
    for(int xd=2;xd<=k;++xd){
        for(int from=1;from<=n;++from){
            for(int i=0;i<33;++i){
                int kt=0;
                int temp=i;
                for(int j=0;j<6;++j)roz[j]=0;
                while(temp){
                    roz[kt]=temp%2;
                    temp>>=1;
                    ++kt;
                }
                if(roz[jaki[from]]==0){
                    for(int z=0;z<kraw[from].size();++z){
                        int dok=0;
                        if(kraw[from][z].s>300000){
                            dok=kraw[from][z].s-300001;
                        }else{
                            dok=kraw[from][z].s+300001;
                        }
                        dp[from][i+poty[jaki[from]]][xd]+=dp[kraw[from][z].f][i][xd-1]-dlakr[kraw[from][z].s][xd-1];
                        dlakr[dok][xd]=dp[kraw[from][z].f][i][xd-1]-dlakr[kraw[from][z].s][xd-1];
                        wynik+=dp[kraw[from][z].f][i][xd-1]-dlakr[kraw[from][z].s][xd-1];
                    }
                }
            }
        }
    }
    //dfs(1,1);
    //cout<<dp[2][poty[0]+poty[1]][2];
    printf("%lld",wynik);

    return 0;
}
