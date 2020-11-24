#include <bits/stdc++.h>
#define lld int
#define MAX 8009
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define INF 1000000

using namespace std;

lld a,t,n,wyn=100000000;
lld tab[3][1009];
lld plec[23][81];

int main()
{
    scanf("%d",&a);
    scanf("%d",&t);
    scanf("%d",&n);
    for(int i=0;i<n;++i){
        scanf("%d",&tab[0][i]);
        scanf("%d",&tab[1][i]);
        scanf("%d",&tab[2][i]);
    }

    for(int x=0;x<23;++x){
            for(int y=0;y<81;++y){
            plec[x][y]=INF;
        }
        }//cout<<"G";
        plec[0][0]=0;

    for(int i=0;i<n;++i){
        for(int x=22;x>=0;--x){
            for(int y=80;y>=0;--y){
            if(x<=tab[0][i]&&y<=tab[1][i]){
                plec[x][y]=min(plec[x][y],tab[2][i]);
            }else{
                plec[x][y]=min(plec[x][y],plec[max(x-tab[0][i],0)][max(y-tab[1][i],0)]+tab[2][i]);
            }
        }
        }
    }


        /*for(int j=0;j<plec.size();++j){
                //cout<<plec[1][n][j];
                if(plec[j].f.f>=a&&plec[j].f.s>=t){
                    wyn=min(wyn,plec[j].s);
                }

        }*/

        cout<<plec[a][t];

    return 0;
}
