#include <iostream>
using namespace std;

// Definition of a Node in the BST
struct BST {
    int data;
    BST* left;
    BST* right;
};

// Level order traversal function
void level_order(BST* root) {
    if (root == NULL)
        return;

    // Declare queue
    BST* queue[100]; // Array to act as a queue
    int front = 0, rear = 0;

    // enqueue(root)
    queue[rear++] = root;

    // while(queue is not empty)
    while (front != rear) {
        // cur = top(q);
        BST* cur = queue[front++];

        // dequeue(q);
        // (Front element already dequeued using front++)

        // printf("%d\n", cur->data);
        printf("%d\n", cur->data);

        // if(cur->left != NULL)
        if (cur->left != NULL)
            // enqueue(cur->left);
            queue[rear++] = cur->left;

        // if(cur->right != NULL)
        if (cur->right != NULL)
            // enqueue(cur->right);
            queue[rear++] = cur->right;
    }
}

int main() {
    // Manually constructing the tree
    BST n1 = {10, nullptr, nullptr};
    BST n2 = {6, nullptr, nullptr};
    BST n3 = {15, nullptr, nullptr};
    BST n4 = {3, nullptr, nullptr};
    BST n5 = {8, nullptr, nullptr};
    BST n6 = {20, nullptr, nullptr};

    // Linking nodes to form the tree
    n1.left = &n2;
    n1.right = &n3;
    n2.left = &n4;
    n2.right = &n5;
    n3.right = &n6;

    // Perform level-order traversal
    printf("Level-order traversal of the BST:\n");
    level_order(&n1);

    return 0;
}
