#include <iostream>
#include <vector>
#include <map>
#include <set>

using namespace std;

void solve() {
    int q; cin >> q;
    map<int,int> mp;
    while(q--) {
        int a,b; cin >> a >> b;
        if (a == 1) { // insert
            mp[b]++; // 5 == 1+1+1
        } else if (a == 2) { // removal
            mp[b]--; // 5 = 5-1-1
        } else if (a == 3) { // check
            bool exist = false;
            for (pair<int,int> x: mp) { // clave, valor -> .first, .second
                if (x.second == b) {
                    exist = true;
                }
            }
            cout << (exist ? 1 : 0) <<endl;
        }
    }
}

int main() {
    solve();
    return 0;
}