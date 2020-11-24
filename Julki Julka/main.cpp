#include <bits/stdc++.h>
#define mp make_pair
#define f first
#define s second
#define pb push_back
#define MAX 200009
#define lld long long
#define MOD 1009

using namespace std;

int n,m,k;
int tab[MAX];
int ile[MAX];
int pref[MAX];
lld liczek=0;
lld liczek1=0;
vector<complex<double> >wynik;
vector<int> roz;
int odw[MAX];

void fft(vector<complex<double> > &x){


}

void ifft(vector<complex<double> > &x){


}

void rob(int l, int p, vector<complex<double> >&x){
    if(l==p){
        for(int i=0;i<=ile[l];++i){
            x.pb(1.000000000);
            //liczek++;
        }
        return;
    }
    //liczek++;
    vector<complex<double> > lew;
    vector<complex<double> > praw;
    rob(l,(l+p)/2,lew);
    rob((l+p)/2+1,p,praw);

    //int ilel=min(k+1,pref[(l+p)/2]-pref[l-1]);
    //int ilep=min(k+1,-pref[(l+p)/2]+pref[p]);
    int maxi=pref[p]-pref[l-1];
    int kl=1;
    while(kl<maxi+1)kl<<=1;
    //kl<<=1;
    //kl<<=1;


    //vector<double>wyn;
    for(int i=0;i<kwyn;++i){
            //liczek++;
        if(i<lew.size()&&i<praw.size()){
            x.pb(lew[i]*praw[i]);
            //liczek++;
        }else{
            x.pb(0);
            //liczek++;
        }
    }
    lew.clear();
    praw.clear();
    ifft(x);
    //cout<<l<<" "<<p<<" ";

    for(int i=0;i<x.size();++i){
        int temp=(int)ceil(real(x[i])-0.2);
        //liczek++;
        temp%=MOD;

        x[i]=(complex<double>)temp;
        //cout<<x[i]<<" ";
    }
    //cout<<endl;
}

int main()
{
    scanf("%d%d%d",&n,&m,&k);
    srand(time(0));
    for(int i=0;i<n;++i){
        //scanf("%d",&tab[i]);
        ile[rand()%m+1]++;
    }
    for(int i=1;i<=m;++i){
        pref[i]=pref[i-1]+ile[i];
    }
    int kk=1;
    //while(kk<m)kk<<=1;
    rob(1,m,wynik);
    printf("%d\n",(int)ceil(real(wynik[k])-0.2));
    cout<<liczek;
    return 0;

}
/*
12 4 4
1 2 3 1 2 3 1 2 3 1 2 3

200000 200000 200000
*/
