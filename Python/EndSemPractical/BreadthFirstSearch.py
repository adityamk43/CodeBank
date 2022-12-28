graph = {
    '6': ['3', '7'],
    '3': ['2', '4'],
    '7': ['8'],
    '2': [],
    '4': ['8'],
    '8': []
}


def BFS(graph, node):
    
    visited=[]
    queue = []
    visited.append(node)
    queue.append(node)

    while queue:
        curr = queue.pop(0)

        print(curr, end=" ")

        for neighbour in graph[curr]:
            if neighbour not in visited:
                visited.append(neighbour)
                queue.append(neighbour)

print("Breadth-First Search")
BFS(graph, '6')