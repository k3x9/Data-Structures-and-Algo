long long int phi(long long int n){			//phi(n) = n*(1 - 1/p1)*(1 - 1/p2)....*(1 - 1/pk), p1,p2.. are prime factors of n
	long long int cnt=n;
	for(long long int i=2;i*i<=n;i++){
		if(n%i == 0){
			cnt -= cnt/i;
			while(n%i==0){
				n/=i;
			}
		}
	}
	if(n>2) cnt -= cnt/n;
	return cnt;
}
