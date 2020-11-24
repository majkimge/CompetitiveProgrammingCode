#include <bits/stdc++.h>
#define lld long long
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define MAX 20009
#define INF 1000000
#define MOD 1000000009

using namespace std;

double n;

pair<lld,lld> zaok(double x){
    lld dl=0;
    lld temp=(lld)floor(x);
    while(temp>0){
        dl++;
        temp=temp/10;
    }

    double temp1=x;
    int dl1=dl;
    while(6-dl1!=0){
        temp1*=10;
        dl1++;
    }//cout<<"A";
    temp1*=10;
    temp=(lld)floor(temp1);
    if(temp%10<5){
        temp=temp/10;
    }else{
        temp=temp/10+1;
    }
    //cout<<dl<<endl;
    return mp(temp,dl);
}

int main()
{
    n=1.000030;
    lld wyn=0;

    while(true){
        n=sqrt(n);
        //cout<<n<<endl;
        //system("pause");
        wyn++;//cout<<zaok(n).f<<endl;   //cout<<"A";
        if(zaok(n).f==100000){
            break;
        }
        lld xx=zaok(n).s;
        n=(double)zaok(n).f;
        //cout<<n<<endl;



        for(int i=6;i>xx;--i){
            n=n/10;
        }
        //cout<<xx<<endl;
    }
    cout<<wyn;
    return 0;
}
