import java.util.*;

public class Graph {
    private final Set<Node> nodes;
    private final Set<Edge> edges;
    private Map<String, String> attributes;

    public Graph() {
        nodes = new HashSet<>();
        edges = new HashSet<>();
        attributes = Map.of();
    }

    public Graph(Map<String, String> attributes) {
        this();
        this.attributes = attributes;
    }

    public Collection<Node> getNodes() {
        return this.nodes;
    }

    public Collection<Edge> getEdges() {
        return this.edges;
    }

    public Graph node(String name) {
        this.nodes.add(new Node(name));

        return this;
    }

    public Graph node(String name, Map<String, String> attributes) {
        this.nodes.add(new Node(name, attributes));

        return this;
    }

    public Graph edge(String start, String end) {
        this.edges.add(new Edge(start, end));

        return this;
    }

    public Graph edge(String start, String end, Map<String, String> attributes) {
        this.edges.add(new Edge(start, end, attributes));

        return this;
    }

    public Map<String, String> getAttributes() {
        return this.attributes;
    }
}
