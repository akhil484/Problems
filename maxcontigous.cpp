class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    //     //O(NlogN)
    //      vector<int> result;
    // if (k == 0) return result;
    // priority_queue<pair<int, int>> w;
    // for (int i = 0, n = (int)nums.size(); i < n; i++) {
    //     while (!w.empty() && w.top().second <= i-k)
    //         w.pop();
    //     w.push(make_pair(nums[i],i));
    //     if (i >= k-1)       //at this point heap will have at least k characters.
    //         result.push_back(w.top().first);
    // }
    // return result;
        
        //O(N) We are adding to last of list and popping from front and keeping it in descending order
         vector<int> result;
    if (k == 0) return result;
    deque<int> w;
    for (int i = 0, n = (int)nums.size(); i < n; i++) {
        while (!w.empty() && w.front() <= i-k)
            w.pop_front();
        while (!w.empty() && nums[w.back()] <= nums[i])
            w.pop_back();
        w.push_back(i);
        if (i >= k-1)
            result.push_back(nums[w.front()]);
        }
    return result;
    }
};
