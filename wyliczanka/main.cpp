#include <bits/stdc++.h>
#define lld long long
#define mp make_pair
#define f first
#define s second
#define pb push_back
#define MAX 1000000

using namespace std;

lld sito[25],n,k;
lld wynik,mod=1,przyps,mod1=1,pocz,mnori=1;
lld odw[25];
lld tab[25];
lld tab1[25];
lld mody[25];
vector<lld> pier;

int main()
{
    sito[2]=1;
    sito[3]=1;
    sito[5]=1;
    sito[7]=1;
    sito[11]=1;
    sito[13]=1;
    sito[17]=1;
    sito[19]=1;
    sito[4]=2;
    sito[8]=2;
    sito[9]=2;
    sito[12]=2;
    sito[16]=2;
    sito[18]=2;
    sito[20]=2;
    scanf("%lld",&n);
    for(lld i=0;i<n;++i){
        scanf("%lld",&tab1[i]);
        tab1[i]--;
        tab[tab1[i]]=i;
    }
    lld temp=(lld)0;
    for(lld i=(lld)0;i<n-1;++i){
        //cout<<temp<<" ";
        lld temod=(lld)0;
        while(temp!=tab[i]){
            if(!odw[temp])++temod;
            temp++;
            temp%=n;

        }
        //cout<<
        mody[n-i]=(temod+(lld)1)%(n-i);
        odw[tab[i]]=(lld)1;
        if(i!=n-(lld)1)
        while(odw[temp]){
            ++temp;
            temp%=n;
        }
    }
    //cout<<mody[20];
    for(lld i=(lld)2;i<=n;++i){
        if(sito[i]==1){
            mod*=i;
            pier.pb(i);
        }
    }
    if(pier.size()>=3){
        mod1=pier[pier.size()-1]*pier[pier.size()-2]*pier[pier.size()-3];
        for(lld i=0;i<mod1;++i){
            if(i%pier[pier.size()-1]==mody[pier[pier.size()-1]]&&i%pier[pier.size()-2]==mody[pier[pier.size()-2]]&&i%pier[pier.size()-3]==mody[pier[pier.size()-3]]){
                pocz=i;
                break;
            }
        }
    }
    if(pocz==0)pocz=mod1;

    for(lld i=pocz;i<=mod;i+=mod1){
        lld czyk=(lld)1;
        //cout<<mody[pier[0]]<<" "<<mod;
        for(lld j=(lld)0;j<pier.size();++j){
            if(i%pier[j]!=mody[pier[j]])czyk=0;
        }
        if(czyk){
            pocz=i;
            break;
        }
    }
    //if(pocz==0)

    for(lld i=(lld)2;i<=n;++i){
        mnori*=(lld)i;
        if(sito[i]==0){
            if(pocz%i!=mody[i]){
                przyps=1;
                //cout<<i<<"X";
            }
        }
    }
    //cout<<przyps<<" "<<mod1;
    if(przyps){
        printf("NIE");
        return 0;
    }
    for(lld i=(lld)2;i<=n;++i){
        if(sito[i]==2){
            lld mnoz=(lld)1;
            while((pocz%i)!=mody[i]&&pocz<=mnori&&pocz>0&&mnoz<(lld)MAX/100){
                pocz+=mod;
                mnoz++;
            }
            if(pocz<=0||pocz>=mnori||mnoz>(lld)MAX/100-4){
                przyps=1;
                break;
            }
            mod*=mnoz;
        }
    }
    if(przyps){
        printf("NIE");
        return 0;
    }
    if(pocz==0){
        printf("%lld",mod);
    }else{
        printf("%lld",pocz);
    }
    return 0;
}
/*
20
20 19 18 17 16 15 14 13 12 11 10 9 8 7 6 5 4 3 2 1
*/
