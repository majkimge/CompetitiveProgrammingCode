#include <bits/stdc++.h>
#define lld long long
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define MAX 1000009
#define MOD 1000000007
#define INF 1000000000000000

using namespace std;

int z,r,n,m,x,y,x2,y2,wynik,w;
pair<pair<int,int>,pair<int,int> >walls[109];
pair<int,int> comp[5];
map<pair<int,int>,int> ilep;
vector<pair<int,int> > badpoint;
pair<int,int> points[209];


int czy(pair<double,double> p1,pair<double,double> p2, pair<double,double> p3, pair<double,double> p4){
    p2.f-=p1.f;
    p2.s-=p1.s;
    p3.f-=p1.f;
    p3.s-=p1.s;
    p4.f-=p1.f;
    p4.s-=p1.s;
    if((p2.f*p3.s-p2.s*p3.f)*(p2.f*p4.s-p2.s*p4.f)<=0){
        p2.f+=p1.f;
        p2.s+=p1.s;
        p3.f+=p1.f;
        p3.s+=p1.s;
        p4.f+=p1.f;
        p4.s+=p1.s;


        p2.f-=p3.f;
        p2.s-=p3.s;
        p1.f-=p3.f;
        p1.s-=p3.s;
        p4.f-=p3.f;
        p4.s-=p3.s;
        if((p4.f*p2.s-p4.s*p2.f)*(p4.f*p1.s-p4.s*p1.f)<=-0.0000001) return 1;
    }
    return 0;
}



int main()
{
    scanf("%d",&z);
    for(int xx=0;xx<z;++xx){
        scanf("%d%d%d",&r,&n,&m);
        for(int i=0;i<n;++i){
            scanf("%d%d",&x,&y);
            comp[i]=mp(x,y);
        }
        for(int i=0;i<m;++i){
            scanf("%d%d%d%d",&x,&y,&x2,&y2);
            walls[i]=mp(mp(x,y),mp(x2,y2));
            ilep[walls[i].f]++;
            if(ilep[walls[i].f]==2){
                badpoint.pb(walls[i].f);
            }
            ilep[walls[i].s]++;
            if(ilep[walls[i].s]==2){
                badpoint.pb(walls[i].s);
            }
            points[2*i]=walls[i].f;
            points[2*i+1]=walls[i].s;
        }
        wynik=0;
        for(int i=0;i<2*m;++i){
            for(int j=0;j<2*m;++j){

                for(int xd=0;xd<n;++xd){
                    for(int xd1=xd;xd1<n;++xd1){
                        pair<pair<int,int>,pair<int,int> > temp=walls[i];
                        pair<pair<int,int>,pair<int,int> > temp1=walls[j];
                        w=0;
                        walls[i]=mp(comp[xd],points[i]);
                        walls[j]=mp(comp[xd1],points[j]);

                        double mian=(double)(walls[j].s.s-walls[j].f.s)*(walls[i].s.f-walls[i].f.f)-(walls[i].s.s-walls[i].f.s)*(walls[j].s.f-walls[j].f.f);
                        double xxx=(double)-walls[i].f.s*(walls[j].s.f-walls[j].f.f)*(walls[i].s.f-walls[i].f.f)/mian-walls[i].f.f*(walls[i].s.s-walls[i].f.s)*(walls[j].s.f-walls[j].f.f)/mian;
                        xxx+=(double)walls[j].f.s*(walls[j].s.f-walls[j].f.f)*(walls[i].s.f-walls[i].f.f)/mian+walls[j].f.f*(walls[j].s.s-walls[j].f.s)*(walls[i].s.f-walls[i].f.f)/mian;
                       double yyy=(double)walls[i].f.s-xxx*(walls[i].s.s-walls[i].f.s)/(walls[i].s.f-walls[i].f.f)+walls[i].f.f*(walls[i].s.s-walls[i].f.s)/(walls[i].s.f-walls[i].f.f);
                         //cout<<"A";walls[i]=temp;
                        walls[j]=temp1;
                        //cout<<(double)(walls[j].s.s-walls[j].f.s)*(walls[i].s.f-walls[i].f.f)<<" "<<yyy<<endl;
                        if(abs(xxx)>(double)r||abs(yyy)>(double)r){
                            w=1;
                            break;
                        }
                        for(int aa=0;aa<n;++aa){
                            for(int bb=0;bb<m;++bb){
                                if(czy(mp(xxx,yyy),mp((double)comp[aa].f,(double)comp[aa].s),mp((double)walls[bb].f.f,(double)walls[bb].f.s)
                                       ,mp((double)walls[bb].s.f,(double)walls[bb].s.s))){
                                    w=1;
                                    break;
                                }
                                if(w)break;
                            }
                        }
                    }
                }
                if(w==0){
                    wynik=1;
                    printf("TAK\n");
                    break;
                }
            }
            if(wynik)break;
        }
        /*for(int i=-r;i<=r;++i){
            for(int j=-r;j<=r;++j){
                int w=0;
                for(int aa=0;aa<n;++aa){
                    for(int bb=0;bb<m;++bb){
                        if(czy(mp(i,j),comp[aa],walls[bb].f,walls[bb].s)){
                            w=1;
                            break;
                        }
                        if(w)break;
                    }
                }
                if(w==0){
                    wynik=1;
                    printf("TAK\n");
                    break;
                }
            }
            if(wynik)break;

        }*/
        if(!wynik) printf("NIE\n");
    }
    return 0;
}
/*
1
10
2
1
-1 0
1 0
-2 -2 2 2
*/
