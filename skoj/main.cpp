#include <bits/stdc++.h>
#define lld long long
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define MAX 2000009
#define INF 1000000009

using namespace std;

int n,a,b,wyn=0;
int kt=1;
int odw[MAX];
int odw1[MAX];
vector<int> dodni[MAX];
//pair<int,int> tab1[MAX];
int m[MAX];

//vector<int> zapy;

int skoj(int from){
      // cout<<from;

        //cout<<from;
        odw[from]=kt;
        for(int i=0;i<dodni[from].size();++i){
            if(m[dodni[from][i]]==-1){
                m[dodni[from][i]]=from;
                wyn++;
                return 1;
            }
        }

        for(int i=0;i<dodni[from].size();++i){
            if(!odw1[from]&&odw[m[dodni[from][i]]]<kt&&skoj(m[dodni[from][i]])){
                m[dodni[from][i]]=from;
                return 1;
            }
        }




    odw1[from]=1;
    return 0;

}

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
