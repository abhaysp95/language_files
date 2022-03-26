#include <iostream>
#include <cstring>
#include <cctype>
#include <stack>

using namespace std;

#define MAXS 400

int main(int argc, char** argv) {
	int t = 0;
	scanf("%d", &t);
	fgetc(stdin);  // take '\n' from stdin
	while(t--) {
		char expr[MAXS - 1];
		fgets(expr, MAXS, stdin);
		int expr_len = strlen(expr);
		if(expr[expr_len - 1] == '\n') expr[expr_len - 1] = '\0';
		char new_expr[expr_len];
		memset(new_expr, '\0', sizeof(new_expr));

		// you can just as well use stack data structure but(I'm trying with array)
		//char arr[MAXS];
		//int copt = 0, carr = 0;
		//for(int i = 0; i < expr_len; i++) {
			//if(isalpha(expr[i])) {
				//new_expr[carr] = expr[i], carr++;
			//}
			//else {
				//if(expr[i] == ')') {
					//if(copt != 0 && arr[copt - 1] != '(')
						//new_expr[carr] = arr[copt - 1], carr++, copt -= 2;
					//else if(copt != 0)
						//copt--;
				//}
				//else {
					//arr[copt] = expr[i], copt++;
				//}
			//}
		//}

		stack<char> opd{};
		int carr = 0;
		for(int i = 0; i < expr_len; i++) {
			if(isalpha(expr[i])) {
				new_expr[carr] = expr[i], carr++;
			}
			else {
				if(expr[i] == ')') {
					if(opd.top() != '(') new_expr[carr] = opd.top(), carr++, opd.pop(), opd.pop();
					else opd.pop();
				}
				else opd.push(expr[i]);
			}
		}
		printf("%s\n", new_expr);
	}
	return 0;
}

/**
inputs:

4
(a+(b*c))
((a+b)*(z+x))
((a+t)*((b+(a+c))^(c+d)))
(((a+b)/(((((c+d)-(d+e))*g)%((e+h)+a))))-(c+d))

**/
