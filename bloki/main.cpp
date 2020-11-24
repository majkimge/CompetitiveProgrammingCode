#include <bits/stdc++.h>
#define pbpush_back
#define mp make_pair
#define lld long long
#define f first
#define s second
#define MAX 1000009
#define INF 2000000009

using namespace std;

lld n,k1,l,k2;
vector<lld> blok[6][6];
lld odw[6][6][6][6];
lld cok[6][6];
lld wyny[6][6];

int main()
{
    scanf("%lld",&n);
    for(int i=0;i<n;++i){
        scanf("%lld%lld%lld",&k1,&l,&k2);
        blok[k1][k2].pb(-l);
        blok[k2][k1].pb(-l);
    }
    for(int i=1;i<=5;++i){
        for(int j=1;j<=5;++j){
            sort(blok[i][j].begin(),blok[j][i].end());
        }
    }
    for(int i=1;i<=5;++i){
        for(int j=1;j<=5;++j){
            wyny[i][j]=blok[i][j][0];
        }
    }
    for(int xx=1;xx<=n;++xx){
        for(int i=1;i<=5;++i){
            for(int j=1;j<=5;++j){
                for(int z=1;z<=5;++z){
                    wyny[i][j]=wyny[i][z]+blok[z][j][odw[i][z][z][j]];
                    odw[i][z][z][j]++;
                    //odw[i][z][z][j]
                }
                for(int z=1;z<=5;++z){
                    wyny[i][j]=wyny[i][z]+blok[z][j][odw[i][z][z][j]];
                    odw[i][z][z][j]++;
                }
            }
        }

    }
    return 0;
}
