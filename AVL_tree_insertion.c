#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data, height;
    struct Node *left, *right;
}Node;

Node* createNode(int data){
    Node* newNode = (Node*)malloc(sizeof(Node));

    newNode->data = data;
    newNode->height = 0;
    newNode->left = newNode->right = NULL;

    return newNode;
}

int max(int a, int b){
    return a>=b ? a : b;
}

//height
int getHeight(Node* root){
    if(root == NULL){
        return 0;
    }
    return root->height;
}

//bFactor
int getBfactor(Node* root){
    if(root==NULL){
        return 0;
    }
    return (getHeight(root->left) - getHeight(root->right));
}

//rightRotate
Node* rightRotate(Node* root){
    Node* y = root->left;
    Node* j = y->right;

    //Modifying three pointers
    root->left = j;
    y->right = root;

    //update Heights
    root->height = max(getHeight(root->left), getHeight(root->right)) + 1;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

    root = y;

    return root;
}

//leftRotate
Node* leftRotate(Node* root){
    Node* y = root->right;
    Node* j = y->left;

    //Modifying three pointers
    root->right = j;
    y->left = root;

    //update Heights
    root->height = max(getHeight(root->left), getHeight(root->right)) + 1;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

    root = y;


    return root;
}

Node* leftRightRotate(Node* root){
   root->left = leftRotate(root->left);
   return rightRotate(root);

}

Node* rightLeftRotate(Node* root){
    root->right = rightRotate(root->right);
    return leftRotate(root);

}

//insert
Node* insertNode(int data, Node* root){
    //base case
    if(root==NULL){
        //creating a newNode
        Node* newNode = createNode(data);
        return newNode;
    }
    //Normal BST recurssive insert
    if(data < root->data){
        root->left = insertNode(data, root->left);
    }
    else if(data > root->data){
        root->right = insertNode(data, root->right);
    }
    else{
        return root;
    }

    //updating height after the insertion
    root->height = max(getHeight(root->left), getHeight(root->right)) + 1;
    
    //now checking bFactor
    
    if(getBfactor(root)>1){
        if(root->left && data < root->left->data){
            root = rightRotate(root);
        }
        else if(root->left && data > root->left->data){
            root = leftRightRotate(root);  
        }
    }
    else if(getBfactor(root) < -1){
        if(root->right && data > root->right->data){
            root = leftRotate(root);
            root->height = max(getHeight(root->left), getHeight(root->right)) + 1;
        }
        else if(root->right && data < root->right->data){
            root = rightLeftRotate(root);
            root->height = max(getHeight(root->left), getHeight(root->right)) + 1;
        }
    }
    
    root->height = max(getHeight(root->left), getHeight(root->right)) + 1;
    
    
    return root;

}

void inorder(Node* root){
    if(root!=NULL){
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void preorder(Node* root){
    if(root!=NULL){
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}
//erase


//find

int main(){

    Node* root = NULL;

    root = insertNode(21, root);
    root = insertNode(14, root);
    root = insertNode(35, root);
    root = insertNode(9, root);
    root = insertNode(17, root);
    root = insertNode(16, root);
    // root = insertNode(, root);


    printf("inorder: ");
    inorder(root);
    printf("\npreorder: ");
    preorder(root);
    printf("\nheight of the AVL tree is : %d\n",  getHeight(root));
    return 0;
}
