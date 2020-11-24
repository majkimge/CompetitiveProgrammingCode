#include <bits/stdc++.h>
#define lld long long
#define MAX 100009
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define INF 1000000000
#define MOD 1000696969

using namespace std;

double tab[4];
vector<complex<double> >vect;

void fft(vector<complex<double> >&x){//cout<<"F";
    if(x.size()<=1){
        return;
    }

    vector<complex<double> > even;
    for(int i=0;i<x.size();i+=2){
        even.pb(x[i]);
    }
    vector<complex<double> > odd;
    for(int i=1;i<x.size();i+=2){
        odd.pb(x[i]);
    }
    fft(even);
    fft(odd);

    for(int i=0;i<x.size()/2;++i){
        complex<double>  t=polar(1.0,M_PI*2/x.size()*i)*odd[i];
        x[i]=even[i]+t;
        x[i+x.size()/2]=even[i]-t;
    }
}

void ifft(vector<complex<double> >&x){
    for(int i=0;i<x.size();++i){
        complex<double> temp(real(x[i]),-imag(x[i]));
        x[i]=temp;
    }
    fft(x);
    for(int i=0;i<x.size();++i){
        complex<double> temp(real(x[i]),-imag(x[i]));
        x[i]=temp;
    }
    for(int i=0;i<x.size();++i){
        x[i]/=x.size();
    }
}

int main()
{
    for(int i=0;i<4;++i){
        scanf("%lf",&tab[i]);

    }
    for(int i=0;i<4;++i){
        complex<double> temp(tab[i],0.0);
        vect.pb(temp);//cout<<"F";

    }
    fft(vect);

    ifft(vect);
    for(int i=0;i<4;++i){
        cout<<real(vect[i])<<" "<<imag(vect[i])<<endl;
    }
    return 0;
}
