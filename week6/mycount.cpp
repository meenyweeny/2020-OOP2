//12181642 �̰��
int mycount(const char * cs) {
	int cnt = 0;
	for (int i = 0; i < 100; i++) {
		if (*(cs + i) == '\0')
			return cnt;
		cnt++;
	}
}