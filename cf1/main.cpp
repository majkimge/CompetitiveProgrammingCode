#include <bits/stdc++.h>
#define lld long long
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define INF 1000000009

using namespace std;

int n,t,czy;
char tab[60][120];

int main()
{
    scanf("%d",&t);
    for(int zz=0;zz<t;++zz)
    {
        scanf("%d",&n);
        scanf("%s",&tab[zz]);
        czy=0;
        int done=0;
        for(int i=0;i<n/2;++i)
        {
            done=0;
            for(int x=-1;x<=1;++x){
                if(x==0||(x==1&&tab[zz][i]=='z')||(x==-1&&tab[zz][i]=='a')) continue;
                if(done) break;
                for(int y=-1;y<=1;++y){
                    if(y==0||(y==1&&tab[zz][n-1-i]=='z')||(y==-1&&tab[zz][n-1-i]=='a')) continue;
                    if(tab[zz][i]+x==tab[zz][n-i-1]+y){
                        //cout<<"X";
                        czy++;
                        done=1;
                        break;
                    }
                }
            }
        }
        if(czy==n/2){
            printf("YES\n");
        }else{
            printf("NO\n");
        }

    }

    return 0;
}
