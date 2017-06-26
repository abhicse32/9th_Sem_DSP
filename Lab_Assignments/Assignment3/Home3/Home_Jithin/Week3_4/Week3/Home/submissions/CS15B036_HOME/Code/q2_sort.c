void selection_sort(int arr[], int i, int n){
	
	if(i == n-1) return;
	
	int j;
	int temp = arr[i];
	int min_ind = i;
	
	for(j = i; j < n; j++){
		
		if(arr[j] < arr[min_ind]) min_ind = j;
		
	}
	
	arr[i] = arr[min_ind];
	arr[min_ind] = temp;
	
	selection_sort(arr,i+1,n);
	
	return ;
}

void bubble_sort(int arr[], int n){

	int i,j;

	for(i = 0; i < n-1; i++){
		
			for(j = 0; j < n-1-i; j++){
			
				if(arr[j] > arr[j+1]) {
					int temp = arr[j];
					arr[j] = arr[j+1];
					arr[j+1] = temp; 
				}
			}
		}
	
	return ;
}

void insertion_sort(int arr[], int i, int n){
	
	if(i == n) return;
	
	int j,l;
	
	for(j = 0; j < i; j++){
		
		if(arr[j] > arr[i]){
			
			int temp = arr[i];
			int k;
			
			for(k = i; k > j; k--)
				arr[k] = arr[k-1];

			arr[j] = temp;
			break;	
		}		
	}
	
	insertion_sort(arr,i+1,n);

}

void merge(int arr[], int i, int f){
	
	int temp[f-i+1];
	int j;
	int p = i;
	
	for(j = 0; j <= f-i; j++){
		temp[j] = arr[p];
		p++;
	}
		
	int k;
	int m = 0;
	int n = (f+i)/2 + 1 - i;
	
	for(k = i; k <= f; k++){
		
		if(((temp[m] < temp[n]) && (m != (i+f)/2 - i+1))||(n == f-i+1)){
			arr[k] = temp[m];
			m++;
		}
		
		else{
			arr[k] = temp[n];
			n++;
		}
	}
	
	return ;
}

void merge_sort(int arr[], int i, int f){
	
	int l;

	if(i == f) return;
	
	merge_sort(arr,i,(i+f)/2);
	merge_sort(arr,(i+f)/2 + 1,f);
	
	merge(arr,i,f);
	
	return ;
}

int median(int arr[], int i, int f){

		if(arr[i] > arr[f]){
			if((arr[(i+f)/2]>arr[f])){
				if(arr[(i+f)/2]<arr[i]) return (i+f)/2;
				return i;
			}
			return f;
		}
		
		else{
			if((arr[(i+f)/2]<arr[f])){
				if(arr[(i+f)]/2<arr[i]) return i;
				return (i+f)/2;
			}
			return f;
		}
}

void swap(int *a, int *b){

	int temp = *a;
	*a = *b;
	*b = temp;

	return ;
}

void quick_sort(int arr[], int i, int f){
	
	int g;

	if(i > f) return ;

	if(i == f) return ;
	
	if(i+1 == f){
		if(arr[i]>arr[f]) swap(&arr[i],&arr[f]);
		return ;
	}

	int key = median(arr,i,f);
	
	swap(&arr[i],&arr[key]);

	int p = i+1;
	int q = f;
	int a = 0;
	
	for(; p < q; p++){
		
		if(arr[p] > arr[i]){
			
			for(; p < q; q--){
				
				if(arr[q] <= arr[i]){
					swap(&arr[p],&arr[q]);
					break;
					}
				if(p == q-1) a = 1;		
			}
			
			if(a != 0) p--;
		}	
	}
	
	swap(&arr[i],&arr[p-1]); 	

	quick_sort(arr,i,p-2);
	quick_sort(arr,q,f);

	return ;
}
