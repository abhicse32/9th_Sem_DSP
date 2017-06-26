#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
	int t,n,i,j,k;
	int arr[1002];
	vector<pair<int,int> > vect;
	cin >> t;
	/*Without modifying the given array*/
	while(t--){
		cin >> n;
		stack<pair<int,int> > stk;
		for(int i=0;i<n;i++)
			cin >> arr[i];
		stk.push(make_pair(0,arr[0]));
		for(int i=1;i<n;i++){
			while(!stk.empty() && stk.top().second < arr[i]){
				vect.push_back(make_pair(stk.top().first,arr[i]));
				stk.pop();
			}
			stk.push(make_pair(i,arr[i]));
		}
		while(!stk.empty()){
			vect.push_back(make_pair(stk.top().first,-1));
			stk.pop();
		}
		sort(vect.begin(), vect.end());
		for(vector<pair<int,int> >::iterator iter= vect.begin(), end= vect.end(); iter!= end;
						++iter)
			cout << iter->second <<" ";
		cout <<endl;
		vect.clear();
	}
}