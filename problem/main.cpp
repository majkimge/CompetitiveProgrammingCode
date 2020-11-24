#include <bits/stdc++.h>
#define lld int
#define MAX 1000009
#define pb push_back
#define mp make_pair
#define f first
#define s second

using namespace std;

int n,m,co,p,x,k,l,kk=1,wynik;
int tab[MAX];
int tree[4*MAX];

void add(int gdzie,int ile){
    gdzie+=kk;
    while(gdzie>0){
        tree[gdzie]+=ile;
        gdzie>>=1;
    }
}

int jak(int a,int b){
    a+=kk;
    b+=kk;
    int wyn=0;
    if(a==b){
        wyn+=tree[a];
    }else{
        wyn+=tree[a];
        wyn+=tree[b];
    }
    while(a/2!=b/2){
        if(a%2==0){
            wyn+=tree[a+1];
        }
        if(b%2==1){
            wyn+=tree[b-1];
        }
        a>>=1;
        b>>=1;
    }
    return wyn;
}

int check(int kt,int od){
    int wyn=1;
    int sum=0;
    if(od>1){
    for(int i=0;i<n;++i){
        if(tab[i]>kt){
            sum++;
            if(sum>=od){
                wyn++;
                sum=1;
            }
        }
    }
    }else{
        for(int i=0;i<n;++i){
        if(tab[i]>kt){
            wyn++;
        }
    }
    }
    return wyn;
}

int main()
{
    scanf("%d",&n);
    scanf("%d",&m);
    if(n>2000&&m>2000){
        while(kk<MAX){
        kk<<=1;
    }
    for(int i=0;i<n;++i){
        scanf("%d",&tab[i]);
        add(tab[i],1);
    }

    for(int i=0;i<m;++i){
        scanf("%d",&co);
        if(co){
            scanf("%d",&k);
            scanf("%d",&l);
            if(k!=1){
                int temp=jak(l+1,MAX-2);
                wynik=temp/(k-1);
            if(temp%(k-1)||wynik==0){
                wynik++;
            }
            }else{
                wynik=jak(l+1,MAX-2)+1;
            }

            printf("%d\n",wynik);
        }else{
            scanf("%d",&p);
            scanf("%d",&x);
            add(tab[p-1],-1);
            tab[p-1]=x;
            add(x,1);
        }
    }
    }else{
        while(kk<MAX){
        kk<<=1;
    }
    for(int i=0;i<n;++i){
        scanf("%d",&tab[i]);
        add(tab[i],1);
    }

    for(int i=0;i<m;++i){
        scanf("%d",&co);
        if(co){
            scanf("%d",&k);
            scanf("%d",&l);
            if(k!=1){
                wynik=jak(l+1,MAX-2)/(k-1);
            if(jak(l+1,MAX-2)%(k-1)||wynik==0){
                wynik++;
            }
            }else{
                wynik=jak(l+1,MAX-2)+1;
            }

            printf("%d\n",wynik);
        }else{
            scanf("%d",&p);
            scanf("%d",&x);
            add(tab[p-1],-1);
            tab[p-1]=x;
            add(x,1);
        }
    }
    }

    return 0;
}
