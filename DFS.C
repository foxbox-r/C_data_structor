#include <stdio.h>
//8 
//1 
//1 2
//1 3
//2 4
//2 5 
//4 8
//5 8
//3 6
//3 7
//6 8
//7 8
//-1 -1


//DFS (Depth First Search)
int n;
int map[31][31];//인접 행렬 
int visited[31];//방문 여부 

void DFS(int v){//vertex 출발정점 (start node)
	visited[v] = 1;//방문했음 표시
	int i;
	for(i=1;i<=n;i++){
		if(map[v][i]==1 && !visited[i]){
			printf("move %d => %d  \n",v,i);
			DFS(i);
		}
	} 
}

int main(void){
	int startV,v1,v2;
	scanf("%d",&n);
	scanf("%d",&startV);
	while(1){
		scanf("%d %d",&v1,&v2);
		if(v1 == -1 && v2 == -1) break;
		map[v1][v2] = map[v2][v1] = 1;
	}
	DFS(startV);
	return 0;
}

//move 1 => 2
//move 2 => 4
//move 4 => 8
//move 8 => 5
//move 8 => 6
//move 6 => 3
//move 3 => 7






