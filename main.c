#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct
{
    char data[50];
    struct Node *left,*right;
} Node;
Node *newNode(char *x)
{
    Node *n = malloc(sizeof(Node));
    strcpy(n -> data,x);
    n -> left = NULL;
    n -> right = NULL;
    return n;
}
Node*findMin(Node*root)
{
    if(root==NULL)
        return NULL;
    while(root->left!=NULL)
        root=root->left;
    return root;
}
void Inorder(Node *root)
{
    if(root != NULL)
    {
        Inorder(root -> left);
        printf("%s ", root -> data);
        Inorder(root -> right);
    }
}
int max(int a,int b)
{
    return a>b?a:b;
}
int Height(Node *root)
{
    if(root == NULL)
        return -1;
    else return 1 + max(Height(root -> left), Height(root -> right));
}
int Size(Node *root)
{
    if(root == NULL)
        return 0;
    else return 1 + Size(root -> left) + Size(root -> right);
}
Node *insert(Node *root,char *x)
{
    if(root == NULL)
        root = newNode(x);
    else if(strcasecmp(x,root -> data) < 0)
        root -> left = insert(root -> left, x);
    else if(strcasecmp(x,root -> data))
        root -> right = insert(root -> right, x);
        return root;
}
Node *GenerateTree()
{
    FILE *f = fopen("C:\\Users\\AbdElrahman\\Downloads\\Dictionary (1).txt ", "r");
    if (!f)
    {
        printf("File Not Found!");
        exit(-1);
    }
    Node *root = NULL;
    while(!feof(f))
    {
        char s[50];
        fscanf(f,"%[^\n]%*c", s);
        root = insert(root, s);
    }
    fclose(f);
    return root;
}
Node *Search(Node *root,char *s)
{
    if(root == NULL)
        return NULL;
    if(strcasecmp(s, root -> data) == 0)
        return root;
    else if(strcasecmp(s,root -> data) < 0)
        return Search(root -> left, s);
    else return Search(root -> right, s);
}
Node *Search_last(Node *root,char *s)
{
    if(root == NULL)
        return NULL;
    if(strcasecmp(s, root -> data)<0)
        {
        if(root->left==NULL)
        {
         return root;}
        else
            return Search_last(root -> left, s);
        }
    else if(strcasecmp(s,root -> data)>0)
     {
      if(root->right==NULL){
       return root;}
       else
        return Search_last(root -> right, s);
     }
}
int check(Node*root,char*s)
{
    if(!Search(root,s))
     return 0;
    else return 1;
}
Node*successor(Node*root,char*data)
{
    Node*current=Search_last(root,data);
    if(current==NULL)
        return NULL;
 if(current->right!=NULL)
       {
    return findMin(current->right);
       }
 else
     {
         Node*successor=NULL;
         Node*ancestor=root;
         while(ancestor!=current)
         {
             if(strcasecmp(ancestor->data,current -> data)>0){
                    successor=ancestor;
                ancestor=ancestor->left;}
             else
             ancestor=ancestor->right;
         }

    return successor;
     }

}
Node* findMax(Node*root) {
    Node*current =root;
    while (current->right!=NULL) {
        current=current->right;
    }
    return current;
}
Node*predecessor(Node*root,char*data)
{
    Node* current=Search_last(root,data);
    if (current==NULL)
        return NULL;
    if (current->left!=NULL) {
        return findMax(current->left);
    } else {
        Node* predecessor=NULL;
        Node* ancestor =root;
        while (ancestor!=current) {
            if (strcasecmp(ancestor->data, current->data) < 0) {
                predecessor = ancestor;
                ancestor=ancestor->right;
            } else {
                ancestor=ancestor->left;
            }
        }
        return predecessor;
    }
}

int main()
{ char sent[100];
char*word;
    Node *n = GenerateTree();
    if(n)
        printf("Dictionary Loaded Successfully!\n");
    printf("........................................\n");
    printf("Size = %d\n", Size(n));
    printf("........................................\n");
    printf("Height = %d\n", Height(n));
    printf("........................................\n");
    printf("Enter a sentence: ");
    fgets(sent,99,stdin);
    sent[strcspn(sent, "\n")] = '\0';
    word=strtok(sent," ");
        while (word != NULL) {
                if(check(n,word))
            printf("%s - CORRECT\n", word);
        else{
        printf("%s -INCORRECT,suggestions:",word);
        Node*l =Search_last(n,word);
        Node*s=successor(n,word);
        Node*p=predecessor(n,word);
        printf("%s, %s, %s",l->data,s->data,p->data);
          }
          printf("\n");
        word= strtok(NULL," ");
        }



    return 0;
}
