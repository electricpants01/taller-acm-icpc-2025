#include <iostream>
#include <vector>
#include <deque>
#include <set>

using namespace std;

vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    set<int> s1, s2;
    vector<int> ans; // answer
    for (int i = 0; i < nums1.size(); ++i) {
        s1.insert(nums1[i]);
    }
    for (int i = 0; i < nums2.size(); ++i) {
        s2.insert(nums2[i]);
    }
    for (auto x: s1) { // 1,2<-s1 : s2 -> 2
        if (s2.contains(x)) ans.push_back(x);
    }
    return ans;
}

int main() {
    vector<int> v = {1,2,2,1};
    vector<int> v2 = {2,2};
    return 0;
}