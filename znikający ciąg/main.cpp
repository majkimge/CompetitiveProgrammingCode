#include <bits/stdc++.h>
#define lld long long
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define MAX 200009
#define pii pair<int,int>
#define pdd pair<double,double>
#define C 1000

using namespace std;

int n,q,a,b,wynik;
int tab[MAX];
int warty[MAX];
int dp[MAX];
int lasty[MAX];
int ile[MAX];
int kk=1;

pair<int,int> tree[MAX*4];


void add(int gdz, int ile){
    gdz+=kk;
    tree[gdz].s+=ile;
    if(tree[gdz].s>0){
        tree[gdz].f=1;
    }else{
        tree[gdz].f=0;
    }
    gdz>>=1;
    while(gdz){
        tree[gdz].f=tree[gdz*2].f+tree[gdz*2+1].f;
        gdz>>=1;
    }
}



int main()
{
    scanf("%d%d",&n,&q);
    for(int i=1;i<=n;++i){
        scanf("%d",&a);
        tab[i]=a;
        ile[tab[i]]++;
        warty[i]=a;
    }

    while(kk<n+2)kk<<=1;
    for(int i=1;i<=n;++i){
        for(int j=i;j>=i-ile[i]+1&&j>0;--j){
            //cout<<j;
            add(j,1);
        }
    }
   // cout<<tree[kk+1].f;
    for(int xd=0;xd<q;++xd){
        scanf("%d%d",&a,&b);
        //cout<<max(0,warty[a]-ile[warty[a]]+1)<<" "<<max(0,warty[a]-ile[warty[a]]+1)<<endl;
        add(max(0,warty[a]-ile[warty[a]]+1),-1);
        //cout<<"A"<<tree[kk+2].f;
        ile[warty[a]]--;
        warty[a]=b;
        ile[b]++;
        //cout<<max(0,warty[a]-ile[warty[a]]+1)<<" "<<max(0,warty[a]-ile[warty[a]]+1)<<endl;
        add(max(0,warty[a]-ile[warty[a]]+1),1);
        printf("%d\n",n-tree[1].f+tree[kk].f);
    }
    return 0;
}
