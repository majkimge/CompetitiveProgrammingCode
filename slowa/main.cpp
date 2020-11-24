#include <bits/stdc++.h>

#define lld long long
#define MAX 1000009
using namespace std;

lld n,m;
//string s,inv;
char s1[MAX];
lld tab[MAX][2];
int main()
{
    ios_base::sync_with_stdio(0);
    cin>>s1;
    cin>>m;
    cin>>n;
    char s[n];
    for(int i=0;i<n;++i){
        s[i]=s1[i];
    }
    for(int i=0;i<m;++i){
        cin>>tab[i][0];
        cin>>tab[i][1];
    }
    for(int j=0;j<m;++j){
        for(int z=n-1-(tab[j][1]-tab[j][0]+1);z>tab[j][1]-1;--z){
            s[z+(tab[j][1]-tab[j][0]+1)]=s[z];

        }
        for(int i=tab[j][1]-1;i>=tab[j][0]-1;--i){
            s[i+(tab[j][1]-1-i)*2+1]=s[i];
            //cout<<"z";
        }
    }
    for(int i=0;i<n;++i){
        cout<<s[i];
    }


    return 0;
}
