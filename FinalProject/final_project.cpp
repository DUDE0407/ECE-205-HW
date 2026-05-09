#include <iostream>
#include <stack>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

// each node stores a value (number or operator) and has left/right children
struct TreeNode {
    string val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(string v) : val(v), left(nullptr), right(nullptr) {}
};

bool isOperator(const string& token) {
    return token == "+" || token == "-" || token == "*" || token == "/";
}

// higher number means higher priority
int precedence(const string& op) {
    if (op == "+" || op == "-") return 1;
    if (op == "*" || op == "/") return 2;
    return 0;
}

// pop one operator and two operands, combine them into a subtree
void combine(stack<TreeNode*>& operandStack, stack<string>& operatorStack) {
    TreeNode* right = operandStack.top(); operandStack.pop();
    TreeNode* left  = operandStack.top(); operandStack.pop();
    string    op    = operatorStack.top(); operatorStack.pop();

    TreeNode* node = new TreeNode(op);
    node->left  = left;
    node->right = right;
    operandStack.push(node);
}

// build an expression tree from a list of tokens using two stacks
TreeNode* buildTree(const vector<string>& tokens) {
    stack<TreeNode*> operandStack;
    stack<string>    operatorStack;

    for (const string& token : tokens) {
        if (token == "(") {
            operatorStack.push(token);

        } else if (token == ")") {
            // combine everything inside the parentheses
            while (!operatorStack.empty() && operatorStack.top() != "(") {
                combine(operandStack, operatorStack);
            }
            operatorStack.pop(); // discard the "("

        } else if (isOperator(token)) {
            // pop operators with higher or equal precedence first
            while (!operatorStack.empty() &&
                   operatorStack.top() != "(" &&
                   precedence(operatorStack.top()) >= precedence(token)) {
                combine(operandStack, operatorStack);
            }
            operatorStack.push(token);

        } else {
            // it's a number, just push it as a leaf node
            operandStack.push(new TreeNode(token));
        }
    }

    // handle any remaining operators
    while (!operatorStack.empty()) {
        combine(operandStack, operatorStack);
    }

    return operandStack.top();
}

// postorder traversal prints the expression in postfix form
void postorder(TreeNode* node) {
    if (!node) return;
    postorder(node->left);
    postorder(node->right);
    cout << node->val << " ";
}

// evaluate the tree using a stack (iterative postorder traversal)
double evaluate_stack(TreeNode* root) {
    // use two stacks to get postorder sequence without recursion
    stack<TreeNode*> s1;
    stack<TreeNode*> s2;
    s1.push(root);
    while (!s1.empty()) {
        TreeNode* cur = s1.top(); s1.pop();
        s2.push(cur);
        if (cur->left)  s1.push(cur->left);
        if (cur->right) s1.push(cur->right);
    }

    // process nodes in postorder and compute the result
    stack<double> valueStack;
    while (!s2.empty()) {
        TreeNode* cur = s2.top(); s2.pop();

        if (!cur->left && !cur->right) {
            valueStack.push(stod(cur->val));
        } else {
            double right = valueStack.top(); valueStack.pop();
            double left  = valueStack.top(); valueStack.pop();
            if (cur->val == "+") valueStack.push(left + right);
            else if (cur->val == "-") valueStack.push(left - right);
            else if (cur->val == "*") valueStack.push(left * right);
            else if (cur->val == "/") valueStack.push(left / right);
        }
    }

    return valueStack.top();
}

int treeDepth(TreeNode* node) {
    if (!node) return 0;
    int l = treeDepth(node->left);
    int r = treeDepth(node->right);
    return 1 + (l > r ? l : r);
}


void freeTree(TreeNode* node) {
    if (!node) return;
    freeTree(node->left);
    freeTree(node->right);
    delete node;
}

// split the input string into tokens by whitespace
vector<string> tokenize(const string& expr) {
    vector<string> tokens;
    istringstream iss(expr);
    string token;
    while (iss >> token) {
        tokens.push_back(token);
    }
    return tokens;
}

int main() {
    cout << "ECE 205 Final Project - Infix Expression Evaluator\n";
    cout << "====================================================\n";
    cout << "Enter an infix expression (operators and numbers separated by spaces):\n";
    cout << "Example: ( 16 + 2 ) * 5 - 28 / 4\n\n";

    cout << "Expression: ";
    cout.flush();
    string line;
    while (getline(cin, line)) {
        // strip trailing \r (Windows line endings)
        if (!line.empty() && line.back() == '\r') line.pop_back();
        if (!line.empty()) break;
    }

    if (line.empty()) {
        cout << "No input provided.\n";
        return 1;
    }

    vector<string> tokens = tokenize(line);
    TreeNode* root = buildTree(tokens);

    cout << "\n[1] Postfix expression: ";
    postorder(root);
    cout << "\n";


    double result = evaluate_stack(root);
    cout << "\n[2] Result: ";
    if (result == (int)result)
        cout << (int)result << "\n";
    else
        cout << result << "\n";

    freeTree(root);
    return 0;
}
