#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAXINPUT 1024
#define MAXHEAP 50

struct huffman_node {
    char data;
    int freq;
    struct huffman_node *left, *right;
};

struct huffman_node *heap[MAXHEAP]; //Initialize HEAP
int last_index = -1;

struct huffman_node* create_node(char data);
void add_char_to_heap(char data);
void print_inorder(struct huffman_node* root);
void print_heap();
void swap(struct huffman_node* a, struct huffman_node* b);
void min_heapify(int n);
struct huffman_node* dequeue();
void enqueue(struct huffman_node* root);
void create_huffman_tree();
void print_huffman_code(struct huffman_node* root,int array[MAXINPUT],int top);
void print_huffman_encoded(struct huffman_node* root,int array[MAXINPUT],int top,char key);

int main()
{
    char input[MAXINPUT];
    printf("Enter Sentence: ");
    fgets(input,MAXINPUT,stdin);

    int i = 0;
    while(input[i] != '\n'){
        add_char_to_heap(input[i]);
        i++;
    }

    printf("\n1. Frequency table of %d characters\n",last_index+1);
    print_heap();

    printf("\n2.1 A Min-Heap (the less frequency, the higher priority)\n");
    min_heapify(last_index);
    print_heap();

    printf("\n2.2 A Huffman Tree\n");
    create_huffman_tree();
    print_inorder(heap[0]);
    printf("\n");

    printf("\n3. Huffman code for each character\n");
    int array[MAXINPUT];
    print_huffman_code(heap[0],array,0);
    
    printf("\n4. Encoded sentence\n");
    i = 0;
    while(input[i] != '\n'){
        print_huffman_encoded(heap[0],array,0,input[i]);
        i++;
    }

    return 0;
}

struct huffman_node* create_node(char data){
    struct huffman_node *new_node = malloc(sizeof(struct huffman_node));
    new_node->data = data;
    new_node->freq = 1;
    new_node->left = NULL;
    new_node->right = NULL;

    return new_node;
}


void add_char_to_heap(char data){
    for(int i = 0; i <= last_index;i++){
        if((heap[i])->data == data){
            (heap[i]->freq)++;
            return;
        }
    }

    struct huffman_node *new_node = create_node(data);
    last_index++;
    heap[last_index] = new_node;
}

void swap(struct huffman_node* a, struct huffman_node* b){
    struct huffman_node temp = *a;
    *a = *b;
    *b = temp;
}

void min_heapify(int n){
    int par_index = n/2-1;
    int left_index,right_index;

    while(par_index >= 0){
        left_index = 2*par_index+1;
        right_index = 2*par_index+2;
        while(left_index < n){
            int min_index = par_index;

            if(heap[left_index]->freq < heap[min_index]->freq){
                min_index = left_index;
            }

            if(heap[right_index]->freq < heap[min_index]->freq && right_index < n){
                min_index = right_index;
            }

            if(min_index == par_index) break;

            swap(heap[par_index],heap[min_index]);

            par_index = min_index;
            left_index = 2*par_index+1;
            right_index = 2*par_index+2;
        }

        par_index--;
    }             
}

void print_heap(){
    for(int i = 0;i <= last_index;i++){
        printf("'%c':%d ",(heap[i])->data,(heap[i])->freq);
    }
    printf("\n");
}

void print_inorder(struct huffman_node* root){
    if(root != NULL){
        print_inorder(root->left);
        printf("'%c':%d ",root->data,root->freq);
        print_inorder(root->right);
    }

    return;
}


void create_huffman_tree(){
    while(last_index > 0){
        struct huffman_node* t1 = dequeue();
        struct huffman_node* t2 = dequeue();
        struct huffman_node* new_tree = create_node('-');
        new_tree->left = t1;
        new_tree->right = t2;
        new_tree->freq = t1->freq + t2->freq;
        enqueue(new_tree);
    }
}

struct huffman_node* dequeue() {
    if (last_index < 0) return NULL;
    
    struct huffman_node* root = heap[0];
    heap[0] = heap[last_index];
    last_index--;
    min_heapify(last_index);
    
    return root;
}

void enqueue(struct huffman_node* root){
    last_index++;
    heap[last_index] = root; 

    min_heapify(last_index);
}

void print_huffman_code(struct huffman_node* root,int array[MAXINPUT],int top){
    if(root->left != NULL){
        array[top] = 0;
        print_huffman_code(root->left, array,top + 1);
    }

    if(root->right != NULL){
        array[top] = 1;
        print_huffman_code(root->right, array,top + 1);
    }

    if(root->left == NULL && root->right == NULL){
        printf("%c ->",root->data);
        for(int i = 0;i < top;i++){
            printf("%d",array[i]);
        }
        printf("\n");
    }
}

void print_huffman_encoded(struct huffman_node* root,int array[MAXINPUT],int top,char key){
    if(root->left != NULL){
        array[top] = 0;
        print_huffman_encoded(root->left, array,top + 1,key);
    }

    if(root->right != NULL){
        array[top] = 1;
        print_huffman_encoded(root->right, array,top + 1,key);
    }

    if(root->left == NULL && root->right == NULL && root->data == key){
        for(int i = 0;i < top;i++){
            printf("%d",array[i]);
        }
        printf(" ");
    }
}