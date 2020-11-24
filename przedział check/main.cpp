#include <bits/stdc++.h>
#define lld long long
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define MAX 10009
#define MOD 1000000009

using namespace std;

pair<lld,lld> lim[MAX];
pair<pair<lld,lld>,lld> temp[MAX];
lld n,a,b,wynik,kk=1,last,kt=-1,gdz,gdz1,c;
lld odw[MAX];
lld odw1[MAX];
priority_queue<pair<lld,lld> >q;

pair<pair<lld,lld>,lld> tree[100000];

pair<lld,lld> add(lld gdzie,lld l, lld p, lld zakl, lld zakp, lld ile){
    if(l>zakp||p<zakl){
        return tree[gdzie].f;
    }
    if(l<=zakl&&p>=zakp){
        tree[gdzie].f.f+=ile;
        tree[gdzie].s+=ile;
        return tree[gdzie].f;
    }

    tree[gdzie*2].f.f+=tree[gdzie].s;
    tree[gdzie*2].s+=tree[gdzie].s;
    tree[gdzie*2+1].f.f+=tree[gdzie].s;
    tree[gdzie*2+1].s+=tree[gdzie].s;

    pair<lld,lld> lew=add(gdzie*2,l,p,zakl,(zakl+zakp)/2,ile);
    pair<lld,lld> praw=add(gdzie*2+1,l,p,(zakl+zakp)/2+1,zakp,ile);

    tree[gdzie].s=0;
    if(lew.f<=praw.f){
        tree[gdzie].f=lew;
    }else{
        tree[gdzie].f=praw;
    }
    return tree[gdzie].f;
}

int main()
{
    scanf("%lld",&n);
    kk=8;
    for(int i=kk;i<kk+kk;++i){
        tree[i].f.s=i-kk;
        add(1,i-kk,i-kk,0,kk-1,MOD);
    }
    /*for(int i=kk-1;i>=0;--i){
    	int temp=i+kk;
    	while(temp>0){
    		tree[temp].f.s=i;
    		temp>>=1;
		}
	}*/
    for(int i=0;i<n;++i){
    	scanf("%lld%lld%lld",&a,&b,&c);
    	add(1,a,b,0,kk-1,c);
    	cout<<tree[1].f.f<<" "<<tree[1].f.s<<endl;

	}
	return 0;
}

    /*
    100
	0 7 5
	0 4 3
*/
