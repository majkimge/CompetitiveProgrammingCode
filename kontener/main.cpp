#include <bits/stdc++.h>
#define lld long long
#define mp make_pair
#define f first
#define s second
#define pb push_back
#define MAX 100009
#define TSize 3500000
#define MOD 1000696969

using namespace std;

pair<int,int> tab[100009];
int q,a,b,c,kk=1;
lld wynik;

/*pair<pair<pair<int,int>,pair<int,int> >, pair<int,int> >tree[TSize];
int n,ilew;

void dod(int gdz, int zakl, int zakp, int ile, int kto, int dok){
    if(zakl==zakp){
        if(tree[gdz].f.f.f<ile){
            tree[gdz].f=mp(ile,kto);
        }
        return;
    }
    if(dok<=(zakl+zakp)/2){
        if(tree[gdz].s.f==0){
            tree[gdz].s.f=ilew;
            ++ilew;
        }
        dod(tree[gdz].s.f,zakl,(zakl+zakp)/2,ile,kto,dok);
    }else{
        if(tree[gdz].s.s==0){
            tree[gdz].s.s=ilew;
            ++ilew;
        }
        dod(tree[gdz].s.s,(zakl+zakp)/2 +1,zakp,ile,kto,dok);
    }
    if(tree[tree[gdz].s.f])
}*/

map<int,pair<pair<int,int>,pair<int,int> > > tree;

int podl(int kto){
    return tab[kto].f*tab[kto].f+2*tab[kto].f*tab[kto].s;
}

int podp(int kto){
    return tab[kto].s*tab[kto].s;
}

void dod(int gdz, int zakl, int zakp, int dok, int kto){
    if(zakl==zakp){
        //cout<<zakl;
        int lew=tab[kto].f*tab[kto].f+2*tab[kto].f*tab[kto].s;
        int praw=tab[kto].s*tab[kto].s;
        if(tree[gdz].f.f<lew){
            tree[gdz].f=mp(lew,kto);
        }
        if(tree[gdz].s.f<praw){
            tree[gdz].s=mp(praw,kto);
        }
        return;
    }
    if(dok<=(zakl+zakp)/2){
        dod(gdz*2,zakl,(zakl+zakp)/2,dok,kto);
    }else{
        dod(gdz*2+1,(zakl+zakp)/2+1,zakp,dok,kto);
    }

    if(tree[gdz*2].f.f<tree[gdz*2+1].f.f){
        tree[gdz].f=tree[gdz*2+1].f;
    }else{
        tree[gdz].f=tree[gdz*2].f;
    }

    if(tree[gdz*2].s.f<tree[gdz*2+1].s.f){
        tree[gdz].s=tree[gdz*2+1].s;
    }else{
        tree[gdz].s=tree[gdz*2].s;
    }
}

pair<pair<int,int>,pair<int,int> > maxi(int gdz, int zakl, int zakp, int l, int p){
    if(l<=zakl&&p>=zakp){
        //pair<pair<int,int>,pair<int,int> > wyn;
        return tree[gdz];

    }else if(l>zakp||p<zakl){
        return mp(mp(0,0),mp(0,0));
    }else{
        pair<pair<int,int>,pair<int,int> > lwyn=maxi(gdz*2,zakl,(zakl+zakp)/2,l,p);
        pair<pair<int,int>,pair<int,int> > pwyn=maxi(gdz*2+1,(zakl+zakp)/2+1,zakp,l,p);
        pair<pair<int,int>,pair<int,int> > wyn;
        if(lwyn.f.f<pwyn.f.f){
            wyn.f=pwyn.f;
        }else{
            wyn.f=lwyn.f;
        }
        if(lwyn.s.f<pwyn.s.f){
            wyn.s=pwyn.s;
        }else{
            wyn.s=lwyn.s;
        }
        return wyn;
    }
}


