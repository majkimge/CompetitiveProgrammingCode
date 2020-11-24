#include <bits/stdc++.h>
#define lld long long
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define MAX 1000009
#define INF 1000000000000000

using namespace std;

int l,n,m,a,b,przyps,wynik;
vector<int> topo;
int kolej[MAX];
int odw[MAX];
int wcykl[MAX];
vector<int> kraw[MAX];

void topos(int from){
    odw[from]=1;
    for(int i=0;i<kraw[from].size();++i){
        if(!odw[kraw[from][i]]){
            topos(kraw[from][i]);
        }
    }
    kolej[from]=topo.size();
    cout<<"X"<<from;
    topo.pb(from);
}


int main()
{
    scanf("%d",&l);
    for(int xx=0;xx<l;++xx){
        topo.clear();
        for(int i=0;i<n;++i){
            kraw[i].clear();
            odw[i]=0;
        }
        scanf("%d",&n);
        scanf("%d",&m);
        for(int i=0;i<m;++i){
            scanf("%d",&a);
            scanf("%d",&b);
            kraw[a].pb(b);
            kraw[b].pb(a);
        }
        topo.pb(-1);
        for(int i=0;i<n;++i){
            if(!odw[i]){
                topos(i);
            }
        }
        topo.pb(-1);
        for(int i=1;i<topo.size()-1;++i){
            if(przyps) break;
            cout<<topo[i]<<" ";
            for(int j=0;j<kraw[i].size();++j){
                if(kraw[i][j]!=topo[i-1]&&kraw[i][j]!=topo[i+1]&&kolej[kraw[i][j]]>i){
                    for(int z=i;z<=kolej[kraw[i][j]];++z){
                        if(wcykl[topo[z]]){
                            przyps=1;
                            break;
                        }else{
                            wcykl[topo[z]]=1;
                        }
                    }
                    wynik++;
                }
            }
        }
        if(przyps){
            printf("NIE\n");
        }else{
            printf("%d\n",wynik);
        }
    }
    return 0;
}
