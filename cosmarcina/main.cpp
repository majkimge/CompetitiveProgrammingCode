#pragma GCC optimize("Os")
#include <bits/stdc++.h>
using namespace std;

typedef long long lld;
typedef pair<int,int> pii;
typedef pair<lld,lld> pll;
typedef pair<lld,int> pli;		///
typedef pair<int,lld> pil;

#define ff first
#define dd second
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define sz size()
#define For(i,s,a) for(lld i=(lld)s;i<(lld)a;++i)
#define rpt(s,it) for(auto it=s.begin();it!=s.end();++it)
#define A(g,h) ans.pb(mp(g,h));



vector<int>c[3000001];
int odl[3000001];
bitset<3000001>odw;
char s[3];

pii stos[3000001];
int _end;

pii dfs(int x, int p = -1, int d = 0){
	odl[x]=0;
	_end=0;
	stos[++_end]=mp(x,p);
	pii ret = mp(0,x);
	while(_end){
		x=stos[_end].ff;
		odw[x]=1;
		p=stos[_end].dd;
		--_end;
		for(int ss=0;ss<c[x].size();++ss){
			if(ss!=p && odw[ss]){
				printf("cykl: %d %d\n",x,ss);
				exit(60);
			}
			if(ss!=p){
				odl[ss]=odl[x]+1;
				ret = max(ret, mp(odl[ss],ss));
				stos[++_end]=mp(ss,x);
			}
		}
	}
	return ret;
}

int32_t main(void){

	int a,b,k;
	cin>>a>>b>>k;
	scanf("%s",s);
	if(memcmp("NIE",s,3)==0){puts("OK");return 0;}
	int tmp = 3;
	int x[4],g;
	int kraw = 0;
	int maxn = 0, minx = 1000;
	while(cin>>g){
		maxn = max(maxn,g);
		minx = min(minx,g);
		if(g<1){puts("0 kurna");exit(41);}
		++tmp;
		tmp%=4;
		if((tmp&1) && g>b){printf("%d wieksze od %d!\n",g,b);exit(42);}
		if(!(tmp&1) && g>a){printf("%d wieksze od %d!\n",g,a);exit(42);}
		x[tmp]=g;
		if(tmp==3)
		c[(x[0]-1)*(b)+x[1]-1].pb((x[2]-1)*(b)+x[3]-1),
		c[(x[2]-1)*(b)+x[3]-1].pb((x[0]-1)*(b)+x[1]-1),
		//cout<<(x[0]-1)*(b)+(x[1]-1)<<" "<<(x[2]-1)*(b)+(x[3]-1)<<endl,
		++kraw;
	}
	//cout<<minx<<" "<<maxn<<endl;
	if(minx < 1 || maxn > a*b){
		puts("liczba spoza zakresu.");
		cout<<minx<<" "<<maxn<<endl;
		exit(44);
	}
	if(kraw!=a*b-1){
		puts("Zla liczba krawedzi");
		printf("wczytano: %d, oczekiwano:%d\n",kraw,a*b+1);
		return 66;
	}
	int xd = dfs(0).dd;
	odw=0;
	xd = dfs(xd).ff;
	if(xd != k){
		printf("œrednica: %d, oczekiwana: %d\n",xd,k);
		return 69;
	}
	if(odw.count()!=a*b){
		puts("Siec nie jest spojna.");
		return 70;
	}
	puts("OK");
}
