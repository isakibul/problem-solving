#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX 100

typedef struct {
    char items[MAX];
    int top;
} st;

void initStack(st *s) {
    s->top = -1;
}

bool isEmpty(st *s) {
    return s->top == -1;
}

bool isFull(st *s) {
    return s->top == MAX - 1;
}

void push(st *s, char c) {
    if (!isFull(s)) {
        s->items[++s->top] = c;
    }
}

char pop(st *s) {
    if (!isEmpty(s)) {
        return s->items[s->top--];
    }
    return '\0';
}

char peek(st *s) {
    if (!isEmpty(s)) {
        return s->items[s->top];
    }
    return '\0';
}

bool isValid(char *s) {
    st stack;
    initStack(&stack);

    for (int i = 0; i < strlen(s); i++) {
        char ch = s[i];
        if (ch == '(' || ch == '{' || ch == '[') {
            push(&stack, ch);
        } else if (ch == ')' || ch == '}' || ch == ']') {
            if (isEmpty(&stack)) return false;
            char top = pop(&stack);
            if ((ch == ')' && top != '(') || (ch == '}' && top != '{') || (ch == ']' && top != '[')) {
                return false;
            }
        }
    }

    return isEmpty(&stack);
}

int main() {
    char input[MAX];
    printf("Enter a string of parentheses: ");
    scanf("%s", input);

    if (isValid(input)) {
        printf("The string is valid.\n");
    } else {
        printf("The string is invalid.\n");
    }

    return 0;
}
