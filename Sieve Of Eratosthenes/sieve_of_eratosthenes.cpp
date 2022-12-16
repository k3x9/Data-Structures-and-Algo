vector<int> sieve_1_to_n(int n){  //This function will return vector v where v[k] = 1, if k is "prime",else 0.
	vector<int> v(n+1,1);
	v[0]=0;
	v[1]=0;
	for(int i=2;i<=n;i++){
		if(v[i] == 1){
			for(int j=2*i;j<=n;j+=i){
				v[j]=0;
			}
		}
	}
	return v;
}
//O(NloglogN)
