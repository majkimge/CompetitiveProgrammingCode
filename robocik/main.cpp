//Michal Mgeladze-Arciuch
#include <bits/stdc++.h>
#define lld long long
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define MAX 100009
#define MOD 1000000009

using namespace std;

lld n,t,sum,wcykl,wynik,a,b,suma,iler;
lld tab[MAX];
pair<lld,lld> cel;
pair<lld,lld> przes;
pair<lld,lld> gdzie;
lld ilezost;

pair<lld,lld> ruch(pair<lld,lld> gdz,lld dl,lld ilez,lld kier,lld mnoz){
    dl=min(dl,ilez);
    if(kier==(lld)0){
        if(gdz.f==cel.f&&gdz.s<cel.s&&gdz.s+dl>=cel.s) wynik+=mnoz;
        gdz.s+=dl;
    }else if(kier==1){
        if(gdz.s==cel.s&&gdz.f<cel.f&&gdz.f+dl>=cel.f) wynik+=mnoz;

        gdz.f+=dl;//cout<<dl;
    }else if(kier==2){
        if(gdz.f==cel.f&&gdz.s>cel.s&&gdz.s-dl<=cel.s) wynik+=mnoz;
        gdz.s-=dl;
    }else{
        if(gdz.s==cel.s&&gdz.f>cel.f&&gdz.f-dl<=cel.f) wynik+=mnoz;
        gdz.f-=dl;
    }
    ilezost-=(dl+1);
    return gdz;
}

pair<lld,lld> ruchpion(pair<lld,lld> gdz,lld dl,lld ilez,lld kier){
    dl=min(dl,ilez);
    if(kier==(lld)0){
        if(gdz.f==cel.f){
            if(przes.s>(lld)0){
                lld doktpod=(cel.s-gdz.s-dl-1)/przes.s;
                lld odnad=(cel.s-gdz.s)/przes.s+1;
                if(cel.s-gdz.s-dl-1<0) doktpod=-1;
                if(abs(cel.s-gdz.s)%abs(przes.s)==(lld)0) odnad--;
                if(odnad>(lld)0&&doktpod<iler&&(cel.s-gdz.s)>0){
                odnad=min(odnad,iler);

                    wynik+=max((lld)0,odnad-1-max((lld)-1,doktpod));
                }
            }else{
                lld doktpod=-(-cel.s+gdz.s)/przes.s;
                lld odnad=-(-cel.s+gdz.s+dl)/przes.s+1;
				if((-cel.s+gdz.s)<0) doktpod=-1;
                //if(abs(-cel.s+gdz.s+dl)%abs(przes.s)==(lld)0) odnad--;
                if(odnad>(lld)0&&doktpod<iler&&(-cel.s+gdz.s+dl)>=0){
                odnad=min(odnad,iler);

                    wynik+=max((lld)0,odnad-1-max((lld)-1,doktpod));
                }
            }
        }
        gdz.s+=dl;
    }else if(kier==1){

        if(przes.s>(lld)0){
            if(gdz.f<cel.f&&gdz.f+dl>=cel.f){
                if(abs(cel.s-gdz.s)%abs(przes.s)==(lld)0&&cel.s>=gdz.s&&(cel.s-gdz.s)/przes.s<iler) wynik++;
            }
        }else{
            if(gdz.f<cel.f&&gdz.f+dl>=cel.f){
                if(abs(-cel.s+gdz.s)%abs(przes.s)==(lld)0&&cel.s<=gdz.s&&-(-cel.s+gdz.s)/przes.s<iler) wynik++;
            }
        }

        gdz.f+=dl;
    }else if(kier==2){
        if(gdz.f==cel.f){
            if(przes.s>(lld)0){
                lld doktpod=(cel.s-gdz.s)/przes.s;
				if(cel.s-gdz.s<0) doktpod=-1;
                lld odnad=(cel.s-gdz.s+dl)/przes.s+1;
                //cout<<odnad;
                //if(abs(cel.s-gdz.s)%abs(przes.s)==(lld)0) doktpod++;
                if(odnad>(lld)0&&doktpod<iler&&(cel.s-gdz.s+dl)>=0){
                odnad=min(odnad,iler);

                    wynik+=max((lld)0,odnad-1-max((lld)-1,doktpod));
                }
            }else{
                lld doktpod=-(-cel.s+gdz.s-dl-1)/przes.s;
                if((-cel.s+gdz.s-dl-1)<0) doktpod=-1;
                lld odnad=-(-cel.s+gdz.s)/przes.s+1;
                if(abs(-cel.s+gdz.s)%abs(przes.s)==(lld)0) odnad--;

                if(odnad>(lld)0&&doktpod<iler&&(-cel.s+gdz.s)>0){
                odnad=min(odnad,iler);
                    //cout<<gdz.s;
                    //cout<<doktpod;
                    wynik+=max((lld)0,odnad-1-max((lld)-1,doktpod));
                }
            }
        }
        gdz.s-=dl;
    }else{
        if(przes.s>(lld)0){
            if(gdz.f-dl<=cel.f&&gdz.f>cel.f){
                if(abs(cel.s-gdz.s)%abs(przes.s)==(lld)0&&cel.s>=gdz.s&&(cel.s-gdz.s)/przes.s<iler) wynik++;
            }
        }else{
            if(gdz.f-dl<=cel.f&&gdz.f>cel.f){
                if(abs(-cel.s+gdz.s)%abs(przes.s)==(lld)0&&cel.s<=gdz.s&&-(-cel.s+gdz.s)/przes.s<iler) wynik++;
            }
        }
        gdz.f-=dl;
    }
    return gdz;
}

