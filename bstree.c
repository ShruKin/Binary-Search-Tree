#include <stdio.h>
#include <malloc.h>

struct BSTree{
    int data;
    struct BSTree *left, *right;
};

struct BSTree* insert(struct BSTree *root, int data){
    struct BSTree *node = (struct BSTree *)malloc(sizeof(struct BSTree));
    node->data = data;
    node->left = NULL;
    node->right = NULL;

    struct BSTree *ptr=root, *prev_ptr=NULL;

    if(root == NULL)
        root = node;

    else{
        while(ptr != NULL){
            prev_ptr = ptr;
            if(data < ptr->data)
                ptr = ptr->left;
            else
                ptr = ptr->right;
        }

        if(data < prev_ptr->data)
            prev_ptr->left = node;
        else
            prev_ptr->right = node;
    }

    return root;
}

struct BSTree* insert_recur(struct BSTree *node, int data) 
{ 
    /* If the tree is empty, return a new node */
    if (node == NULL){
        node = (struct BSTree *)malloc(sizeof(struct BSTree));
        node->data = data;
        node->left = NULL;
        node->right = NULL;
        return node;
    } 
  
    /* Otherwise, recur down the tree */
    if (data < node->data) 
        node->left  = insert(node->left, data); 
    else if (data > node->data) 
        node->right = insert(node->right, data);    
  
    /* return the (unchanged) node pointer */
    return node; 
}

struct BSTree* create(){
    struct BSTree *root = NULL;
    int data;

    printf("Enter data: ");
    scanf("%d", &data);

    while(data != -1){
        root = insert(root, data);        
        printf("Enter data: ");
        scanf("%d", &data);
    }

    return root;
}

struct BSTree* create_recur(){
    struct BSTree *root = NULL;
    int data;

    printf("Enter data: ");
    scanf("%d", &data);
    if( data != -1)
        root = insert_recur(root, data);        

    while(data != -1){
        printf("Enter data: ");
        scanf("%d", &data);

        if(data != -1)
            insert_recur(root, data);        
    }

    return root;
}

void preorder(struct BSTree *root)
{
	if(root != NULL)
	{
		printf("%d ",root->data);	
		preorder(root->left);
		preorder(root->right);
	}
}

void postorder(struct BSTree *root)
{
	if(root != NULL)
	{
		postorder(root->left);
		postorder(root->right);
		printf("%d ",root->data);	
	}
}

void inorder(struct BSTree *root)
{
	if(root != NULL)
	{
		inorder(root->left);
		printf("%d ",root->data);	
		inorder(root->right);
	}
}

int height(struct BSTree *root)  
{  
    if (root == NULL)  
        return 0;  
    else
    {  
        int lheight = height(root->left);  
        int rheight = height(root->right);  

        if (lheight > rheight)  
            return(lheight + 1);  
        else 
            return(rheight + 1);  
    }  
}  

int search(struct BSTree *root, int data){
    if(root == NULL)
        return 0;

    if(root->data == data)
        return 1;

    if(data < root->data)
        return search(root->left, data);
    else
        return search(root->right, data);
}