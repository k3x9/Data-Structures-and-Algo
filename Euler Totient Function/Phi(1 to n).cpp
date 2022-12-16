//Number of integers from 1 to i that are co prime to i.
vector<long long int> euler_totient_1_to_n(long long int n){
	vector<long long int> v(n+1);
	for(long long int i=0;i<=n;i++){
		v[i] = i;
	}
	for(long long int i=2;i<=n;i++){
		if(v[i]==i){
			v[i] = i-1;
			for(long long int j=i*2;j<=n;j+=i){
				v[j] -= v[j]/i;
			}
		}
	}
	return v;
}
