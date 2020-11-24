#include <bits/stdc++.h>
#define lld long long
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define MAX 1009
#define pii pair<lld,lld>

using namespace std;

lld n,m,a,b,s;
pii pun[MAX],wierz[MAX];
int odw[MAX];
vector<int> v;

lld str(pii A,pii B, pii C){
	B.f-=A.f;
	B.s-=A.s;
	C.f-=A.f;
	C.s-=A.s;
	if(C.f*B.s-C.s*B.f>0)return 1;
	if(C.f*B.s-C.s*B.f<0)return -1;
	return 0;
}

lld bin(pii A, int ile){
    pii od=wierz[0];
    int l=ile-1;
    int p=1;
    int s=(l+p)/2;
    int wskl=ile-1;
    /*if(str(od,wierz[ile-1],A)>=0){
        return 0;
    }*/
    while(l>=p){
        s=(l+p)/2;
        if(str(od,wierz[s],A)<0){
            l=s-1;
            wskl=s;
        }else{
            p=s+1;
        }
    }
    l=1;
    p=ile-1;
    s=(l+p)/2;
    int wskp=1;
    /*if(str(od,wierz[1],A)<=0){
        return 0;
    }*/
    while(l<=p){
        s=(l+p)/2;
        if(str(od,wierz[s],A)>0){
            l=s+1;
            wskp=s;
        }else{
            p=s-1;
        }
    }
    if(str(wierz[wskp],wierz[wskl],A)<=0)return 0;
    return 1;
}

int main()
{
    scanf("%lld%lld",&n,&m);
    for(int i=0;i<n;++i){
        scanf("%lld%lld",&a,&b);
        pun[i]=mp(a,b);
    }
    for(int i=0;i<m;++i){
        scanf("%lld",&s);
        for(int j=0;j<s;++j){
            scanf("%lld",&a);
            wierz[j]=pun[a-1];
        }
        lld wyn=0;
        for(int j=0;j<n;++j){
            int czy=1;
            for(int z=0;z<s;++z){
                if(str(wierz[z],wierz[(z+1)%s],pun[j])<=0)czy=0;
            }
            wyn+=czy;
        }
        printf("%lld\n",wyn);
    }
    return 0;
}
/*
5 1
-1000000000 -1000000000
-1000000000 1000000000
1000000000 1000000000
1000000000 -1000000000
1 0
4 1 2 3 4*/
