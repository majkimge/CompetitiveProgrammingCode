#include <bits/stdc++.h>
#define lld long long
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define MAX 1000009
#define INF 1000000009

using namespace std;

lld a,b,wyn;
int odw[MAX];

lld f(lld p, lld k){
    //cout<<p<<" "<<k<<endl;
    //system("pause");
    lld dp=0;
    lld dk=0;
    lld pp=p;
    lld kk=k;
    while(pp){
        pp>>=1;
        dp++;
    }
    while(kk){
        kk>>=1;
        dk++;
    }
    //cout<<dk<<" "<<dp<<endl;
    if(p==0){
        return ((lld)1<<dk);
    }
    if(p==k){
        return 1;
    }
    if(dp==dk){
        return f(p-((lld)1<<(dp-1)),k-((lld)1<<(dk-1)));
    }else{
        lld dod=1;
        lld k1=k;
        k1-=((lld)1<<(dk-1));
        lld k2=0;
        while(k1)
        {
            ++k2;
            k1>>=1;
        }

        lld cot=f(p,((lld)1<<(dk-1))-1);
        return 2*cot+((lld)1<<(k2))-max(((lld)1<<(k2))-p,(lld)0);
    }


}

int main()
{
    scanf("%lld",&a);
    scanf("%lld",&b);
    cout<<f(a,b);
    //cout<<wyn;
    return 0;
}
