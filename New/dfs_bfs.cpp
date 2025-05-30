#include<iostream>
#include<vector>
#include<queue>

using namespace std;

vector<int> bfs(int v , vector<int>adjList[]){
	
	queue<int>q;
	vector<bool>visited(v,false);
	vector<int>ans;
	
	q.push(0);
	visited[0] = true;
	
	while(!q.empty()){
		int node = q.front(); //first element
		q.pop();  //first element poped
		
		ans.push_back(node);
		
		for(int j = 0;j<adjList[node].size();j++){
			if(visited[adjList[node][j]]==false){
				visited[adjList[node][j]] = true;
				q.push(adjList[node][j]);
			}
		}
	}
	return ans;
}

void dfs(int node,vector<int>adjList[],vector<bool>& visited,vector<int>& ans){
	
	visited[node] = true;
	ans.push_back(node);
	
	for(int j = 0;j<adjList[node].size();j++){
		if(visited[adjList[node][j]] ==false){
			dfs(adjList[node][j],adjList,visited,ans);
		}
	}
}


int main(){
	int vertex,edges;
	cout<<"Enter the no. of vertex and edges :";
	cin>>vertex>>edges;
	
	vector<int>adjList[vertex];
	cout<<"Enter the edges :";
	int v,u;
	for(int i = 0;i<edges;i++){
		cin>>v>>u;
		
		adjList[u].push_back(v);
		adjList[v].push_back(u);
		
	}
	
	cout<<"\nAdjacenct List :"<<endl;
	for(int i =0;i<vertex;i++){
		cout<<i<<"-->";
		for(int j = 0;j<adjList[i].size();j++){
			cout<<adjList[i][j]<<" ";
		}
		cout<<endl;
	}
	
	//bfs
	vector<int> ans = bfs(vertex,adjList);
	
	cout<<"\nBfs Traversal :"<<endl;
	for(auto a :ans)
		cout<<a<<" ";
	cout<<endl;
	
	//dfs
	vector<int>ans2;
	vector<bool>visited(vertex,false);
	dfs(0,adjList,visited,ans2);
	
	cout<<"\nDfs Traversal :"<<endl;
	for(auto a :ans2)
		cout<<a<<" ";
	cout<<endl;
	
	return 0;
}

/*
input :
5 6

0 1
0 2
1 2
1 3    
2 4
3 4

output:
Adjacenct List :
0-->1 2 
1-->0 2 3 
2-->0 1 4 
3-->1 4 
4-->2 3 

Bfs Traversal :
0 1 2 3 4 

Dfs Traversal :
0 1 2 4 3 

*/


