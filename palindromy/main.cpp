#include <bits/stdc++.h>
#define lld long long
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define MAX 200009
#define INF 1000000009
#define MOD 1000696969

using namespace std;

int n;
char s[MAX];
int alf[27];
int alfl[27];
int alfp[27];
int czy=0;
int przyps=0;
int sr;
int srod;
int pol=0;
vector<int> lewyp;
vector<int> prawyp;
vector<int> lewyd;
vector<int> prawyd;
vector<int> lewyost;
vector<int> prawyost;
lld lewyc,prawyc,czysr,blok;
lld wynik,kk=1;
priority_queue<int> lit[27];

int tree[600009];

int dod(int l,int p){
    l+=kk;
    p+=kk;
    if(l==p){
        tree[l]++;
    }else{
        tree[l]++;
        tree[p]++;
    }
    while(l/2!=p/2){
        if(l%2==0){
            tree[l+1]++;
        }
        if(p%2==1){
            tree[p-1]++;
        }
        l>>=1;
        p>>=1;
    }

}

int check(int gdzie){
    gdzie+=kk;
    int wyn=0;
    while(gdzie>0){
        wyn+=tree[gdzie];
        gdzie>>=1;
    }
    return wyn;
}

int main()
{
    scanf("%s",s);
    while(s[n]){
        n++;
    }
    while(kk<n){
        kk<<=1;
    }
    for(int i=0;i<n;++i){
        alf[s[i]-'a']++;
    }
    for(int i=0;i<'z'-'a';++i){
        if(alf[i]%2){
            if(czy||n%2==0){
                przyps=1;
                break;
            }else{
                czy=1;
                sr=i;
            }
        }
    }
    if(przyps){
        printf("-1");
    }else{
        if(n%2){
            for(int i=0;i<n/2;++i){
                if(s[n/2-i]-'a'==sr){
                    srod=i;
                    alfl[sr]--;
                    pol=1;
                    break;
                }
                if(s[n/2+i]-'a'==sr){
                    srod=i;
                    alfp[sr]--;
                    break;
                }
            }
        }
        if(n%2&&pol){
            for(int i=0;i<n/2+1;++i){
                alfl[s[i]-'a']++;
            }
            for(int i=n/2+1;i<n;++i){
                alfp[s[i]-'a']++;
            }
        }else{
            for(int i=0;i<n/2;++i){
                alfl[s[i]-'a']++;
            }
            for(int i=n/2;i<n;++i){
                alfp[s[i]-'a']++;
            }
        }

        if(n%2&&pol){
            for(int i=n/2;i>=0;--i){
                if((s[i]-'a'==sr&&czysr)||s[i]-'a'!=sr){
                if(alfl[s[i]-'a']>alf[s[i]-'a']/2){

                        lewyp.pb(s[i]-'a');
                        wynik+=n/2-i-lewyc;
                        //cout<<wynik;
                        lewyc++;
                        alfl[s[i]-'a']--;


                }else{
                    lewyd.pb(s[i]-'a');
                }
                }else{
                    czysr=1;
                }
            }
            for(int i=n/2+1;i<n;++i){
                if(alfp[s[i]-'a']>alf[s[i]-'a']/2){

                        prawyp.pb(s[i]-'a');
                        wynik+=i-n/2-1-prawyc;
                        //cout<<wynik;
                        prawyc++;
                        alfp[s[i]-'a']--;


                }else{
                    prawyd.pb(s[i]-'a');
                }
            }
        }else{
            if(n%2){
                for(int i=n/2-1;i>=0;--i){
                    if(alfl[s[i]-'a']>alf[s[i]-'a']/2){

                            lewyp.pb(s[i]-'a');
                            wynik+=n/2-i-lewyc;
                            lewyc++;
                            alfl[s[i]-'a']--;


                    }else{
                        lewyd.pb(s[i]-'a');
                    }
                }
                for(int i=n/2;i<n;++i){
                    if((s[i]-'a'==sr&&czysr)||s[i]-'a'!=sr){
                    if(alfp[s[i]-'a']>alf[s[i]-'a']/2){

                            prawyp.pb(s[i]-'a');
                            wynik+=i-n/2-prawyc;
                            prawyc++;
                            alfp[s[i]-'a']--;


                    }else{
                        prawyd.pb(s[i]-'a');
                    }
                    }else{
                            czysr=1;
                    }
                }

            }else{
                for(int i=n/2-1;i>=0;--i){
                    if(alfl[s[i]-'a']>alf[s[i]-'a']/2){

                            lewyp.pb(s[i]-'a');
                            wynik+=n/2-i-lewyc;
                            lewyc++;
                            alfl[s[i]-'a']--;


                    }else{
                        lewyd.pb(s[i]-'a');
                    }
                }
                for(int i=n/2;i<n;++i){
                    if(alfp[s[i]-'a']>alf[s[i]-'a']/2){

                            prawyp.pb(s[i]-'a');
                            wynik+=i-n/2-prawyc;
                            prawyc++;
                            alfp[s[i]-'a']--;


                    }else{
                        prawyd.pb(s[i]-'a');
                    }
                }
            }
        }
        //cout<<srod;


        for(int i=lewyd.size()-1;i>=0;--i){
            lewyost.pb(lewyd[i]);
        }
        for(int i=lewyp.size()-1;i>=0;--i){
            prawyost.pb(lewyp[i]);
        }
        blok=lewyp.size();
        for(int i=0;i<prawyp.size();++i){
            lewyost.pb(prawyp[i]);
        }
        for(int i=0;i<prawyd.size();++i){
            prawyost.pb(prawyd[i]);
        }


        if(n%2){
            wynik+=max((lld)srod,blok);

        }
        //cout<<wynik;

        wynik+=blok*blok;
        for(int i=0;i<lewyost.size();++i){

            lit[lewyost[i]].push(i);//cout<<"D";
        }

        for(int i=0;i<prawyost.size();++i){
            int gd=lit[prawyost[i]].top();
            lit[prawyost[i]].pop();
            wynik+=lewyost.size()-1-i-gd+check(gd);
            dod(gd,lewyost.size()-1);
        }
        printf("%lld",wynik);
    }
    return 0;
}
