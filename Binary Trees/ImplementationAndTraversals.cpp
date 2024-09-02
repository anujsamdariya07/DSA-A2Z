#include <bits/stdc++.h>

using namespace std;

class Node
{
public:
	int data;
	Node *left;
	Node *right;

	Node()
	{
		left = NULL;
		right = NULL;
	}

	Node(int data)
	{
		this->data = data;
		left = NULL;
		right = NULL;
	}
};

// It creates root node of the created root
Node *createTree()
{
	cout << "Enter value of node: ";
	int data;
	cin >> data;

	if (data == -1)
	{
		return NULL;
	}

	// 1. Create node
	Node *root = new Node(data);

	// 2. Create left subtree
	cout << "Left of node: " << root->data << endl;
	root->left = createTree();

	// 3. Create right subtree
	cout << "Right of node: " << root->data << endl;
	root->right = createTree();

	return root;
}

void preOrder(Node *root)
{
	if (root == NULL)
	{
		return;
	}

	// NLR
	// N
	cout << root->data << " ";
	// L
	preOrder(root->left);
	// R
	preOrder(root->right);
}

void inOrder(Node *root)
{
	if (root == NULL)
	{
		return;
	}

	// LNR
	// L
	inOrder(root->left);
	// N
	cout << root->data << " ";
	// R
	inOrder(root->right);
}

void postOrder(Node *root)
{
	if (root == NULL)
	{
		return;
	}

	// LRN
	// L
	postOrder(root->left);
	// R
	postOrder(root->right);
	// N
	cout << root->data << " ";
}

void levelOrderTraversal(Node *root)
{
	if (root == NULL)
	{
		return;
	}

	queue<Node *> q;
	q.push(root);
	cout << "LEVEL ORDER: ";

	while (!q.empty())
	{
		Node *front = q.front();
		cout << front->data << " ";
		q.pop();
		if (front->left != NULL)
		{
			q.push(front->left);
		}
		if (front->right != NULL)
		{
			q.push(front->right);
		}
	}
}

// Printing level wise
void levelOrderTraversal2(Node *root)
{
	if (root == NULL)
	{
		return;
	}

	queue<Node *> q;
	q.push(root);
	q.push(NULL);
	cout << "LEVEL ORDER: ";

	// while (!q.empty()) -> infinite loop for last NULL
	while (q.size() > 1)
	{
		Node *front = q.front();
		q.pop();

		if (front == NULL)
		{
			cout << endl;
			q.push(NULL);
		}
		else
		{
			cout << front->data << " ";
			if (front->left != NULL)
			{
				q.push(front->left);
			}
			if (front->right != NULL)
			{
				q.push(front->right);
			}
		}
	}
}

int heightOfTree(Node *root)
{
	// // Base case
	// if (root == NULL) return 0;

	// int leftHeight = maxDepth(root->left);
	// int rightHeight = maxDepth(root->right);
	// int height = 1 + max(leftHeight, rightHeight);
	// return height;

	if (root == NULL)
	{
		return 0;
	}

	queue<Node *> q;
	q.push(root);
	q.push(NULL);
	int count = 1;
	cout << "LEVEL ORDER: ";

	// while (!q.empty()) -> infinite loop for last NULL
	while (q.size() > 1)
	{
		Node *front = q.front();
		q.pop();

		if (front == NULL)
		{
			cout << endl;
			count++;
			q.push(NULL);
		}
		else
		{
			cout << front->data << " ";
			if (front->left != NULL)
			{
				q.push(front->left);
			}
			if (front->right != NULL)
			{
				q.push(front->right);
			}
		}
	}
	return count;
}

int maximumDepth(Node *root)
{
	// For empty tree
	if (root == NULL)
	{
		return 0;
	}
	return max(maximumDepth(root->left), maximumDepth(root->right)) + 1;
}

int diameterOfBinaryTree(Node *root)
{
	// For NULL root
	if (root == NULL)
		return 0;

	int option1 = diameterOfBinaryTree(root->left);											// 2
	int option2 = diameterOfBinaryTree(root->right);										// 1
	int option3 = maximumDepth(root->left) + maximumDepth(root->right); // 2+1 +1 = 4-1 = 5
	return max(option1, max(option2, option3));
}

// Height balanced tree
bool isBalanced(Node *root)
{
	if (root == NULL)
	{
		return true;
	}

	int leftHeight = maximumDepth(root->left);
	int rightHeight = maximumDepth(root->right);

	bool rootAns = (abs(leftHeight - rightHeight) <= 1);
	bool leftAns = isBalanced(root->left);
	bool rightAns = isBalanced(root->right);

	return rootAns && leftAns && rightAns;
}

Node *lowestCommonAncestor(Node *root, Node *p, Node *q)
{
	// Base conditions
	if (root == NULL)
	{
		return NULL;
	}
	if (root == p)
	{
		return p;
	}
	if (root == q)
	{
		return q;
	}

	Node *leftAns = lowestCommonAncestor(root->left, p, q);
	Node *rightAns = lowestCommonAncestor(root->right, p, q);

	if (leftAns != NULL && rightAns != NULL)
	{
		return root;
	}
	else if (leftAns == NULL && rightAns != NULL)
	{
		return rightAns;
	}
	else if (leftAns != NULL && rightAns == NULL)
	{
		return leftAns;
	}
	else
	{
		return NULL;
	}
}

bool solve(Node *root, int targetSum, int sum = 0)
{
	if (root == NULL)
	{
		return false;
	}

	sum += root->data;

	bool rootAns = false;

	// Check whether leaf node and compare sum with targetSum
	if (root->left == NULL && root->right == NULL)
	{
		rootAns = (sum == targetSum);
	}

	bool leftAns = solve(root->left, targetSum, sum);
	bool rightAns = solve(root->right, targetSum, sum);

	return rootAns || leftAns || rightAns;
}

bool hasPathSum(Node *root, int targetSum)
{
	if (root == NULL)
	{
		return false;
	}
	return solve(root, targetSum);
}

void solve(Node *root, int targetSum, vector<vector<int>> &ans, vector<int> v, int sum = 0)
{
	if (root == NULL)
	{
		return;
	}

	sum += root->data;
	v.push_back(root->data);

	if (root->left == NULL && root->right == NULL)
	{
		if (sum == targetSum)
		{
			ans.push_back(v);
		}
		else
		{
			return;
		}
	}

	solve(root->left, targetSum, ans, v, sum);
	solve(root->right, targetSum, ans, v, sum);
}

vector<vector<int>> pathSum(Node *root, int targetSum)
{
	// For empty root
	if (root == NULL)
	{
		return {};
	}

	vector<vector<int>> ans;
	vector<int> v;
	solve(root, targetSum, ans, v);
	return ans;
}

int main()
{
	Node *root = createTree();
	cout << root->data << endl;
	cout << "PRE ORDER: ";
	preOrder(root);
	cout << '\n'
			 << "IN ORDER: ";
	inOrder(root);
	cout << '\n'
			 << "POST ORDER: ";
	postOrder(root);
	cout << '\n';
	levelOrderTraversal(root);
	cout << '\n';
	levelOrderTraversal2(root);
}