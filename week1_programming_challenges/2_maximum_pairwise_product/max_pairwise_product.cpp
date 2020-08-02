#include <iostream>
#include <vector>
#include <algorithm>

long long MaxPairwiseProduct(const std::vector<int>& numbers) {
    long long int first = numbers[0], second = numbers[1];
    int n = numbers.size();
    long long int maxPair;

    if (second > first)
	   std::swap(second,first);

    //First, set first to be the biggest number between index 1 and 0
/*    if (numbers[0] > numbers[1]) {
        first = numbers[0];
        second = numbers[1];
    } else {
        first = numbers[1];
        second = numbers[0];
    }
*/
    //compare the each numbers in the vector one by one with first
    //if the number is less than first, compare it to second, move on
    for (int i = 2; i < n; i++) {
        if(numbers[i] >= first) {
            second = first;
            first = numbers[i];
        } else if (numbers[i] > second) {
         second = numbers[i];
        }
    }

    return maxPair = first * second;
}

int main() {
    int n;
    std::cin >> n;
    std::vector<int> numbers(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> numbers[i];
    }

    std::cout << MaxPairwiseProduct(numbers) << std::endl;
    return 0;
}
