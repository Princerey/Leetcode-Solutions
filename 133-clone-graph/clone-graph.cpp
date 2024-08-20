class Solution {
public:
    unordered_map<Node*, Node*> cloningGraph;
    Node* cloneGraph(Node* node) 
    {
        if (node == nullptr)
         {
            return nullptr;
        }
        if (cloningGraph.find(node) == cloningGraph.end())
         {
            cloningGraph[node] = new Node(node -> val);
            for (auto neighbor : node -> neighbors) 
            {
                cloningGraph[node] -> neighbors.push_back(cloneGraph(neighbor));
            }
        }
        return cloningGraph[node];
    }
};