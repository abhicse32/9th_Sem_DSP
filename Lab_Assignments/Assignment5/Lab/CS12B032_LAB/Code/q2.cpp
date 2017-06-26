#include <iostream>
#include <stack>
#include <cstring>
using namespace std;
int main(){
    int t;
    char str[1005];
    cin >> t;
    while(t--){
        cin >> str;
        int len= strlen(str);
        stack<char> st;
        for(int i=0;i<len;i++){
            if(str[i]=='{')
                st.push(str[i]);
            else{
                if(!st.empty() && st.top()=='{')
                    st.pop();
                else st.push(str[i]);
            }
        }
        len= st.size();
        int reversals=-1;
        if(!(len&1)){
            reversals=0;
            while(!st.empty()){
                char top1= st.top();
                st.pop();
                char top2= st.top();
                st.pop();
                if(top1==top2)
                    reversals++;
                else reversals+=2;
            }
        }
        cout << reversals <<endl;
    }
}