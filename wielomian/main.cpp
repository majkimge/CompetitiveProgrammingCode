#include <bits/stdc++.h>
#define mp make_pair
#define f first
#define s second
#define pb push_back
#define MAX 3000000
#define lld long long


using namespace std;

lld tt[MAX],sum;
lld poty[MAX*2];
vector<lld>tab;
lld n,m,q;

void fft(vector<lld > &x,lld kt){
    int N=x.size();
    if(N<=1)return ;

    vector<lld>even;
    vector<lld>odd;
    for(int i=0;i<N;++i){
        if(i%2==0){
            even.pb(x[i]);
        }else{
            odd.pb(x[i]);
        }
    }

    fft(even,(kt*2)%n);
    fft(odd,(kt*2)%n);

    //if(N==4)cout<<even[1]<<" "<<odd[1]<<endl;
    for(int i=0;i<N/2;++i){
        //lld t=polar(1.0,-2*i*M_PI/N)*odd[i];
        x[i]=even[i]+poty[(i*kt)%n]*odd[i];
        x[i+N/2]=even[i]+poty[((i+N/2)*kt)%n]*odd[i];
        x[i]%=m;
        x[i+N/2]%=m;
    }
}

/*void ifft(vector<complex<double> > &x){
    int N=x.size();
    for(int i=0;i<N;++i){
        x[i]=conj(x[i]);
    }
    fft(x);
    for(int i=0;i<N;++i){
        x[i]=conj(x[i]);
        x[i]=x[i]/(complex<double>)N;
    }

}*/



int main()
{
    scanf("%lld%lld%lld",&n,&m,&q);
    for(int i=0;i<n;++i){
        scanf("%lld",&tt[i]);
        tab.pb(tt[i]);
    }
    poty[0]=1;
    for(int i=1;i<n*2;++i){
        poty[i]=poty[i-1]*q;
        poty[i]%=m;
    }
    fft(tab,1);
    for(int i=0;i<n;++i){
        sum+=tab[i];
        sum%=m;
    }
    printf("%lld\n",sum);
    for(int i=1;i<=n;++i){
        printf("%lld ",tab[(i)%n]);
    }
    /*ifft(tab);
    for(int i=0;i<n;++i){
        cout<<tab[i];
    }*/
    return 0;
}
