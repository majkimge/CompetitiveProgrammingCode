#include <bits/stdc++.h>

using namespace std;

int n;
int p[1000];
char s[1000];

int main()
{
    scanf("%d",&n);
    scanf("%s",s);
    for(int i=2;i<n;++i){
        int pref=p[i-1];
        while(pref>0&&s[i]!=s[pref+1]) pref--;
        if(s[pref+1]==s[i]){
            pref++;
        }
        p[i]=pref;
    }
    return 0;
}