int main()
{
    scanf("%d",&q);
    while(kk<1000000000)kk<<=1;
    for(int i=1;i<=q;++i){
        scanf("%d%d%d",&a,&b,&c);

        if(a==1){
            tab[i]=mp(b,c);
            dod(1,0,kk-1,(b*b+2*b*c)/(c*c),i);
            //cout<<(b*b+2*b*c)/(c*c);
        }else{
            int gran=(c*c+2*b*c)/(b*b);
            //cout<<gran;
            wynik=0;

            pair<pair<int,int>,pair<int,int> > pier=maxi(1,0,kk-1,0,max(0,gran-1));
            int lz=pier.f.s;
            int pz=pier.s.s;
            //cout<<lz;
            //wynik=max(wynik,min(podl(lz),podp(lz)));
            //wynik=max(wynik,min(podl(pz),podp(pz)));
            if((lld)podl(lz)*b*b<=(lld)podp(lz)*(c*c+2*b*c)){
                wynik=max(wynik,(lld)podl(lz)*b*b);
            }
            if((lld)podl(pz)*b*b<=(lld)podp(pz)*(c*c+2*b*c)){
                wynik=max(wynik,(lld)podl(pz)*b*b);
            }

            pier=maxi(1,0,kk-1,0,max(0,gran));

            lz=pier.f.s;
            //cout<<podp(lz)*(c*c+2*b*c);
            pz=pier.s.s;
            if((lld)podl(lz)*b*b<=(lld)podp(lz)*(c*c+2*b*c)){
                wynik=max(wynik,(lld)podl(lz)*b*b);
            }
            if((lld)podl(pz)*b*b<=(lld)podp(pz)*(c*c+2*b*c)){
                wynik=max(wynik,(lld)podl(pz)*b*b);
            }

            /*wynik=max(wynik,min(podl(lz),podp(lz)));
            wynik=max(wynik,min(podl(pz),podp(pz)));*/

            pier=maxi(1,0,kk-1,0,max(0,gran+1));
            lz=pier.f.s;
            pz=pier.s.s;
            //wynik=max(wynik,min(podl(lz),podp(lz)));
            //wynik=max(wynik,min(podl(pz),podp(pz)));
            if((lld)podl(lz)*b*b<=(lld)podp(lz)*(c*c+2*b*c)){
                wynik=max(wynik,(lld)podl(lz)*b*b);
            }
            if((lld)podl(pz)*b*b<=(lld)podp(pz)*(c*c+2*b*c)){
                wynik=max(wynik,(lld)podl(pz)*b*b);
            }


            //cout<<wynik;
            //wynik=0;

            pier=maxi(1,0,kk-1,gran-1,kk-1);
            lz=pier.f.s;
            pz=pier.s.s;
            //cout<<lz;
            //wynik=max(wynik,min(podl(lz),podp(lz)));
            //wynik=max(wynik,min(podl(pz),podp(pz)));
            if((lld)podl(lz)*b*b>=(lld)podp(lz)*(c*c+2*b*c)){
                wynik=max(wynik,(lld)podp(lz)*(c*c+2*b*c));
            }
            if((lld)podl(pz)*b*b>=(lld)podp(pz)*(c*c+2*b*c)){
                wynik=max(wynik,(lld)podp(pz)*(c*c+2*b*c));
            }

            pier=maxi(1,0,kk-1,gran,kk-1);
            lz=pier.f.s;
            pz=pier.s.s;
            if((lld)podl(lz)*b*b>=(lld)podp(lz)*(c*c+2*b*c)){
                wynik=max(wynik,(lld)podp(lz)*(c*c+2*b*c));
            }
            if((lld)podl(pz)*b*b>=(lld)podp(pz)*(c*c+2*b*c)){
                wynik=max(wynik,(lld)podp(pz)*(c*c+2*b*c));
            }

            /*wynik=max(wynik,min(podl(lz),podp(lz)));
            wynik=max(wynik,min(podl(pz),podp(pz)));*/

            pier=maxi(1,0,kk-1,gran+1,kk-1);
            lz=pier.f.s;
            pz=pier.s.s;
            //wynik=max(wynik,min(podl(lz),podp(lz)));
            //wynik=max(wynik,min(podl(pz),podp(pz)));
            if((lld)podl(lz)*b*b>=(lld)podp(lz)*(c*c+2*b*c)){
                wynik=max(wynik,(lld)podp(lz)*(c*c+2*b*c));
            }
            if((lld)podl(pz)*b*b>=(lld)podp(pz)*(c*c+2*b*c)){
                wynik=max(wynik,(lld)podp(pz)*(c*c+2*b*c));
            }

            printf("%lld\n",wynik);
        }
    }
    return 0;
}
