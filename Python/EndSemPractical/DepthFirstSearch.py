graph = {
    '9': ['31', '6'],
    '31': ['2', '4'],
    '6': ['8'],
    '2': [],
    '4': ['8'],
    '8': []
}

visited = set()

def DFS(graph, visited, node):

    print(node, end=" ")
    visited.add(node)

    for neighbour in graph[node]:
        if neighbour not in visited:
            DFS(graph, visited, neighbour)
        
print("Depth-First Search")
DFS(graph, visited, '9')