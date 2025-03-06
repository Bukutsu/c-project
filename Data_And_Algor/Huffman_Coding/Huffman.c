#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A Huffman tree node
typedef struct MinHeapNode {
  char data;                 // Input character
  unsigned freq;             // Frequency of the character
  struct MinHeapNode *left;  // Left child
  struct MinHeapNode *right; // Right child
} MinHeapNode;

// A Min Heap (Priority Queue)
typedef struct MinHeap {
  unsigned size;       // Current size of min heap
  unsigned capacity;   // Capacity of min heap
  MinHeapNode **array; // Array of minheap node pointers
} MinHeap;

// Utility function to allocate a new min heap node
MinHeapNode *newNode(char data, unsigned freq) {
  MinHeapNode *temp = (MinHeapNode *)malloc(sizeof(MinHeapNode));
  temp->left = temp->right = NULL;
  temp->data = data;
  temp->freq = freq;
  return temp;
}

// Utility function to create a min heap of given capacity
MinHeap *createMinHeap(unsigned capacity) {
  MinHeap *minHeap = (MinHeap *)malloc(sizeof(MinHeap));
  minHeap->size = 0;
  minHeap->capacity = capacity;
  minHeap->array = (MinHeapNode **)malloc(minHeap->capacity * sizeof(MinHeapNode *));
  return minHeap;
}

// Utility function to swap two min heap nodes
void swapMinHeapNode(MinHeapNode **a, MinHeapNode **b) {
  MinHeapNode *t = *a;
  *a = *b;
  *b = t;
}

// Standard minHeapify function
void minHeapify(MinHeap *minHeap, int idx) {
  int smallest = idx;
  int left = 2 * idx + 1;
  int right = 2 * idx + 2;

  if (left < minHeap->size &&
      minHeap->array[left]->freq < minHeap->array[smallest]->freq)
    smallest = left;

  if (right < minHeap->size &&
      minHeap->array[right]->freq < minHeap->array[smallest]->freq)
    smallest = right;

  if (smallest != idx) {
    swapMinHeapNode(&minHeap->array[smallest], &minHeap->array[idx]);
    minHeapify(minHeap, smallest);
  }
}

// Function to check if size of heap is 1 or not
int isSizeOne(MinHeap *minHeap) {
  return (minHeap->size == 1);
}

// Function to extract minimum value node from heap
MinHeapNode *extractMin(MinHeap *minHeap) {
  MinHeapNode *temp = minHeap->array[0];
  minHeap->array[0] = minHeap->array[minHeap->size - 1];
  --minHeap->size;
  minHeapify(minHeap, 0);
  return temp;
}

// Function to insert a new node to Min Heap
void insertMinHeap(MinHeap *minHeap, MinHeapNode *minHeapNode) {
  ++minHeap->size;
  int i = minHeap->size - 1;

  while (i && minHeapNode->freq < minHeap->array[(i - 1) / 2]->freq) {
    minHeap->array[i] = minHeap->array[(i - 1) / 2];
    i = (i - 1) / 2;
  }

  minHeap->array[i] = minHeapNode;
}

// Function to build min heap
void buildMinHeap(MinHeap *minHeap) {
  int n = minHeap->size - 1;
  for (int i = (n - 1) / 2; i >= 0; --i)
    minHeapify(minHeap, i);
}

// Print an array of size n
void printArr(int arr[], int n) {
  for (int i = 0; i < n; ++i)
    printf("%d", arr[i]);
  printf("\n");
}

// Check if this node is a leaf
int isLeaf(MinHeapNode *root) {
  return !(root->left) && !(root->right);
}

// Creates a min heap of capacity equal to size and inserts all characters
// of data[] in min heap
MinHeap *createAndBuildMinHeap(char data[], int freq[], int size) {
  MinHeap *minHeap = createMinHeap(size);

  for (int i = 0; i < size; ++i)
    minHeap->array[i] = newNode(data[i], freq[i]);

  minHeap->size = size;
  buildMinHeap(minHeap);
  return minHeap;
}

// The main function that builds Huffman tree
MinHeapNode *buildHuffmanTree(char data[], int freq[], int size) {
  MinHeapNode *left, *right, *top;

  // Step 1: Create a min heap of capacity equal to size
  MinHeap *minHeap = createAndBuildMinHeap(data, freq, size);

  // Iterate while size of heap doesn't become 1
  while (!isSizeOne(minHeap)) {
    // Step 2: Extract the two minimum frequency items from min heap
    left = extractMin(minHeap);
    right = extractMin(minHeap);

    // Step 3: Create a new internal node with frequency equal to the
    // sum of the two nodes' frequencies. Make the two extracted nodes
    // as left and right children of this new node. Add this node to the min heap
    // '$' is a special value for internal nodes, not used
    top = newNode('$', left->freq + right->freq);
    top->left = left;
    top->right = right;
    insertMinHeap(minHeap, top);
  }

  // Step 4: The remaining node is the root node and the tree is complete
  return extractMin(minHeap);
}

// Prints Huffman codes from the root of Huffman Tree
void printCodes(MinHeapNode *root, int arr[], int top) {
  // Assign 0 to left edge and recur
  if (root->left) {
    arr[top] = 0;
    printCodes(root->left, arr, top + 1);
  }

  // Assign 1 to right edge and recur
  if (root->right) {
    arr[top] = 1;
    printCodes(root->right, arr, top + 1);
  }

  // If this is a leaf node, then print the character and its code
  if (isLeaf(root)) {
    printf("%c: ", root->data);
    printArr(arr, top);
  }
}

// The main function to create Huffman codes
void HuffmanCodes(char data[], int freq[], int size) {
  // Construct Huffman Tree
  MinHeapNode *root = buildHuffmanTree(data, freq, size);

  // Print Huffman codes using the Huffman tree built above
  int arr[100], top = 0;
  printCodes(root, arr, top);
}

// Driver program to test above functions
int main() {
  char arr[] = {'a', 'b', 'c', 'd', 'e', 'f'};
  int freq[] = {5, 9, 12, 13, 16, 45};
  int size = sizeof(arr) / sizeof(arr[0]);

  printf("Huffman Codes:\n");
  HuffmanCodes(arr, freq, size);

  return 0;
}
