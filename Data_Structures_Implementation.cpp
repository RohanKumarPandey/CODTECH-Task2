#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

class LinkedList {
private:
    Node* head;
public:
    LinkedList() : head(nullptr) {}
    
    void insert(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    void display() {
        Node* temp = head;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    bool search(int val) {
        Node* temp = head;
        while (temp) {
            if (temp->data == val) return true;
            temp = temp->next;
        }
        return false;
    }

    void remove(int val) {
        if (!head) return;
        if (head->data == val) {
            Node* toDelete = head;
            head = head->next;
            delete toDelete;
            return;
        }
        Node* temp = head;
        while (temp->next && temp->next->data != val) {
            temp = temp->next;
        }
        if (temp->next) {
            Node* toDelete = temp->next;
            temp->next = temp->next->next;
            delete toDelete;
        }
    }
};

class TreeNode {
public:
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

class BinaryTree {
private:
    TreeNode* root;
    
    void inorder(TreeNode* node) {
        if (node) {
            inorder(node->left);
            cout << node->data << " ";
            inorder(node->right);
        }
    }

public:
    BinaryTree() : root(nullptr) {}
    
    void insert(int val) {
        TreeNode* newNode = new TreeNode(val);
        if (!root) {
            root = newNode;
            return;
        }
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode* temp = q.front();
            q.pop();
            if (!temp->left) {
                temp->left = newNode;
                return;
            } else {
                q.push(temp->left);
            }
            if (!temp->right) {
                temp->right = newNode;
                return;
            } else {
                q.push(temp->right);
            }
        }
    }

    void displayInOrder() {
        inorder(root);
        cout << endl;
    }

    bool search(int val) {
        if (!root) return false;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode* temp = q.front();
            q.pop();
            if (temp->data == val) return true;
            if (temp->left) q.push(temp->left);
            if (temp->right) q.push(temp->right);
        }
        return false;
    }
};

class Graph {
private:
    vector<vector<int>> adj;
public:
    Graph(int vertices) {
        adj.resize(vertices);
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void display() {
        for (int i = 0; i < adj.size(); i++) {
            cout << i << ": ";
            for (int j : adj[i]) {
                cout << j << " ";
            }
            cout << endl;
        }
    }

    bool search(int start, int target) {
        vector<bool> visited(adj.size(), false);
        queue<int> q;
        q.push(start);
        visited[start] = true;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            if (node == target) return true;
            for (int neighbor : adj[node]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }
        return false;
    }
};

int main() {
    LinkedList ll;
    ll.insert(10);
    ll.insert(20);
    ll.insert(30);
    ll.display();
    cout << "Search 20: " << (ll.search(20) ? "Found" : "Not Found") << endl;
    ll.remove(20);
    ll.display();

    BinaryTree bt;
    bt.insert(5);
    bt.insert(3);
    bt.insert(8);
    bt.displayInOrder();
    cout << "Search 8: " << (bt.search(8) ? "Found" : "Not Found") << endl;

    Graph g(5);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 4);
    g.display();
    cout << "Search path from 0 to 3: " << (g.search(0, 3) ? "Found" : "Not Found") << endl;

    return 0;
}
