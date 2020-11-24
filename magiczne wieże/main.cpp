#include <bits/stdc++.h>
#define pb push_back
#define lld long long
#define mp make_pair
#define f first
#define s second
#define MAX 209
#define MOD 1000000007
#define MOD1 1000696969
#define INF 1000000000000000
#define piii pair<pair<double,double>,lld>
#define piiii pair<pair<double,double>,pair<double,double> >
#define pii pair<double,double>

using namespace std;

int n,pozm,br;
double a,b,c,d;
int ziom[MAX];
int odw[MAX];
piii points[MAX];
piii points1[MAX];
piiii last;
vector<pii> wiel;
#define x first
#define y second
int lesser(piii a, piii b)
{
	if(!a.x.x && !a.x.y)return 1;
	if(!a.x.y && !b.x.y)return a.x.x>b.x.x;
	if(!a.x.y && a.x.x>0)return 1;
	if(!b.x.y && b.x.x>0)return 0;
	if(a.x.y>0 && b.x.y<0)return 1;
	if(a.x.y<0 && b.x.y>0)return 0;
	return a.x.x*b.x.y-a.x.y*b.x.x>0;
}
#undef x
#undef y

double area()
{
    // Initialze area
    double area = 0.0;

    // Calculate value of shoelace formula
    int j = wiel.size()-1;
    for (int i = 0; i < wiel.size(); i++)
    {
        area += (wiel[j].f + wiel[i].f) * (wiel[j].s - wiel[i].s);
        j = i;  // j is previous vertex to i
    }

    // Return absolute value
    return abs(area / 2.0);
}


pii inter(pii A, pii B, pii C, pii D)
{
    double a1 = B.s - A.s;
    double b1 = A.f - B.f;
    double c1 = a1*(A.f) + b1*(A.s);

    double a2 = D.s - C.s;
    double b2 = C.f - D.f;
    double c2 = a2*(C.f)+ b2*(C.s);

    double determinant = a1*b2 - a2*b1;

    if (determinant == 0)
    {

        return mp(MOD, MOD);
    }
    else
    {
        double x = (b2*c1 - b1*c2)/determinant;
        double y = (a1*c2 - a2*c1)/determinant;
        return mp(x, y);
    }
}

int side(pii a, pii b, pii c){
//    d=(a.f−b.f)(c.s−b.s)−(a.s−b.s)(c.f−b.f);
    return d;
}

int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;++i){
        scanf("%lf%lf%lf%lf",&a,&b,&c,&d);
        points[i*2]=points1[i*2]=mp(mp(a,b),i*2);
        points[i*2+1]=points1[i*2+1]=mp(mp(c,d),i*2+1);
        ziom[i*2]=i*2+1;
        ziom[i*2+1]=i*2;
    }
    sort(points,points+2*n,lesser);
    int gdz=points[0].s;

    while(!odw[gdz/2]){cout<<gdz<<endl;
        odw[gdz/2]=1;
        int gdz1=0;
        for(int i=0;i<2*n;++i){
            points1[i].f.f-=points[gdz].f.f;
            points1[i].f.s-=points[gdz].f.s;
        }
        sort(points1,points1+2*n,lesser);
        for(int i=0;i<2*n;++i){
            if(points1[i].s==gdz){
                    cout<<"D";
                    continue;
            }
            cout<<points[gdz].f.f<<" "<<points[gdz].f.s<<" "<<points[points1[i].s].f.f<<" "<<points[points1[i].s].f.s<<endl;
            cout<<side(points[gdz].f,points[points1[i].s].f,points[ziom[gdz]].f);
            if(side(points[gdz].f,points[points1[i].s].f,points[ziom[gdz]].f)>0){
                pozm=1;
                gdz1=points[ziom[gdz]].s;
                cout<<"X";
                break;
            }
            if(side(points[gdz].f,points[points1[i].s].f,points[ziom[gdz]].f)<=0&&side(points[gdz].f,points[points1[i].s].f,points[ziom[points1[i].s]].f)<=0){


                if(gdz!=points[0].s&&gdz!=points[ziom[points[0].s]].s){
                    gdz1=points[points1[i].s].s;
                    pii xd=inter(last.f,last.s,points[gdz].f,points[points1[i].s].f);
                    if(xd.f<MOD/2){
                        wiel.pb(xd);
                    }
                }
                last=mp(points[gdz].f,points[points1[i].s].f);
                pozm=1;
                break;
            }
        }


        for(int i=0;i<2*n;++i){
            points1[i].f.f+=points[gdz].f.f;
            points1[i].f.s+=points[gdz].f.s;
        }
        gdz=gdz1;
        if(!pozm){
            br=1;
            break;
        }
    }
    if(br){
        printf("0");
    }else{
        printf("%lf",area());
    }
    return 0;
}
