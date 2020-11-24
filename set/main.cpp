#include <bits/stdc++.h>
#define lld long long
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define MAX 100009

using namespace std;

set<int> s;

int main()
{
    s.insert(4);
    cout<<"Begin "<<*s.begin()<<endl;
    cout<<"End "<<*s.end()<<endl;
    cout<<"End -1 "<<*--s.end()<<endl;
    cout<<"upper bigger "<<*s.upper_bound(4)<<endl;
    return 0;
}
