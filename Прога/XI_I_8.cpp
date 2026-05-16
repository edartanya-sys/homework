#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

// Fenwick Tree
struct Fenwick {
    int n;
    vector<int> f;

    Fenwick(int n) : n(n), f(n + 1, 0) {}

    void add(int i, int v) {
        for (++i; i <= n; i += i & -i)
            f[i] += v;
    }

    int sum(int i) {
        int r = 0;
        for (++i; i > 0; i -= i & -i)
            r += f[i];
        return r;
    }

    int get(int l, int r) {
        return sum(r) - sum(l - 1);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    map<ll, vector<pair<ll,ll>>> horiz, vert;
    vector<ll> ys;

    for (int i = 0; i < n; i++) {
        ll x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        if (y1 == y2) {
            if (x1 > x2) swap(x1, x2);
            horiz[y1].push_back({x1, x2});
            ys.push_back(y1);
        } else {
            if (y1 > y2) swap(y1, y2);
            vert[x1].push_back({y1, y2});
            ys.push_back(y1);
            ys.push_back(y2);
        }
    }

    // --- merge intervals ---
    auto merge = [&](vector<pair<ll,ll>>& v) {
        sort(v.begin(), v.end());
        vector<pair<ll,ll>> res;
        for (auto [l,r]: v) {
            if (res.empty() || l > res.back().second + 1)
                res.push_back({l,r});
            else
                res.back().second = max(res.back().second, r);
        }
        return res;
    };

    ll total_h = 0;
    for (auto& [y, v] : horiz) {
        auto m = merge(v);
        for (auto [l,r]: m)
            total_h += (r - l + 1);
        v = m;
    }

    ll total_v = 0;
    for (auto& [x, v] : vert) {
        auto m = merge(v);
        for (auto [l,r]: m)
            total_v += (r - l + 1);
        v = m;
    }

    // --- compress y ---
    sort(ys.begin(), ys.end());
    ys.erase(unique(ys.begin(), ys.end()), ys.end());

    auto getY = [&](ll y) {
        return lower_bound(ys.begin(), ys.end(), y) - ys.begin();
    };

    // --- events ---
    struct Event {
        ll x;
        int type; // 0 add, 1 remove, 2 query
        int y1, y2;
    };

    vector<Event> events;

    // вертикали
    for (auto& [x, v] : vert) {
        for (auto [y1,y2]: v) {
            events.push_back({x, 0, getY(y1), getY(y2)});
            events.push_back({x, 1, getY(y1), getY(y2)});
        }
    }


    for (auto& [y, v] : horiz) {
        int cy = getY(y);
        for (auto [l,r]: v) {
            events.push_back({l, 2, cy, cy});
            events.push_back({r, 3, cy, cy});
        }
    }

    sort(events.begin(), events.end(), [](auto& a, auto& b){
        if (a.x != b.x) return a.x < b.x;
        return a.type < b.type;
    });

    Fenwick bit(ys.size());

    ll inter = 0;

    for (auto& e: events) {
        if (e.type == 0) {
            for (int y = e.y1; y <= e.y2; y++)
                bit.add(y, 1);
        } else if (e.type == 1) {
            for (int y = e.y1; y <= e.y2; y++)
                bit.add(y, -1);
        } else if (e.type == 2) {
            inter += bit.get(e.y1, e.y1);
        }
    }

    cout << total_h + total_v - inter << "\n";
}