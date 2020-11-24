#include <bits/stdc++.h>
#define lld long long
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define MAX 200009


using namespace std;

int n,m,a,b;
vector<int> kraw[MAX];
int wyniki[MAX];
int odw[MAX];
int przyps=0;

int dfs(int from,int oczy,int cot){
    odw[from]=1;
    if(kraw[from].size()==0){
        przyps=1;
    }
    wyniki[from]=cot;
    for(int i=0;i<kraw[from].size();++i){
        if(!odw[kraw[from][i]]){
            dfs(kraw[from][i],oczy,cot^1);
        }
    }

}


int main()
{
    scanf("%d",&n);
    scanf("%d",&m);
    for(int i=0;i<m;++i){
        scanf("%d",&a);
        scanf("%d",&b);
        kraw[a].pb(b);
        kraw[b].pb(a);
    }
    for(int i=1;i<=n;++i){
        if(!odw[i]){
            dfs(i,i,0);
        }
    }
    if(przyps){
        printf("NIE\n");
    }else{
        printf("TAK\n");
        for(int i=1;i<=n;++i){
            if(wyniki[i]==0){
                printf("K\n");
            }else{
                printf("S\n");
            }
        }

    }
    return 0;
}
