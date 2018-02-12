//  Clone an undirected graph. Each node in the graph contains a label and a
//  list of its neighbors.

// OJ's undirected graph serialization:

// Nodes are labeled uniquely.
// We use # as a separator for each node, and , as a separator for node label
// and each neighbor of the node.

// As an example, consider the serialized graph {0,1,2#1,2#2,2}.

// The graph has a total of three nodes, and therefore contains three parts as
// separated by #.

//     First node is labeled as 0. Connect node 0 to both nodes 1 and 2.
//     Second node is labeled as 1. Connect node 1 to node 2.
//     Third node is labeled as 2. Connect node 2 to node 2 (itself), thus
//     forming a self-cycle.

// Visually, the graph looks like the following:

//        1
//       / \
//      /   \
//     0 --- 2
//          / \
//          \_/

/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */

class Solution {
    using nd = UndirectedGraphNode;

    unordered_map<nd *, nd *> otn; // map old node to new node

  public:
    // DFS
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if (!node)
            return NULL;

        if (otn.find(node) == otn.end()) {
            // copy node
            otn.emplace(node, new nd(node->label));

            // copy neighbors
            for (auto n : node->neighbors)
                otn[node]->neighbors.push_back(cloneGraph(n));
        }

        return otn[node];
    }

    // BFS
    UndirectedGraphNode *cloneGraph_BFS(UndirectedGraphNode *node) {
        if (!node)
            return NULL;

        queue<nd *> q;
        q.push(node);

        // copy node
        otn.emplace(node, new nd(node->label));

        while (!q.empty()) {
            auto curr = q.front();
            q.pop();

            // copy curr's neighbors
            for (auto n : curr->neighbors) {
                if (otn.find(n) == otn.end()) {
                    otn.emplace(n, new nd(n->label));
                    q.push(n);
                }
                otn[curr]->neighbors.push_back(otn[n]);
            }
        }

        return otn[node];
    }
};
