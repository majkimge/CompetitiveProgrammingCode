#include <bits/stdc++.h>
#define lld long long
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define MOD 1000000007
#define MAX 800009

using namespace std;

lld wyn=1,n,sum;
lld kom[MAX],lis[MAX];
pair<lld,lld> lac[MAX];

lld brut(){
    lld ret=0;
    lld mini=(lld)MOD*MOD;
    do{
        lld temp=0;
        for(int i=0;i<n;++i){
            temp+=abs(kom[i]-lis[i]);
        }
        if(temp==mini){
            ret++;
        }else if(temp<mini){
            mini=temp;
            ret=1;
        }
    }while(next_permutation(lis,lis+n));
    return ret;
}

int main()
{
    for(int xd=0;xd<100000;++xd){
        wyn=1;
        //scanf("%lld",&n);
        n=rand()%10+1;
        srand(time(0)+n*12);
        for(int i=0;i<n;++i){
            //scanf("%lld",&kom[i]);
            kom[i]=rand()%1000000000+1;
            lac[i]=mp(kom[i],1);
        }
        for(int i=0;i<n;++i){
            //scanf("%lld",&lis[i]);
            lis[i]=rand()%1000000000+1;
            lac[i+n]=mp(lis[i],-1);
        }
        sort(kom,kom+n);
        sort(lis,lis+n);
        sort(lac,lac+2*n);



        for(int i=0;i<2*n;++i){
            if(sum*lac[i].s<0)wyn*=abs(sum);
            sum+=lac[i].s;
            wyn%=MOD;
        }
        //printf("%lld\n",wyn);
        //printf("%lld\n",brut());
        if(wyn!=brut())cout<<"XDDDDDD";
    }

    return 0;
}
