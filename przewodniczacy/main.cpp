#include<bits/stdc++.h>
#define lld long long
#define pb push_back
#define mp make_pair
#define MAX 500009
#define f first
#define s second

using namespace std;

int n,q,x,y;
char tab[MAX];
int sumy[MAX];
int tree[MAX*3];
vector<int> us;

void ustaw(int gdzie,int co){

}
int main()
{
    scanf("%d",&n);
    scanf("%s",tab);
    scanf("%d",&q);
    if(n<3000000&&q<3000000){
        for(int z=0;z<q;++z){
        scanf("%d",&x);
        scanf("%d",&y);
        int s=0;
        int wyn=0;
        for(int i=x-1;i<y;++i){
            if(tab[i]=='C'){
                s++;
            }else{
                s--;
                if(s<0){
                    us.pb(i);
                    s++;
                    wyn++;
                }
            }
        }
        s=0;
        for(int i=y-1;i>=x-1;--i){

            if(tab[i]=='C'){
                s++;
            }else{

                if(!us.empty()&&us[us.size()-1]==i){
                    us.pop_back();
                }else{
                    s--;
                if(s<0){
                    //us.pb(i);
                    s++;
                    wyn++;
                }
                }

            }
        }//cout<<"D";
        us.clear();
        printf("%d\n",wyn);
    }
    }else{
        for(int z=0;z<q;++z){
        scanf("%d",&x);
        scanf("%d",&y);
    }

    return 0;
}
