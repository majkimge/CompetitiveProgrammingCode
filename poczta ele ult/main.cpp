#include <bits/stdc++.h>
#define lld long long
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define MAX 209

using namespace std;

int n,kt;
int tab[MAX];
int tab1[MAX];
int dp[MAX][MAX][MAX],wynik=MAX;
map<int,int> m;
int tab2[MAX],kt1;

int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;++i){
        scanf("%d",&tab1[i]);
    }
    for(int i=0;i<n;++i){
        tab[kt]=tab1[i];
        tab2[kt]=tab1[i];
        while(i+1<n&&tab1[i]==tab1[i+1]){
            ++i;
        }
        ++kt;
    }
    sort(tab2,tab2+kt);
    for(int i=0;i<kt;++i){
        int tt=tab2[i];
        m[tt]=kt1;
        while(i<kt-1&&tab2[i+1]==tt){
            ++i;
        }
        kt1++;
    }
    for(int i=0;i<kt;++i){
        tab[i]=m[tab[i]];
        //cout<<tab[i]<<" ";
    }
    //cout<<endl;
    n=kt;
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            for(int z=0;z<n;++z){
                dp[i][j][z]=MAX;
            }
        }
    }

    for(int i=0;i<n;++i){
        dp[i][i][tab[i]]=1;
    }
    for(int i=0;i<n-1;++i){
        if(tab[i]==tab[i+1]){
            dp[i][i+1][tab[i]]=1;
        }else{
            dp[i][i+1][tab[i]]=2;
            dp[i][i+1][tab[i+1]]=2;
        }
    }
    for(int i=3;i<=n;++i){
        for(int j=0;j<=n-i;++j){
            for(int z=j;z<=j+i-2;++z){
                dp[j][j+i-1][tab[z]]=min(min(dp[j][j+i-1][tab[z]],dp[j][j+i-2][tab[z]]+1),dp[j][z][tab[z]]+dp[z+1][j+i-2][tab[j+i-1]]);
                //if(i==6&&j==0&&z==2)cout<<"X "<<dp[j][j+i-2][tab[z]]+1<<" X";
                if(tab[z]==tab[j+i-1])dp[j][j+i-1][tab[z]]=min(min(dp[j][j+i-1][tab[z]],dp[j][j+i-2][tab[z]]),dp[j][z][tab[z]]+dp[z+1][j+i-2][tab[j+i-1]]);
            }
            int minix=209;
            for(int z=j;z<=j+i-2;++z){
                minix=min(minix,dp[j][j+i-2][tab[z]]+1);
                if(tab[z]==tab[j+i-1])minix=min(minix,dp[j][j+i-2][tab[z]]);
            }
            dp[j][j+i-1][tab[j+i-1]]=min(dp[j][j+i-1][tab[j+i-1]],minix);
        }
    }
    /*dp[0][0]=1;
    for(int i=1;i<n;++i){
        dp[i][i]=MAX;
        for(int j=0;j<i;++j)dp[i][i]=min(dp[i][i],dp[i-1][j]+1);
        for(int j=0;j<i;++j){
            if(tab[j]==tab[i])dp[i][i]=min(dp[i][i],dp[i-1][j]);
            dp[i][j]=dp[i-1][j]+1;
            for(int z=j+1;z<i;++z){
                if(tab[z]==tab[i])dp[i][j]=min(dp[i][j],dp[z-1][j]+dp[i-1][z]-dp[z][z]+1);
            }
        }
    }*/
    for(int i=0;i<kt1;++i){
        wynik=min(wynik,dp[0][n-1][i]);
    }
    /*for(int i=0;i<n;++i){
        for(int j=i;j<n;++j){
            for(int z=0;z<kt1;++z){
                cout<<i<<" "<<j<<" "<<z<<": "<<dp[i][j][z]<<endl;
            }

        }
    }*/
    printf("%d",wynik);
    return 0;
}
