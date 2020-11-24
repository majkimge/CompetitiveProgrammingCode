#include <bits/stdc++.h>
#define lld long long
#define pb push_back
#define MAX 3000009
#define pii pair<int,int>
#define mp make_pair
#define f first
#define s second

using namespace std;

deque<pii> miny;
deque<pii> maxy;
int n,t,pocz,kon;
int tab[MAX];
int wynik;

void rozsz(){
    while(!maxy.empty()&&maxy.back().f<=tab[kon]){
        maxy.pop_back();
    }
    maxy.push_back(mp(tab[kon],kon));

    while(!miny.empty()&&miny.back().f>=tab[kon]){
        miny.pop_back();
    }
    miny.push_back(mp(tab[kon],kon));

}

void skroc(){
    while(!maxy.empty()&&maxy.front().s<pocz){
        maxy.pop_front();
    }
    while(!miny.empty()&&miny.front().s<pocz){
        miny.pop_front();
    }
}

int main()
{
    scanf("%d%d",&t,&n);
    for(int i=0;i<n;++i){
        scanf("%d",&tab[i]);
    }
    rozsz();
    while(kon<n){
        while(kon<n&&maxy.front().f-miny.front().f<=t){
            kon++;
            rozsz();
        }
        if(maxy.front().f-miny.front().f<=t){
            wynik=max(wynik,kon-pocz);
        }else{
            wynik=max(wynik,kon-pocz);
        }
        while(maxy.front().f-miny.front().f>t){
            pocz++;
            skroc();
        }
    }
    printf("%d",wynik);
    return 0;
}
