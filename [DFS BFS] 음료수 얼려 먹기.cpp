#include<iostream>
using namespace std;

int n,m;
int graph[1000][1000];
	
// DFS로 특정 노드를 방문하고 연결된 모든 노드들도 방문
bool dfs(int x, int y){
	// 주어진 범위를 벗어나는 경우에는 즉시 종료
	if(x < 0 || x > n - 1 || y < 0 || y > m - 1){
		return false;
	}
	
	// 현재 노드를 아직 방문하지 않았다면
	if(graph[x][y] == 0){
		// 구멍이 뚫려 있는 부분 방문 처리  
		graph[x][y] = 1;
		
		// 상, 하, 좌, 우의 위치들도 모두 재귀적으로 호출  
		dfs(x - 1, y); 
		dfs(x + 1, y); 
		dfs(x, y - 1); 
		dfs(x, y + 1); 
		
		return true; 
	}
	
	return false; // 칸막이가 존재하는 부분  
}

int main(void){
	
	int result = 0;
	// N, M을 공백을 기준으로 구분하여 입력 받기
	cin >> n >> m;	
	
	// 2차원 리스트의 맵 정보 입력 받기
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			scanf("%1d", &graph[i][j]);
		}
	}
	
	// 모든 노드(위치)에 대하여 음료수 채우기
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(dfs(i,j)){
				result += 1;
			}
		}
	}
	
	cout << result;
}
