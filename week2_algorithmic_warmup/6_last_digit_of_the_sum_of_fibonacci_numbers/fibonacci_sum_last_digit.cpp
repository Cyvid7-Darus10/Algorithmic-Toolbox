#include <iostream>

#define ll long long

int fibonacci_sum_naive(ll n) {
    if (n <= 1)
        return n;

    int previous = 0;
    int current  = 1;
    int sum      = 1;
    int tmp_previous;

    for (int i = 0; i < n - 1; i++) {
        tmp_previous = previous;
        previous = current;
        current = (tmp_previous + current) % 10;
        sum += current;
        sum %=  10;
    }

    return sum;
}

int fibonacci_sum_fast(ll n) {
    n %= 60;
    if (n <= 1)
        return n;

    ll previous = 0, current  = 1, sum = 1, tmp_previous;
    
    for (ll i = 0; i < n - 1; ++i) {
        tmp_previous = previous;
        previous = current;
        current = (tmp_previous + current) % 10;
        sum += current;
        sum %= 10;
    }

    return sum;
}

int main() {
    ll n = 0;
    std::cin >> n;
    std::cout << fibonacci_sum_fast(n);
    // while(1){
    //     n = rand() %100;

    //     if(fibonacci_sum_naive(n) == fibonacci_sum_fast(n))
    //         std::cout << "Right!" << std::endl;
    //     else{
    //         std::cout << "wrong!";
    //         break;
    //     }
    // }
}
