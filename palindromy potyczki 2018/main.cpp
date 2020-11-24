#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define MAX 20000009
#define MOD 1000000007
#define MOD1 1000696969
#define INF 1000000000000000
#pragma GCC optimize ("O3")
typedef uint_fast64_t lld;

using namespace std;

lld n,maxin=MAX,przez,przez1;
lld xory;
lld xory1;
char c;
lld dpoty=1,dpoty1=1,odw,odw1;
lld poty=1,poty1=1,razy1,razy;
lld hasz,hasz1,odwhasz,odwhasz1;

lld pot(lld co,lld dok){
    if(dok==0){
        return 1;
    }else if(dok%2==0){
        lld temp=pot(co,dok/2);
        return (temp*temp)%MOD;

    }else{
        return (co*pot(co,dok-1))%MOD;
    }



}

lld pot1(lld co,lld dok){
    if(dok==0){
        return 1;
    }else if(dok%2==0){
        lld temp=pot1(co,dok/2);
        return (temp*temp)%MOD1;

    }else{
        return (co*pot1(co,dok-1))%MOD1;
    }



}

int main()
{
    for(int i=1;i<=MAX;++i){
        dpoty*=31;
        dpoty%=MOD;
        dpoty1*=31;
        dpoty1%=MOD1;

    }

    scanf("%lld",&n);
    odw=pot(31,MOD-2);

    odw1=pot1(31,MOD1-2);//cout<<dpoty1;
    n=0;
    scanf("%c",&c);
    c='a';
    do{
		//cout<<"X";
        c=getchar();
        //cout<<c;
        if(!(c>='a'))break;
        ++n;
        //cout<<"X"<<(c-'a'+1)<<endl;
        lld st=(c-'a'+1);
        hasz+=st*poty;
        hasz%=MOD;
        hasz1+=st*poty1;
        hasz1%=MOD1;
        poty*=31;
        poty1*=31;
        poty%=MOD;
        poty1%=MOD1;
        odwhasz+=st*dpoty;
        odwhasz%=MOD;

        odwhasz1+=st*dpoty1;
        odwhasz1%=MOD1;
        //cout<<odwhasz1<<endl;
        dpoty*=odw;
        dpoty%=MOD;
        dpoty1*=odw1;
        dpoty1%=MOD1;
    }while(true);
    przez=pot(31,MAX-n+1);
    przez1=pot1(31,MAX-n+1);
    przez=pot(przez,MOD-2);
    przez1=pot1(przez1,MOD1-2);
    odwhasz*=przez;
    odwhasz%=MOD;
    odwhasz1*=przez1;
    odwhasz1%=MOD1;
    //cout<<odwhasz1;
    if(hasz==odwhasz&&hasz1==odwhasz1){
		printf("TAK");
	}else{
		printf("NIE");
	}
    return 0;
}
