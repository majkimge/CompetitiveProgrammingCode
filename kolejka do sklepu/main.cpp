#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define MAX 100009
#define INF 100000000009
#define MOD 1000000007
#define llu unsigned long long
#define lld long long

using namespace std;

int zz,n,kk=1;;
int tab[MAX];
int wyny[MAX];
int tree[270000];

void dod(int gdzie,int co){
    gdzie+=kk;
    while(gdzie>0){
        tree[gdzie]+=co;
        gdzie>>=1;
    }
}

int check(int ile,int ilemam,int gdzie){
    if(gdzie>=kk) return gdzie-kk;
    if(tree[gdzie*2]>=ile-ilemam){
        return check(ile,ilemam,gdzie*2);
    }else{
        return check(ile,ilemam+tree[gdzie*2],gdzie*2+1);
    }
}

int main()
{
    scanf("%d",&zz);
    for(int xdd=0;xdd<zz;++xdd){
        scanf("%d",&n);
        kk=1;
        while(kk<n){
            kk<<=1;
        }
        for(int i=0;i<270000;++i){
            tree[i]=0;
        }
        for(int i=0;i<n;++i){
            scanf("%d",&tab[i]);
            //tab[i]=0;
            wyny[i]=0;
            dod(i,1);
        }
        for(int i=n-1;i>=0;--i){
            int temp=check(tab[i]+1,0,1);
            //cout<<"X"<<temp<<" ";
            wyny[i]=temp+1;
            dod(temp,-1);
        }
        for(int i=0;i<n;++i){
            printf("%d ",wyny[i]);
        }
        printf("\n");
    }
    return 0;
}
