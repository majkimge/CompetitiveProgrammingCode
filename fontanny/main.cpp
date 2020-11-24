#include <bits/stdc++.h>
#define lld long long
#define MAX 100009

using namespace std;

lld n;
char o[MAX*2];
char w[MAX*2];
char ting;
lld pom1,pom2,wyn,p3;
int main()
{
    scanf("%lld",&n);
    scanf("%s",o);
    scanf("%s",w);
    lld tem=0;
    ting=o[0];
    for(int i=0;i<n;++i){
        o[i]=o[i+1];
        //o[i+n]=o[i];
        //w[i+n]=w[i];
    }
    o[n-1]=ting;
    for(int i=0;i<n;++i){
        //o[i]=o[i+1];
        o[i+n]=o[i];
        w[i+n]=w[i];
    }
    while(o[tem]=='1'&&tem<n){
        tem++;
        //cout<<"G";
    }
    //cout<<tem;
    if(tem==n){
        for(int i=0;i<n;++i){
            if(w[i]=='1'){
                pom1++;
            }
        }
        cout<<pom1*(pom1-1)+1;
    }else{
        pom2=tem;
        while(pom2<tem+n+1){
            while(o[pom2]=='0'&&pom2<tem+n+1){
            pom2++;
        }
        p3=0;
        while(o[pom2]=='1'&&pom2<tem+n+1){
                //cout<<pom2;


            if(w[pom2]=='1'){
                p3++;
                //cout<<pom2;
            }
            pom2++;
        }
        if(w[pom2]=='1'){
                p3++;
                //cout<<pom2;
            }
            //cout<<p3<<" ";
        wyn+=p3*(p3-1)/2;
        }
        cout<<wyn;

    }
    return 0;
}
