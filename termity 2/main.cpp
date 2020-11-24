#include <bits/stdc++.h>
#define lld long long
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define MAX 3000009

using namespace std;

int tab[MAX][2],a,b,n;
int czy=0;
pair<int,int> kraw[MAX];
vector<pair<int,int> >krawy0[MAX];
vector<pair<int,int> >krawy1[MAX];


int main()
{
    scanf("%d",&n);
    for(int i=0;i<n-1;++i){
        scanf("%d%d",&a,&b);
        kraw[i]=mp(a,b);
    }
    for(int i=0;i<n-1;++i){
        if(tab[kraw[i].f][i%2]&&tab[kraw[i].s][i%2]){
            printf("%d",i+1);
            czy=1;
            break;
        }
        if(i%2){
            krawy0[i].pb(kraw[i].f)
        }
        tab[kraw[i].f][(i+1)%2]=1;
        tab[kraw[i].s][(i+1)%2]=1;
        tab[kraw[i].f][i%2]=(tab[kraw[i].f][i%2]|tab[kraw[i].s][i%2]);
        tab[kraw[i].s][i%2]=(tab[kraw[i].f][i%2]|tab[kraw[i].s][i%2]);
    }
    if(!czy){
        printf("-1");
    }
    return 0;
}
