#include <bits/stdc++.h>
#define lld long long
#define mp make_pair
#define f first
#define s second
#define pb push_back
#define MAX 509
#define INF 2000000009

using namespace std;

char tab1[MAX][MAX],a[5009];
bool tab[MAX][MAX];
bool dp[MAX][MAX][2];
int r,c,m;
int ite;

int main()
{
    scanf("%d%d%d",&r,&c,&m);
    for(int i=1;i<=r;++i){
        scanf("%s",&tab1[i][1]);
    }
    for(int i=1;i<=r;++i){
        for(int j=1;j<=c;++j){
            tab[i][j]=(tab1[i][j]=='.');
            dp[i][j][0]=tab[i][j];
        }
    }
    /*for(int i=1;i<=r;++i){
        for(int j=1;j<=c;++j){
            cout<<tab[i][j];
        }
        cout<<endl;
    }*/
    ite=1;
    scanf("%s",a);
    for(int i=0;i<m;++i){
        //scanf("%s",a);
        //cout<<a[i];
        if(a[i]=='E'){

            for(int i=1;i<=r;++i){
                for(int j=1;j<=c;++j){
                    dp[i][j][ite]=(tab[i][j]&dp[i][j-1][ite^1]);
                }
            }
        }else if(a[i]=='W'){
            for(int i=1;i<=r;++i){
                for(int j=1;j<=c;++j){
                    dp[i][j][ite]=(tab[i][j]&dp[i][j+1][ite^1]);
                }
            }
        }else if(a[i]=='S'){
            for(int i=1;i<=r;++i){
                for(int j=1;j<=c;++j){
                    dp[i][j][ite]=(tab[i][j]&dp[i-1][j][ite^1]);
                }
            }
        }else if(a[i]=='N'){
            for(int i=1;i<=r;++i){
                for(int j=1;j<=c;++j){
                    dp[i][j][ite]=(tab[i][j]&dp[i+1][j][ite^1]);
                }
            }
        }else{//cout<<i;
            for(int i=1;i<=r;++i){
                for(int j=1;j<=c;++j){
                    dp[i][j][ite]=(tab[i][j]&(dp[i+1][j][ite^1]|dp[i-1][j][ite^1]|dp[i][j-1][ite^1]|dp[i][j+1][ite^1]));
                }
            }
        }
        ite=ite^1;
    }
    int wynik=0;
    for(int i=1;i<=r;++i){
                for(int j=1;j<=c;++j){
                    wynik+=dp[i][j][ite^1];
                }
            }
            printf("%d",wynik);
    return 0;
}
