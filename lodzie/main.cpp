#include<bits/stdc++.h>
#define pdd pair<double,double>
#define pii pair<long long,long long>
#define mp make_pair
#define f first
#define s second
#define pb push_back
#define MAX 100009
#define lld long long
#define INF 1000000009

using namespace std;

lld n,k,a,b,minix,miniy,minipos,wskl,wskp,lodl,lodp,wynik;
pii lody[MAX];
pair<pii,lld> telody[MAX];
pii wierz[MAX];
vector<pair<pii,lld> > hull;
pair<pii,lld> twierz[MAX];
lld onhull[MAX];



bool cmp(pair<pii,lld> A, pair<pii,lld> B)
{
	if(!A.f.f && !A.f.s)return 1;
	if(!A.f.s && !B.f.s)return A.f.f>B.f.f;
	if(!A.f.s && A.f.f>0)return 1;
	if(!B.f.s && B.f.f>0)return 0;
	if(A.f.s>0 && B.f.s<0)return 1;
	if(A.f.s<0 && B.f.s>0)return 0;
	return A.f.f*B.f.s-A.f.s*B.f.f>0;
}

int str(pii A, pii B, pii C){
	B.f-=A.f;
	B.s-=A.s;
	C.f-=A.f;
	C.s-=A.s;
	if(B.f*C.s-B.s*C.f<0)return 0;
	if(B.f*C.s-B.s*C.f==0)return 2;
	return 1;
}

int main(){

	scanf("%lld",&n);
	for(int i=0;i<n;++i){
		scanf("%lld%lld",&a,&b);
		lody[i]=mp(a,b);
		telody[i]=mp(lody[i],i);
	}
	miniy=INF;
	for(int i=0;i<n;++i){
		if(lody[i].s<miniy){
			minipos=i;
			miniy=lody[i].s;
			minix=lody[i].f;
		}
	}
	//swap(lody[0],lody[minipos]);
	swap(telody[0],telody[minipos]);

	for(int i=0;i<n;++i){
		telody[i].f.f-=minix;
		telody[i].f.s-=miniy;
	}
	sort(telody,telody+n,cmp);
	for(int i=0;i<n;++i){
		telody[i].f.f+=minix;
		telody[i].f.s+=miniy;
	}
	/*for(int i=0;i<n;++i){
		cout<<telody[i].s<<endl;
	}*/

	if(n==1){cout<<"0";}else{
		hull.pb(telody[n-1]);
		hull.pb(telody[n-2]);
		for(int i=n-3;i>=0;--i){
			if(!str(hull[hull.size()-2].f,hull[hull.size()-1].f,telody[i].f)){
				hull.pb(telody[i]);
				onhull[telody[i].s]=1;
			}else{
				while(hull.size()>=2&&str(hull[hull.size()-2].f,hull[hull.size()-1].f,telody[i].f)){
					onhull[hull[hull.size()-1].s]=0;
					hull.pop_back();
				}
				hull.pb(telody[i]);
				onhull[telody[i].s]=1;
			}
		}

		/*for(int i=0;i<hull.size();++i){
			cout<<hull[i].s+1<<endl;
		}*/
		scanf("%lld",&k);
		for(int i=0;i<k;++i){
			scanf("%lld%lld",&a,&b);
			wierz[i]=mp(a,b);
			//twierz[i]=mp(mp(wierz[i].f-lody[0].f,wierz[i].s-lody[0].s),i);
		}
		lodl=lodp=0;
		/*sort(twierz,twierz+k,cmp);
		for(int i=0;i<k;++i){
			cout<<twierz[i].s<<endl;
		}
		//cout<<twierz[0].s<<" "<<twierz[k-1].s<<endl;
		*/
		//cout<<lody[0].f;
		while(!str(lody[0],wierz[wskl],wierz[(wskl-1+k)%k])){
			wskl=(wskl-1+k)%k;
		}
		while(!str(lody[0],wierz[wskl],wierz[(wskl+1+k)%k])){
			wskl=(wskl+1+k)%k;
		}
		//cout<<str(lody[0],wierz[3],wierz[4]);
		//cout<<wierz[3].s-lody[0].s;

		while(str(lody[0],wierz[wskp],wierz[(wskp-1+k)%k])){
			wskp=(wskp-1+k)%k;
		}
		while(str(lody[0],wierz[wskp],wierz[(wskp+1+k)%k])){
			wskp=(wskp+1+k)%k;
		}
		for(int i=0;i<hull.size();++i){
			if(!str(lody[0],wierz[wskl],hull[(i+1)%hull.size()].f)&&str(lody[0],wierz[wskl],hull[i].f))lodl=hull[(i+1)%hull.size()].s;
			if(str(lody[0],wierz[wskp],hull[i].f)&&!str(lody[0],wierz[wskp],hull[(i+1)%hull.size()].f))lodp=hull[i].s;
		}
		//cout<<hull[1].f.f;
		//cout<<str(lody[0],wierz[wskp],hull[0].f);
		//cout<<lodl+1;
		while(!str(lody[lodl],wierz[wskl],wierz[(wskl-1+k)%k])){
			wskl=(wskl-1+k)%k;
		}
		while(!str(lody[lodl],wierz[wskl],wierz[(wskl+1+k)%k])){
			wskl=(wskl+1+k)%k;
		}

		while(str(lody[lodp],wierz[wskp],wierz[(wskp-1+k)%k])){
			wskp=(wskp-1+k)%k;
		}
		while(str(lody[lodp],wierz[wskp],wierz[(wskp+1+k)%k])){
			wskp=(wskp+1+k)%k;
		}
		//cout<<wskl<<" "<<wskp<<endl;
		for(int i=0;i<n;++i){
			if(str(lody[lodl],wierz[wskl],lody[i])==1&&str(lody[lodp],wierz[wskp],lody[i])==0&&str(wierz[wskl],wierz[wskp],lody[i])!=str(wierz[wskl],wierz[wskp],lody[0]))wynik++;
		}
		wynik=n-wynik-1;
		printf("%lld",wynik);
	}

	return 0;
}



/*
9
9 6
8 5
10 8
8 8
-2 3
-1 5
9 1
0 1
-1 2
7
1 1
5 1
8 3
7 5
4 6
0 5
-1 3
*/
