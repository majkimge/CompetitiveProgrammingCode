#include <bits/stdc++.h>
#define MAX 500009
#define pb push_back

using namespace std;

int zaj[MAX];
int wyn[MAX];
int tab[MAX];
int pos[MAX];
int tree[MAX*4];
int n,k=1,m,tpos;

void ustaw(int gdzie){
    gdzie+=k;
    tree[gdzie]=1;
    gdzie>>=1;
    while(gdzie>0){
        tree[gdzie]=min(tree[gdzie*2],tree[gdzie*2+1]);
        gdzie>>=1;
    }
}

int check(int gdzie){
    int czyp=0;
    gdzie+=k;
    gdzie>>=1;
    while(gdzie<k){
        if(!czyp){
            if(tree[gdzie*2+1]==0){
                czyp=1;
                gdzie=gdzie*2+1;
            }else{
                gdzie>>=1;
            }
        }else{
            if(tree[gdzie*2]==0){
                //czyp=1;
                gdzie=gdzie*2;
            }else{
                gdzie=gdzie*2+1;
            }
        }
    }
    return gdzie-k;
}

int main()
{
    scanf("%d",&n);
    scanf("%d",&m);
    for(int i=0;i<n;++i){
        scanf("%d",&tab[i]);
        pos[tab[i]]=i;
    }
    while(k<n){
        k<<=1;
    }
    for(int i=1;i<=n;++i){
        if(!zaj[max(0,pos[i]-m)]){
            wyn[max(0,pos[i]-m)]=i;
            zaj[max(0,pos[i]-m)]=1;
            ustaw(max(0,pos[i]-m));
        }else{
            tpos=check(max(0,pos[i]-m));
            wyn[tpos]=i;
            zaj[tpos]=1;
            ustaw(tpos);
        }
    }
    for(int i=0;i<n;++i){
        printf("%d ",wyn[i]);
    }
    return 0;
}
