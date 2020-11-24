#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define MAX 100009
#define INF 100000000009
#define MOD 1000696969
#define llu unsigned long long
#define lld long long

using namespace std;

int n,q,co,a,b,len,kk=1;
char s[MAX];
pair<lld,lld> tree[MAX*5];
lld ztree[MAX*5];


lld pot(lld dok){
    if(dok==0){
        return 1;
    }else if(dok%2==0){
        lld temp=pot(dok/2);
        temp%=MOD;
        return (temp*temp)%MOD;
    }else{
        lld temp=pot(dok-1);
        temp%=MOD;
        return (temp*31)%MOD;
    }


}

void zadd(int gdzie,lld co){
    gdzie+=kk;
    while(gdzie>0){
        ztree[gdzie]+=co;
        ztree[gdzie]%=MOD;
        gdzie>>=1;
    }
}

pair<lld,lld> invert(int l,int p,int od,int dok,int gdzie){
    if(l<=od&&p>=dok){
        lld temp=tree[gdzie].f;
        tree[gdzie].f=ztree[gdzie];
        ztree[gdzie]=temp;
        tree[gdzie].s++;
        return mp(temp,tree[gdzie].f);
    }else if(l>dok||p<od){
        return mp(0,0);
    }else{
        pair<lld,lld> temp=invert(l,p,od,od+(dok-od)/2,gdzie*2);
        pair<lld,lld> temp1=invert(l,p,od+(dok-od)/2+1,dok,gdzie*2+1);
        temp.f+=temp1.f;
        temp.s+=temp1.s;
        temp.f%=MOD;
        temp.s%=MOD;
        lld tempix=tree[gdzie].f;
        tree[gdzie].f=tree[gdzie].f-temp.f+temp.s+3*MOD;
        tree[gdzie].f%=MOD;
        ztree[gdzie]=ztree[gdzie]+temp.f-temp.s+3*MOD;
        ztree[gdzie]%=MOD;
        return mp(tempix%MOD,tree[gdzie].f%MOD);
    }
}

lld check(int l,int p,int od,int dok,int gdzie,int ileinw){
    lld wyn=0;
    if(l<=od&&p>=dok){
        lld temp=tree[gdzie].f;
        if((ileinw)%2==1){
            temp=ztree[gdzie]%MOD;
        }
        return temp;
    }else if(l>dok||p<od){
        return 0;
    }else{
        lld temp=check(l,p,od,od+(dok-od)/2,gdzie*2,ileinw+tree[gdzie].s);
        wyn+=temp;
        temp=check(l,p,od+(dok-od)/2+1,dok,gdzie*2+1,ileinw+tree[gdzie].s);
        wyn+=temp;
        return wyn%MOD;
    }
}

void add(int gdzie,lld co){
    gdzie+=kk;
    while(gdzie>0){
        tree[gdzie].f+=co;
        tree[gdzie].f%=MOD;
        gdzie>>=1;
    }
}




int main()
{
    //cout<<'z'-'a';
    scanf("%d%d",&n,&q);
    scanf("%s",s);
    while(kk<n){
        kk<<=1;
    }
    for(int i=0;i<n;++i){
        zadd(i,(('z'-s[i])*pot(i))%MOD);
        add(i,((s[i]-'a')*pot(i))%MOD);
        //cout<<tree[kk+4].f<<" ";
    }
    for(int i=0;i<q;++i){
        scanf("%d",&co);
        if(co==1){
            scanf("%d",&a);
            a--;
            scanf("%d",&b);
            b--;
            invert(a,b,0,kk-1,1);
        }else{
            scanf("%d",&a);
            scanf("%d",&b);
            scanf("%d",&len);
            a--;
            b--;
            lld t1=check(a,a+len-1,0,kk-1,1,0);
            t1%=MOD;
            lld t2=check(b,b+len-1,0,kk-1,1,0);
            //cout<<t2;
            t2%=MOD;
            t1=(t1*(pot(b))%MOD)%MOD;
            t2=(t2*(pot(a))%MOD)%MOD;
            if(t1==t2){
                printf("TAK\n");
            }else{
                printf("NIE\n");
            }
        }
    }
    return 0;
}

/*
8 100
aaaazzzz
1 4 5
1 2 3
2 1 5 4



*/
