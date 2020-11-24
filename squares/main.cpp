#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define MAX 100009
#define lld long long

using namespace std;
lld x,y,wyn=0,czyk=1;
pair<lld,lld> pi[5];
pair<lld,lld> dr[5];

int czy(pair<lld,lld> a,pair<lld,lld> b,pair<lld,lld> c,pair<lld,lld> d){
    lld tf=a.f;
    lld ts=a.s;
    lld df=c.f;
    lld ds=c.s;
    if(((b.f-tf)*(c.s-ts)-(b.s-ts)*(c.f-tf))*((b.f-tf)*(d.s-ts)-(b.s-ts)*(d.f-tf))<=0&&
       ((d.f-df)*(a.s-ds)-(d.s-ds)*(a.f-df))*((d.f-df)*(b.s-ds)-(d.s-ds)*(b.f-df))<=0){
        return 1;
       }
    return 0;
}


int sgn(int a){
    if(a<0){
        return -1;
    }else{
        return 1;
    }
}
int pok(pair<lld,lld> a,pair<lld,lld> b,pair<lld,lld> c){
    lld cf=c.f;
    lld cs=c.s;
    return sgn((b.f-cf)*(a.s-cs)-(b.s-cs)*(a.f-cf));
}

int main()
{
    for(int i=0;i<4;++i){
        scanf("%d",&x);
        scanf("%d",&y);
        pi[i]=mp(x,y);
    }
    for(int i=0;i<4;++i){
        scanf("%d",&x);
        scanf("%d",&y);
        dr[i]=mp(x,y);
    }
    for(int i=0;i<4;++i){
        for(int j=0;j<4;++j){
            //cout<<czy(pi[i],pi[(i+1)%4],dr[j],dr[(j+1)%4]);
            if(czy(pi[i],pi[(i+1)%4],dr[j],dr[(j+1)%4])){
                wyn=1;
                //cout<<"F";
            }
        }
    }
    if(wyn){
        printf("YES");
    }else{
        wyn=pok(pi[0],dr[0],dr[1]);
        for(int i=0;i<4;++i){
            for(int j=0;j<4;++j){
                    //cout<<pok(pi[i],dr[j],dr[(j+1)%4]);
                if(wyn!=pok(pi[i],dr[j],dr[(j+1)%4])){
                    czyk=0;
                }

            }

        }
        if(czyk){
            printf("YES");
        }else{
            wyn=pok(dr[0],pi[0],pi[1]);
            czyk=1;
        for(int i=0;i<4;++i){
            for(int j=0;j<4;++j){
                   //cout<<pok(dr[i],pi[j],pi[(j+1)%4]);
                if(wyn!=pok(dr[i],pi[j],pi[(j+1)%4])){
                    czyk=0;
                }

            }

        }
        if(czyk){
            printf("YES");
        }else{
            printf("NO");
        }
        }
    }
    return 0;
}
