#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct huffman_node {
    char character_data;
    int frequency_count;
    struct huffman_node *left_child;
    struct huffman_node *right_child;
};

struct priority_queue {
    int current_size;
    int max_capacity;
    struct huffman_node **heap_array;
};

struct priority_queue *create_priority_queue(int initial_capacity) {
    struct priority_queue *new_queue = (struct priority_queue *)malloc(sizeof(struct priority_queue));
    new_queue->max_capacity = initial_capacity;
    new_queue->current_size = 0;
    new_queue->heap_array = (struct huffman_node **)malloc(initial_capacity * sizeof(struct huffman_node *));
    return new_queue;
}

void swap_nodes(struct huffman_node **a, struct huffman_node **b) {
    struct huffman_node *temporary_node = *a;
    *a = *b;
    *b = temporary_node;
}

void min_heapify(struct priority_queue *queue, int index) {
    int smallest = index;
    int left_index = 2 * index + 1;
    int right_index = 2 * index + 2;
    
    if (left_index < queue->current_size && queue->heap_array[left_index]->frequency_count < queue->heap_array[smallest]->frequency_count) {
        smallest = left_index;
    }
    
    if (right_index < queue->current_size && queue->heap_array[right_index]->frequency_count < queue->heap_array[smallest]->frequency_count) {
        smallest = right_index;
    }
    
    if (smallest != index) {
        swap_nodes(&queue->heap_array[smallest], &queue->heap_array[index]);
        min_heapify(queue, smallest);
    }
}

struct huffman_node *extract_minimum(struct priority_queue *queue) {
    struct huffman_node *min_node = queue->heap_array[0];
    queue->heap_array[0] = queue->heap_array[queue->current_size - 1];
    queue->current_size--;
    min_heapify(queue, 0);
    return min_node;
}

void insert_into_queue(struct priority_queue *queue, struct huffman_node *node) {
    queue->current_size++;
    int current_index = queue->current_size - 1;
    while (current_index > 0 && node->frequency_count < queue->heap_array[(current_index - 1)/2]->frequency_count) {
        queue->heap_array[current_index] = queue->heap_array[(current_index - 1)/2];
        current_index = (current_index - 1)/2;
    }
    queue->heap_array[current_index] = node;
}

void build_huffman_tree(struct priority_queue *queue) {
    while (queue->current_size > 1) {
        struct huffman_node *left_node = extract_minimum(queue);
        struct huffman_node *right_node = extract_minimum(queue);
        
        struct huffman_node *parent_node = (struct huffman_node *)malloc(sizeof(struct huffman_node));
        parent_node->character_data = '\0';
        parent_node->frequency_count = left_node->frequency_count + right_node->frequency_count;
        parent_node->left_child = left_node;
        parent_node->right_child = right_node;
        
        insert_into_queue(queue, parent_node);
    }
}

void generate_codes(struct huffman_node *root_node, char *current_code, char **code_table, int depth) {
    if (root_node == NULL) {
        return;
    }
    
    if (root_node->left_child == NULL && root_node->right_child == NULL) {
        current_code[depth] = '\0';
        code_table[(unsigned char)root_node->character_data] = strdup(current_code);
    }
    
    current_code[depth] = '0';
    generate_codes(root_node->left_child, current_code, code_table, depth + 1);
    
    current_code[depth] = '1';
    generate_codes(root_node->right_child, current_code, code_table, depth + 1);
}

void print_codes(char *input_string, char **code_table) {
    for (int i = 0; input_string[i] != '\0'; i++) {
        printf("%s", code_table[(unsigned char)input_string[i]]);
    }
    printf("\n");
}

int main() {
    char input_string[] = "this is an example for huffman encoding";
    
    int frequency_table[256] = {0};
    for (int i = 0; input_string[i] != '\0'; i++) {
        frequency_table[(unsigned char)input_string[i]]++;
    }
    
    struct priority_queue *queue = create_priority_queue(100);
    for (int i = 0; i < 256; i++) {
        if (frequency_table[i] > 0) {
            struct huffman_node *new_node = (struct huffman_node *)malloc(sizeof(struct huffman_node));
            new_node->character_data = (char)i;
            new_node->frequency_count = frequency_table[i];
            new_node->left_child = NULL;
            new_node->right_child = NULL;
            insert_into_queue(queue, new_node);
        }
    }
    
    build_huffman_tree(queue);
    
    char **code_table = (char **)malloc(256 * sizeof(char *));
    char current_code[100];
    generate_codes(queue->heap_array[0], current_code, code_table, 0);
    
    printf("Encoded string: ");
    print_codes(input_string, code_table);
    
    return 0;
}