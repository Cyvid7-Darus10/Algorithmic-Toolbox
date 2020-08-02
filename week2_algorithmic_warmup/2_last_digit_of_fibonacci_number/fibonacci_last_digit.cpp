#include <iostream>

long long get_fibonacci_last_digit_naive(int n) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;

    for (int i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = (tmp_previous + current)% 10;
    }

    return current;
}

int get_fibonacci_last_digit_fast(int n) {
    n %= 60;
    if (n <= 1) return n;

    int prev = 0;
    int cur = 1;
    int copyP;
    int sum = 0;
    for(int i = 1; i < n; i++) {
        copyP = prev;
        prev = cur;
        cur = (copyP + cur)%10;
    }
    
    return cur;
}

int main() {
    int n;
    std::cin >> n;
    int c = get_fibonacci_last_digit_fast(n);
    std::cout << c << '\n';
    
    // while (1) {
    //     n = rand() % 1000000000 + 1;
    //     if (get_fibonacci_last_digit_naive(n) == get_fibonacci_last_digit_fast(n))
    //         std::cout << n <<" <- okay" << std::endl;
    //     else
    //     {
    //         std::cout << "bad" << std::endl;
    //         std::cout << n << " === " << get_fibonacci_last_digit_naive(n) <<  "||" << get_fibonacci_last_digit_fast(n);
    //         break;
    //     }
        
    // }
    
}
