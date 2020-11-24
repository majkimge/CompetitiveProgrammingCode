#include<bits/stdc++.h>
#define lld int
#define MAX 1000009
#define f first
#define s second
#define mp make_pair

using namespace std;

lld n,temp,wyn=0,kon;
pair<lld,lld> wys[MAX];

set<int> kol;


int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		scanf("%d",&temp);
		wys[i]=mp(temp,i);
	}
	sort(wys+1,wys+n+1);
	kol.insert(0);
	kol.insert(n+1);
	for(int i=1;i<=n;++i){
		//cout<<wys[i].f<<" "<<wys[i].s<<" "<<*kol.lower_bound(wys[i].s)<<" "<<*(--kol.lower_bound(wys[i].s))<<" "<<(*kol.lower_bound(wys[i].s)-*(--kol.lower_bound(wys[i].s))-1)*wys[i].f<<endl;

		//cout<< *kol.lower_bound(wys[i].s);

		//cout<< *kol.end();
		wyn=max(wyn,(*kol.lower_bound(wys[i].s)-*(--kol.lower_bound(wys[i].s))-1)*wys[i].f);

			kol.insert(wys[i].s);

	}
	cout<<wyn;

}
