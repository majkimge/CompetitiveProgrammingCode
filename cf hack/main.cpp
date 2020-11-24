#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(void)
{
  ll l = 0, r = 0;
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  l = a * 2 + b + c;
  r = b + c + d * 2;
  if (a == 0 && a == b && b == c && c == d)
    puts("1");
  else if (r == l)
  {
    if (c != 0 && (a == 0 || d == 0))
      puts("0");
    else
      puts("1");
  }
  else
    puts("0");
  // system("pause");
  return 0;
}
