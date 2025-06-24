//Era(n)を呼んだ後、isprime[i]=iが素数かどうか　となっている。
vector < bool > isprime;
//返り値は素数のリスト。
vector < ll > Era(int n) {
	isprime.resize(n, true);
	vector < ll > res;
	isprime[0] = false;
	isprime[1] = false;
	for(ll i = 2; i < n; ++i) isprime[i] = true;
	for(ll i = 2; i < n; ++i) {
		if(isprime[i]) {
			res.push_back(i);
			for(ll j = i * 2; j < n; j += i) isprime[j] = false;
		}
	}
	return res;
}