pair<lld,lld> ruchpoz(pair<lld,lld> gdz,lld dl,lld ilez,lld kier){
    dl=min(dl,ilez);
    if(kier==1){
        if(gdz.s==cel.s){
            if(przes.f>(lld)0){
                lld doktpod=(cel.f-gdz.f-dl-1)/przes.f;
                lld odnad=(cel.f-gdz.f)/przes.f+1;
                if((cel.f-gdz.f-dl-1)<0) doktpod=-1;
                if(abs(cel.f-gdz.f)%abs(przes.f)==(lld)0) odnad--;
                if(odnad>(lld)0&&doktpod<iler&&(cel.f-gdz.f)>0){
                odnad=min(odnad,iler);

                    wynik+=max((lld)0,odnad-1-max((lld)-1,doktpod));
                }
            }else{
                lld doktpod=-(-cel.f+gdz.f)/przes.f;
                lld odnad=-(-cel.f+gdz.f+dl)/przes.f+1;
                if((-cel.f+gdz.f)<0) doktpod=-1;
                //if(abs(-cel.s+gdz.s+dl)%abs(przes.s)==(lld)0) odnad--;
                if(odnad>(lld)0&&doktpod<iler&&(-cel.f+gdz.f+dl)>=0){
                    //cout<<doktpod;
                odnad=min(odnad,iler);

                    wynik+=max((lld)0,odnad-1-max((lld)-1,doktpod));
                }
            }
        }
        gdz.f+=dl;
    }else if(kier==(lld)0){
        if(przes.f>(lld)0){
            if(gdz.s<cel.s&&gdz.s+dl>=cel.s){
                if(abs(cel.f-gdz.f)%abs(przes.f)==(lld)0&&cel.f>=gdz.f&&(cel.f-gdz.f)/przes.f<iler) wynik++;
            }
        }else{
            if(gdz.s<cel.s&&gdz.s+dl>=cel.s){
                if(abs(-cel.f+gdz.f)%abs(przes.f)==(lld)0&&cel.f<=gdz.f&&-(-cel.f+gdz.f)/przes.f<iler) wynik++;
            }
        }

        gdz.s+=dl;
    }else if(kier==3){
        if(gdz.s==cel.s){
            //cout<<gdz.s;
            if(przes.f>(lld)0){
                lld doktpod=(cel.f-gdz.f)/przes.f;
                lld odnad=(cel.f-gdz.f+dl)/przes.f+1;
                if((cel.f-gdz.f)<0) doktpod=-1;
                //if(abs(cel.f-gdz.f)%abs(przes.f)==(lld)0) doktpod++;
                if(odnad>(lld)0&&doktpod<iler&&(cel.f-gdz.f+dl)>=0){
                odnad=min(odnad,iler);

                    wynik+=max((lld)0,odnad-1-max((lld)-1,doktpod));
                }
            }else{
                lld doktpod=-(-cel.f+gdz.f-dl-1)/przes.f;
                lld odnad=-(-cel.f+gdz.f)/przes.f+1;
                if((-cel.f+gdz.f-dl-1)<0) doktpod=-1;
                if(abs(-cel.f+gdz.f)%abs(przes.f)==(lld)0) odnad--;
                if(odnad>(lld)0&&doktpod<iler&&(-cel.f+gdz.f)>0){
                odnad=min(odnad,iler);

                    wynik+=max((lld)0,odnad-1-max((lld)-1,doktpod));
                }
            }
        }
        gdz.f-=dl;
    }else{
        if(przes.f>(lld)0){
            if(gdz.s-dl<=cel.s&&gdz.s>cel.s){
                if(abs(cel.f-gdz.f)%abs(przes.f)==(lld)0&&cel.f>=gdz.f&&(cel.f-gdz.f)/przes.f<iler) wynik++;
            }
        }else{
            if(gdz.s-dl<=cel.s&&gdz.s>cel.s){
                if(abs(-cel.f+gdz.f)%abs(przes.f)==(lld)0&&cel.f<=gdz.f&&-(-cel.f+gdz.f)/przes.f<iler) wynik++;
            }
        }
        gdz.s-=dl;
    }
    return gdz;
}

