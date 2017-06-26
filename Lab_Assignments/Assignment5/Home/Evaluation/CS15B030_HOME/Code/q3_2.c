#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int main() {
	stack* stk = stack_new();
	char c;
	int op1, op2;
	while ((c = getchar()) != EOF) {
		switch (c) {
		case '+':
			op2 = stack_pop(stk);
			op1 = stack_pop(stk);
			op1 = op1 + op2;
			stack_push(stk, op1);
			break;

		case '-':
			if ((c = getchar()) == ' ') {
				op2 = stack_pop(stk);
				op1 = stack_pop(stk);
				op1 = op1 - op2;
				stack_push(stk, op1);
			} else {
				op1 = 0;
				while (c != ' ') {
					op1 = op1 * 10 + ((int) c - 48);
					c = getchar();
				}
				stack_push(stk, -op1);
			}
			break;

		case '*':
			op2 = stack_pop(stk);
			op1 = stack_pop(stk);
			op1 = op1 * op2;
			stack_push(stk, op1);
			break;

		case '/':
			op2 = stack_pop(stk);
			op1 = stack_pop(stk);
			op1 = op1 / op2;
			stack_push(stk, op1);
			break;

		case '%':
			op2 = stack_pop(stk);
			op1 = stack_pop(stk);
			op1 = op1 % op2;
			stack_push(stk, op1);
			break;

		case '^':
			op2 = stack_pop(stk);
			op1 = stack_pop(stk);
			op1 = op1 ^ op2;
			stack_push(stk, op1);
			break;

		case ' ':
			break;

		case '\n':
			printf("%d\n", stack_pop(stk));
			break;

		case '|':
			op2 = stack_pop(stk);
			op1 = stack_pop(stk);
			op1 = op1 | op2;
			stack_push(stk, op1);
			break;

		case '&':
			op2 = stack_pop(stk);
			op1 = stack_pop(stk);
			op1 = op1 & op2;
			stack_push(stk, op1);
			break;

		default:
			op1 = 0;
			while (c != ' ') {
				op1 = op1 * 10 + ((int) c - 48);
				c = getchar();
			}
			stack_push(stk, op1);
		}
	}
}
