#include <bits/stdc++.h>

using namespace std;
struct node
{
    int data;
    struct node *left;
    struct node *right;
    node(int value)
    {
        data = value;
        left = NULL;
        right = NULL;
    };
};
void PrintLevelOrder(struct node *root)
{
    if (!root)
        return;
    queue<node *> levels;
    levels.push(root);
    levels.push(NULL);
    while (!levels.empty())
    {
        node *temp = levels.front();
        levels.pop();
        if (temp)
        {
            if (temp->left)
                levels.push(temp->left);
            if (temp->right)
                levels.push(temp->right);
            cout << temp->data << " ";
        }
        else if (!levels.empty())
            levels.push(NULL);
    }
}
void sumofKthlevel(node *root, int k)
{
    if (!root)
        return;
    queue<node *> levels;
    levels.push(root);
    levels.push(NULL);
    int sum = 0;
    while (!levels.empty())
    {
        node *temp = levels.front();
        levels.pop();
        if (temp)
        {
            if (temp->left)
                levels.push(temp->left);
            if (temp->right)
                levels.push(temp->right);
            // cout << temp->data << " ";
            if (k == 0)
                sum += temp->data;
        }
        else if (!levels.empty())
        {
            // cout<<sum<<" ";
            // sum=0;
            k--;
            levels.push(NULL);
        }
    }
    cout << sum;
}
void count_and_sum(node *root)
{
    if (!root)
        return;
    queue<node *> q;
    q.push(root);
    q.push(NULL);
    int count = 0, sum = 0;
    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();
        if (temp)
        {
            if (temp->left)
                q.push(temp->left);
            if (temp->right)
                q.push(temp->right);
            count++;
            sum += temp->data;
        }
        else if (!q.empty())
            q.push(NULL);
    }

    cout << count << " " << sum << endl;
}
int count(node *root)
{
    if (!root)
        return 0;
    return count(root->left) + count(root->right) + 1;
}

