#include<bits/stdc++.h>

using namespace std;

int main(){
srand(time(NULL));

int a = 'A';
int m;

cin >> m;

for(int i = 0;i<m;i++){
for(int j = 0;j<m;j++){
	printf("%c ",a+rand()%26);		
}
cout << endl;
}

return 0;
}
