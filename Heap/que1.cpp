//Kth Largest Element in an Array

//1.MAX HEAP
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq;  // Max Heap by default

        // Push all elements into the priority queue
        for (int num : nums) {
            pq.push(num);
        }

        // Pop elements until we reach the k-th largest
        int num;
        while (k > 0) {
            num = pq.top();
            pq.pop();
            k--;
        }
        return num;
    }
};

int main() {
    Solution sol;

    // Example input
    vector<int> nums = {3, 2, 1, 5, 6, 4};
    int k = 2;
    int result = sol.findKthLargest(nums, k);
    cout << "The " << k << "-th largest element is: " << result << endl;

    return 0;
}



