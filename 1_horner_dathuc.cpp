
#include <bits/stdc++.h>
using namespace std;

double
horner (double poly[], int n, double x)
{
  double result = poly[0];
  for (int i = 1; i < n; i++)
    {
      result = result * x + poly[i];
    }
  return result;
}

int
main ()
{
  double poly[] = { 2, -6, 2, -1 };
  int n = sizeof (poly) / sizeof (poly[0]);
  double x = 3;
  double result = horner (poly, n, x);
  cout << "The value of polynomial at x = " << x << " is: " << result << endl;
  return 0;
}
