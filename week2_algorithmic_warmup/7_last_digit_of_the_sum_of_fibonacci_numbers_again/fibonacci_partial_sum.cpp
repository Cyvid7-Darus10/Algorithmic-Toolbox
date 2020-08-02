#include <iostream>
#include <vector>
using std::vector;

long long get_fibonacci_partial_sum_naive(long long from, long long to) {
    long long sum = 0;

    long long current = 0;
    long long next  = 1;

    for (long long i = 0; i <= to; ++i) {
        if (i >= from) {
            sum += current;
        }

        long long new_current = next;
        next = next + current;
        current = new_current;
    }

    return sum % 10;
}

long long get_fibonacci_partial_sum_fast(long long from, long long to) {
    to %= 60;
    from %= 60;
    long long sum = 0;

    if(to < from)
        to += 60;

    long long current = 0;
    long long next  = 1;

    for (long long i = 0; i <= to; ++i) {
        if (i >= from) {
            sum += current;
            sum %= 10;
        }

        long long new_current = next;
        next = (next + current)%10;
        current = new_current;
    }

    return sum;
}

int main() {
    long long from, to;
    std::cin >> from >> to;
    std::cout << get_fibonacci_partial_sum_fast(from, to) << '\n';
    // while(1) {
    //     from = rand()%100 + 1;
    //     to = rand()%1000000 + 1;
    //     if (get_fibonacci_partial_sum_fast(from, to) == get_fibonacci_partial_sum_naive(from, to)) 
    //         std::cout << from << "|" << to << " - right!" << std::endl;
    //     else
    //     {
    //         std::cout << from << "|" << to << " - wrong! " << get_fibonacci_partial_sum_fast(from, to) << "|" << get_fibonacci_partial_sum_naive(from, to) <<  std::endl;
    //         break;
    //     }
        
    // }
}
