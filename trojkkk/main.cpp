#include <bits/stdc++.h>
#define lld long long
#define MOD 1000000007
#define pb push_back

using namespace std;

lld n,suma,wyn;
float a,b,c;
vector<float> v;
map<float,int> m;

int main()
{
    scanf("%lld",&n);
    for(int i=0;i<n;++i){
        scanf("%f",&a);
        scanf("%f",&b);
        scanf("%f",&c);
        if(b==0){

            b=1000000000;
        }
        m[a/b]++;
        //cout<<a;
        if(m[a/b]==1){
            //cout<<"F";
            v.pb(a/b);
        }
        suma++;
    }
    wyn=suma*(suma-1)*(suma-2)/6;
    //cout<<wyn;
    for(int i=0;i<v.size();++i){
           //cout<<v[i];
        wyn-=(lld)m[v[i]]*(m[v[i]]-1)/2*(n-m[v[i]]);
        wyn-=(lld)m[v[i]]*(m[v[i]]-1)*(m[v[i]]-2)/6;
    }
    printf("%lld",wyn%MOD);
    return 0;
}
