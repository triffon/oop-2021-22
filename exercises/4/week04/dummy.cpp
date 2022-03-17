#define N jdhfkjfdksj
#define maxMacros(a,b) (a)>(b) ? a : b 
int main () {
	#ifdef test
	int debugMode = true;
	#endif
	int m = N;
	int p = N;
	int c = maxMacros(m,p);
	return 0;
}

// g++ -E .\dummy.cpp  -D test=true -o dummy1.cpp