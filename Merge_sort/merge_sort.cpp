void merge(int left[] , int right[] , int arr[] , int n1 , int n2){
	int k = 0;

	for(int i=0 , j=0 ; i<n1 || j<n2; k++){
		if(i == n1){
			arr[k] = right[j];
			j++;
		}
		else if(j == n2){
			arr[k] = left[i];
			i++;
		}
		else if(left[i] <= right[j]){
			arr[k] = left[i];
			i++;
		}
		else{
			arr[k] = right[j];
			j++;
		}
	}
}

void merge_sort(int arr[] , int n){
	if(n <= 1) return;

	int left[n/2] , right[n - n/2];
	for(int i=0;i<n;i++){
		if(i < n/2) left[i] = arr[i];
		else right[i - n + n/2 + n%2] = arr[i];
	}

	merge_sort(left , n/2);
	merge_sort(right , n - n/2);
	merge(left , right , arr , n/2 , n - n/2);
}
