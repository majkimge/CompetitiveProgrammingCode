#include <bits/stdc++.h>
#define lld long long
#define MOD 1000696969
#define pb push_back

using namespace std;

char s[1009][59];
int dl[1009];
lld hasze[1009][59];
lld poty[59];
lld n,t;
lld odw[1009];
map<lld,lld> odwhasz;
map<lld,lld> uzhasz;
vector<lld>v;
vector<lld>v1;

int main()
{//cout<<"A";
    scanf("%lld",&t);
    poty[0]=29;
    for(int i=1;i<59;++i){
        poty[i]=poty[i-1]*29;
        poty[i]%=MOD;
    }
    for(int xd=0;xd<t;++xd){
        scanf("%lld",&n);
        for(int i=0;i<n;++i){
            scanf("%s",s[i]);
            while(s[i][dl[i]])dl[i]++;
            hasze[i][0]=s[i][dl[i]-1]-'A'+1;

            for(int j=2;j<=dl[i];++j){
                    //cout<<s[i][dl[i]-j]-'A'+1;
                hasze[i][j-1]=(s[i][dl[i]-j]-'A'+1)*poty[j-1]+hasze[i][j-2];
                hasze[i][j-1]%=MOD;
            }
        }
        //cout<<"A";
        int dd=-1;
        int czy=1;
        int gdz=0;
        int czy1=1;
        int wynik=0;
        while(czy1){
            czy1=0;
            czy=1;
            dd=-1;
            gdz=0;

            while(czy){
                czy=0;
                ++dd;
                for(int i=0;i<n;++i){
                    if(!odw[i]&&!uzhasz[hasze[i][dd]]&&dl[i]>dd){
                        v.pb(hasze[i][dd]);
                        if(odwhasz[hasze[i][dd]]){
                            czy=1;
                            gdz=i;
                            //uzhasz[hasze[i][dd]]=1;
                            break;
                        }
                        odwhasz[hasze[i][dd]]++;
                    }
                }
                for(int i=0;i<v.size();++i){
                    odwhasz[v[i]]=0;
                }
                v.clear();
            }
            dd--;
            //cout<<hasze[0][1]<<" "<<hasze[1][1];
            cout<<gdz<<" "<<dd;
            if(dd>=0){

                for(int i=0;i<n;++i){
                    if(i==gdz||odw[i])continue;
                    if(hasze[i][dd]==hasze[gdz][dd]){
                        czy1=1;
                        odw[i]=odw[gdz]=1;
                        uzhasz[hasze[i][dd]]=1;
                        v1.pb(hasze[i][dd]);
                        wynik+=2;
                        break;
                    }
                }
            }

        }
        printf("Case #%d: %d\n",xd+1,wynik);
        for(int i=0;i<n;++i){
            for(int j=0;j<59;++j){
                s[i][j]=0;
                hasze[i][j]=0;
            }
            dl[i]=0;
            odw[i]=0;
        }
        for(int i=0;i<v1.size();++i){
            uzhasz[v1[i]]=0;
        }
        v1.clear();
    }
    return 0;
}
/*
1
4
BB
A
AA
B
*/
