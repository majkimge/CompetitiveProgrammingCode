#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define MAX 10009
#define INF 100000000009
#define llu unsigned long long
#define lld long long

using namespace std;

int p,dl;
char s[59][MAX];
int wyny[59][MAX];

int main()
{
    scanf("%d",&p);
    for(int zz=0;zz<p;++zz){
        scanf("%s",s[zz]);
        dl=0;
        while(s[zz][dl]){
            dl++;
        }
        int ter=1;
        for(int i=dl-1;i>=0;--i){
            //cout<<i;
            char co=s[zz][i];
            wyny[zz][i]=ter;
            i--;

            while(s[zz][i]==co){
                wyny[zz][i]=1;
                i--;
            }
            i++;
            ter=wyny[zz][i]^1;
        }
        if(wyny[zz][0]){
            printf("Ania\n");
        }else{
            printf("Bogdan\n");
        }
    }

    return 0;
}
