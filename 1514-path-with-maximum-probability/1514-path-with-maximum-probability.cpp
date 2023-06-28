class Solution {
private:
    void dfs(unordered_map<int, vector<pair<int, double>>>& m, double& ans, int start, int end) {
        priority_queue<pair<double, int>> pq;
        pq.push({ 1.0, start });

        unordered_map<int, double> maxProb;
        maxProb[start] = 1.0;

        while (!pq.empty()) {
            double prob = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            if (node == end) {
                ans = max(ans, prob);
                continue;
            }

            for (auto& neighbor : m[node]) {
                int nextNode = neighbor.first;
                double edgeProb = neighbor.second;
                double nextProb = prob * edgeProb;

                if (nextProb > maxProb[nextNode]) {
                    maxProb[nextNode] = nextProb;
                    pq.push({ nextProb, nextNode });
                }
            }
        }
    }

public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        double ans = 0;
        unordered_map<int, vector<pair<int, double>>> m;

        for (int i = 0; i < edges.size(); i++) {
            m[edges[i][0]].push_back({ edges[i][1], succProb[i] });
            m[edges[i][1]].push_back({ edges[i][0], succProb[i] });
        }

        dfs(m, ans, start, end);
        return ans;
    }
};
