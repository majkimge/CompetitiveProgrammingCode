#include <bits/stdc++.h>
#define lld long long
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define MAX 1000000
#define pii pair<lld,lld>
#define pdd pair<double,double>

using namespace std;

pii points[MAX];
lld n,a,b;
vector<pii> otoczka;

pdd lineLineIntersection(pdd A, pdd B, pdd C, pdd D)
{
    // Line AB represented as a1x + b1y = c1
    double a1 = B.s - A.s;
    double b1 = A.f - B.f;
    double c1 = a1*(A.f) + b1*(A.s);

    // Line CD represented as a2x + b2y = c2
    double a2 = D.s - C.s;
    double b2 = C.f - D.f;
    double c2 = a2*(C.f)+ b2*(C.s);

    double determinant = a1*b2 - a2*b1;

    if (determinant == 0)
    {
        // The lines are parallel. This is simplified
        // by returning a pair of FLT_MAX
        return mp(MAX, MAX);
    }
    else
    {
        double x = (b2*c1 - b1*c2)/determinant;
        double y = (a1*c2 - a2*c1)/determinant;
        return mp(x, y);
    }
}


bool cmp(pair <lld , lld > a , pair < lld , lld > b)
{
	if(a.s==0 && a.f==0)
	{
		return true;
	}
	else if(b.s==0 && b.f==0)
	{
		return false;
	}
	if(a.first*b.second-a.second*b.first<0)
	return true;
	else if((a.first*b.second-a.second*b.first==0) &&(abs(a.first)+abs(a.second)>abs(b.first)+abs(b.second)) )
	return true;
	else
	return false;
}

lld str(pii A,pii B, pii C){
	B.f-=A.f;
	B.s-=A.s;
	C.f-=A.f;
	C.s-=A.s;
	if(C.f*B.s-C.s*B.f>0)return 1;      //prawo
	if(C.f*B.s-C.s*B.f<0)return -1;     //lewo
	return 0;
}

void licz_otoczke(){
    sort(points,points+n);
    for(int i=0;i<n;++i){
        points[i].f-=points[0].f;
        points[i].s-=points[0].s;
    }
    sort(points,points+n,cmp);
    otoczka.pb(points[0]);
    otoczka.pb(points[1]);
    for(int i=2;i<n;++i){
        while(otoczka.size()>1&&str(otoczka[otoczka.size()-2],otoczka[otoczka.size()-1],points[i])==-1)otoczka.pop_back();
        otoczka.pb(points[i]);
    }
}

int main()
{
    scanf("%lld",&n);
    for(int i=0;i<n;++i){
        scanf("%lld%lld",&a,&b);
        points[i]=mp(a,b);
    }
    sort(points,points+n,cmp);
    for(int i=0;i<n;++i){
        printf("%lld %lld\n",points[i].f,points[i].s);
    }
    cout<<endl<<endl;
    licz_otoczke();
    for(int i=0;i<otoczka.size();++i){
        printf("%lld %lld\n",otoczka[i].f,otoczka[i].s);
    }
    return 0;
}
/*
7
2 3
4 2
3 2
0 3
2 0
0 0
1 1
*/
