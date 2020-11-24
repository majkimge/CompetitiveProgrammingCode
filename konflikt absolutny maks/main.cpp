#include<bits/stdc++.h>
#define lld long long
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define MAX 10009

using namespace std;

int n,m,a,b,kt=1,wyn,wynik;

vector<int> krawy[MAX];
vector<int> kra[MAX];
int odw[MAX];
int odw1[MAX];
int co[MAX];
int czy[MAX];

void dfs(int from, int od){
    odw1[from]=od;
    for(int i=0;i<kra[from].size();++i){
        if(odw1[kra[from][i]]!=od){
            krawy[od].pb(kra[from][i]);
            dfs(kra[from][i],od);
        }
    }
}

int skoj(int kto){
	odw[kto]=kt;
	for(int i=0;i<krawy[kto].size();++i){
		if(co[krawy[kto][i]]==0){
			co[krawy[kto][i]]=kto;
			czy[kto]=1;
			//wyn++;
			return 1;
		}
	}
	for(int i=0;i<krawy[kto].size();++i){
		if(odw[co[krawy[kto][i]]]<kt){
			if(skoj(co[krawy[kto][i]])){
				co[krawy[kto][i]]=kto;
				czy[kto]=1;
				return 1;
			}
		}
	}
	return 0;
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;++i){
		scanf("%d%d",&a,&b);
		kra[a].pb(b);
	}
	for(int i=1;i<=n;++i){
        dfs(i,i);
	}
	for(int i=1;i<=n;++i){
		wyn+=skoj(i);
		kt++;
	}

	printf("%d",n-wyn);
	return 0;
}
