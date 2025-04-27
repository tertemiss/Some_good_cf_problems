#include <iostream>
#include <vector>
 
int main() {
    int t;
    std::cin >> t;
    while(t--) {
        int n;
        std::cin >> n;
        int a, b;
        int sum = 0;
        std::cout.flush();
        for (int i = 0; i < n - 1; ++i) {
            std::cin >> a >> b;
        }
        int l = 1, r = n;
        while(l != r) {
            int mid = (l + r) / 2 + 1;
            std::cout << "? 1 " << (r - mid + 1) << ' ';
            for (int i = mid; i <= r; ++i) {
                std::cout << i << ' ';
            }
            std::cout << '\n';
            std::cout.flush();
            std::cin >> a;
            std::cout << "? 2 1\n";
            std::cout << "? 1 " << (r - mid + 1) << ' ';
            for (int i = mid; i <= r; ++i) {
                std::cout << i << ' ';
            }
            std::cout << '\n';
            std::cout.flush();
            std::cin >> b;
            if (a + (r - mid + 1) * 2 == b || b + (r - mid + 1) * 2 == a) {
                r = mid - 1;
            } else {
                l = mid;
            }
        }
        std::cout << "? 1 1 " << l << '\n';
        int v = 0;
        std::cout.flush();
        std::cin >> v;
        std::cout << "? 1 1 1" << '\n';
        int one = 0;
        std::cout.flush();
        std::cin >> one;
        
        if (l == 1) {
            v = 0;
        } else {
            one -= v;
        }
        std::vector<int> vec(n, 0);
        vec[l - 1] = v;
        vec[0] = one; 
        for (int i = 1; i < n; ++i) {
            if (vec[i] != 0) {
                continue;
            } else {
                std::cout << "? 1 1 " << i + 1 << '\n';
                std::cout.flush();
                std::cin >> a;
                a -= one + v;
                vec[i] = a;
            }
        }
        std::cout << "! ";
        for (auto i : vec) {
            std::cout << i << ' ';
        }
        std::cout << '\n';
        std::cout.flush();
    }
}
