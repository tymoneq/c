#include <bits/stdc++.h>
using namespace std;
constexpr int M = 5e4 + 10, INF = 1e9;
vector<pair<int, int>> Graph[M];
int Dist[M];
bool Vis[M];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("6.in", "r", stdin);
    int n, K;
    char z;
    cin >> n >> K;
    vector<int> Cows(n);
    unordered_map<int, vector<int>> Indexes;
    for (int i = 0; i < n; i++)
    {
        cin >> Cows[i];
        Indexes[Cows[i]].push_back(i);
    }
    for (int i = 1; i <= K; i++)
        for (int j = 1; j <= K; j++)
        {
            cin >> z;
            if (z == '1')
                if (Indexes[i].size() > 0)
                    for (int w : Indexes[i])
                        if (Indexes[j].size() > 0)
                            for (int v : Indexes[j])
                                Graph[w].push_back({v, abs(w - v)});
        }
    for (int i = 0; i < n; i++)
        Dist[i] = INF;
    Dist[0] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 0});
    while (!pq.empty())
    {
        auto v = pq.top();
        pq.pop();
        if (!Vis[v.second])
            for (auto w : Graph[v.second])
                if (Dist[w.first] > Dist[v.second] + w.second)
                {
                    Dist[w.first] = Dist[v.second] + w.second;
                    pq.push({Dist[w.first], w.first});
                }
        Vis[v.second] = 1;
    }
    cout << (Dist[n - 1] != INF ? Dist[n - 1] : -1);
    return 0;
}