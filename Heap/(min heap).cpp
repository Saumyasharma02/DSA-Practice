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

/*This C++ code finds the **k closest points to the origin (0,0) from a list of 2D points using a min-heap (priority queue). 
The function `kClosest` takes a vector of points and an integer `k` as input and returns a vector of the `k` closest points based on their Euclidean distance 
from the origin. 
Instead of calculating the actual distance (which would require a square root operation), it uses the squared distance formula \(x^2 + y^2\) to avoid 
unnecessary computationwhile maintaining accuracy for comparison. 
Each point’s distance, along with its index, is stored as a pair in a min-heap (using a priority queue with `greater<>` comparator). 
Since the heap stores elements in ascending order of distance, the smallest (closest) distance is always on top. 
The algorithm then extracts the top `k` elements from the heap and adds the corresponding points to the result vector. 
This approach ensures an efficient solution with a time complexity of **O(n log n)** due to heap insertions and extractions.*/
