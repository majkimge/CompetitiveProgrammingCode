#include <bits/stdc++.h>
#include <bits/stdc++.h>
#define lld long long
#define mp make_pair
#define s second
#define f first
#define MAX 500009
#define INF 1000000000
#define pb push_back
#define pii pair<int,int>

using namespace std;

int tab[MAX];
int n,k;
int jakdal[MAX];
int cogdz[MAX];
int odw[MAX];

pii tree[2200000];
int kk=1;
int wynik[MAX];
priority_queue<int> ind;
int cot=n;


pii maxi(int l, int p){
    if(p<l)return mp(0,0);
    l+=kk;
    p+=kk;
    pii wyn;
    if(tree[l].f>tree[p].f){
        wyn=tree[l];
    }else{
        wyn=tree[p];
    }

    while(l/2!=p/2){
        if(l%2==0){
            if(tree[l+1].f>wyn.f){
                wyn=tree[l+1];
            }
        }
        if(p%2==1){
            if(tree[p-1].f>wyn.f){
                wyn=tree[p-1];
            }
        }
        l>>=1;
        p>>=1;
    }
    return wyn;
}

int zm(int gdz, int na){
    gdz+=kk;
    tree[gdz].f=na;
    gdz>>=1;
    while(gdz){

        if(tree[gdz*2].f>tree[gdz*2+1].f){
            tree[gdz]=tree[gdz*2];
        }else{
            tree[gdz]=tree[gdz*2+1];
        }
        gdz>>=1;
    }
}

int locmax(int kt){
    int ter=maxi(kt*k,k*(kt+1)-1).f;

    int terind=maxi(kt*k,k*(kt+1)-1).s;
    //cout<<terind<<endl;
    int ll=maxi(max(terind-k+1,0), terind-1).f;
    int pp=maxi(terind+1,terind+k-1).f;
    //cout<<ll<<" "<<ter<<" "<<pp<<endl;
    if(ll<ter&&pp<ter&&!odw[ter]&&ter!=0){
        //cout<<terind<<"X ";
        ind.push(terind);
        odw[ter]=1;
    }

}


int main()
{
    scanf("%d%d",&n,&k);
    while(kk<n*2)kk<<=1;
    for(int i=0;i<n;++i){
        scanf("%d",&tab[i]);
        cogdz[tab[i]]=i;

    }

    for(int i=0;i<kk;++i){
        int ti=i+kk;
        while(ti){
            tree[ti].s=i;
            ti>>=1;
        }
    }
    for(int i=0;i<n;++i){
        zm(i,tab[i]);

    }
    //cout<<maxi(1,n-1).s;
    for(int i=0;i<(n+k)/k+1;++i){
        locmax(i);
    }
    cot=n;
    while(!ind.empty()){
        int mom=ind.top();
        //cout<<mom<<endl;
        ind.pop();
        wynik[mom]=cot;
        cot--;
        zm(mom,0);
        locmax(mom/k);
        locmax(max(0,mom/k-1));
        locmax(mom/k+1);
    }
    for(int i=0;i<n;++i){
        printf("%d ",wynik[i]);
    }
    return 0;
}
