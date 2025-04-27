#include <iostream>
#include <vector>
#include <stack>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;
    
    std::vector<int> vec(n);

    for (int i = 0; i < n; ++i) std::cin >> vec[i];

    std::vector<int> dp_l(n, 0), dp_r(n, 0), pref(n, 0);
    dp_l[0] = 1;
    dp_r[0] = 1;
    std::stack<int> st_l, st_r;
    st_l.push(0);
    st_r.push(0);
    
    for (int i = 1; i < n; ++i) {
        pref[i] = i;
        dp_r[i] = std::min(dp_l[i - 1], dp_r[i - 1]) + 1;
        
        while(!st_r.empty() && vec[st_r.top()] <= i - st_r.top()) {
            st_r.pop();
        }

        if (!st_r.empty() && dp_r[st_r.top()] < dp_r[i]) {
            dp_r[i] = dp_r[st_r.top()];
            pref[i] = st_r.top();
        }

        while(!st_r.empty() && vec[st_r.top()] + st_r.top() <= vec[i] + i) {
            st_r.pop();
        }

        if (st_r.empty() || dp_r[i] < dp_r[st_r.top()]) {
            st_r.push(i);
        }

        dp_l[i] = std::min(dp_l[i - 1], dp_r[i - 1]) + 1;

        while(!st_l.empty() && i - st_l.top() < vec[i]) {
            if (dp_l[i] >= dp_l[st_l.top()]) {
                dp_l[i] = dp_l[st_l.top()];
            }
            st_l.pop();
        }

        st_l.push(i);
    }

    std::cout << std::min(dp_l[n - 1], dp_r[n - 1]) << '\n';
    
    int ind = n - 1;
    while(ind >= 0) {
        if (dp_l[ind] <= dp_r[ind]) {
            std::cout << ind + 1 << " L" << '\n';
            int dist = vec[ind] - 1;
            --ind;
            while(ind >= 0 && dist) {
                dist = std::max(dist, vec[ind]);
                --ind;
                --dist;
            }
        } else {
            while(pref[ind] != ind) {
                ind = pref[ind];
            }
            std::cout << ind + 1 << " R" << '\n';
            --ind;
        }
    }
}
