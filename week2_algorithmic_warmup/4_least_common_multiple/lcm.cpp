#include <iostream>
#define ll long long

ll lcm_naive(ll a, ll b) {
  for (long l = 1; l <= (long long) a * b; ++l)
    if (l % a == 0 && l % b == 0)
      return l;

  return (long long) a * b;
}

ll gcd_fast(ll a, ll b) {
  if (a % b == 0)
    return b;
  return gcd_fast(b, a % b);
}

ll lcm_fast(ll a, ll b) {
  return a*b/gcd_fast(a,b);
}

int main() {
  ll a, b;
  std::cin >> a >> b;
  std::cout << lcm_fast(a, b) << std::endl;

  // while (1) {
  //   a = rand()%200+1;
  //   b = rand()%3000+1;
  //   if (lcm_naive(a, b) == lcm_fast(a, b))
  //     std::cout << "okay" << std::endl;
  //   else
  //   {
  //     std::cout << "bad" << std::endl;
  //     std::cout << a << "|" << b << " === " << lcm_naive(a, b) << " | " << lcm_fast(a, b) << std::endl;
  //     break;
  //   }
    
  // }

  return 0;
}
