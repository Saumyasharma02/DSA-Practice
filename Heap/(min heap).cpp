//Kth Largest Element in an Array
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // Min-heap to store the top k largest elements
        priority_queue<int, vector<int>, greater<int>> minHeap;

        // Iterate through each number
        for (int num : nums) {
            minHeap.push(num);

            // Keep the heap size to k elements
            if (minHeap.size() > k) {
                minHeap.pop();  // Remove the smallest element
            }
        }

        // The top element of the heap is the k-th largest
        return minHeap.top();
    }
};

