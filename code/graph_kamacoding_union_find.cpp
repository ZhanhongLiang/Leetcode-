#include <iostream>
#include <vector>

using namespace std;

// 并合集定义
// union-find
// 通常用一个数组来表示,其中每个元素的值指向其父节点,根节点指向自己
// 表示该元素是集合的代表

class UnionFind {
  public:
    // 初始化parent数组
    UnionFind(int size) {
        parent.resize(size);
        // 初始化parent数组
        rank.resize(size, 0); // 初始化秩为 0
        for (int i = 0; i < size; i++) {
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
    void unionSets(int x, int y) {
        int root_x = find(x);
        int root_y = find(y);
        if (root_x != root_y) {
            parent[root_y] = root_x;
        }
    }

    // 判断x和v是否找到同一个根
    // 最后我们如何判断两个元素是否在同一个集合里
    bool isSame(int x, int y) {
        int root_x = find(x);
        int root_y = find(y);
        return root_x == root_y;
    }

    //
    int unionByRank(int x, int y) {
        int root_x = find(x);
        int root_y = find(y);
        if (root_x != root_y) {
            if (rank[root_x] < rank[root_y]) {
                // 将小秩树合并到大秩树上
                parent[root_x] = root_y;
            } else if (rank[root_x] > rank[root_y]) {
                parent[root_y] = root_x;
            } else {
                // 随便选择一个作为新的根
                parent[root_y] = root_x;
                rank[root_x]++; // 秩加一
            }
        }
    }

  private:
    vector<int> parent;
    vector<int> rank; // 记录每棵树的高度，也就是秩
};
