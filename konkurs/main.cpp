#include <bits/stdc++.h>
#define lld long long
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define MAX 2100

using namespace std;

int z,w,k,r,kk=1;
int tree[MAX][MAX];

void ustaw(int x,int y,int co){
    x+=kk;
    int yy=y+kk;
    tree[x][yy]=co;
    while(x>0){
        yy=y+kk;
        while(yy>0){
            if(yy>=kk){
                if(x>=kk){
                    tree[x][yy]=co;
                }else{
                    tree[x][yy]=max(tree[x*2][yy],tree[x*2+1][yy]);
                }

            }else{
                tree[x][yy]=max(tree[x][yy*2],tree[x][yy*2+1]);
                if(x<kk){
                tree[x][yy]=max(tree[x][yy],max(tree[x*2][yy],tree[x*2+1][yy]));
                }
            }
            yy>>=1;
        }
        x>>=1;
    }
}

int check(int x, int y){
    int l=max(x-r,0);
    int p=min(x+r,k-1);
    int g=max(y-r,0);
    int d=min(y+r,w-1);
    l+=kk;
    p+=kk;
    g+=kk;
    d+=kk;
    int l1=l;
    int p1=p;
    int g1=g;
    int d1=d;
    int wyn=0;
    wyn=max(tree[l][d],tree[l][g]);

    wyn=max(wyn,max(tree[p][d],tree[p][g]));


    while(g/2!=d/2){
        if(g%2==0){
            wyn=max(wyn,max(tree[l][g+1],tree[p][g+1]));
        }
        if(d%2==1){
            wyn=max(wyn,max(tree[l][d-1],tree[p][d-1]));
        }
        d>>=1;
        g>>=1;
    }

    while(l/2!=p/2){
        g=g1;
        d=d1;
        if(l%2==0){
            wyn=max(wyn,max(tree[l+1][d],tree[l+1][g]));

            while(g/2!=d/2){
                if(g%2==0){
                    wyn=max(wyn,tree[l+1][g+1]);
                }
                if(d%2==1){
                    wyn=max(wyn,tree[l+1][d-1]);
                }
                d>>=1;
                g>>=1;
            }
        }
        g=g1;
        d=d1;
        if(p%2==1){
            wyn=max(wyn,max(tree[p-1][d],tree[p-1][g]));

            while(g/2!=d/2){
                if(g%2==0){
                    wyn=max(wyn,tree[p-1][g+1]);
                }
                if(d%2==1){
                    wyn=max(wyn,tree[p-1][d-1]);
                }
                d>>=1;
                g>>=1;
            }
        }
        l>>=1;
        p>>=1;
    }
    return wyn;
}

int main()
{

    scanf("%d",&z);
    for(int xx=0;xx<z;++xx){
        scanf("%d",&w);
        scanf("%d",&k);
        scanf("%d",&r);
        for(int i=0;i<2092;++i){
            for(int j=0;j<2092;++j){
            tree[i][j]=0;
        }
        }
        while(kk<max(w,k)){
            kk<<=1;
        }
        for(int i=0;i<w;++i){
            for(int j=0;j<k;++j){
                int temp=0;
                scanf("%d",&temp);
                ustaw(j,i,temp);
            }
        }
        for(int i=0;i<w;++i){
            for(int j=0;j<k;++j){
                int temp=0;
                temp=check(j,i);
                printf("%d ",temp);
            }
            printf("\n");
        }

    }
    return 0;
}
