typedef struct tree {
    char* word;
    struct tree* left;
    struct tree* right;
    struct tree* parent;
} treeNode;

typedef treeNode* node;

node Min(node root);
node Max(node root);

void insert(node* root, char* value);
void removeNode(node* root, char* value);
char* treeMax(node root);
char* treeMin(node root);
char* ancestor(node root);
char* descendant(node root);
void printTree(node root);

// ZADANIE 15
void saveToFile(node root);
void readFromFile(node* root, char* filename);