#include <iostream>
#include <stack>
#include <cstring>
using namespace std;
int main(){
	char str[1003];
	int t,n;
	cin >> t;
	while(t--){
		cin >> str;
		stack<char> st;
		int len= strlen(str);
		if(len&1){
			cout <<"0\n";
			continue;
		}

		bool flag= false;
		for(int i=0;i<len;i++){
			switch(str[i]){
				case '[':
				case '{':
				case '(':
					st.push(str[i]);
					break;
				case ']':
					if(st.empty() || st.top()!='[')
						flag=true;
					else st.pop();
					break;
				case '}':
					if(st.empty() || st.top()!='{')
						flag=true;
					else st.pop();
					break;

				case ')':
					if(st.empty() || st.top()!='(')
						flag=true;
					else st.pop();
					break;

				default: 
					break;
			}
			if(flag)
				break;
		}
		if(!flag)
			cout << "1\n";
		else cout <<"0\n";
	}
	return 0;
}