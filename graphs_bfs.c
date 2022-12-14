// Online C compiler to run C program online
#include <stdio.h>
#include <stdlib.h>
#define V 10
int main() {
    //structs to store the special data
    struct queue {
      int adj[V];
      int front;
      int rear;
    }; //queue
   
    struct node {
        int d;
        struct node * next;
    };//node that makes up the adjacency list in the Graph
   
    struct Graph {
      struct node * vertices[V];  
      int vis[V];
    }; //graph as adjacency list
   
    struct edge {
      int s;
      int d;
    }; //edge represent directed link  - from source to destination
   
    struct queue * createQ() {
      struct queue* Q = malloc(sizeof(struct queue));
      Q->front = -1;
      Q->rear = -1;
      return Q;
    }
   
    struct queue * enq(struct queue * q, int toVisit){
        struct queue * Q = q;
        if (Q->rear==-1) Q->front++;
        Q->rear++;
        Q->adj[Q->rear] = toVisit;
        return Q;
    }
   
    int deq(struct queue * q){
        struct queue * Q = q;
        int removed = Q->adj[Q->front];
        Q->front++;
        return removed;
    }
   
    void printQ(struct queue * q){
        struct queue * Q = q;
        for(int i = Q->front; i < Q->rear; i++){
            printf("%d,",Q->adj[i]);
        }
        printf("\n");
    }
   
    struct Graph * e2g(struct edge edges[], int e){
        struct Graph * graph = (struct Graph *)malloc(sizeof(struct Graph));
        for (int i = 0; i < V; i++){
            graph->vertices[i] = NULL; //because we dont want it to be 0
        }
        for (int i = 0; i < e; i++){ //loop to add the edges to the graph
            int src = edges[i].s;
            int dest = edges[i].d;
           
            struct node * newNode = (struct node *)malloc(sizeof(struct node));
            newNode->d = dest; //create a new node for destination
            newNode->next = graph->vertices[src]; // add the node which was previously at the src index to the next of the new node
            graph->vertices[src] = newNode; // make the new node as the head of the adjacency list
        }
        return graph;
    }
   
    void bfs(struct Graph * gr, int start){
        for (int i = 0; i < V; i++){
            gr->vis[i] = 0;
        }//did this to make sure that all the nodes are marked 0 for unvisited before we start the BFS
        printf(">>BFS Traversal<<\n");
        struct Graph * graph = gr;
        struct queue * q = createQ();
        q = enq(q, start); //adding the starting vertex to the queue of "to be visited queue"    
        graph->vis[start] = 1; //marking the first/starting node as visited by making the array value of that index as 1
       
        while  (q->front <= q->rear){ //while loop until the queue is empty
            printf("%d->", visit); //printing the node which is visited
            int visit = deq(q); //it's important to note the node which is to be removed so that we can add the adjacent node of the removed node to the queue of to be visited noded.
            struct node * temp = graph->vertices[visit]; //taking the first adjacent node as temp
            while (temp){//loop to access all the nodes in the adjacency list
                if (graph->vis[temp->d] == 0){
                    q = enq(q, temp->d);//add the adjacent node to the loop if it is unvisited
                    graph->vis[temp->d] = 1;// and then marking it visited.
                }
                temp = temp->next;
            }
           
        }
        printf("END\n"); 
    }
   

    struct edge edges [] = {{1,2}, {1,3}, {2,3}, {2,4}, {3,4}, {4,5}};
    int num = sizeof(edges)/sizeof(edges[0]);
   
    struct Graph * g = e2g(edges, num);
   
    bfs(g,1);
   
    return 0;
   
}
