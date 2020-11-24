#include<bits/stdc++.h>
#define lld long long
#define pb push_back
#define mp make_pair
#define MAX 200009
#define f first
#define s second

using namespace std;

int n,x,y,st,pio,po,co;//co =0 == pion
int tab[MAX];
map<int,int>mpion;
map<int,int>mpoz;
vector<int> pion;
vector<int> poz;
vector<int> mopion[2];
vector<int> mopoz[2];
vector<int> mopion1[374];
vector<int> mopoz1[374];
vector<int> wynpion[374];
vector<int> wynpoz[374];
int dod[MAX];
int uj[MAX];


int main()
{
    scanf("%d",&n);
    if(n<10000){
        for(int i=0;i<n;++i){
        scanf("%d",&tab[i]);
    }
    int kt=0;
    while(kt<n&&tab[kt]==0){
        pio++;
        kt++;
    }
    for(int i=kt;i<n;++i){
        if(tab[i]){
            co=co^1;
        }else{
            int ile=0;
            while(i<n&&tab[i]==0){
                ile++;
                i++;
            }
            i--;
            if(co==1){
                poz.pb(ile);
            }else{
                pion.pb(ile);
            }
        }
    }
    sort(pion.begin(),pion.end());
    sort(poz.begin(),poz.end());

    scanf("%d",&x);
    scanf("%d",&y);
    //cout<<pion.size();
    //cout<<poz.size();
    mpion[pio]=1;

    mpoz[0]=1;

    mopoz[0].pb(0);

    mopion[0].pb(pio);
    int kk=0;
    for(int i=pion.size()-1;i>=0;--i){
            int xd=mopion[kk].size();
            for(int j=0;j<8100;++j){
                dod[j]=0;
                uj[j]=0;
            }
        for(int j=0;j<xd;++j){//cout<<mpion[1];

                //mpion[mopion[j]+pion[i]]=1;
                if((mopion[kk][j]+pion[i]>=0&&dod[mopion[kk][j]+pion[i]]==0)||(mopion[kk][j]+pion[i]<0&&uj[-mopion[kk][j]-pion[i]]==0)){
                    mopion[kk^1].pb(mopion[kk][j]+pion[i]);
                    if(mopion[kk][j]+pion[i]>=0){
                        dod[mopion[kk][j]+pion[i]]=1;
                    }else{
                        uj[-mopion[kk][j]-pion[i]]=1;
                    }
                }

                //cout<<mopion[kk^1][0];

                //mpion[mopion[j]-pion[i]]=1;
                if((mopion[kk][j]-pion[i]>=0&&dod[mopion[kk][j]-pion[i]]==0)||(mopion[kk][j]-pion[i]<0&&uj[-mopion[kk][j]+pion[i]]==0)){

                mopion[kk^1].pb(mopion[kk][j]-pion[i]);
                if(mopion[kk][j]-pion[i]>=0){
                        dod[mopion[kk][j]-pion[i]]=1;
                    }else{
                        uj[-mopion[kk][j]+pion[i]]=1;
                    }
                }

        }
        mopion[kk].clear();
        kk=kk^1;
    }
    int kp=0;
    for(int i=poz.size()-1;i>=0;--i){
            int xd=mopoz[kp].size();
            for(int j=0;j<8100;++j){
                dod[j]=0;
                uj[j]=0;
            }

        for(int j=0;j<xd;++j){
                //cout<<"F";
                //mpoz[mopoz[j]+poz[i]]=1;
                if((mopoz[kp][j]+poz[i]>=0&&dod[mopoz[kp][j]+poz[i]]==0)||(mopoz[kp][j]+poz[i]<0&&uj[-mopoz[kp][j]-poz[i]]==0)){
                mopoz[kp^1].pb(mopoz[kp][j]+poz[i]);//cout<<poz[i]<<" "<<i;
                if(mopoz[kp][j]+poz[i]>=0){
                    dod[mopoz[kp][j]+poz[i]]=1;
                }else{
                uj[-mopoz[kp][j]-poz[i]]=1;
                }
                }

                //mpoz[mopoz[j]-poz[i]]=1;
                if((mopoz[kp][j]-poz[i]>=0&&dod[mopoz[kp][j]-poz[i]]==0)||(mopoz[kp][j]-poz[i]<0&&uj[-mopoz[kp][j]+poz[i]]==0)){
                mopoz[kp^1].pb(mopoz[kp][j]-poz[i]);
                if(mopoz[kp][j]-poz[i]>=0){
                    dod[mopoz[kp][j]-poz[i]]=1;
                }else{
                uj[-mopoz[kp][j]+poz[i]]=1;
                }
                }

        }
        mopoz[kp].clear();
        kp=kp^1;
    }
    //cout<<pio;
    int czypo=0;
    int czypio=0;
    for(int i=0;i<mopoz[kp].size();++i){
        if(mopoz[kp][i]==x||mopoz[kp][i]==-x){
            czypo=1;
        }
    }
    for(int i=0;i<mopion[kk].size();++i){//cout<<mopion[kk][i]<<" ";

        if(mopion[kk][i]==y||mopion[kk][i]==-y){
            czypio=1;
        }
    }
    if(czypo&&czypio){
        printf("TAK");
    }else{
        printf("NIE");
    }
    }else{
        for(int i=0;i<n;++i){
        scanf("%d",&tab[i]);
    }
    int kt=0;
    while(kt<n&&tab[kt]==0){
        pio++;
        kt++;
    }
    for(int i=kt;i<n;++i){
        if(tab[i]){
            co=co^1;
        }else{
            int ile=0;
            while(i<n&&tab[i]==0){
                ile++;
                i++;
            }
            i--;
            if(co==1){
                poz.pb(ile);
            }else{
                pion.pb(ile);
            }
        }
    }
    sort(pion.begin(),pion.end());
    sort(poz.begin(),poz.end());
    int sqrt=1;
    while(sqrt*sqrt<n){
        sqrt++;
    }
    int ktpoz=0;
    int ktpion=0;
    int ss=0;
    int kto=0;
    while(kto<pion.size()){
        while(ss<sqrt){
            mopion1[ktpion].pb(pion[kto]);
            ss+=pion[kto];
            kto++;
        }
        ktpion++;
    }



    int ss=0;
    int kto=0;
    while(kto<poz.size()){
        while(ss<sqrt){
            mopoz1[ktpoz].pb(poz[kto]);
            ss+=poz[kto];
            kto++;
        }
        ktpoz++;
    }


    scanf("%d",&x);
    scanf("%d",&y);
    //cout<<pion.size();
    //cout<<poz.size();
    mpion[pio]=1;

    mpoz[0]=1;

    mopoz[0].pb(0);

    mopion[0].pb(pio);
    int kk=0;
    for(int i=pion.size()-1;i>=0;--i){
            int xd=mopion[kk].size();
            for(int j=0;j<8100;++j){
                dod[j]=0;
                uj[j]=0;
            }
        for(int j=0;j<xd;++j){//cout<<mpion[1];

                //mpion[mopion[j]+pion[i]]=1;
                if((mopion[kk][j]+pion[i]>=0&&dod[mopion[kk][j]+pion[i]]==0)||(mopion[kk][j]+pion[i]<0&&uj[-mopion[kk][j]-pion[i]]==0)){
                    mopion[kk^1].pb(mopion[kk][j]+pion[i]);
                    if(mopion[kk][j]+pion[i]>=0){
                        dod[mopion[kk][j]+pion[i]]=1;
                    }else{
                        uj[-mopion[kk][j]-pion[i]]=1;
                    }
                }

                //cout<<mopion[kk^1][0];

                //mpion[mopion[j]-pion[i]]=1;
                if((mopion[kk][j]-pion[i]>=0&&dod[mopion[kk][j]-pion[i]]==0)||(mopion[kk][j]-pion[i]<0&&uj[-mopion[kk][j]+pion[i]]==0)){

                mopion[kk^1].pb(mopion[kk][j]-pion[i]);
                if(mopion[kk][j]-pion[i]>=0){
                        dod[mopion[kk][j]-pion[i]]=1;
                    }else{
                        uj[-mopion[kk][j]+pion[i]]=1;
                    }
                }

        }
        mopion[kk].clear();
        kk=kk^1;
    }
    int kp=0;
    for(int i=poz.size()-1;i>=0;--i){
            int xd=mopoz[kp].size();
            for(int j=0;j<8100;++j){
                dod[j]=0;
                uj[j]=0;
            }

        for(int j=0;j<xd;++j){
                //cout<<"F";
                //mpoz[mopoz[j]+poz[i]]=1;
                if((mopoz[kp][j]+poz[i]>=0&&dod[mopoz[kp][j]+poz[i]]==0)||(mopoz[kp][j]+poz[i]<0&&uj[-mopoz[kp][j]-poz[i]]==0)){
                mopoz[kp^1].pb(mopoz[kp][j]+poz[i]);//cout<<poz[i]<<" "<<i;
                if(mopoz[kp][j]+poz[i]>=0){
                    dod[mopoz[kp][j]+poz[i]]=1;
                }else{
                uj[-mopoz[kp][j]-poz[i]]=1;
                }
                }

                //mpoz[mopoz[j]-poz[i]]=1;
                if((mopoz[kp][j]-poz[i]>=0&&dod[mopoz[kp][j]-poz[i]]==0)||(mopoz[kp][j]-poz[i]<0&&uj[-mopoz[kp][j]+poz[i]]==0)){
                mopoz[kp^1].pb(mopoz[kp][j]-poz[i]);
                if(mopoz[kp][j]-poz[i]>=0){
                    dod[mopoz[kp][j]-poz[i]]=1;
                }else{
                uj[-mopoz[kp][j]+poz[i]]=1;
                }
                }

        }
        mopoz[kp].clear();
        kp=kp^1;
    }
    //cout<<pio;
    int czypo=0;
    int czypio=0;
    for(int i=0;i<mopoz[kp].size();++i){
        if(mopoz[kp][i]==x||mopoz[kp][i]==-x){
            czypo=1;
        }
    }
    for(int i=0;i<mopion[kk].size();++i){//cout<<mopion[kk][i]<<" ";

        if(mopion[kk][i]==y||mopion[kk][i]==-y){
            czypio=1;
        }
    }
    if(czypo&&czypio){
        printf("TAK");
    }else{
        printf("NIE");
    }
    }

    return 0;
}