pair<lld,lld> ruchdziw(pair<lld,lld> gdz,lld dl,lld ilez,lld kier){
    dl=min(dl,ilez);
    if(kier==(lld)0){
        if(abs(gdz.f-cel.f)%abs(przes.f)==0&&(gdz.f-cel.f)/przes.f<=(lld)0&&(gdz.f-cel.f)/przes.f>-iler){
            if(gdz.s-przes.s*((gdz.f-cel.f)/przes.f)<cel.s&&gdz.s-przes.s*((gdz.f-cel.f)/przes.f)+dl>=cel.s) wynik++;

        }
        gdz.s+=dl;
    }else if(kier==1){
        if(abs(gdz.s-cel.s)%abs(przes.s)==0&&(gdz.s-cel.s)/przes.s<=(lld)0&&(gdz.s-cel.s)/przes.s>-iler){

            if(gdz.f-przes.f*((gdz.s-cel.s)/przes.s)<cel.f&&gdz.f-przes.f*((gdz.s-cel.s)/przes.s)+dl>=cel.f) wynik++;

        }

        gdz.f+=dl;
    }else if(kier==2){
        if(abs(gdz.f-cel.f)%abs(przes.f)==0&&(gdz.f-cel.f)/przes.f<=(lld)0&&(gdz.f-cel.f)/przes.f>-iler){
            if(gdz.s-przes.s*((gdz.f-cel.f)/przes.f)>cel.s&&gdz.s-przes.s*((gdz.f-cel.f)/przes.f)-dl<=cel.s) wynik++;

        }
        gdz.s-=dl;
    }else{
        //cout<<gdz.;
        if(abs(gdz.s-cel.s)%abs(przes.s)==0&&(gdz.s-cel.s)/przes.s<=(lld)0&&(gdz.s-cel.s)/przes.s>-iler){ //cout<<"A";
            if(gdz.f-przes.f*((gdz.s-cel.s)/przes.s)>cel.f&&gdz.f-przes.f*((gdz.s-cel.s)/przes.s)-dl<=cel.f) wynik++;

        }
        gdz.f-=dl;
    }
    return gdz;
}

int main()
{
    scanf("%lld%lld",&n,&t);
    for(int i=(lld)0;i<n;++i){
        scanf("%d",&tab[i]);
        suma+=tab[i];
    }
    scanf("%lld%lld",&a,&b);
    cel=mp(a,b);
    //cout<<b;
    if(a==b&&a==(lld)0){
        wynik++;
    }
    if(n%4==(lld)0){
        wcykl+=n+suma;

        for(int i=(lld)0;i<n/4;++i){
            przes.s+=(tab[i*4]-tab[i*4+2]);
            przes.f+=(tab[i*4+1]-tab[i*4+3]);
        }
        iler=t/wcykl;
        //cout<<t;
        gdzie=mp((lld)0,(lld)0);
        ilezost=t;
        //cout<<iler;
        //cout<<przes.f;
        if(przes.f==(lld)0&&przes.s==(lld)0){
            for(int i=(lld)0;i<n;++i){
                gdzie=ruch(gdzie,tab[i],ilezost,i%4,iler);
            }
            ilezost=t-iler*wcykl;
            gdzie=mp(iler*przes.f,iler*przes.s);
            for(int i=(lld)0;i<n;++i){
                gdzie=ruch(gdzie,tab[i],ilezost,i%4,1);
            }
        }else if(przes.f==(lld)0){

            for(int i=(lld)0;i<n;++i){
                gdzie=ruchpion(gdzie,tab[i],ilezost,i%4);
            }
            gdzie=mp(iler*przes.f,iler*przes.s);
            ilezost=t-iler*wcykl;
            //cout<<iler;
            for(int i=(lld)0;i<n;++i){
                gdzie=ruch(gdzie,tab[i],ilezost,i%4,1);
            }
        }else if(przes.s==(lld)0){
            for(int i=(lld)0;i<n;++i){
                gdzie=ruchpoz(gdzie,tab[i],ilezost,i%4);
            }
            gdzie=mp(iler*przes.f,iler*przes.s);
            ilezost=t-iler*wcykl;
            for(int i=(lld)0;i<n;++i){
                gdzie=ruch(gdzie,tab[i],ilezost,i%4,1);
            }
        }else{
            for(int i=(lld)0;i<n;++i){
                    //cout<<gdzie.f;
                gdzie=ruchdziw(gdzie,tab[i],ilezost,i%4);
            }
            gdzie=mp(iler*przes.f,iler*przes.s);
            ilezost=t-iler*wcykl;
            for(int i=(lld)0;i<n;++i){
                gdzie=ruch(gdzie,tab[i],ilezost,i%4,1);
            }
        }



    }else{
        wcykl=(lld)4*suma+(lld)4*n;
        iler=t/wcykl;
        gdzie=mp((lld)0,(lld)0);
        ilezost=t;
        for(int i=(lld)0;i<(lld)4*n;++i){
            //cout<<gdzie.f;
            //cout<<tab[i%n];
            gdzie=ruch(gdzie,tab[i%n],ilezost,i%4,iler);
        }
        //cout<<iler;
        ilezost=t-iler*wcykl;
        //cout<<ilezost;
        //cout<<gdzie.f;
        gdzie=mp((lld)0,(lld)0);
        for(int i=(lld)0;i<4*n;++i){
            gdzie=ruch(gdzie,tab[i%n],ilezost,i%4,1);
        }
    }
    printf("%lld",wynik);
    return 0;
}
