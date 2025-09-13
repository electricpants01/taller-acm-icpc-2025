#include <iostream>
#include <vector>
#include <deque>
#include <set>

using namespace std;

bool containsDuplicate(vector<int>& nums) { // O(n)
    set<int> s;
    int len = nums.size();
    for(int i=0;i<len;i++) {
        s.insert(nums[i]);
    }
    return s.size() != len;
}

bool containsDuplicateSlow(vector<int>& nums) { // O(n**2)
    for (int i = 0; i < nums.size()-1; ++i) {
        for (int j = i+1; j < nums.size(); ++j) {
            if (nums[i] == nums[j]) return true;
        }
    }
    return false;
}

int main() {
    vector<int> v = {1,2,3,1};
    cout << containsDuplicate(v);
    return 0;
}