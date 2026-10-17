class Solution {
public:
    int minSwaps(vector<int>& nums) {
        vector<pair<int, int>> ans;
        vector<int> visited(nums.size(), 0);

        priority_queue<pair<pair<int, int>, int>,
        vector<pair<pair<int, int>, int>>,
        greater<pair<pair<int, int>, int>>> pq;

        for (int i = 0; i < nums.size(); i++) {
            int sum = 0;
            int x = nums[i];

            while (x > 0) {
                sum += x % 10;
                x /= 10;
            }

            pq.push({{sum, nums[i]}, i});
        }

        while (!pq.empty()) {
            ans.push_back({pq.top().second, pq.top().first.second});
            pq.pop();
        }

        int count = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (visited[i] || ans[i].first == i)
                continue;

            int j = i;
            int size = 0;

            while (!visited[j]) {
                visited[j] = 1;
                j = ans[j].first;
                size++;
            }

            count += size - 1;
        }

        return count;
    }
};