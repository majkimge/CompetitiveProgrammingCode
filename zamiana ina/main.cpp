#include <bits/stdc++.h>
#include <fstream>

using namespace std;

int t,n,od=14000,dok=14600,s,m,a,b,ile;

int main()
{
    FILE *plik;
    FILE *nowy;

    plik = fopen("C:/Users/majkimge/Desktop/str/str1.in", "r");
    nowy = fopen("C:/Users/majkimge/Desktop/str/str3c.in", "w");



    cin>>od;
    cin>>dok;
    cin>>ile;
    fscanf(plik,"%d",&t);
    for(int xd=0;xd<od;++xd){
        fscanf(plik,"%d%d%d",&n,&s,&m);
        for(int i=0;i<n-1;++i){
            fscanf(plik,"%d%d",&a,&b);
        }
        //cout<<n<<endl;
        //cout<<a<<" "<<b<<endl;
    }
    int ilemam=0;
    fprintf(nowy,"%d\n",ile);
    for(int xd=od;xd<dok;++xd){
        if(ilemam==ile)break;
        int czyk=0;
        fscanf(plik,"%d%d%d",&n,&s,&m);
        if(n<51000000){
            czyk=1;
            ++ilemam;
        }
        if(czyk)fprintf(nowy,"%d %d% d\n",n,s,m);

        for(int i=0;i<n-1;++i){
            fscanf(plik,"%d%d",&a,&b);
            if(czyk)fprintf(nowy,"%d %d\n",a,b);
        }
        //cout<<n<<endl;
        //cout<<a<<" "<<b<<endl;
    }
    return 0;
}
