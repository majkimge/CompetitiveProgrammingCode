#include <bits/stdc++.h>
#define lld long long
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define MAX 1000009

using namespace std;

int n,m,q;
int a;
vector<int> s[MAX];

int bin(int l,int p,int co,int jak){
    int ss=(l+p)/2;
    int wyn=-1;
    while(l<=p){
        ss=(l+p)/2;
        if(s[jak][ss]>co){
            wyn=s[jak][ss];
            p=ss-1;
        }else{
            l=ss+1;
        }
    }
    return wyn;
}

int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;++i){
        scanf("%d",&a);
        s[a].pb(i);
    }
    scanf("%d",&q);
    for(int xx=0;xx<q;++xx){
        scanf("%d",&m);
        int ost=-1;
        int czy=1;
        for(int i=0;i<m;++i){
            scanf("%d",&a);
            int temp=0;
            if(czy) temp=bin(0,s[a].size()-1,ost,a);

            //cout<<temp;
            if(temp==-1){
                czy=0;
                //break;
            }
            ost=temp;
        }
        if(!czy){
            printf("NIE\n");
        }else{
            printf("TAK\n");
        }
    }
    return 0;
}
