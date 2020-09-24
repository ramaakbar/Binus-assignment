#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct data {
    int number;
    struct data *left, *right;
} * root;

bool found = false;

void clear() {
    int i;
    for (i = 0; i < 25; i++) printf("\n");
}

void push(struct data **temp, int number) {
    if (*temp == NULL) {
        *temp = (struct data *)malloc(sizeof(struct data));
        (*temp)->number = number;
        (*temp)->left = (*temp)->right = NULL;

        printf("\n\n\n --- Number added to tree ---\n");
    } else {
        if (number < (*temp)->number) {
            push(&(*temp)->left, number);
        } else if (number > ((*temp)->number)) {
            push(&(*temp)->right, number);
        } else {
            printf("\n\n\n --- cannot input number ---\n");
        }
    }
}

void popall(struct data *temp) {
    if (temp != NULL) {
        popall(temp->left);
        popall(temp->right);
        free(temp);
    }
}

void add() {
    int number;

    printf("\n\n\n");
    do {
        printf(" Input Number: ");
        scanf("%d", &number);
        fflush(stdin);
    } while (number <= 0);
    printf("\n");
    push(&root, number);

    getchar();
    fflush(stdin);
}

void searchupdate(struct data **temp, int number) {
    if ((*temp) != NULL) {
        if ((*temp)->number == number) {
            found = true;
        }
        searchupdate(&(*temp)->left, number);
        searchupdate(&(*temp)->right, number);
    }
}

void search() {
    int number;
    printf("\n\n\n");
    do {
        printf(" Input Number: ");
        scanf("%d", &number);
        fflush(stdin);
    } while (number <= 0);
    found = false;
    searchupdate(&root, number);
    if (found == false) {
        printf("\n\n\n --- number not found ---\n");
    } else {
        printf("\n\n\n --- number is found ---\n");
    }
    getchar();
    fflush(stdin);
}

void InOrder(struct data *temp) {
    if (temp) {
        InOrder(temp->left);
        printf(" - %d\n", temp->number);
        InOrder(temp->right);
    }
}

void PreOrder(struct data *temp) {
    if (temp) {
        printf(" - %d\n", temp->number);
        PreOrder(temp->left);
        PreOrder(temp->right);
    }
}

void PostOrder(struct data *temp) {
    if (temp) {
        PostOrder(temp->left);
        PostOrder(temp->right);
        printf(" - %d\n", temp->number);
    }
}

void inprepost() {
    clear();
    if (root == NULL) {
        printf(" --- There is No Data ---\n");
    } else {
        printf("\n Preorder  : \n");
        PreOrder(root);
        printf("\n Inorder   : \n");
        InOrder(root);
        printf("\n Postorder : \n");
        PostOrder(root);
    }
    getchar();
    fflush(stdin);
}

void menu() {
    printf("\n BST");
    printf("\n ----------------------\n");
    printf("\n 1. Add Tree");
    printf("\n 2. Search");
    printf("\n 3. InOrder, PreOrder, PostOrder");
    printf("\n 4. Exit");
    printf("\n\n >> Input choice : ");
}

int main() {
    push(&root, 3);
    push(&root, 8);
    push(&root, 5);
    push(&root, 1);
    push(&root, 2);
    push(&root, 9);
    push(&root, 10);
    push(&root, 6);
    int choice;
    do {
        clear();
        menu();
        scanf("%d", &choice);
        fflush(stdin);

        switch (choice) {
            case 1:
                add();
                break;
            case 2:
                search();
                break;
            case 3:
                inprepost();
                break;
        }
    } while (choice != 4);
    popall(root);
    return 0;
}