#include <bits/stdc++.h>
#define lld long long
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define MAX 4000009
#define pii pair<lld,lld>
#define pdd pair<double,double>

using namespace std;

lld n,a,b,c,ile,kk=1;
pair<pii,lld> points[20009];
pair<pii,pair<pii,pii> >vect[MAX];
pair<lld,pair<pii,pii> >tree[20000];
lld wynik;
lld gdz[20009];

bool cmp(pair<pii,pair<pii,pii> > pier, pair<pii,pair<pii,pii> > sec){
    pier.s.s.s-=pier.s.f.s;
    pier.s.s.f-=pier.s.f.f;
    sec.s.s.s-=sec.s.f.s;
    sec.s.s.f-=sec.s.f.f;

    if(pier.s.s.f*sec.s.s.s-pier.s.s.s*sec.s.s.f>0)return 1;
    if(pier.s.s.f*sec.s.s.s-pier.s.s.s*sec.s.s.f<0)return 0;

    if((pier.s.s.s)*(pier.s.s.s)+(pier.s.s.f)*(pier.s.s.f)>
       (sec.s.s.s)*(sec.s.s.s)+(sec.s.s.f)*(sec.s.s.f))return 1;
    if((pier.s.s.s)*(pier.s.s.s)+(pier.s.s.f)*(pier.s.s.f)<
       (sec.s.s.s)*(sec.s.s.s)+(sec.s.s.f)*(sec.s.s.f))return 0;
    if(pier.s.f.f>sec.s.f.f)return 1;
    return 0;
}

lld ilo(pair<pii,pair<pii,pii> > pier, pair<pii,pair<pii,pii> > sec){
    pier.s.s.s-=pier.s.f.s;
    pier.s.s.f-=pier.s.f.f;
    sec.s.s.s-=sec.s.f.s;
    sec.s.s.f-=sec.s.f.f;
    return pier.s.s.f*sec.s.s.s-pier.s.s.s*sec.s.s.f;
}

bool cmp1(pair<pii,lld> A, pair<pii,lld> B){
    if(A.f.s<B.f.s)return 1;
    if(A.f.s>B.f.s)return 0;
    if(A.f.f<B.f.f)return 1;
    return 0;
}

void ust(lld gdz, lld kt){
    gdz+=kk;
    tree[gdz]=mp(kt,mp(mp(max((lld)0,points[kt].s),max((lld)0,points[kt].s)),mp(max((lld)0,points[kt].s),points[kt].s)));
    gdz>>=1;
    while(gdz){
        tree[gdz].s.f.f=max((lld)0,max(tree[gdz*2].s.f.f,tree[gdz*2].s.s.s+tree[gdz*2+1].s.f.f)); //Prefiks max z prefiks lewego i wart lewego plus prefiks prawego
        tree[gdz].s.f.s=max((lld)0,max(tree[gdz*2+1].s.f.s,tree[gdz*2].s.f.s+tree[gdz*2+1].s.s.s)); //Sufiks max z suf prawego i wart prawego plus suf lewego
        tree[gdz].s.s.f=max(max((lld)0,max(tree[gdz*2].s.s.f,tree[gdz*2+1].s.s.f)),tree[gdz*2].s.f.s+tree[gdz*2+1].s.f.f); //Infiks max z infiksów synów, sufiks lewego + prefiks prawego
        tree[gdz].s.s.s=tree[gdz*2].s.s.s+tree[gdz*2+1].s.s.s;  //Wart = suma wart synów
        gdz>>=1;
    }
}

int main()
{
    scanf("%lld",&n);
    for(int i=0;i<n;++i){
        scanf("%lld%lld%lld",&a,&b,&c);
        points[i]=mp(mp(a,b),c);
    }
    sort(points,points+n,cmp1);
    for(int i=0;i<n;++i){
        //cout<<points[i].f.f<<" "<<points[i].f.s<<endl;
        for(int j=i+1;j<n;++j){
            vect[ile]=mp(mp(i,j),mp(points[i].f,points[j].f));
            ++ile;
        }
    }

    sort(vect,vect+ile,cmp);
    //cout<<endl;
    while(kk<n)kk<<=1;;
    for(int i=0;i<n;++i){
        ust(i,i);
        gdz[i]=i;
    }//cout<<"A";
    //cout<<tree[0]
    wynik=max(wynik,tree[1].s.s.f);
    for(int i=0;i<ile;++i){


        if(gdz[vect[i].f.f]<gdz[vect[i].f.s]){

            ust(gdz[vect[i].f.f],vect[i].f.s);
            ust(gdz[vect[i].f.s],vect[i].f.f);
            lld temp=(lld)gdz[vect[i].f.f];
            gdz[vect[i].f.f]=gdz[vect[i].f.s];
            gdz[vect[i].f.s]=temp;
        }
        if(i==ile-1||ilo(vect[i],vect[i+1])!=0){
            wynik=max(wynik,tree[1].s.s.f);//cout<<vect[i].f.f<<" "<<vect[i].f.s<<endl;
        }
        //for(int i=0;i<n;++i)cout<<tree[i+kk].s.s.s<<" ";
        //cout<<endl;
    }
    printf("%lld",wynik);
    return 0;
}
/*
4
1 0 3
2 0 1
3 0 -10
4 0 2
*/
