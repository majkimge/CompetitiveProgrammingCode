#include<bits/stdc++.h>
#define lld long long
#define pb push_back
#define mp make_pair
#define MAX 5000009
#define f first
#define s second
#define INF 1000000000
#define MOD 1000696951
#define MOD1 1000000009

using namespace std;

char tab[MAX];
int n,roz,roz1,pocz;
int uz[30];
int uz1[30];
int wid[30];
int czy;
int wyn;
lld hasz[MAX];
lld tt;
//lld hasz1[MAX];
vector<int> dziel;

lld pot(lld co,lld dok){
    if(dok==0){
        return 1;
    }
    if(dok%2==0){
        lld temp=pot(co,dok/2);
        temp%=MOD;
        return (temp*temp)%MOD;
    }
    lld temp1=pot(co,dok-1);
    temp1%=MOD;
    return (temp1*co)%MOD;
}

lld pot1(lld co,lld dok){
    if(dok==0){
        return 1;
    }
    if(dok%2==0){
        lld temp=pot(co,dok/2);
        temp%=MOD1;
        return (temp*temp)%MOD1;
    }
    lld temp1=pot(co,dok-1);
    temp1%=MOD1;
    return (temp1*co)%MOD1;
}

int main()
{
    scanf("%s",tab);
    while(tab[n]!=0){
        n++;
    }
    for(int i=1;i*i<=n;++i){
        if(n%i==0){
            dziel.pb(i);
            dziel.pb(n/i);
        }
    }

    hasz[1]=(tab[0]-'a'+1)*(tab[0]-'a'+1);
    //hasz1[1]=pot1(31,(tab[0]-'a'));
    for(int i=2;i<=n;++i){
        hasz[i]=((tab[i-1]-'a'+1)*(tab[i-1]-'a'+1)+hasz[i-1])%MOD;
        //hasz1[i]=(pot1(31,(tab[i-1]-'a'))+hasz1[i-1])%MOD1;
    }


    //cout<<pocz;
    sort(dziel.begin(),dziel.end());
    if(n<=0){
        for(int i=0;i<dziel.size();++i){
        if(dziel[i]>=pocz){
            //cout<<"A";
            for(int j=0;j<30;++j){
                uz[j]=0;
                uz1[j]=0;
            }
            for(int j=0;j<dziel[i];++j){
                uz[tab[j]-'a']++;
            }


            czy=1;
            for(int z=1;z<n/dziel[i];++z){
                if(!czy) break;
                for(int j=0;j<30;++j){
                    uz1[j]=0;
                }
                for(int j=0;j<dziel[i];++j){
                    uz1[tab[j+z*dziel[i]]-'a']++;
                }
                /*for(int j=0;j<2;++j){
                    cout<<uz[j];
                }*/

                for(int j=0;j<30;++j){
                    if(uz[j]!=uz1[j]){
                        czy=0;

                        //cout<<"X"<<uz[j]<<j<<uz1[j];
                        break;
                    }
                }
            }
            if(czy){
                wyn=dziel[i];
                break;
            }
        }
    }
    }else{
    for(int i=0;i<dziel.size();++i){
        if(dziel[i]>=pocz){
            //cout<<"A";
            czy=1;
            tt=hasz[dziel[i]];
            //int tt1=hasz1[dziel[i]];
            //cout<<tt;
            for(int j=dziel[i]*2;j<=n;j+=dziel[i]){

                if((hasz[j]-hasz[j-dziel[i]]+MOD)%MOD!=tt/*||(hasz1[j]-hasz1[j-dziel[i]]+MOD1)%MOD1!=tt1*/){
                    czy=0;
                    break;
                }
            }
            if(czy){
                wyn=dziel[i];
                break;
            }
        }
    }
    }

    printf("%d",wyn);
    return 0;
}
