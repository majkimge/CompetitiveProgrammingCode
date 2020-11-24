#include <bits/stdc++.h>
#define lld long long
#define mp make_pair
#define f first
#define s second
#define pb push_back
#define MAX 600009

using namespace std;

int t,n,ost,br,wynik;
char s[MAX];
char s1[MAX];
int mana[MAX];
int dody[MAX];
pair<int,int> tree[MAX*2];
int kk=1;



int main()
{
    scanf("%d",&t);
    for(int xd=0;xd<t;++xd){
        n=0;
        wynik=0;
        ost=0;
        scanf("%s",s);
        while(s[n])++n;

        for(int i=0;i<n;++i){
            s1[i*2]='#';
            s1[i*2+1]=s[i];
        }
        s1[n*2]='#';
        mana[0]=1;
        ost=0;
        br=0;
        for(int i=1;i<=n*2;++i){
            //cout<<s1[i];

                if(br>i)mana[i]=min(mana[ost-i+ost],br-i);
                while(s1[i+mana[i]]==s1[i-mana[i]]){
                    if(s1[i]=='#'&&mana[i]%4==0&&mana[i-mana[i]/2]>=mana[i]/2){
                        wynik=max(wynik,mana[i]);
                    }
                    ++mana[i];
                    if(i-mana[i]<0||i+mana[i]>2*n)break;
                }
                mana[i]--;
                if(mana[i]+i>=br){
                    br=mana[i]+i;
                    ost=i;
                }
        }

        //cout<<endl;
        //for(int i=1;i<=n*2;++i){cout<<mana[i]<<" ";
        //}
        printf("%d\n",wynik);


        for(int i=0;i<=n*2+3;++i)s[i]=s1[i]=mana[i]=0;
        //for(int i=0;i<=2*n+10;++i)tree[i].f=tree[i].s;

    }
    return 0;
}
