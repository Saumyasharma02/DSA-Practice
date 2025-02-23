//K Closest Points to Origin
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        int n = points.size();
        priority_queue<pair<long long, int>,vector<pair<long long, int>>,greater<pair<long long, int>>> pq;
        for(int i=0;i<n;i++)
        {
            long long dist=(long long)(points[i][0]*points[i][0])+(long long)(points[i][1]*points[i][1]);
            pq.push({dist,i});
        }
        vector<vector<int>> ans;
        while(k>=1)
        {
            ans.push_back(points[pq.top().second]);
            pq.pop();
            k--;
        }
        return ans;
    }
};
