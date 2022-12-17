#include<bits/stdc++.h>
#define MAXN 100005

using namespace std;
int n, k, john[MAXN], result[MAXN][21][3];

bool check(int a,int b){  // win or lose?
	if(a == 0 && b == 2) return 1;
	if(a == 1 && b == 0) return 1;
	if(a == 2 && b == 1) return 1;
	return 0;
}

int DFS(int gamesLeft,int changesLeft,int thisSign){
	if(changesLeft == -1) // not a valid game
		return 0;
	if(gamesLeft == 1) // last game, return current result
		return check(thisSign,john[gamesLeft]);
	if(result[gamesLeft][changesLeft][thisSign] > -1) // alrady calculated
		return result[gamesLeft][changesLeft][thisSign];
	
	int ret=0;
	for(int i=0;i<3;++i){
	    int changed = (i!=thisSign); // 1 or 0
		// win or lose this time, need to check if changesLeft valid
		// changesLeft-changed>=0 to check if valid
	    int thisTime = changesLeft-changed >= 0? check(i, john[gamesLeft]) :0;  
		int nowResult = DFS(gamesLeft-1, changesLeft-changed, i) + thisTime;
		// it is possible that we already have a better result for this 
		// situation. E.g. maybe result at i = 0 is better than i = 2
		ret = max(ret, nowResult);
	}
	
	result[gamesLeft][changesLeft][thisSign] = ret; // avoid TLE, save to cache
	return ret;
}

int main(){
	cin >> n >> k;
	for(int i=1; i<=n; ++i){
		char c = getchar();
		while(!isalpha(c)) c = getchar(); // make sure reading char
		if(c == 'H') john[i] = 0;// stone 
		if(c == 'P') john[i] = 1;// paper
		if(c == 'S') john[i] = 2;// scissors 
	}
	memset(result, -1, sizeof(result)); // memset only for 0 or -1
	cout << max(DFS(n,k,0), max(DFS(n,k,1), DFS(n,k,2))) << endl;
}