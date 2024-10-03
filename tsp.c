#include <math.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int *arr;
  int n;
} stack;

void swap(int *a, int *b) {
  int aux = *a;
  *a = *b;
  *b = aux;
}

stack *stack_create(int n) {
  stack *s = (stack *)malloc(sizeof(stack));
  s->arr = (int *)malloc(n * sizeof(int));
  s->n = 0;
  return s;
}

void stack_push(stack *s, int value) {
  s->arr[s->n] = value;
  s->n++;
}

int stack_pop(stack *s) {
  s->n--;
  return s->arr[s->n];
}

int stack_top(stack *s) { return s->arr[s->n - 1]; }

int stack_empty(stack *s) { return s->n == 0; }

int stack_size(stack *s) { return s->n; }

void stack_destroy(stack *s) {
  free(s->arr);
  free(s);
}

void print_stack(stack *s) {
  for (int i = 0; i < s->n; i++) {
    printf("%d ", s->arr[i]);
  }
  printf("\n");
}

/* permutates every element except the first one */
int **permutate(int *arr, int start, int end, int **perms, int *index) {
  if (start == end) {
    for (int i = 0; i <= end; i++) {
      perms[*index][i] = arr[i];
    }
    (*index)++;
  } else {
    for (int i = start; i <= end; i++) {
      swap(&arr[start], &arr[i]);
      permutate(arr, start + 1, end, perms, index);
      swap(&arr[start], &arr[i]);
    }
  }
  return perms;
}

int **permutate_wrapper(int *arr, int n, int **perms) {
  int index = 1;
  return permutate(arr, index, n - 1, perms, &index);
}

int **generate_tsp_matrix(int n) {
  int **matrix = (int **)malloc(n * sizeof(int *));
  for (int i = 0; i < n; i++) {
    matrix[i] = (int *)malloc(n * sizeof(int));
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      scanf("%d", &matrix[i][j]);
    }
  }
  return matrix;
}

int main() {
  int n;
  scanf("%d", &n);
  int **matrix = generate_tsp_matrix(n);
  return 0;
}
