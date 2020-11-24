#include <bits/stdc++.h>
#define lld long long
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define MAX 100009
#define INF 100000000
#define MOD 1000000009

using namespace std;

int n,pier=320,itl,itp,gl,gp,ggl,ggp;
int tab[MAX];
int rep[320];
int czyz[MAX];
int wyny[MAX];
int ilez;

int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;++i){
        scanf("%d",&tab[i]);
    }
    for(int i=0;i<n;++i){
        itl=i;
        itp=i;
        gl=(i-tab[i]+n)%n;
        gp=(i+tab[i]+n)%n;
        ilez=0;
        ggl=INF;
        int wyn=0;
        for(int j=0;j<n;++j){
            czyz[j]=0;
        }
        while(ilez!=n){
            while((itl+n)%n!=(gl+n)%n){
                ggl=min(ggl,itl-tab[itl]);
                if(!czyz[(itl+n)%n]){
                    ilez++;
                    czyz[(itl+n)%n]=1;
                }

                itl--;
            }
            gl=ggl;
            while((itp+n)%n!=(gp+n)%n){
                ggp=max(ggp,itp+tab[itp]);
                if(!czyz[(itp+n)%n]){
                    ilez++;
                    czyz[(itp+n)%n]=1;
                }

                itp++;
            }
            gp=ggp;
            wyn++;
        }
        wyny[i]=wyn;
        printf("%d ",wyn);
    }

    return 0;
}
