typedef struct tree {
    int value;
    struct tree* left;
    struct tree* right;
    struct tree* parent;
} treeNode;

typedef treeNode* node;

void insert(node* root, int val);
int containSameValues(node* tree1, node* tree2);
node ancestor(node root);
node descendant(node root);
node Min(node root);
node Max(node root);
void printTree(node root);