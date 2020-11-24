#include<bits/stdc++.h>
#define lli long long
#define f first
#define s second
#define mod 1000000007
#define inf 1000000000
#define mp make_pair
#define pb push_back
using namespace std;
const int N=500009;
const int M=500009;
int ojc[N];
vector<pair<int,pair<int,int> > > wysokosci;

long long wyn[500009];
long long naj[500009];

int find(int x)
{
	if(ojc[x]==x) return x;
	ojc[x]=find(ojc[x]);
	return (ojc[x]);
}
void junion(int x,int y, long long z)
{
	int repx=find(x);
	int repy=find(y);
	if(repx==repy) return;
	ojc[repy]=repx;
	wyn[repx]=(wyn[repx]+z-naj[repx])*(wyn[repy]+z-naj[repy])%mod;
	naj[repx]=z;
}

int main()
{
	int n,m,h;
	scanf("%d%d%d", &m, &n, &h);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
	{
		ojc[(j-1)*n+i]=(j-1)*n+i;
		wyn[(j-1)*n+i]=1;
	}

		for(int i=1;i<=m;i++)
			for(int j=1;j<n;j++)
			{int w;
				scanf("%d", &w);
				wysokosci.pb(mp(w,mp((i-1)*n+j+1,(i-1)*n+j)));

			}
		for(int j=1;j<m;j++)
			for(int i=1;i<=n;i++)
			{
				int w;
				scanf("%d", &w);
				wysokosci.pb(mp(w,mp((j)*n+i,(j-1)*n+i)));
					//printf("\n%d %d wys %d",(j)* n+i, (j-1)*n+i, w );
			}
	sort(wysokosci.begin(),wysokosci.end());
	lli wynik=0;
	for(int i=0;i<wysokosci.size();i++)
		{junion(wysokosci[i].s.f, wysokosci[i].s.s, wysokosci[i].f);
		}
	wynik=wyn[find(1)];
	wynik+=h-naj[find(1)];
	wynik%=mod;
	printf("%lld", wynik);
}
