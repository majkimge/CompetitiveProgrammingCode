#include <bits/stdc++.h>
#define lld long long
#define pb push_back

using namespace std;

lld n,k,p;
vector<lld> last;
vector<lld> now;

int main()
{
    scanf("%lld",&n);

    for(int i=0;i<n;++i){
        scanf("%lld",&k);
        scanf("%lld",&p);
        last.clear();
        now.clear();
        if(k<=1){
            printf("1\n");
        }else{
            for(int j=2;j<=k;++j){
                last.pb(0);
                last.pb(0);
                for(int i=0;i<6;++i){
                last.pb(1);
            }
            now.pb(0);
            now.pb(0);
            for(int z=2;z<j+3;++z){
                now.pb((last[z]+last[z-1]+last[z-2])%3);
            }
            for(int z=1;z<=k-j;++z){
                cout<<"  ";
            }
            for(int z=1;z<=j;++z){
                now.pb(now[now.size()-z*2]);
            }

            //now.pb(now[now.size()-4]);
            for(int z=2;z<now.size();++z){
                cout<<now[z]<<" ";
            }
            cout<<endl;
            last.clear();
            for(int z=0;z<now.size();++z){
                last.pb(now[z]);
                //cout<<last[z];
            }
            //cout<<endl;
            now.clear();
        }
        printf("%lld\n",last[k-abs(k-p)+2]);

    }
        }

    return 0;
}
