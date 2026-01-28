# 🧠 Problem Statement

# Design a Python application to model a Graph and implement various graph traversal and shortest path algorithms using inheritance.
# The graph structure and traversal results must be saved to and loaded from a file using serialization.



# 1️⃣ Class Design (Inheritance)

# 🔹 Base Class: Graph
# Stores graph using adjacency list
# Methods:
# add_vertex(v)
# add_edge(u, v)
# display_graph()

# 🔹 Derived Class: GraphTraversal(Graph)
# Inherits from Graph

# Implements:
# bfs(start_vertex)
# dfs(start_vertex)

# 🔹 Derived Class: WeightedGraph(Graph)
# Inherits from Graph

# Implements:
# add_weighted_edge(u, v, w)
# dijkstra(start_vertex)

# 2️⃣ Data Structures to Use
# Feature Data Structure

# Graph storage dict of list
# BFS queue (collections.deque)
# DFS stack or recursion
# Dijkstra priority queue (heapq)
# Visited nodes set

# 3️⃣ Serialization Requirement
# Save graph object to a file using:
# pickle
# Load graph object back from file
# File name: graph_data.pkl

# 🧪 Functional Requirements

# ✔ Add vertices and edges
# ✔ Perform BFS and DFS traversals
# ✔ Compute shortest path using Dijkstra
# ✔ Save graph to file
# ✔ Load graph from file and reuse it


# 🧑‍💻 Sample Starter Code (Partial)

import pickle
from collections import deque
import heapq

class Graph:
    # initialize the graph 
    def __init__(self):
        self.graph = {}
    # add vertex
    def add_vertex(self, vertex):
        if vertex not in self.graph:
            self.graph[vertex] = []
    # add edge
    def add_edge(self, u, v):
        self.add_vertex(u)
        self.add_vertex(v)
        self.graph[u].append((v)) 
        # For undirected graph , Uncomment this 
        # self.graph[v].append((u))

    def display_graph(self):
        for vertex in self.graph:
            print(vertex, "->", self.graph[vertex])


class GraphTraversal(Graph):
 def  __init__(self,graph_obj):
    self.graph=graph_obj.graph

 def bfs(self, start):
        visited = set()
        queue = deque([start])
        print("BFS:", end=" ")
        while queue:
            vertex = queue.popleft()

            if vertex not in visited:
                 print(vertex,"->", end=" ")
                 visited.add(vertex)

                 for neighbor,_ in self.graph[vertex]:
                     if neighbor not in visited:
                      queue.append(neighbor)
                # queue.extend(self.graph[vertex])
        print()

 def dfs(self, start, visited=None):
        if start not in self.graph:
            print("Vertex not found")
            return

        if visited is None:
            visited=set()
        
        print(start,"->",end=" ")
        visited.add(start)
        
        for neighbor ,_ in self.graph[start]:
            if neighbor not in visited:
                self.dfs(neighbor,visited)    


class WeightedGraph(Graph):
    def __init__(self,graph_obj):
        self.graph=graph_obj.graph
    def add_weighted_edge(self, u, v, weight):
        self.add_vertex(u)
        self.add_vertex(v)
        self.graph[u].append((v, weight))

    def dijkstra(self, start):
        if start not in self.graph:
            print("Vertex is not in graph")
            return 
        
        pq = [(0, start)]
        distances = {v: float('inf') for v in self.graph}
        distances[start] = 0

        while pq:
          current_dist, current_vertex = heapq.heappop(pq)
        
          for neighbor, weight in self.graph[current_vertex]:
              distance = current_dist + weight
            
              if distance < distances[neighbor]:
                distances[neighbor] = distance
                heapq.heappush(pq, (distance, neighbor))

        return distances


# 💾 Serialization Example
if __name__=="__main__":
   graph_obj=Graph()
   graph_traversal=GraphTraversal(graph_obj)
   wg= WeightedGraph(graph_obj)
   wg.add_weighted_edge("A","B",2)
   wg.add_weighted_edge("A","C",3)
   wg.add_weighted_edge("B","D",4)
   option=0
   while(option!=7):
       print("Menu")
       print("1. Add edge ")
       print("2. BFS ")
       print("3. DFS ")
       print("4. Dijskstra ")
       print("5. Save Graph ")
       print("6. Load Graph ")
       print("7. Exit")
       option=int(input("Enter your option:"))
       if(option==1):
           u=input("Enter source vertex:")
           v=input("Enter destination vertex:")
           w=input("Enter weight of edge:")
           wg.add_weighted_edge(u,v,w)
           
       elif(option==2):
           start=input("Enter start Vertex:")
           graph_traversal.bfs(start)
           
       elif(option==3):
           start=input("Enter start Vertex:")
           graph_traversal.dfs(start)
           
       elif(option==4):
           start=input("Enter start Vertex:")
           print(wg.dijkstra(start))
           
       elif(option==5):
           # Save graph
            with open("graph_data.pkl", "wb") as f:
                pickle.dump(graph_obj, f)
            print("\n Saved Successfully !")
            
       elif(option==6):
           # Load graph
            with open("graph_data.pkl", "rb") as f:
                graph_obj = pickle.load(f)
                graph_obj.display_graph()
            
       elif(option==7):
            print("\nBye bye")
            
       else:
           print("Invalid option")
           
           
           
           
        