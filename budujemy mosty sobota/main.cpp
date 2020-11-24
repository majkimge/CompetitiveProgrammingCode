#include <bits/stdc++.h>
#define lld long long
#define mp make_pair
#define f first
#define s second
#define pb push_back
#define MAX 1000009

using namespace std;

int n;
lld w[MAX], pref[MAX], h[MAX], dp[MAX], st[MAX],kk=1,INF=100000000000000000;
int licz[2100000];

void dod(int kt,int zakl, int zakp, int gdz){
    int zakr=zakp-zakl;


    lld st1=st[licz[gdz]];
    lld st2=st[kt];
    lld l1=(lld)st1-2*h[licz[gdz]]*zakl;
    lld s1=(lld)st1-2*h[licz[gdz]]*((zakl+zakp)/2);
    lld s11=(lld)st1-2*h[licz[gdz]]*((zakl+zakp)/2+1);
    lld p1=(lld)st1-2*h[licz[gdz]]*zakp;

    lld l2=(lld)st2-2*h[kt]*zakl;
    lld s2=(lld)st2-2*h[kt]*((zakl+zakp)/2);
    lld s22=(lld)st2-2*h[kt]*((zakl+zakp)/2+1);
    lld p2=(lld)st2-2*h[kt]*zakp;

    //if(gdz==1)cout<<p2<<" "<<p1<<endl;
    //if(kt==3)cout<<gdz<<endl;
    if(zakl==zakp&&s2<=s1){
        licz[gdz]=kt;
        return;
    }
    if(l2<=l1&&s2<=s1){
        dod(licz[gdz],(zakl+zakp)/2 + 1,zakp,gdz*2+1);
        licz[gdz]=kt;
    }else if(l2>=l1&&s2>=s1){
        dod(kt,(zakl+zakp)/2 + 1,zakp,gdz*2+1);
        //licz[gdz]=kt;
    }else if(p2<=p1&&s22<=s11){
        dod(licz[gdz],zakl,(zakl+zakp)/2,gdz*2);
        licz[gdz]=kt;
    }else{
        dod(kt,zakl,(zakl+zakp)/2,gdz*2);
    }
}

pair<lld,lld> mini(int gdz, int h1){
    gdz+=kk;
    lld wyn=INF;
    lld kto=0;
    while(gdz){
        //if(h1==6&&licz[gdz]==3)cout<<"X";
        if((lld)st[licz[gdz]]-h1*h[licz[gdz]]*2<wyn){
            wyn=(lld)st[licz[gdz]]-h1*h[licz[gdz]]*2;
            kto=gdz;
        }
        gdz>>=1;
    }
    return mp(wyn,kto);
}


int main()
{
    scanf("%d",&n);
    while(kk<1000000)kk<<=1;
    st[0]=INF;
    for(int i=1;i<=n;++i){
        scanf("%lld",&h[i]);
    }
    for(int i=1;i<=n;++i){
        scanf("%lld",&w[i]);
    }
    for(int i=1;i<=n;++i){
        pref[i]=pref[i-1]+w[i];
        st[i]=-pref[i]+h[i]*h[i];
    }
    dp[1]=0;
    dod(1,0,kk-1,1);
    //cout<<mini(8,8).f<<endl;
    for(int i=2;i<=n;++i){
        lld minik=mini(h[i],h[i]).f;
        dp[i]=minik+pref[i-1]+h[i]*h[i];
        st[i]+=dp[i];
        dod(i,0,kk-1,1);
        //cout<<st[2]<<" ";
    }
    //cout<<dp[2]
    printf("%lld",dp[n]);
    return 0;
}
