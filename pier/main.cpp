#include <bits/stdc++.h>
#define mp make_pair
#define lld long long
#define f first
#define s second
#define MAX 100009
#define MOD 1000000009

using namespace std;

pair<lld,pair<lld,lld> > tree[MAX*3];
lld n,q,k,t,a,b,c,kk=1,mw,ww,temp;

lld pote(lld cok,lld dok){
    if(dok<=0){
        return 1;
    }else if(dok%2==0){5
        lld temp4=pote(cok,dok/2);
        temp4%=MOD;
        return (temp4*temp4)%MOD;
    }else{
        return (((pote(cok,dok-1))%MOD)*cok)%MOD;
    }
}

lld add(lld pz,lld kz,lld pp,lld kp,lld ktory){
    if(pz<=pp&&kz>=kp){
           // cout<<"B";
        tree[ktory]=mp(tree[ktory].f,mp(kp-pp-tree[ktory].f*2+1+tree[ktory].s.f,tree[ktory].s.s));
        return kp-pp-tree[ktory].f*2+1;
    }else if(pz>kp||kz<pp){
        return 0;
    }else{
        lld wyn1=0;
        lld wyn2=0;
        wyn1=add(pz,kz,pp,(kp-pp)/2+pp,ktory*2);
        wyn2=add(pz,kz,(kp-pp)/2+pp+1,kp,ktory*2+1);
        //cout<<wyn1<<wyn2;
        tree[ktory]=mp(tree[ktory].f,mp(tree[ktory].s.f,tree[ktory].s.s+wyn1+wyn2));
        return wyn1+wyn2;
    }

}

void check(lld pz,lld kz,lld pp,lld kp,lld ktory){
    //cout<<"W";
    if(pz<=pp&&kz>=kp){
        ww+=tree[ktory].s.s+tree[ktory].f;
        ww+=tree[ktory].s.f;
    }else if(pz>kp||kz<pp){

    }else{
        lld wyn1=0;
        lld wyn2=0;
        check(pz,kz,pp,(kp-pp)/2+pp,ktory*2);
        check(pz,kz,(kp-pp)/2+pp+1,kp,ktory*2+1);
        mw+=tree[ktory].s.f;

    }
}

int main()
{
    scanf("%lld",&n);
    scanf("%lld",&k);
    scanf("%lld",&q);
    while(kk<n){
        kk<<=1;
    }
    for(int i=kk;i<2*kk;++i){
        scanf("%lld",&temp);
        lld kop=i;
        while(kop>0){
            tree[kop]=mp(tree[kop].f+temp%2,mp(0,0));
            kop>>=1;
        }
    }

    for(int i=0;i<q;++i){
        scanf("%lld",&t);
    scanf("%lld",&a);
    scanf("%lld",&b);
    scanf("%lld",&c);
    if(t==1&&c%2==1){

        add(a-1,b-1,0,kk-1,1);

    }else{
        mw=0;
        ww=0;

        check(a-1,b-1,0,kk-1,1);//cout<<mw+ww;
            //cout<<"B";
            if(c==1){
                if(mw+ww>0){
                    printf("%lld\n",pote(2,b-a));
                }else{
                printf("0\n");
                }
            }else{
                printf("%lld\n",pote(2,b-a));
            }


    }

    }
    return 0;
}
