//Prime Pairs With Target Sum
class Solution {
public:
    vector<vector<int>> findPrimePairs(int n) 
    {
        vector<bool> isPrime(n + 1, true);
        isPrime[0] = isPrime[1] = false; 
        // Finding prime numbers using Sieve of Eratosthenes algorithm
        for (int i = 2; i * i <= n; i++) 
        {
            if (isPrime[i]) 
            {
                for (int j = i * i; j <= n; j += i) {
                isPrime[j]=false;//Mark multiples of i as non-prime 
                }
            }
        }
        vector<vector<int>> ans;
        for(int i=2;i < n;i++)
        {
            int j = n - i; 
            if(isPrime[i] && isPrime[j] && i <= j)
            {
                vector<int> temp = {i,j};
                ans.push_back(temp);
            }
        }
        return ans;
    }
};
