#include <iostream>
#include <vector>
#include <map>
#include <set>

using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    map<int,pair<bool, int>> mp;
    // pair -> {1,2} -> .first ; .second
    vector<int> ans;
    for (int i = 0; i < nums.size(); ++i) {
        if (mp[target - nums[i]].first == true) {
            ans.push_back(i);
            ans.push_back(mp[target - nums[i]].second);
            return ans;
        } else {
            mp[nums[i]] = make_pair(true, i);
        }
    }
    return ans;
}

int main() {
    vector<int> v = {1,2,2,1};
    vector<int> v2 = {2,2};
    return 0;
}