#include <bits/stdc++.h>
#define lld long long
#define MAX 1009
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define INF 1000000000

using namespace std;

int n,wyn,ile;
char t[MAX];
int tab[300][300];
vector<pair<int,int> >v;
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;++i){

            scanf("%s",t);
            for(int j=0;j<n;++j){

            if(t[j]!='.'){
                //cout<<i<<" "<<j<<endl;
            v.pb(mp(i,j));
                tab[102+i][102+j]=1;
                ile++;
            }
        }
    }
    //cout<<endl;
    for(int i=0;i<v.size();++i){
            //cout<<"G";
        for(int j=0;j<v.size();++j){
            for(int z=0;z<v.size();++z){
                if(j!=z&&j!=i&&z!=i){
                        //wyn++;
                    int rozy=v[j].f-v[i].f;
                    int rozx=v[j].s-v[i].s;
                    //cout<<v[i].f<<" "<<v[i].s<<" "<<v[j].f<<" "<<v[j].s<<endl;
                    if(rozx==0&&v[z].s==v[j].s){
                        wyn++;
                    }else if(rozy==0&&v[z].f==v[j].f){
                        wyn++;
                    }else if(v[z].s!=v[j].s&&v[z].f!=v[j].f&&rozx!=0&&rozy!=0){
                        int gcd=__gcd(rozx,rozy);
                        rozx/=gcd;
                        rozy/=gcd;
                        //cout<<rozx<<" "<<rozy<<endl;
                        if(abs(v[z].s-v[i].s)%rozx==0){
                            if(v[z].f==v[i].f+(v[z].s-v[i].s)/rozx*rozy){
                                wyn++;

                            }
                        }
                    }
                }
            }
        }
    }
    printf("%d",(wyn/6));
    return 0;
}
/*
5
..T..
A....
.FE.R
....X
S....
*/
