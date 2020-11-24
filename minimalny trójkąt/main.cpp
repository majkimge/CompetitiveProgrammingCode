#include <bits/stdc++.h>
#define lld long long
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define MAX 2009
#define MOD 2000000007
#define ulld unsigned long long

using namespace std;

pair<lld,lld> points[MAX];
lld n,x,y,ilev,cogdz[MAX],wynik;
pair<int,int> vec[MAX*MAX];
map<pair<lld,lld>,lld> mm;
lld ul[MAX];
lld czysw[MAX];
vector<lld> terswap;
lld poczy[MAX],kony[MAX];



//pair<pair<pair<lld,lld>,pair<lld,lld> >,pair<lld,lld> >

bool cmp(pair<int,int> AA, pair<int,int> BB){
    pair<pair<pair<lld,lld>,pair<lld,lld> >,pair<lld,lld> >A=mp(mp(points[AA.f],points[AA.s]),mp(AA.f,AA.s));
    pair<pair<pair<lld,lld>,pair<lld,lld> >,pair<lld,lld> >B=mp(mp(points[BB.f],points[BB.s]),mp(BB.f,BB.s));
    lld xx1=A.f.s.f-A.f.f.f;
    lld yy1=A.f.s.s-A.f.f.s;
    lld xx2=B.f.s.f-B.f.f.f;
    lld yy2=B.f.s.s-B.f.f.s;
    if(xx1*yy2-yy1*xx2<0)return 0;
    if(xx1*yy2-yy1*xx2>0)return 1;

    lld temp1=(A.f.s.f-A.f.f.f)*(A.f.s.f-A.f.f.f);
    lld temp2=(A.f.s.s-A.f.f.s)*(A.f.s.s-A.f.f.s);
    ulld dl1=(ulld)temp1+temp2;
    temp1=(B.f.s.f-B.f.f.f)*(B.f.s.f-B.f.f.f);
    temp2=(B.f.s.s-B.f.f.s)*(B.f.s.s-B.f.f.s);
    ulld dl2=(ulld)temp1+temp2;


    if(dl1<dl2)return 0;
    if(dl1>dl2)return 1;
    if(B.s.s>A.s.s)return 1;
    return 0;
}


lld area (lld A,lld B,lld C){
    lld ret=abs(points[A].f*(points[B].s-points[C].s)+points[B].f*(points[C].s-points[A].s)+points[C].f*(points[A].s-points[B].s));
    return ret;
}
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;++i){
        scanf("%lld%lld",&x,&y);
       //x+=MOD;
       //y+=MOD;
        points[i]=mp(y,x);
    }
    sort(points,points+n);

    for(int i=0;i<n;++i)swap(points[i].f,points[i].s);
    for(int i=0;i<n;++i){
        cogdz[i]=i;
        ul[i]=i;
    }
    for(int i=0;i<n;++i){
        for(int j=i+1;j<n;++j){
            vec[ilev]=mp(i,j);
            ++ilev;
        }
    }
    sort(vec,vec+ilev,cmp);
    cout<<endl;
    for(int i=0;i<n;++i)cout<<points[i].f<<" "<<points[i].s<<endl;
    cout<<endl;
    /*for(int i=0;i<ilev;++i){
        cout<<vec[i].s.f+1<<" "<<vec[i].s.s+1<<endl;
    }*/
    wynik=(lld)MOD*MOD;
    for(int i=0;i<ilev;++i){

        pair<pair<pair<lld,lld>,pair<lld,lld> >,pair<lld,lld> > AA=mp(mp(points[vec[i].f],points[vec[i].s]),mp(vec[i].f,vec[i].s));
        lld x1=AA.f.s.f-AA.f.f.f;
        lld y1=AA.f.s.s-AA.f.f.s;
        int pocz=cogdz[AA.s.f];//for(int j=0;j<n;++j)cout<<x1<<" "<<y1<<endl;
        //cout<<endl;
        int kon=cogdz[AA.s.s];
        for(int j=pocz;j<=(pocz+kon)/2;++j){
                poczy[ul[j]]=pocz;
                kony[ul[j]]=kon;
                poczy[ul[kon-(j-pocz)]]=pocz;
                kony[ul[kon-(j-pocz)]]=kon;
            terswap.pb(ul[j]);
            terswap.pb(ul[kon-(j-pocz)]);
            czysw[ul[j]]=1;
            czysw[ul[kon-(j-pocz)]]=1;
            swap(ul[j],ul[kon-(j-pocz)]);
            cogdz[ul[j]]=j;
            cogdz[ul[kon-(j-pocz)]]=kon-(j-pocz);
        }
        cout<<AA.s.f+1<<" "<<AA.s.s+1<<endl;
        if(pocz)wynik=min(wynik,area(AA.s.f,AA.s.s,ul[pocz-1]));
        if(kon<n-1)wynik=min(wynik,area(AA.s.f,AA.s.s,ul[kon+1]));
        //if(i<ilev-1)cout<<
        while(i<ilev-1&&x1*(points[vec[i+1].s].s-points[vec[i+1].f].s)-y1*(points[vec[i+1].s].f-points[vec[i+1].f].f)==0){
            if(czysw[vec[i+1].s]){
                if(poczy[vec[i+1].s])wynik=min(wynik,area(vec[i+1].s,vec[i+1].f,ul[poczy[vec[i+1].s]-1]));
                if(kony[vec[i+1].s]<n-1)wynik=min(wynik,area(vec[i+1].s,vec[i+1].f,ul[kony[vec[i+1].s]+1]));
            }else{
                AA=mp(mp(points[vec[i].f],points[vec[i].s]),mp(vec[i].f,vec[i].s));
        x1=AA.f.s.f-AA.f.f.f;
        y1=AA.f.s.s-AA.f.f.s;
        pocz=cogdz[AA.s.f];//for(int j=0;j<n;++j)cout<<x1<<" "<<y1<<endl;
        //cout<<endl;
        kon=cogdz[AA.s.s];
        for(int j=pocz;j<=(pocz+kon)/2;++j){
                poczy[ul[j]]=pocz;
                kony[ul[j]]=kon;
                poczy[ul[kon-(j-pocz)]]=pocz;
                kony[ul[kon-(j-pocz)]]=kon;
            terswap.pb(ul[j]);
            terswap.pb(ul[kon-(j-pocz)]);
            czysw[ul[j]]=1;
            czysw[ul[kon-(j-pocz)]]=1;
            swap(ul[j],ul[kon-(j-pocz)]);
            cogdz[ul[j]]=j;
            cogdz[ul[kon-(j-pocz)]]=kon-(j-pocz);
        }
        if(poczy[vec[i+1].s])wynik=min(wynik,area(vec[i+1].s,vec[i+1].f,ul[poczy[vec[i+1].s]-1]));
                if(kony[vec[i+1].s]<n-1)wynik=min(wynik,area(vec[i+1].s,vec[i+1].f,ul[kony[vec[i+1].s]+1]));
            }

            ++i;
        }
        for(int j=0;j<terswap.size();++j){
            czysw[terswap[j]]=0;
        }
        terswap.clear();
    }
    printf("%lld",wynik);
    return 0;
}
/*
4
2 1
0 3
1 2
3 2

6
-1 0
1 1
0 1
1 0
0 0
-1 1
*/
