#include <bits/stdc++.h>

#define lld int
#define MAX 1000009
#define f first
#define s second
using namespace std;

lld n, k;
pair<lld,lld> pocz[MAX];
pair<lld,lld> kon[MAX];
lld po,ko,kto,ile=0,wynik=0,maxi=0;
pair<lld,lld> praw[MAX];
lld ppraw[MAX][2];
lld opraw[MAX];
bool podst[MAX];
bool wyw[MAX];
int ktorwpodst[MAX];
int pier,ost;
int odost=0;
vector<lld> needed;
vector<int> oneeded;
int tempo,tempo1;
bool compare(const pair<lld, lld>&i, const pair<lld, lld>&j)
{
    return i.first < j.first;
}

int main()
{

    scanf("%i",&n);
    scanf("%i",&k);
    for(int i=0;i<k;++i){
        ppraw[i][0]=-1;
        needed.push_back(i);
        oneeded.push_back(i);
    }
    for(int i=0;i<n;++i){
        scanf("%i",&po);

        scanf("%i",&ko);
        pocz[i]=make_pair(po,i);
        kon[i]=make_pair(ko,i);
    }
    sort(&pocz[0],&pocz[n],compare);
    sort(&kon[0],&kon[n],compare);
    lld y=0;
    lld z=0;
    while(y<=n-k||z<=n-k){
        if(ile<=k){
            if(pocz[y].f<=kon[z].f&&y!=n){

                ile++;

                    if(!needed.empty()){
                        if(needed.size()==1){
                            ost=pocz[y].f;
                        }
                        tempo=needed.size();
                        ktorwpodst[pocz[y].s]=needed[tempo-1];
                        ppraw[needed[tempo-1]][0]=pocz[y].s;
                        ppraw[needed[tempo-1]][1]=y;
                        podst[pocz[y].s]=true;
                        needed.pop_back();
                    }
                if(ile>=k){
                    wynik=pocz[y].f-ost;
                    if(wynik>maxi){
                        maxi=wynik;
                        while(!oneeded.empty()){
                            opraw[oneeded[oneeded.size()-1]]=ppraw[oneeded[oneeded.size()-1]][0];
                            oneeded.pop_back();
                        }
                    }
                }
                y++;
            }else if(pocz[y].f>kon[z].f||y==n){
                if(ile>=k){
                    wynik=kon[z].f-ost;
                    if(wynik>maxi){
                        maxi=wynik;
                        while(!oneeded.empty()){
                            opraw[oneeded[oneeded.size()-1]]=ppraw[oneeded[oneeded.size()-1]][0];
                            oneeded.pop_back();
                        }
                    }
                }
                wyw[kon[z].s]=true;
                ile--;


                if(podst[kon[z].s]){
                    needed.push_back(ktorwpodst[kon[z].s]);
                    oneeded.push_back(ktorwpodst[kon[z].s]);
                }
            z++;
            }
        }else{
            if(pocz[y].f<=kon[z].f&&y!=n){
                ile++;
                wynik=pocz[y].f-ost;
                if(wynik>maxi){
                        maxi=wynik;
                        while(!oneeded.empty()){
                            opraw[oneeded[oneeded.size()-1]]=ppraw[oneeded[oneeded.size()-1]][0];
                            oneeded.pop_back();
                        }
                    }
                    y++;
            }else if(pocz[y].f>kon[z].f||y==n){
                 wynik=kon[z].f-ost;
                    if(wynik>maxi){
                        maxi=wynik;
                        while(!oneeded.empty()){
                            opraw[oneeded[oneeded.size()-1]]=ppraw[oneeded[oneeded.size()-1]][0];
                            oneeded.pop_back();
                        }
                    }
                    if(podst[kon[z].s]){

                    if(ppraw[ktorwpodst[kon[z].s]][1]>=odost){

                    for(int ps=ppraw[ktorwpodst[kon[z].s]][1]+1;ps<n;++ps){

                        if(!wyw[pocz[ps].s]&&!podst[pocz[ps].s]){

                            tempo1=ktorwpodst[kon[z].s];
                            ktorwpodst[pocz[ps].s]=tempo1;
                            ppraw[tempo1][0]=pocz[ps].s;
                            ppraw[tempo1][1]=ps;
                            podst[pocz[ps].s]=true;
                            ost=pocz[ps].f;
                            oneeded.push_back(tempo1);
                            odost=ps;
                            break;
                        }

                    }
                    }else{
                        for(int ps=odost+1;ps<n;++ps){

                        if(!wyw[pocz[ps].s]&&!podst[pocz[ps].s]){

                            tempo1=ktorwpodst[kon[z].s];
                            ktorwpodst[pocz[ps].s]=tempo1;
                            ppraw[tempo1][0]=pocz[ps].s;
                            ppraw[tempo1][1]=ps;
                            podst[pocz[ps].s]=true;
                            ost=pocz[ps].f;
                            oneeded.push_back(tempo1);
                            odost=ps;
                            break;
                        }

                        }
                    }
                    wyw[kon[z].s]=true;
                    ile--;
                    z++;
                }else{
                    ile--;
                    wyw[kon[z].s]=true;
                    z++;
                }
            }
        }

    }
    printf("%i\n",maxi);
    for(int i=0;i<k;++i){
        printf("%i ",opraw[i]+1);
    }
    return 0;
}
