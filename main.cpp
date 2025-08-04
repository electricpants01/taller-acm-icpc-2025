#include <iostream>
#include <vector>
#include <deque>

using namespace std;

vector<int> maxSlidingWindow(vector<int>& nums, int k) { // O(n) vs O(n*k)
    vector<int> result;
    if (nums.empty() || k <= 0) return result;
    deque<int> dq;
    // Process the first k elements
    for (int i = 0; i < k; ++i) {
        // Remove elements smaller than the current element from the back
        while (!dq.empty() && nums[dq.back()] <= nums[i]) {
            dq.pop_back();
        }
        // Add the current element's index to the back
        dq.push_back(i);
    }
    // The first maximum is at the front of the deque
    result.push_back(nums[dq.front()]);
    // Process the remaining elements
    for (int i = k; i < nums.size(); ++i) {
        // Remove the index of the element that is out of the window
        if (!dq.empty() && dq.front() == i - k) {
            dq.pop_front();
        }
        // Remove elements smaller than the current element from the back
        while (!dq.empty() && nums[dq.back()] <= nums[i]) {
            dq.pop_back();
        }
        // Add the current element's index to the back
        dq.push_back(i);
        // The maximum for the current window is at the front
        result.push_back(nums[dq.front()]);
    }

    return result;
}

int main() {
    vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;
    vector<int> result = maxSlidingWindow(nums, k);

    cout << "Input: nums = [1,3,-1,-3,5,3,6,7], k = 3" << endl;
    cout << "Output: [";
    for (size_t i = 0; i < result.size(); ++i) {
        cout << result[i] << (i == result.size() - 1 ? "" : ", ");
    }
    cout << "]" << endl;

    return 0;
}