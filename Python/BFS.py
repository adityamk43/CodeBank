# Python3 Program to print BFS traversal
# from a given source vertex. BFS(int s)
# traverses vertices reachable from s.
from collections import defaultdict

# This class represents a directed graph
# using adjacency list representation


class Graph:

    # Constructor
    def __init__(self):

        # default dictionary to store graph
        self.graph = defaultdict(list)

    # function to add an edge to graph
    def addEdge(self, u, v):
        self.graph[u].append(v)

    # Function to print a BFS of graph
    def BFS(self, s):

        # Mark all the vertices as not visited
        print(self.graph)
        visited = [False] * (max(self.graph) + 1)

        # Create a queue for BFS
        queue = []

        # Mark the source node as
        # visited and enqueue it
        queue.append(s)
        visited[s] = True

        while queue:

            # Dequeue a vertex from
            # queue and print it
            s = queue.pop(0)
            print(s, end=" ")

            # Get all adjacent vertices of the
            # dequeued vertex s. If a adjacent
            # has not been visited, then mark it
            # visited and enqueue it
            # print("queue:", queue)
            # print("s:", s)
            for i in self.graph[s]:
                # print("i:", i)
                if visited[i] == False:
                    queue.append(i)
                    visited[i] = True
            
            # print("\n")

# Driver code


# Create a graph given in
# the above diagram
g = Graph()

n = int(input("Enter number of edges: "))
print("\n")

for i in range(n):
    g.addEdge(int(input("Enter current node: ")), int(input("Enter connecting node: ")))
    print("\n")

# g.addEdge(0, 1)
# g.addEdge(0, 2)
# g.addEdge(1, 2)
# g.addEdge(2, 0)
# g.addEdge(2, 3)
# g.addEdge(3, 3)

print("Following is Breadth First Traversal"
      " (starting from vertex 2)")

start = int(input("Enter Starting Node:"))
g.BFS(start)
# g.BFS(2)

