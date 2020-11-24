#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define MAX 1009
#define pdd pair<double,double>
#define pii pair<int,int>

using namespace std;

int z,n,x,r,y,x2,y2,wynik,m;

pdd comp[500];
pair<pdd,pdd >walls[MAX];
vector<pdd >badpoints;
vector<pdd >points;




pdd inter(pdd A, pdd B, pdd C, pdd D)
{
    double a1 = B.s - A.s;
    double b1 = A.f - B.f;
    double c1 = a1*(A.f) + b1*(A.s);

    double a2 = D.s - C.s;
    double b2 = C.f - D.f;
    double c2 = a2*(C.f)+ b2*(C.s);

    double det = a1*b2 - a2*b1;

    if (det == 0)
    {
        return mp(r*10, r*10);
    }
    else
    {
        double x = (b2*c1 - b1*c2)/det;
        double y = (a1*c2 - a2*c1)/det;
        return mp(x, y);
    }
}

int czy(pdd p1,pdd p2, pdd p3, pdd p4){
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



int tensam(double A, double B){
    if(A+0.0001>=B&&A-0.0001<=B)return 1;
    return 0;
}


int na(pdd A, pdd B, pdd C)
{
    if(A.f>B.f)swap(A,B);
    if(C.f>=A.f-0.0001&&C.f<=B.f+0.0001&&C.s>=min(A.s,B.s)-0.0001&&C.s<=max(B.s,A.s)+0.0001){
        if(tensam(A.f,B.f)){        //Linia y=a
            if(tensam(A.f,C.f))return 1;
            return 0;
        }else{
            double pry=(max(B.s,A.s)-min(B.s,A.s))/(B.f-A.f);
            double pry1=(max(C.s,A.s)-min(C.s,A.s))/(C.f-A.f);
            if(tensam(pry,pry1))return 1;
            return 0;
        }
    }
    return 0;
}


int main()
{
    scanf("%d",&z);
    for(int xdd=0;xdd<z;++xdd){
        scanf("%d%d%d",&r,&n,&m);
        badpoints.clear();
        points.clear();
        for(int i=0;i<n;++i){
            scanf("%d%d",&x,&y);
            x+=r;
            y+=r;
            comp[i]=mp((double)x,(double)y);
        }
        for(int i=0;i<m;++i){
            scanf("%d%d%d%d",&x,&y,&x2,&y2);
            x+=r;
            x2+=r;
            y+=r;
            y2+=r;
            walls[i]=mp(mp((double)x,(double)y),mp((double)x2,(double)y2));

            points.pb(mp((double)x,(double)y));



            points.pb(mp((double)x2,(double)y2));
        }
        for(int i=0;i<m;++i){
            for(int j=i+1;j<m;++j){
                pdd prze=inter(walls[i].f,walls[i].s,walls[j].f,walls[j].s);
                if(prze.f>2*r+1||prze.s>2*r+1)break;

                if(na(walls[i].f,walls[i].s,prze)&&na(walls[j].f,walls[j].s,prze)){
                    badpoints.pb(prze);

                }
            }
        }
        for(int i=0;i<n;++i){
            for(int j=i+1;j<n;++j){
                for(int p=0;p<points.size();p++){
                    for(int q=0;q<points.size();q++){
                        pdd prze=inter(comp[i],points[p],comp[j],points[q]);

                        if(prze.f>2*r+1||prze.s>2*r+1)break;
                        int wyn=1;
                        for(int rr=0;rr<n;++rr){
                            for(int ss=0;ss<m;++ss){
                                if(czy(comp[rr],prze,walls[ss].f,walls[ss].s)){
                                    wyn=0;
                                    break;
                                }
                            }
                            for(int ss=0;ss<badpoints.size();++ss){
                                //if(!(tensam(prze.f,badpoints[ss].f&&tensam(prze.s,badpoints[ss].s)))){
                                    if(na(prze,comp[rr],badpoints[ss]))wyn=0;
                                //}
                            }
                            for(int ss=0;ss<m;++ss){
                                if(p!=q&&na(walls[ss].f,walls[ss].s,prze))wyn=0;
                            }
                        }
                        if(wyn){
                            wynik=1;
                            cout<<prze.f<<" "<<prze.s<<endl;
                        }
                    }
                }
            }
        }
        if(wynik){
            printf("TAK\n");
        }else{
            printf("NIE\n");
        }

    }

    return 0;
}
