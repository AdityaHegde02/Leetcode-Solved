class Solution {
public:
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj_list(n);
        for (auto &e : edges) {
            adj_list[e[0]].push_back(e[1]);
            adj_list[e[1]].push_back(e[0]);
        }
        vector<int> total_child(n);
        int total_dis = 0;
        find_num_child(0, adj_list, total_child, -1);
        find_dis(0, adj_list, -1, 0, total_dis);
        vector<int> result(n);
        result[0] = total_dis;
        find_result(0, adj_list, total_child, result, -1, n);
        return result;
    }
    
    int find_num_child(int cur_node, vector<vector<int>>& adj_list, vector<int>& total_child, int parent) {
        int child = 1;
        for (auto neighbor : adj_list[cur_node]) {
            if (parent != neighbor)
                child += find_num_child(neighbor, adj_list, total_child, cur_node);
        }
        total_child[cur_node] = child;
        return child;
    }
    
    void find_dis(int cur_node, vector<vector<int>>& adj_list, int parent, int cur_dis, int& total_dis) {
        total_dis += cur_dis;
        for (auto neighbor : adj_list[cur_node]) {
            if (parent != neighbor) 
                find_dis(neighbor, adj_list, cur_node, cur_dis + 1, total_dis);
        }
    }
    
    void find_result(int cur_node, vector<vector<int>>& adj_list, vector<int>& total_child, vector<int>& result, int parent, int n) {
        if (cur_node != 0) result[cur_node] = result[parent] - total_child[cur_node] + (n - total_child[cur_node]);
        for (auto neighbor : adj_list[cur_node]) {
            if (parent != neighbor) 
                find_result(neighbor, adj_list, total_child, result, cur_node, n);
        }
    }
    
};