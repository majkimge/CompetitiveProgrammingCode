#include <stdio.h>

using namespace std;
char n;
int i=0;
char word[201];
char temp;
int main()
{
    scanf("%i",&n);
    scanf("%200s",word);
    while(word[i]!='\0'){
        if((word[i]-'A'-n)%26+'A'<'A'){
            word[i]+=26;
        }
        printf("%c",(word[i]-'A'-n)%26+'A');
        i++;
    }
    return 0;
}
