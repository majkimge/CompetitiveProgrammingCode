#include <bits/stdc++.h>
#define lld long long
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define MAX 200009
#define pii pair<int,int>
#define pdd pair<double,double>

using namespace std;

int n;

pdd wierz[10][4],sr[10];
double a,b,c,d,x,y,wynik,L=100,P=-100,G=-100,D=100;

int zn(double A){
    if(A>0.0000)return 1;
    return -1;
}

int czyprz(pdd A, pdd B, pdd C, pdd D){
    B.f-=A.f;
    C.f-=A.f;
    D.f-=A.f;
    B.s-=A.s;
    C.s-=A.s;
    D.s-=A.s;
    if(zn(B.f*C.s-B.s*C.f)==-zn(B.f*D.s-B.s*D.f)){
        B.f+=A.f;
        C.f+=A.f;
        D.f+=A.f;
        B.s+=A.s;
        C.s+=A.s;
        D.s+=A.s;

        A.f-=C.f;
        B.f-=C.f;
        D.f-=C.f;
        A.s-=C.s;
        B.s-=C.s;
        D.s-=C.s;
        if(zn(D.f*A.s-D.s*A.f)==-zn(D.f*B.s-D.s*B.f)){
            return 1;
        }
    }
    return 0;
}

int pokt(pdd A, pdd B, pdd C){
    B.f-=A.f;
    C.f-=A.f;
    B.s-=A.s;
    C.s-=A.s;

    return zn(B.f*C.s-B.s*C.f);
}

int czyzaw(pdd A, pdd B, pdd C, pdd D, int kt){
    int xd=pokt(wierz[kt][0],wierz[kt][1],A);
    int xd1=pokt(wierz[kt][0],wierz[kt][1],B);
    int xd2=pokt(wierz[kt][0],wierz[kt][1],C);
    int xd3=pokt(wierz[kt][0],wierz[kt][1],D);
    int xd4;
    if(xd!=xd1||xd!=xd2||xd!=xd3)return 0;
    for(int i=0;i<=4;++i){
        xd4=pokt(wierz[kt][i%4],wierz[kt][(i+1)%4],A);
        xd1=pokt(wierz[kt][i%4],wierz[kt][(i+1)%4],B);
        xd2=pokt(wierz[kt][i%4],wierz[kt][(i+1)%4],C);
        xd3=pokt(wierz[kt][i%4],wierz[kt][(i+1)%4],D);
        if(xd!=xd1||xd!=xd2||xd!=xd3||xd!=xd4)return 0;
    }
    return 1;
}

int czyprzkw(pdd A, pdd B, pdd C, pdd D, int kt){
    for(int i=0;i<4;++i){
        if(czyprz(A,B,wierz[kt][i%4],wierz[kt][(i+1)%4]))return 1;
    }
    for(int i=0;i<4;++i){
        if(czyprz(B,C,wierz[kt][i%4],wierz[kt][(i+1)%4]))return 1;
    }
    for(int i=0;i<4;++i){
        if(czyprz(C,D,wierz[kt][i%4],wierz[kt][(i+1)%4]))return 1;
    }
    for(int i=0;i<4;++i){
        if(czyprz(D,A,wierz[kt][i%4],wierz[kt][(i+1)%4]))return 1;
    }
    return 0;
}

int czysrw(pdd A, pdd B, pdd C, pdd D, int kt){

        int xd=pokt(A,B,sr[kt]);
        int xd1=pokt(B,C,sr[kt]);
        int xd2=pokt(C,D,sr[kt]);
        int xd3=pokt(D,A,sr[kt]);
        if(xd!=xd1||xd!=xd2||xd!=xd3)return 0;

    return 1;

}

void rob(pdd A, pdd B, pdd C, pdd D, double pol){
    for(int i=0;i<n;++i){
        if(czyzaw(A,B,C,D,i)){

            wynik+=pol;
            return;
        }
    }
    if(pol>0.0001){
        for(int i=0;i<n;++i){
        if(czyprzkw(A,B,C,D,i)||czysrw(A,B,C,D,i)){ //cout<<"A";
            rob(A,mp((A.f+B.f)/2,A.s),mp((A.f+B.f)/2,(A.s+D.s)/2),mp(A.f,(A.s+D.s)/2),pol/4);
            rob(mp(A.f,(A.s+D.s)/2),mp((A.f+B.f)/2,(A.s+D.s)/2),mp((A.f+B.f)/2,C.s),D,pol/4);
            rob(mp((A.f+B.f)/2,A.s),B,mp(B.f,(A.s+D.s)/2),mp((A.f+B.f)/2,(A.s+D.s)/2),pol/4);
            rob(mp((A.f+B.f)/2,(A.s+D.s)/2),mp(B.f,(A.s+D.s)/2),C,mp((A.f+B.f)/2,C.s),pol/4);
            return;
        }
    }

    }else{
        for(int i=0;i<n;++i){
        if(czyprzkw(A,B,C,D,i)||czysrw(A,B,C,D,i)){
            wynik+=pol/2;
            return;
        }
    }
    }

    return;
}

int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;++i){
        scanf("%lf%lf%lf%lf",&a,&b,&c,&d);
        x=c-a;
        y=d-b;
        wierz[i][0]=mp(c,d);
        wierz[i][1]=mp(a+y,b-x);
        wierz[i][2]=mp(a-x,b-y);
        wierz[i][3]=mp(a-y,b+x);
        for(int j=0;j<4;++j){
            L=min(L,wierz[i][j].f);
            D=min(D,wierz[i][j].s);
            P=max(P,wierz[i][j].f);
            G=max(G,wierz[i][j].s);
        }
    }
    rob(mp(L,D),mp(P,D),mp(P,G),mp(L,G),(P-L)*(G-D));
    printf("%d",(int)round(wynik));
    return 0;
}
