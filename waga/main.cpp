#include <bits/stdc++.h>

#define lld long long
#define mp make_pair
#define f first
#define s second
#define pb push_back

using namespace std;

lld n,l,p,temp,sumal,sumap;
vector<lld> lewe;
vector<lld>prawe;
char moc[1000][1000];

void zlicz(){
    int i=1000;
    bool czy;
    moc[0][0]='3';
    moc[0][1]='a';
    for(int i=0;i<=190;++i){
            czy=0;
        int j=0;
        char temp[200];
        for(int z=0;z<200;++z){
            temp[z]=0;
        }
        lld pl=0;
        j=190;
        while(moc[i][j]!='a'){
            j--;
        }
        j--;
        lld l=j;
        while(j>=0){
            temp[l-j]=(char)((((lld)(moc[i][j])-48)*3+pl)%10+48);
            pl=(((lld)(moc[i][j])-48)*3+pl)/10;
            if(j==0){
                temp[l-j+1]=(char)(pl+48);
                if(temp[l-j+1]!='0'){
                    czy=1;
                }
                temp[l-j+2]='a'
            }
            j--;
        }
        lld k;
        if(czy){
            k=l-j+1
        }else{
            k=l-j;
        }
        lld w=k;
        while(k>=0){
            moc[i+1][w-k]=temp[k];
            k--;
        }
        moc[i+1][w+1]='a';
    }
}

int main()
{
    scanf("%lld",&n);
    while(n>0){
        if(n%3==1){
            p++;
            prawe.pb(pow(3,temp));
            n=n/3;
        }else if(n%3==2){
            l++;
            lewe.pb(pow(3,temp));
            n++;
            n=n/3;
        }else{
        n=n/3;
        }
        temp++;
    }
    printf("%lld ",l);
    for(lld i=0;i<lewe.size();++i){
            sumal+=lewe[i];
        printf("%lld ",lewe[i]);
    }
    printf("\n%lld ",p);
    for(lld i=0;i<prawe.size();++i){
        printf("%lld ",prawe[i]);
    sumap+=prawe[i];
    }
    cout<<sumal<<endl<<sumap;
    return 0;
}
