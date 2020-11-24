#include <bits/stdc++.h>

#define pb push_back
#define mp make_pair
#define f first
#define s second
#define lld long long
#define MAX 109

using namespace std;

int n,k,it,x,y,tx,ty;
int tab[MAX][MAX];
int sumy[MAX][MAX];
lld wyny[MAX][MAX][MAX];
int odw[MAX][MAX][MAX];
queue<pair<int,int> > q[MAX];
lld wynik;

int main()
{
    scanf("%d%d",&n,&k);
    n<<=1;
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            scanf("%d",&tab[i][j]);
        }
    }
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            tx=j+1;
            ty=i+1;
            while(tx>=0&&tx<n&&ty>=0&&ty<n){
                sumy[i][j]+=tab[ty][tx];
                tx++;
                ty++;
            }

            tx=j+1;
            ty=i-1;
            while(tx>=0&&tx<n&&ty>=0&&ty<n){
                sumy[i][j]+=tab[ty][tx];
                tx++;
                ty--;
            }

            tx=j-1;
            ty=i-1;
            while(tx>=0&&tx<n&&ty>=0&&ty<n){
                sumy[i][j]+=tab[ty][tx];
                tx--;
                ty--;
            }

            tx=j-1;
            ty=i+1;
            while(tx>=0&&tx<n&&ty>=0&&ty<n){
                sumy[i][j]+=tab[ty][tx];
                tx--;
                ty++;
            }
        }
    }
    q[0].push(mp(0,n/2-1));
    q[0].push(mp(0,n/2));
    wyny[0][n/2-1][0]=sumy[0][n/2-1];
    wyny[0][n/2][0]=sumy[0][n/2];
    for(int i=1;i<=k;++i){
        while(!q[i-1].empty()){
            x=q[i-1].front().s;
            y=q[i-1].front().f;
            int temp=wyny[y][x][i-1];
            tx=x+1;
            ty=y+1;
            while(tx>=0&&tx<n&&ty>=0&&ty<n){
                wyny[ty][tx][i]=max(wyny[ty][tx][i],(lld)temp+sumy[ty][tx]);
                if(!odw[ty][tx][i]){
                    odw[ty][tx][i]=1;
                    q[i].push(mp(ty,tx));
                }

                tx++;
                ty++;
            }

            tx=x+1;
            ty=y-1;
            while(tx>=0&&tx<n&&ty>=0&&ty<n){
                wyny[ty][tx][i]=max(wyny[ty][tx][i],(lld)temp+sumy[ty][tx]);
                if(!odw[ty][tx][i]){
                    odw[ty][tx][i]=1;
                    q[i].push(mp(ty,tx));
                }
                tx++;
                ty--;
            }

            tx=x-1;
            ty=y-1;
            while(tx>=0&&tx<n&&ty>=0&&ty<n){
                wyny[ty][tx][i]=max(wyny[ty][tx][i],(lld)temp+sumy[ty][tx]);
                if(!odw[ty][tx][i]){
                    odw[ty][tx][i]=1;
                    q[i].push(mp(ty,tx));
                }
                tx--;
                ty--;
            }

            tx=x-1;
            ty=y+1;
            while(tx>=0&&tx<n&&ty>=0&&ty<n){
                wyny[ty][tx][i]=max(wyny[ty][tx][i],(lld)temp+sumy[ty][tx]);
                if(!odw[ty][tx][i]){
                    odw[ty][tx][i]=1;
                    q[i].push(mp(ty,tx));
                }
                tx--;
                ty++;
            }
        }
    }
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            wynik=max(wynik,wyny[i][j][k]);
        }
    }
    printf("%lld",wynik);
    return 0;
}
