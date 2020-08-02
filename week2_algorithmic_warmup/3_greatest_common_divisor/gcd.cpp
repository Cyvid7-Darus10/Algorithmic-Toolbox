#include <iostream>

int gcd_naive(int a, int b) {
  int current_gcd = 1;
  for (int d = 2; d <= a && d <= b; d++) {
    if (a % d == 0 && b % d == 0) {
      if (d > current_gcd) {
        current_gcd = d;
      }
    }
  }
  return current_gcd;
}

int gcd_fast(int a, int b) {
  if (a % b == 0)
    return b;
  return gcd_fast(b, a % b);
}

int main() {
  int a, b;
  std::cin >> a >> b;
  std::cout << gcd_fast(a, b) << std::endl;

  // while (1) {
  //   a = rand()%200011+1;
  //   b = rand()%3000+1;
  //   if (gcd_naive(a, b) == gcd_fast(a, b))
  //     std::cout << "okay" << std::endl;
  //   else
  //   {
  //     std::cout << "bad" << std::endl;
  //     std::cout << a << "|" << b << " === " << gcd_naive(a, b) << " | " << gcd_fast(a, b) << std::endl;
  //     break;
  //   }
    
  // }

  return 0;
}
