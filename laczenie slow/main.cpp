#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define lld long long
#define MOD 1000000007


using namespace std;

lld z,ile;
char s[10][1000009];

int main()
{
    scanf("%lld",&z);
    for(int xx=0;xx<z;++xx){
        scanf("%s",&s[xx][0]);
        lld dl=0;
        ile=1;
        while(s[xx][dl]!=0){
            dl++;
        }

        for(int i=1;i<dl-3;++i){
            if(s[xx][i]=='k'&&s[xx][i+1]=='o'&&s[xx][i+2]=='t'){
                lld temp=i+3;
                lld n=1;
                lld t=1;
                lld ss=2;

                while(s[xx][temp]=='k'&&s[xx][temp+1]=='o'&&s[xx][temp+2]=='t'&&temp<dl-3){
                    t=n; //cout<<"G";
                    n=ss;
                    ss=t+n;
                    t%=MOD;
                    n%=MOD;
                    ss%=MOD;
                    temp+=3;
                }
                ss%=MOD;
                ile*=ss;
                ile%=MOD;
                i=temp;
            }
        }
        printf("%lld\n",(ile)%MOD);
    }
    return 0;
}
