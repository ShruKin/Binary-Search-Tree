#include "visualize.cpp"

int main(int argc, char const *argv[])
{
    int ch, data;
    struct BSTree *root = NULL;

    while(1){
        printf("MENU");
        printf("\n1. Create");
        printf("\n2. Insert");
        printf("\n3. Visualize");
        printf("\n4. Inorder");
        printf("\n5. Preorder");
        printf("\n6. Postorder");
        printf("\n7. Search");
        printf("\n0. EXIT");

        printf("\nEnter choice: ");
        scanf("%d", &ch);

        printf("\n");
        switch(ch){
            case 0: exit(0);    break;

            case 1: root = create();    break;

            case 2:
                printf("Enter data: ");
                scanf("%d", &data);
                root = insert(root, data);
                break;

            case 3: visualize(root);    break;

            case 4: inorder(root);  break;

            case 5: preorder(root); break;

            case 6: postorder(root);    break;

            case 7: 
                printf("Enter data: ");
                scanf("%d", &data);

                if(search(root, data))
                    printf("%d found in the BSTree!", data);
                else
                    printf("%d not found in the BSTree!", data);

        }
        printf("\n\n");
    }

    return 0;
}
