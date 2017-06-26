#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "stack.h"

bool isHigherPrecedence(char c, char d) {
	if (d == '(') {
		return true;
	}
	if (c == '|') {
		return false;
	} else if (c == '^') {
		if (d != '|') {
			return false;
		}
	} else if (c == '&') {
		if (d != '|' && d != '^') {
			return false;
		}
	} else if (c == '+' || c == '-') {
		if (d != '|' && d != '^' && d != '&') {
			return false;
		}
	} else if (c == '*' || c == '/' || c == '%') {
		if (d != '|' && d != '^' && d != '&' && d != '+' && d != '-') {
			return false;
		}
	}
	return true;
}

int main() {
	char c = getchar();
	stack* stk = stack_new();
	while (c != EOF) {
		if (c == '(') {
			stack_push(stk, (int) c);
			c = getchar();
		} else if (c == ' ') {
			c = getchar();
		} else if (c == '+' || c == '-' || c == '*' || c == '/' || c == '%'
				|| c == '&' || c == '|' || c == '^') {
			if (stack_is_empty(stk)) {
				stack_push(stk, (int) c);
			} else {
				char d = stack_pop(stk);
				if (isHigherPrecedence(c, d)) {
					stack_push(stk, (int) d);
					stack_push(stk, (int) c);
				} else {
					while (!isHigherPrecedence(c, d)) {
						printf("%c ", d);
						if (!stack_is_empty(stk)) {
							d = (char) stack_pop(stk);
						} else {
							break;
						}
					}
					if (isHigherPrecedence(c, d)) {
						stack_push(stk, (int) d);
					}
					stack_push(stk, (int) c);

				}
			}
			c = getchar();
		} else if (c == '\n') {
			while (stack_size(stk) > 1) {
				printf("%c ", (char) stack_pop(stk));
			}
			if (!stack_is_empty(stk)) {
				printf("%c\n", (char) stack_pop(stk));
			}
			c = getchar();
		} else if (c == ')') {
			char d = getchar();
			while (!stack_is_empty(stk)) {
				if ((c = (char) stack_pop(stk)) != '(') {
					if (d == '\n' && stack_is_empty(stk)) {
						printf("%c", c);
					}else{
						printf("%c ", c);
					}
				}else{
					break;
				}
			}
			c = d;
		} else {
			while (c != ' ' && c != '\n' && c != EOF) {
				printf("%c", c);
				c = getchar();
			}
			printf(" ");
		}
	}
	return 0;
}
