#include <bits/stdc++.h>
#define lld long long
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define MOD 10007
#define MAX 809


using namespace std;

int n;
bitset<256> tab[MAX];
bitset<256> l,p;
char s[MAX];
vector<int> wynik;
bitset<256> dp[MAX][MAX];
int ziom[MAX];
int odw[MAX];

int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;++i){
        scanf("%s",s);
        for(int j=0;j<n;++j){
            if(s[j]=='1'){

                tab[i].set(j);
            }
        }
    }
    //cout<<tab[0][5];
    for(int i=0;i<MAX;++i){
        ziom[i]=i%n;
    }
    for(int i=0;i<2*n;++i){
        dp[i][i].set(ziom[i]);
    }
    for(int i=2;i<=n;++i){
        for(int j=0;j<n*2-i;++j){
            for(int k=0;k<i;++k){
                if(k==0&&(tab[ziom[j]]&dp[j+1][j+i-1]).any()){
                    dp[j][j+i-1].set(ziom[j]);
                }else if(k==i-1&&(tab[ziom[k+j]]&dp[j][j+i-2]).any()){
                    dp[j][j+i-1].set(ziom[k+j]);
                }else{
                    //if(i==3&&j==6&&k==0)cout<<dp[6][6];
                    if(k!=0&&k!=i-1&&((tab[ziom[k+j]]&dp[j][j+k-1]).any())&&(tab[ziom[k+j]]&dp[j+k+1][j+i-1]).any()){
                        dp[j][j+i-1].set(ziom[k+j]);
                    }
                }
            }
        }
    }
    //cout<<ziom[7];
    //cout<<dp[6][8][0];
    for(int i=0;i<n;++i){

            for(int k=0;k<n;++k){
                if(dp[i][i+n-1][k]&&!odw[k]){
                    odw[k]=1;
                    wynik.pb(k+1);
                }
            }

    }
    sort(wynik.begin(),wynik.end());
    printf("%d\n",wynik.size());
    for(int i=0;i<wynik.size();++i){
        printf("%d\n",wynik[i]);
    }
    return 0;
}
