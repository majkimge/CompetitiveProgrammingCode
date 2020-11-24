#include <bits/stdc++.h>
#define lld long long
#define mp make_pair
#define f first
#define s second
using namespace std;



lld t,n;
lld fiby[100];
lld prefiby[100];
char binar[100];
lld fibo(lld a){
lld q[2][2];
lld p[2][2];
lld w[2][2];

if(a<2) return a;
    q[0][0]=1;
    q[0][1]=1;
    q[1][0]=1;
    q[1][1]=0;
    w[0][0]=1;
    w[1][1]=1;
    w[0][1]=0;
    w[1][0]=0;
    a--;

    while(a){
        if(a&1){
            p[0][0]=w[0][0]*q[0][0]+w[0][1]*q[1][0];
            p[0][1]=w[0][0]*q[0][1]+w[0][1]*q[1][1];
            p[1][0]=w[1][0]*q[0][0]+w[1][1]*q[1][0];
            p[1][1]=w[1][0]*q[0][1]+w[1][1]*q[1][1];

            w[0][0]=p[0][0];
            w[0][1]=p[0][1];
            w[1][0]=p[1][0];
            w[1][1]=p[1][1];
        }
        a>>=1;

        if(!a) break;
            p[0][0]=q[0][0]*q[0][0]+q[0][1]*q[1][0];
            p[0][1]=q[0][0]*q[0][1]+q[0][1]*q[1][1];
            p[1][0]=q[1][0]*q[0][0]+q[1][1]*q[1][0];
            p[1][1]=q[1][0]*q[0][1]+q[1][1]*q[1][1];

            q[0][0]=p[0][0];
            q[0][1]=p[0][1];
            q[1][0]=p[1][0];
            q[1][1]=p[1][1];

    }
    return w[0][0];

}

lld bin(lld a){
    lld cnt=0;
    char wyni[100];
    //string rwyni;
    while(a){

        if(a%2==0){
            wyni[cnt]='0';
        }else{
            wyni[cnt]='1';
        }
        cnt++;
        //cout<<cnt;
        a>>=1;
    }
    for(int i=cnt-1;i>=0;--i){
        binar[cnt-1-i]=wyni[i];
       // cout<<rwyni[cnt-i-1];
    }
    return cnt;
}
int main()
{
    fiby[1]=1;
    fiby[2]=1;
    for(int i=3;i<70;++i){
        fiby[i]=fiby[i-1]+fiby[i-2];
    }
    for(int i=1;i<70;++i){
        prefiby[i]=fibo(i)+prefiby[i-1];
        //cout<<prefiby[i];
    }
    scanf("%lld",&t);
    //cout<<prefiby[6];
    for(int z=0;z<t;++z){
        scanf("%lld",&n);

    lld cou=bin(n);
    lld wyn=prefiby[cou];
    lld uj=0;
    bool czy=0;
    for(int i=1;i<cou;++i){
        if(binar[i]=='1'&&i==1) break;
        if(i>1){
            if(binar[i]=='0'){
                if(!czy){
                    uj+=fiby[cou-i];
                }
                czy=0;
            }else{
                if(czy) break;
                czy=1;
            }
        }
    }
    printf("%lld\n",wyn-uj);
    }


    return 0;
}
