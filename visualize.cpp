#include "bstree.c"
#include <iostream>
#include <queue>
#include <math.h>

using namespace std;

struct asciiBSTree{
    struct BSTree *tree;
    int pos;
};

void visualize(struct BSTree *root){
    int h = height(root);
    int *arr_tree = (int *)malloc((pow(2,h)-1) * sizeof(int));

    for(int i=0; i<(pow(2,h)-1); i++)
        arr_tree[i] = -1;


    queue <asciiBSTree> q;
    q.push({root, 0});

    while(q.empty() ==  false){
        struct asciiBSTree node = q.front();
        arr_tree[node.pos] = node.tree->data;
        q.pop();

        if(node.tree->left != NULL)
            q.push({node.tree->left, 2*node.pos+1});

        if(node.tree->right != NULL)
            q.push({node.tree->right, 2*node.pos+2});
    }

    int k=0, head_space, int_space;
    for(int i=0; i<h; i++){
        head_space = pow(2,(h-i-1))-1;
        int_space = pow(2,(h-i))-1;

        for(int j=0; j<head_space; j++)
            printf("  ");

        for(int j=0; j<(pow(2,i)); j++){
            if(arr_tree[k] == -1)
                printf("  ");
            else
                printf("%2d", arr_tree[k]);

            for(int l=0; l<int_space; l++)
                printf("  ");

            k++;
        }

        printf("\n");
    }
}