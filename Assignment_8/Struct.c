#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 10

typedef int element;
typedef struct {
	element data[MAX];
	int top;
} StackType;

void init_stack(StackType* s) {
	s->top = -1;
}

int is_empty(StackType* s) {
	return(s->top == -1);
}

int is_full(StackType* s) {
	return(s->top == (MAX - 1));
}

void push(StackType* s, element item) {
	if (is_full(s)) {
		fprintf(stderr, "Stack Full!\n");
		return;
	}
	else {
		s->data[++(s->top)] = item;
	}
}
element pop(StackType* s) {
	if (is_empty(s)) {
		fprintf(stderr, "Stack Empty!\n");
		return -1;
	}
	else
		return s->data[(s->top)--];
}

int main() {
	StackType s;
	srand(time(NULL));
	init_stack(&s);
	printf("--------Using Struct--------\n");
	for (int i = 1; i <= 30; i++) {
		int rand_num = rand() % 100 + 1;
		if ((rand_num % 2) == 0) {
			printf("[%d] pop %d\n", i, pop(&s));
		}
		else {
			printf("[%d] push %d\n",i, rand_num);
			push(&s, rand_num);
		}
	}
	system("pause");
}