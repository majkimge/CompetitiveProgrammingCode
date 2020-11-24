#include <bits/stdc++.h>

#define lld double
#define mp make_pair
#define f first
#define s second
#define MAX 100009
#define INF 100000000000

using namespace std;

long long n;
pair<pair<lld,lld>,pair<lld,lld> > tab[MAX];
lld x11,y11,x22,y22;
lld tempx1,tempx2,tempx3,tempy1,tempy2,tempy3;
bool czy;
bool cmp(const pair<pair<lld,lld>,pair<lld,lld> > &a,const pair<pair<lld,lld>,pair<lld,lld> > &b)
{
       return a.f.f>b.f.f;
}
bool cmp1(const pair<pair<lld,lld>,pair<lld,lld> > &a,const pair<pair<lld,lld>,pair<lld,lld> > &b)
{
       return a.f.s>b.f.s;
}
bool cmp2(const pair<pair<lld,lld>,pair<lld,lld> > &a,const pair<pair<lld,lld>,pair<lld,lld> > &b)
{
       return a.s.f>b.s.f;
}
bool cmp3(const pair<pair<lld,lld>,pair<lld,lld> > &a,const pair<pair<lld,lld>,pair<lld,lld> > &b)
{
       return a.s.s>b.s.s;
}

int main()
{
    scanf("%lld",&n);
    //cout<<n;
    for(int i=0;i<n;++i){
        scanf("%lf",&x11);
        scanf("%lf",&y11);
        scanf("%lf",&x22);
        scanf("%lf",&y22);
        tab[i]=mp(mp(x11,y11),mp(x22,y22));
    }
    sort(tab,tab+n,cmp);
    sort(tab,tab+n,cmp1);
    sort(tab,tab+n,cmp2);
    sort(tab,tab+n,cmp3);

    for(int i=1;i<n;++i){
            if(czy) break;
        for(int j=0;j<i;j++){
            tempx1=tab[j].s.f-tab[j].f.f;
            tempy1=tab[j].s.s-tab[j].f.s;
            tempx2=tab[i].s.f-tab[j].f.f;
            tempy2=tab[i].f.s-tab[j].f.s;
            tempx3=tab[i].f.f-tab[j].f.f;
            tempy3=tab[i].s.s-tab[j].f.s;
            if(((tempx1*tempy2-tempx2*tempy1)>0&&(tempx1*tempy3-tempx3*tempy1)<0)||((tempx1*tempy2-tempx2*tempy1)<0&&(tempx1*tempy3-tempx3*tempy1)>0)){
                tempx1=tab[i].f.f-tab[i].s.f;
                tempy1=tab[i].s.s-tab[i].f.s;
                tempx2=tab[j].f.f-tab[i].s.f;
                tempy2=tab[j].f.s-tab[i].f.s;
                tempx3=tab[i].s.f-tab[i].s.f;
                tempy3=tab[i].s.s-tab[i].f.s;
                if(((tempx1*tempy2-tempx2*tempy1)>0&&(tempx1*tempy3-tempx3*tempy1)<0)||((tempx1*tempy2-tempx2*tempy1)<0&&(tempx1*tempy3-tempx3*tempy1)>0)){
                    czy=1;
                    break;
                }
            }
        }
    }
    if(czy){
        printf("NIE");
    }else{
        printf("TAK");
    }
    return 0;
}
