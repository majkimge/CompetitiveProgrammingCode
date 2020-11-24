#include<bits/stdc++.h>
#define lld long long
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define MAX 100009

using namespace std;

int n,k,wynik,a,b,urw;
int tab[MAX];
int deg[MAX];
vector<int> kraw[MAX];
int ojc[MAX];
int odw[MAX];
int war[MAX];
priority_queue<pair<int,int> >q;

int dfs(int from){
	odw[from]=1;
	vector<int> v;
	v.clear();

	for(int i=0;i<kraw[from].size();++i){
		if(!odw[kraw[from][i]]){
			ojc[kraw[from][i]]=from;
			v.pb(dfs(kraw[from][i]));
		}
	}
	if(!v.empty()){
        sort(v.begin(),v.end());
	}
	for(int i=0;i<v.size();++i){
        if(tab[from]+v[i]<=k){
            tab[from]+=v[i];
        }else{
            wynik++;
        }
	}
	v.clear();
	return tab[from];
}

int main(){
	scanf("%d%d",&n,&k);
	urw=n;
	for(int i=1;i<=n;++i){
		scanf("%d",&tab[i]);
	}
	for(int i=0;i<n-1;++i){
		scanf("%d%d",&a,&b);
		kraw[a].pb(b);
		kraw[b].pb(a);
	}
	dfs(1);

	printf("%d",wynik);
	return 0;
}
