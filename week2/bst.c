#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node*left;
    struct node*right;
};
struct node*root=NULL;
struct node* createNewNode(int data){
     struct node*temp=(struct node*)malloc(sizeof(struct node));
     temp->data=data;
     temp->left=NULL;
     temp->right=NULL;
     return temp;
}
struct node* findmin(struct node*root){
    struct node*temp=root;
    while(temp->left!=NULL){
        temp=temp->left;
    }  
    return temp;
}
struct node* insertNode(struct node*node,int data){
    if(node==NULL)
       return createNewNode(data);
    if(data<node->data)
       node->left= insertNode(node->left,data);
    else
      node->right= insertNode(node->right,data);
    return node;
}
struct node*deleteNode(struct node*root,int data){
    if(root==NULL){
        printf("empty\n");
        return root;
    }
    if(root->data>data){
        root->left=deleteNode(root->left,data);
    }
    else if(root->data<data){
        root->right=deleteNode(root->right,data);
    }
    else{
        if(root->left==NULL&&root->right==NULL){
            free(root);
            return NULL;
        }
        else if(root->left == NULL){
            struct node* temp = root->right;
            free(root);
            return temp;
         }
        else if(root->right == NULL){
            struct node* temp = root->left;
            free(root);
            return temp;
        }

        else{
            struct node*temp=findmin(root->right);
            root->data=temp->data;
            root->right=deleteNode(root->right,temp->data);
        }
    }
    return root;
}
void inorder(struct node*root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    printf("%d  ",root->data);
    inorder(root->right);
}
int main(){
    int choice,data;
    while(1){
      printf("1)Insert\n2)delete\n3)display\n4)exit\n");
      printf("enter your choice\n");
      scanf("%d",&choice);
      switch(choice){
      case 1:
          printf("enter the data:\n");
          scanf("%d",&data);
          root=insertNode(root,data);
         break;
      case 2:
        printf("enter the data:\n");
        scanf("%d",&data);
        root=deleteNode(root,data);
        break;
      case 3:
         inorder(root);
         printf("\n");
         break;
      case 4:
          exit(0);
      default:
         printf("invalid choice\n");
    }
}
    return 0;
}