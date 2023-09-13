class BellmanFord:
    def __init__(self, vertices):
        self.V = vertices
        self.graph = []

    def add_edge(self, u, v, w):
        self.graph.append([u, v, w])

    def bellman_ford(self, src):
        # Step 1: Initialize distances
        distances = [float('inf')] * self.V
        distances[src] = 0

        # Step 2: Relax all edges V-1 times
        for _ in range(self.V - 1):
            for u, v, w in self.graph:
                if distances[u] != float('inf') and distances[u] + w < distances[v]:
                    distances[v] = distances[u] + w

        # Step 3: Check for negative weight cycles
        for u, v, w in self.graph:
            if distances[u] != float('inf') and distances[u] + w < distances[v]:
                print("Graph contains negative weight cycle.")
                return

        # Step 4: Print shortest distances
        self.print_distances(distances)

    def print_distances(self, distances):
        print("Vertex Distance from Source:")
        for i in range(self.V):
            print(f"{i} \t\t {distances[i]}")


# Example usage:
if __name__ == "__main__":
    g = BellmanFord(5)
    g.add_edge(0, 1, -1)
    g.add_edge(0, 2, 4)
    g.add_edge(1, 2, 3)
    g.add_edge(1, 3, 2)
    g.add_edge(1, 4, 2)
    g.add_edge(3, 2, 5)
    g.add_edge(3, 1, 1)
    g.add_edge(4, 3, -3)
    
    source_vertex = 0
    g.bellman_ford(source_vertex)
