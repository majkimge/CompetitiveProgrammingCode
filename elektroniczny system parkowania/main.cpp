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
pair<lld,lld> temp[MAX];
lld n,a,b,wynik,kk=1,last;
lld odw[MAX];
lld odw1[MAX];
priority_queue<pair<lld,lld> >q;

pair<pair<lld,lld>,lld> tree[100000];

pair<lld,lld> add(lld gdzie,lld l, lld p, lld zakl, lld zakp, lld ile){
    if(l>zakp||p<zakl){
        return mp(MOD,0);
    }
    if(l<=zakl&&p>=zakp){
        tree[gdzie].f.f+=ile;
        tree[gdzie].s+=ile;
        return tree[gdzie].f;
    }
    pair<lld,lld> lew=add(gdzie*2,l,p,zakl,(zakl+zakp)/2,ile+tree[gdzie].s);
    pair<lld,lld> praw=add(gdzie*2+1,l,p,(zakl+zakp)/2+1,zakp,ile+tree[gdzie].s);
    tree[gdzie].s=0;
    if(lew.f<praw.f){
        tree[gdzie].f=lew;
    }else{
        tree[gdzie].f=praw;
    }
    return tree[gdzie].f;
}



int main()
{
    scanf("%lld",&n);

    for(lld i=0;i<n;++i){
        scanf("%lld%lld",&a,&b);
        lim[i]=mp(b,a);
        q.push(mp(-b,i));
        temp[i]=mp(b-a,i);
    }
    while(kk<n){
        kk<<=1;
    }
    sort(temp,temp+n);
    lld gdz=0;
    lld gdz1=0;
    lld kt=0;
    for(lld i=kk;i<=n+kk;++i){
        tree[i]=mp(mp(MOD,i-kk),0);
    }
    for(lld i=0;i<kk;++i){
        tree[i]=mp(mp(MOD,0),0);
    }
    for(lld i=0;i<n;++i){
        //cout<<gdz<<" "<<kt<<" ";
        if(kt!=0){
            add(1,0,kt-1,0,kk-1,gdz-gdz1);
        }

        while(kt<n&&temp[kt].f<gdz){
            if(!odw[temp[kt].s]){
                add(1,kt,kt,0,kk-1,gdz+lim[temp[kt].s].s-MOD);
                odw[temp[kt].s]=1;
            }

            kt++;
        }
        pair<lld,lld> t1=tree[1].f;
        //cout<<t1.f<<" ";
        pair<lld,lld> t2;
        if(kt==0){
            t1.f=MOD;
        }
        while(!q.empty()&&odw[q.top().s]){
            q.pop();
        }
        if(!q.empty()){
            t2=q.top();
            t2.f=-t2.f;
        }else{
            t2.f=MOD;
        }


        if(t1.f<=t2.f){
            //cout<<"X"<<endl;
            if(t1.f<MOD&&t1.f-lim[temp[t1.s].s].s<=lim[temp[t1.s].s].f&&!odw1[temp[t1.s].s]){
                wynik++;

                gdz1=gdz;
                gdz=t1.f;
            }else{
                gdz1=gdz;
            }
            add(1,t1.s,t1.s,0,kk-1,MOD);
        }else{
            //cout<<endl;
            if(!q.empty()){
                wynik++;
                gdz1=gdz;
                gdz=t2.f;
                odw1[t2.s]=1;
                q.pop();
            }
        }
    }
    printf("%lld",wynik);
    return 0;
}