int sum(node *root)
{
    if (!root)
        return 0;
    return sum(root->left) + sum(root->right) + root->data;
}
int height(node *root)
{
    if (!root)
        return 0;
    return max(height(root->left), height(root->right)) + 1;
}
int diameter(node *root)
{
    if (!root)
        return 0;
    int lheight = height(root->left);
    int rheight = height(root->right);
    int dia = lheight + rheight + 1;
    int ldiameter = diameter(root->left);
    int rdiameter = diameter(root->right);

    return max(max(ldiameter, rdiameter), dia);
}
int diameter(node *root, int *height)
{
    if (!root)
    {
        *height = 0;
        return 0;
    }
    int lh = 0, rh = 0;
    int ldiameter = diameter(root->left, &lh);
    int rdiameter = diameter(root->right, &rh);
    int currd = lh + rh + 1;
    *height = max(lh, rh) + 1;
    return max(max(ldiameter, rdiameter), currd);
}
int sumrReplacement(node *root)
{
    if (!root)
        return 0;
    return root->data = sumrReplacement(root->left) + sumrReplacement(root->right) + root->data;
}
void inorder(node *root)
{
    if (!root)
        return;
    inorder(root->left);
    cout << root->data << endl;
    inorder(root->right);
}
bool isBalanced(node *root)
{
    if (!root)
        return true;
    if (!isBalanced(root->left))
        return false;
    if (!isBalanced(root->right))
        return false;

    int lheight = height(root->left);
    int rheight = height(root->right);
    if (abs(lheight - rheight) <= 1)
        return true;
    else
        return false;
}
bool isbalanced(node *root, int *height)
{
    if (!root)
    {
        *height = 0;
        return true;
    }
    int lh = 0, rh = 0;
    if (!isbalanced(root->left, &lh))
        return false;
    if (!isbalanced(root->right, &rh))
        return false;
    *height = max(lh, rh) + 1;
    if (abs(lh - rh) <= 1)
        return true;
    else
        return false;
}
void rightview(node *root)
{
    if (!root)
        return;
    queue<node *> q;
    q.push(root);
    q.push(NULL);
    vector<int> rightnode;
    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();
        if (temp)
        {
            if (temp->left)
                q.push(temp->left);
            if (temp->right)
                q.push(temp->right);
            if (!q.front())
                rightnode.push_back(temp->data);
        }
        else if (!q.empty())
        {

            q.push(NULL);
        }
    }
    for (auto it : rightnode)
        cout << it << endl;
}
void leftview(node *root)
{
    if (!root)
        return;
    queue<node *> q;
    q.push(root);
    q.push(NULL);
    vector<int> leftnodes;
    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();
        if (temp)
        {
            if (temp->left)
                q.push(temp->left);
            if (temp->right)
                q.push(temp->right);
            if (!q.front())
                leftnodes.push_back(temp->data);
        }
        else if (!q.empty())
        {
            q.push(NULL);
        }
    }
    for (auto it : leftnodes)
        cout << it << " ";
    cout << endl;
}
// To find lowest comman ancestor
node *LCA(node *root, int n1, int n2)
{
    if (!root)
        return NULL;
    if (root->data == n1 || root->data == n2)
        return root;
    node *left = LCA(root->left, n1, n2);
    node *right = LCA(root->right, n1, n2);
    if (left && right)
        return root;
    if (!left && !right)
        return NULL;
    if (!right)
        return LCA(root->left, n1, n2);
    return LCA(root->right, n1, n2);
}
// to find distance from root to that node
int findDistance(node *root, int data, int distance)
{
    if (!root)
        return -1;
    if (root->data == data)
        return distance;
    int right = findDistance(root->right, data, distance + 1);
    if (right != -1)
        return right;
    return findDistance(root->left, data, distance + 1);
}
// to find shortest distance between n1 and n2
int sDistance(node *root, int n1, int n2)
{
    if (!root)
        return 0;
    node *lca = LCA(root, n1, n2);
    return findDistance(lca, n1, 0) + findDistance(lca, n2, 0);
}
bool getpath(node *root, int key, vector<int> &path)
{
    if (!root)
        return false;
    path.push_back(root->data);
    if (root->data == key)
        return true;
    if (getpath(root->left, key, path) || getpath(root->right, key, path))
    {
        return true;
    }
    path.pop_back();
    return false;
}
//path of node from root node
vector<int> path(node *root, int key)
{
    vector<int> ans;
    if (!root)
    {
        ans.push_back(-1);
        return ans;
    }
    if (getpath(root, key, ans))
        return ans;
    return ans;
}
int maxsumpath(node*root,int &ans)
{
    if(!root)return 0;
    int left=maxsumpath(root->left,ans);
    int right=maxsumpath(root->right,ans);
    int nodemax=max(max(root->data,root->data+left+right),max(root->data+left,root->data+right));
    ans=max(ans,nodemax);
    int singlepath=max(root->data,max(root->data+left,root->data+right));
    return singlepath;
}
int main()
{
    node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);
    //    root->right->right->left=new node(8);
    root->right->right->right = new node(9);
    cout << "LEVEL ORDER TRAVERSAL:";
    PrintLevelOrder(root);
    cout << endl;
    cout << "RIGHT VIEW OF A TREE:" << endl;
    rightview(root);
    cout << "LEFT VIEW OF A TREE:" << endl;
    leftview(root);
    cout << "SUM OF A 2ND LEVEL NODES:";
    sumofKthlevel(root, 2);
    cout << endl;
    cout << "find distance between::" << sDistance(root, 4, 9) << endl;
    cout << "TOTAL NUMBER OF NODES AND THEIR SUM:";
    count_and_sum(root);
    cout << "TOTAL NODES:" << count(root) << endl;
    cout << "SUM OF NODES:" << sum(root) << endl;
    cout << "HEIGHT OF A TREE:" << height(root) << endl;
    cout << "DIAMETER OF A TREE:" << diameter(root) << endl;
    int height = 0;
    cout << "DIAMETER OF A TREE:" << diameter(root, &height) << endl;
    cout << "INORDER TRAVERSAL AFTER SUMREPLACEMENT:" << endl;
    // sumrReplacement(root);
    inorder(root);
    if (isBalanced(root))
        cout << "Tree is Balanced" << endl;
    else
        cout << "Tree is Unbalanced" << endl;
    if (isbalanced(root, &height))
        cout << "Tree is Balanced" << endl;
    else
        cout << "Tree is Unbalanced" << endl;
    vector<int> res = path(root, 5);
    for (auto it : res)
        cout << it << " ";
    cout << endl;
    int ans=0;
    maxsumpath(root,ans);
    cout<<"Maximum path sum:"<<ans<<endl;
    return 0;
}