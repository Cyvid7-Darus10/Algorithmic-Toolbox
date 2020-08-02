#include <iostream>

#define ll long long

ll get_fibonacci_huge_naive(ll n, ll m) {
    if (n <= 1)
        return n;

    ll previous = 0;
    ll current  = 1;

    for (ll i = 0; i < n - 1; ++i) {
        ll tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }

    return current % m;
}


ll get_fibonacci_huge_fast(ll n, ll m) {
    int pisano = 1;

    ll prev2 = 0;
    ll cur2 = 1;
    ll copyP2; 
    //Look for the Pisano number
    for (ll i = 1; i < m*m; i++) {
        copyP2 = prev2;
        prev2 = cur2;
        cur2 = (copyP2 + prev2)%m;
        if (cur2 == 1 && prev2 == 0) //the pisano ends when the sequence starts with 1 and
            break;                  //prev is 0
        else
            pisano++;
    }

    n %= pisano;

    if (n <= 1) return n;
    
    prev2 = 0;
    cur2 = 1; 
    copyP2;

    for(ll i = 1; i < n; i++) {
        copyP2 = prev2;
        prev2 = cur2;
        cur2 = (copyP2 + cur2) % m;
    }
    
    return cur2;
}

int main() {
    ll n, m;
    std::cin >> n >> m;
    std::cout << get_fibonacci_huge_fast(n, m) << '\n';
}
