#include <bits/stdc++.h>
#include <bits/stdc++.h>
#define lld long long
#define mp make_pair
#define s second
#define f first
#define MAX 109
#define INF 1000000000
#define MOD 1000000007
#define pb push_back
#define pii pair<int,char>

using namespace std;

int tab[MAX][MAX],n,m,a,b,c;
int pom[MAX][MAX],wyn[MAX][MAX];

void spm(int dok){
    if(dok<=1)return;
    if(dok%2==0){
        spm(dok/2);
        for(int i=1;i<=n;++i){
            for(int j=1;j<=n;++j){
                pom[i][j]=wyn[i][j];
                wyn[i][j]=0;
            }
        }
        for(int i=1;i<=n;++i){
            for(int j=1;j<=n;++j){
                for(int k=1;k<=n;++k){
                    wyn[i][j]+=pom[i][k]*pom[k][j];
                    wyn[i][j]%=MOD;
                }
            }
        }
    }else{
        spm(dok-1);
        for(int i=1;i<=n;++i){
            for(int j=1;j<=n;++j){
                pom[i][j]=wyn[i][j];
                wyn[i][j]=0;
            }
        }
        for(int i=1;i<=n;++i){
            for(int j=1;j<=n;++j){
                for(int k=1;k<=n;++k){
                    wyn[i][j]+=tab[i][k]*pom[k][j];
                    wyn[i][j]%=MOD;
                }
            }
        }
    }
}

int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;++i){
        scanf("%d%d",&a,&b);
        tab[a][b]=1;
        wyn[a][b]=1;
    }
    spm(3000000);
    cout<<wyn[1][2];
    return 0;
}
