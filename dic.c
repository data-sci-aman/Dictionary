#include <stdio.h>
#include <stdlib.h>

struct dict{
    struct dict *left, *right;
    char word[10],meaning[20];
} * Root=NULL;


typedef struct dict dictionary;
int check(char[], char[]);
void insert(dictionary *);
void search();
void view(dictionary *);

int check (char a[], char b[]){
    int i,j,c;
    for(i=0,j=0; a[i]!='\0'&& b[i]!='\0'; i++,j++){
        if(a[i]>b[j]){
            c=1;
            break;
        }else if (a[i]<b[j]){
            c=-1;
            break;
        }else{
            c=0;
        }
    }
    if(c==1)
        return 1;
    else if(c==-1)
        return -1;
    else 
        return 0;        
}

void Search(){
    char word[10];
    dictionary *ptr;
    int flag=0;
    ptr=Root;
    printf("\nEnter the word");
    scanf("%s",word);
    while(ptr!=NULL && flag==0){
        if(check(word,ptr->word)==1)
            ptr=ptr->right;
        else if(check(word,ptr->word)==-1)
            ptr=ptr->left;
        else{
            flag=1;
            printf("\nMeaning is:%s",ptr->meaning);
            break;
        }
    }
    if(flag==0 && ptr==NULL)
        printf("\nWord not found!");
}

void insert(dictionary *temp){
    dictionary *ptr,*par;
    int flag=0;
    ptr=Root;
    if(Root==NULL){
        Root=temp;
    }
    else{
        while(ptr!=NULL){
        if(check(temp->word,ptr->word)==1){
            par=ptr;
            ptr=ptr->right;
        }
        else if(check(temp->word,ptr->word)==-1){
            par=ptr;
            ptr=ptr->left;
        }
        else{
            flag=1;
            printf("Word already exists!");
            break;
        }
    }
    if(flag==0){
        if(check(par->word,temp->word)==1)
            par->left=temp;
        else if(check(par->word,temp->word)==-1)
            par->right=temp; 
    }
       
    }
    
}
void view(dictionary *ptr){
    if(Root==NULL){
        printf("\nEmpty Dictionary!!");
    }
    else{
        if(ptr!=NULL){
            view(ptr->left);
            printf("\nWord: %s",ptr->word);
            printf("\nWord: %s",ptr->meaning);
            view(ptr->right);
        }
    }
        
}

int main(){
    int choice;
    dictionary *temp;
    while(choice!=4){
        printf("1.Search\n2.Insert\n3.View\n4.Quit\nEnter Your Choice-");
        scanf("%d",&choice);
        switch(choice){
            case 1:Search(); break;
            case 2: 
            temp=(dictionary *)malloc(sizeof(dictionary));
            temp->left=NULL;
            temp->right=NULL;
            printf("\nInsert Word:");
            scanf("%s",temp->word);
            printf("\nInsert Meaning:");
            scanf("%s",temp->meaning);
            insert(temp);
            break;
            case 3: view(Root);break;
            case 4: exit(0);
        }
    }
    return 0;
}