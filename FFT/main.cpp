#include <bits/stdc++.h>
#define mp make_pair
#define f first
#define s second
#define pb push_back
#define MAX 1000000
#define lld long long


using namespace std;

int tt[MAX];
vector<complex<double> >tab;
lld n;

void fft(vector<complex<double> > &x){
    int N=x.size();
    if(N<=1)return ;

    vector<complex<double> >even;
    vector<complex<double> >odd;
    for(int i=0;i<N;++i){
        if(i%2==0){
            even.pb(x[i]);
        }else{
            odd.pb(x[i]);
        }
    }

    fft(even);
    fft(odd);

    for(int i=0;i<N/2;++i){
        complex<double> t=polar(1.0,-2*i*M_PI/N)*odd[i];
        x[i]=even[i]+t;
        x[i+N/2]=even[i]-t;
    }
}

void ifft(vector<complex<double> > &x){
    int N=x.size();
    for(int i=0;i<N;++i){
        x[i]=conj(x[i]);
    }
    fft(x);
    for(int i=0;i<N;++i){
        x[i]=conj(x[i]);
        x[i]=x[i]/(complex<double>)N;
    }

}



int main()
{
    scanf("%lld",&n);
    for(int i=0;i<n;++i){
        scanf("%d",&tt[i]);
        tab.pb((double)tt[i]);
    }
    fft(tab);
    for(int i=0;i<n;++i){
        cout<<tab[i];
    }
    ifft(tab);
    for(int i=0;i<n;++i){
        cout<<tab[i];
    }
    return 0;
}
