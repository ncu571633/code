Given n nodes labeled from 0 to n - 1 and a list of undirected edges (each edge is a pair of nodes), write a function to find the number of connected components in an undirected graph.

Example 1:

0          3

|          |

1 --- 2    4

Given n = 5 and edges = [[0, 1], [1, 2], [3, 4]], return 2.

Example 2:

0           4

|           |

1 --- 2 --- 3

Given n = 5 and edges = [[0, 1], [1, 2], [2, 3], [3, 4]], return 1.

Note:

You can assume that no duplicate edges will appear in edges. Since all edges are undirected, [0, 1] is the same as [1, 0] and thus will not appear together in edges.


class Solution {
    public:
        int countComponents(int n, vector<pair<int, int> >& edges) {
            int res = 0;
            vector<vector<int> > g(n);
            vector<bool> v(n, false);
            for (auto a : edges) {
                g[a.first].push_back(a.second);
                g[a.second].push_back(a.first);
            }
            for (int i = 0; i < n; ++i) {
                if (!v[i]) {
                    ++res;
                    dfs(g, v, i);
                }
            }
            return res;
        }
        void dfs(vector<vector<int> > &g, vector<bool> &v, int i) {
            if (v[i]) return;
            v[i] = true;
            for (int j = 0; j < g[i].size(); ++j) {
                dfs(g, v, g[i][j]);
            }
        }
};
