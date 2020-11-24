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
lld n,a,b,wynik,kk=1,last,kt=-1,gdz,gdz1;
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
    pair<lld,lld> lew=add(gdzie*2,l,p,zakl,(zakl+zakp)/2,ile+tree[gdzie].s);
    pair<lld,lld> praw=add(gdzie*2+1,l,p,(zakl+zakp)/2+1,zakp,ile+tree[gdzie].s);
    if(gdzie==kk/4&&l==2){
        //cout<<"X"<<lew.f<<" "<<praw.f<<" ";
    }
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

    for(int i=0;i<n;++i){
        scanf("%lld%lld",&a,&b);
        lim[i]=mp(a,b);
        q.push(mp(-b,i));
        temp[i]=mp(mp(b-a,b),i);
    }
    while(kk<n){
        kk<<=1;
    }
    sort(temp,temp+n);
    for(int i=kk;i<kk+kk;++i){
        tree[i].f.s=i-kk;
        add(1,i-kk,i-kk,0,kk-1,MOD);
    }
    for(int i=0;i<n;++i){
        if(kt>=0){
            add(1,0,kt,0,kk-1,gdz-gdz1);
        }
        while(kt<n-1&&temp[kt+1].f.f<gdz){
            if(!odw[temp[kt+1].s]){
                add(1,kt+1,kt+1,0,kk-1,gdz+lim[temp[kt+1].s].f-MOD);
                odw1[temp[kt+1].s]=1;
            }
            kt++;
        }
        pair<lld,lld> t1=tree[1].f;

        pair<lld,lld> t2=mp(MOD,0);
        while(!q.empty()&&(odw[q.top().s]||odw1[q.top().s])){
            q.pop();
        }
        if(!q.empty()){
            t2=q.top();
            t2.f=-t2.f;
        }
        //cout<<gdz<<" "<<kt<<" "<<t1.f<<" "<<t2.f<<endl;
        if(t1.f<=t2.f){
            if(!odw[temp[t1.s].s]&&gdz<=lim[temp[t1.s].s].s&&t1.f<MOD){
                wynik++;
                //cout<<"G"<<endl;
            }
            add(1,t1.s,t1.s,0,kk-1,MOD);
            odw[temp[t1.s].s]=1;
            gdz1=gdz;
            gdz=t1.f;
        }else{
            if(!odw[t2.s]&&t2.f<MOD){
                wynik++;
            }
            odw[t2.s]=1;
            if(!q.empty()){
                q.pop();
            }

            gdz1=gdz;
            gdz=t2.f;
        }
        if(gdz>=MOD)break;
    }
    printf("%lld",wynik);
    return 0;
}
