#include <bits/stdc++.h>
#define lld long long
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define MAX 100009
#define MOD 1000000007
#define RYMC 30

using namespace std;

int t, n, wlen, syllen, words, sent, inter,zmiekcz,ilesamo,ilrymy;
float mean_len, mean_syl, mean_zmiekcz,zmiekcz_in_sen, syl_in_sen;

string s;
int samo[200];
char ss[2];
char rymy[RYMC][3];

int czyl(int ind){
    if((s[ind]>='a'&&s[ind]<='z')||(s[ind]>='A'&&s[ind]<='Z'))return 1;
    return 0;
}

int czyends(int ind){
    if(s[ind]=='.'||s[ind]=='!'||s[ind]=='?')return 1;
    return 0;
}

int czyrym(int gdz, int iter){
    if(rymy[iter][0]==rymy[(gdz+RYMC)%RYMC][0]&&rymy[iter][1]==rymy[(gdz+RYMC)%RYMC][1]&&rymy[iter][2]==rymy[(gdz+RYMC)%RYMC][2])return 1;
    return 0;
}

int main()
{
    scanf("%d",&t);
    samo['a']=1;
    samo['e']=1;
    samo['y']=1;
    samo['u']=1;
    samo['o']=1;
    samo['A']=1;
    samo['E']=1;
    samo['Y']=1;
    samo['U']=1;
    samo['O']=1;
    ifstream myfile ("a.in");

    cin.getline(ss,1);
    for(int xd=0;xd<t;++xd){
        //scanf("%s",s);
        getline(myfile,s);
        n=0;
        while(s[n]||s[n+1]||s[n+2])++n;
        wlen=0;
        syllen=0;
        words=1;
        sent=1;
        inter=0;
        zmiekcz=0;
        ilesamo=0;
        ilrymy=0;
        int iter=0;
        //cout<<n;
        for(int i=0;i<n;++i){
            if(samo[s[i]]){
                syllen++;
                ilesamo++;
            }else if(s[i]=='i'){
                ilesamo++;
                if(i==0||!czyl(i-1)||samo[s[i-1]]||!samo[s[i+1]]){
                    syllen++;
                    if(!samo[s[i-1]])
                    zmiekcz++;
                }else{
                    if(!samo[s[i-1]])
                    zmiekcz++;
                }
            }
            if(czyl(i))wlen++;
            if(s[i]==' '){
                ++words;

            }
            if(czyends(i)){
                ++sent;
                ++inter;
            }
            if(s[i]==','){
                ++inter;
            }
            if(s[i]==','||czyends(i)||s[i]==' '){
                rymy[iter][0]=s[i-3];
                rymy[iter][1]=s[i-2];
                rymy[iter][2]=s[i-1];
                for(int i=1;i<RYMC;++i){

                    if(czyrym(iter+i,iter)){
                        ilrymy++;
                        break;
                    }
                }
                ++iter;
                iter%=RYMC;
            }
        }
        cout<<words<<","<<sent<<","<<inter<<","<<syllen<<","<<zmiekcz<<","<<wlen<<","<<ilrymy;
    }

    return 0;
}
/*
3
Robi go, robi go. XD tez. XDDDDD WF.
*/
