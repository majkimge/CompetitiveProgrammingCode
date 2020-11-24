#include <bits/stdc++.h>

#define lld long long
#define MAX 4000009
#define mp make_pair
#define f first
#define s second
using namespace std;

lld n;
lld x,y;
lld wynik=0;
lld prewyn=0;
lld wyntera=0;
lld xsum=0;
lld ysum=0;
pair<lld,lld> ruchy[MAX];

lld det(pair<lld,lld> p1, pair<lld,lld> p2) {
    return p1.f * p2.s - p1.s * p2.f;
}
#define pii pair<lld,lld>
#define x first
#define y second
bool lesser(pii a, pii b)
{
	if(!a.x && !a.y)return 1;
	if(!a.y && !b.y)return a.x>b.x;
	if(!a.y && a.x>0)return 1;
	if(!b.y && b.x>0)return 0;
	if(a.y>0 && b.y<0)return 1;
	if(a.y<0 && b.y>0)return 0;
	return a.x*b.y-a.y*b.x>0;
}
#undef x
#undef y
int main()
{
    scanf("%lld",&n);
    for(int i=0;i<n;++i){
        scanf("%lld",&x);
        scanf("%lld",&y);
        if(!x && !y){--n,--i;continue;}
        ruchy[i]=mp(x,y);
    }
    sort(ruchy,ruchy+n,lesser);
    for(int i=n;i<2*n;++i){
        //scanf("%lld",&x);
        //scanf("%lld",&y);
        //if(!rx && !y){--n,--i;continue;}
        ruchy[i]=ruchy[i-n];
    }

   /* for(int i=0;i<n;++i){

        cout<<ruchy[i].first<<" XD "<<ruchy[i].second<<endl;
    }*/
    for(int i=0;i<n;i++){
        wynik=0;
        xsum=0;
        ysum=0;
        prewyn=0;
        for(int j=i;j<i+n;j++){
           /* if((xsum+ruchy[j].f)*(xsum+ruchy[j].f)+(ysum+ruchy[j].s)*(ysum+ruchy[j].s)>prewyn){*/
                xsum+=ruchy[j].f;
                ysum+=ruchy[j].s;
                wynik=xsum*xsum+ysum*ysum;
            //}

            if(wynik>wyntera){
                wyntera=wynik;
            }
            prewyn=wynik;
        }
    }
    cout<<wyntera;
    return 0;
}
