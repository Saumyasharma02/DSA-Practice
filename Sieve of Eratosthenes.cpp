#include <iostream>
#include <vector>
using namespace std;

void sieveOfEratosthenes(int N) {
    vector<bool> isPrime(N + 1, true); // Create boolean array
    isPrime[0] = isPrime[1] = false;   // 0 and 1 are not prime

    for (int i = 2; i * i <= N; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j <= N; j += i) {
                isPrime[j] = false;  // Mark multiples of i as non-prime
            }
        }
    }

    // Print all prime numbers
    cout << "Prime numbers up to " << N << " are: ";
    for (int i = 2; i <= N; i++) {
        if (isPrime[i]) {
            cout << i << " ";
        }
    }
    cout << endl;
}

int main() {
    int N = 50; // Find all primes up to N
    sieveOfEratosthenes(N);
    return 0;
}
