#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9 + 7;
int main() {
    int n, e;
    cin >> n >> e;
    vector<vector<int>> adj_mat(n + 1, vector<int>(n + 1, INF));
    for (int i = 1; i <= n; i++) 
        adj_mat[i][i] = 0; 
    for (int i = 0; i < e; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        adj_mat[a][b] = min(adj_mat[a][b], c);
    }
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (adj_mat[i][k] < INF && adj_mat[k][j] < INF) {
                    adj_mat[i][j] = min(adj_mat[i][j], adj_mat[i][k] + adj_mat[k][j]);
                }
            }
        }
    }
    int q;
    cin >> q;
    while (q--) {
        int x, y;
        cin >> x >> y;
        if (adj_mat[x][y] == INF)
            cout << "INF\n";
        else
            cout << adj_mat[x][y] << "\n";
    }

    return 0;
}
