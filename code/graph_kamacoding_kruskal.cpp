#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>

using namespace std;

/**
 * 边的权值排序，因为要优先选最小的边加入到生成树里
    遍历排序后的边
      如果边首尾的两个节点在同一个集合，说明如果连上这条边图中会出现环
      如果边首尾的两个节点不在同一个集合，加入到最小生成树，并把两个节点加入同一个集合
如何判断两个节点是否是同一个集合的，用并查集
 */

// kruskal
// 边优先算法
// l,r为 边两边的节点，val为边的数值
struct Edge {
    int l, r, val;
    Edge(int l_, int r_, int val_) : l(l_), r(r_), val(val_) {}
};

// 节点数量
int n = 10001;
// 并查集标记节点关系的数组
vector<int> parent(n, -1); // 节点编号是从1开始的，n要大一些

// 并查集初始化
void init() {
    for (int i = 0; i < n; ++i) {
        parent[i] = i;
    }
}

// 查找函数
// 查找元素的根节点，路径压缩优化可以提高效率。
// 使用路径压缩优化find函数
// 因为原始的find函数就是每次查找其父亲节点，
// 需要不断的递归下去
// 假如多叉树高度很深的华，每次find需要递归很多次
// 除了根节点其他所有节点都挂载根节点下，这样我们在寻根的时候就很快，只需要一步，
int find(int x) {
    if (parent[x] != x) {
        parent[x] = find(parent[x]); // 这里路径压缩了
    }
    return parent[x];
}

// 合并操作
// 将两个集合合并，可以使用按秩合并优化
// 确保较小的树合并到较大的树下
// 合并
void unionSets(int x, int y) {
    int root_x = find(x);
    int root_y = find(y);
    if (root_x == root_y) {
        return;
    }
    parent[root_y] = root_x;
}

bool static cmp(const Edge &a, const Edge &b) { return a.val < b.val; }

int main() {
    int v, e;
    int x, y, k;
    // 用来储存边
    vector<Edge> edges;
    vector<Edge> result_tree;
    int result = 0;
    cin >> v >> e;
    while (e--) {
        cin >> x >> y >> k;
        edges.push_back(Edge(x, y, k));
    }

    // 需要将边的权值按照从小到大进行排序
    sort(edges.begin(), edges.end(), cmp);

    // 并查集初始化
    init();

    // 从头开始遍历
    for (Edge edge : edges) {
        int root_x = find(edge.l);
        int root_y = find(edge.r);
        if (root_x != root_y) {
            result += edge.val;
            result_tree.push_back(edge);
            unionSets(root_x, root_y);
        }
    }
    for (Edge edge : edges) {
        cout << edge.l << " - " << edge.r << " : " << edge.val << endl;
    }
    cout << result << endl;
    return 0;
}