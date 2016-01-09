/**
 * @author Ronny MacMaster
 * 
 * A class which reprsents a graph of geographic locations
 * Nodes in the graph are intersections between roads or dead ends
 *
 */
package roadgraph;


import java.util.HashMap;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.List;
import java.util.Map;
import java.util.PriorityQueue;
import java.util.Queue;
import java.util.ArrayList;
import java.util.Set;
import java.util.function.Consumer;
import geography.GeographicPoint;
import geography.RoadSegment;
import util.GraphLoader;

public class MapGraph {
	private int numVertices, numEdges;
	private Set<GeographicPoint> vertices;
	private Set<Edge> roads;
	private HashMap<GeographicPoint, Vertex> intersections;	//(coor, intersection)
	
	/** 
	 * Create a new empty MapGraph 
	 */
	public MapGraph()
	{
		vertices = new HashSet<GeographicPoint>();
		intersections = new HashMap<GeographicPoint, Vertex>();
		roads = new HashSet<Edge>();
		numVertices = 0; numEdges = 0;
	}
	
	/**
	 * Get the number of vertices (road intersections) in the graph
	 * @return The number of vertices in the graph.
	 */
	public int getNumVertices()
	{
		return numVertices;
	}
	
	/**
	 * Get the number of road segments in the graph
	 * @return The number of edges in the graph.
	 */
	public int getNumEdges()
	{
		return numEdges; 
	}
	
	/**
	 * Return the intersections, which are the vertices in this graph.
	 * @return The vertices in this graph as GeographicPoints
	 */
	public Set<GeographicPoint> getVertices()
	{
		return vertices;
	}
	
	/** Add a node corresponding to an intersection at a Geographic Point
	 * If the location is already in the graph or null, this method does 
	 * not change the graph.
	 * @param location  The location of the intersection
	 * @return true if a node was added, false if it was not (the node
	 * was already in the graph, or the parameter is null).
	 */
	public boolean addVertex(GeographicPoint location)
	{
		if((location == null)||vertices.contains(location))
			return false;
		vertices.add(location);
		intersections.put(location, new Vertex(location));
		numVertices++;
		return true;
	}
	
	/**
	 * Adds a directed edge to the graph from pt1 to pt2.  
	 * Precondition: Both GeographicPoints have already been added to the graph
	 * @param from The starting point of the edge
	 * @param to The ending point of the edge
	 * @param roadName The name of the road
	 * @param roadType The type of the road
	 * @param length The length of the road, in km
	 * @throws IllegalArgumentException If the points have not already been
	 *   added as nodes to the graph, if any of the arguments is null,
	 *   or if the length is less than 0.
	 */
	public void addEdge(GeographicPoint from, GeographicPoint to, String roadName,
			String roadType, double length) throws IllegalArgumentException {
		if(!vertices.contains(from)||!vertices.contains(to)||
				(from == null)||(from == null)||(length < 0)){
			throw new IllegalArgumentException();
		}
		Vertex ver = intersections.get(from);
		Edge edge = new Edge(roadName, roadType, intersections.get(from), intersections.get(to), length);
		ver.addNeighbor(edge);//add road out of start
		roads.add(edge);
		numEdges++;
	}
	

	/** Find the path from start to goal using breadth first search
	 * 
	 * @param start The starting location
	 * @param goal The goal location
	 * @return The list of intersections that form the shortest (unweighted)
	 *   path from start to goal (including both start and goal).
	 */
	public List<GeographicPoint> bfs(GeographicPoint start, GeographicPoint goal) {
		// Dummy variable for calling the search algorithms
        Consumer<GeographicPoint> temp = (x) -> {};
        return bfs(start, goal, temp);
	}
	
	/** Find the path from start to goal using breadth first search
	 * 
	 * @param start The starting location
	 * @param goal The goal location
	 * @param nodeSearched A hook for visualization.  See assignment instructions for how to use it.
	 * @return The list of intersections that form the shortest (unweighted)
	 *   path from start to goal (including both start and goal).
	 */
	public List<GeographicPoint> bfs(GeographicPoint start, 
			 					     GeographicPoint goal, Consumer<GeographicPoint> nodeSearched)
	{
		Queue<Vertex> point_queue = new LinkedList<Vertex>();
		Set<Vertex> visited_set = new HashSet<Vertex>();
		Map<Vertex, Vertex> parent_map = new HashMap<Vertex, Vertex>();
		
		Vertex curr = intersections.get(start);
		point_queue.add(curr);
		while(!point_queue.isEmpty()){
			curr = point_queue.remove();
			nodeSearched.accept(curr.getLocation());
			if(curr.getLocation().equals(goal))
				return reconstructPath(parent_map, intersections.get(start), intersections.get(goal)); // terminal state;
			for(Vertex v : curr.getNeighbors()){
				if(!visited_set.contains(v)){
					visited_set.add(v);
					parent_map.put(v, curr);
					point_queue.add(v);
				}
			}
		}
		return null;
	}
	
	/** Reconstruct the path from start to goal using the Parent Map
	 * 
	 * @param parents The parent map
	 * @param start The starting location
	 * @param goal The goal location
	 * @return The list of intersections that form the path from 
	 *   start to goal (including both start and goal).
	 */
	private List<GeographicPoint> reconstructPath(Map<Vertex, Vertex> parents, Vertex start, Vertex goal){
		LinkedList<GeographicPoint> path = new LinkedList<GeographicPoint>();
		Vertex curr = goal;
		while(!curr.equals(start)){
			path.addFirst(curr.getLocation());
			curr = parents.get(curr);
		}
		path.addFirst(start.getLocation()); 
		return path;
	}
	
	

	/** Find the path from start to goal using Dijkstra's algorithm
	 * 
	 * @param start The starting location
	 * @param goal The goal location
	 * @return The list of intersections that form the shortest path from 
	 *   start to goal (including both start and goal).
	 */
	public List<GeographicPoint> dijkstra(GeographicPoint start, GeographicPoint goal) {
		// Dummy variable for calling the search algorithms
		// You do not need to change this method.
        Consumer<GeographicPoint> temp = (x) -> {};
        return dijkstra(start, goal, temp);
	}
	
	/** Find the path from start to goal using Dijkstra's algorithm
	 * 
	 * @param start The starting location
	 * @param goal The goal location
	 * @param nodeSearched A hook for visualization.  See assignment instructions for how to use it.
	 * @return The list of intersections that form the shortest path from 
	 *   start to goal (including both start and goal).
	 */
	public List<GeographicPoint> dijkstra(GeographicPoint start, 
										  GeographicPoint goal, Consumer<GeographicPoint> nodeSearched)
	{
		Queue<Vertex> point_queue = new PriorityQueue<Vertex>();
		Set<Vertex> visited_set = new HashSet<Vertex>();
		Map<Vertex, Vertex> parent_map = new HashMap<Vertex, Vertex>();
		
		for(GeographicPoint p : vertices){
			Vertex v = intersections.get(p);
			v.setStartDistance(v.infinity());
			v.setEndDistance(0);
		}
		
		Vertex curr = intersections.get(start);
		curr.setStartDistance(0);
		point_queue.add(curr);
		while(!point_queue.isEmpty()){
			curr = point_queue.remove();
			if(!visited_set.contains(curr)){
				visited_set.add(curr);
				nodeSearched.accept(curr.getLocation());
				if(curr.getLocation().equals(goal))
					return reconstructPath(parent_map, intersections.get(start), intersections.get(goal));
				for(Vertex v : curr.getNeighbors()){
					Edge e = curr.getNeighborRoad(v);
					double dist = curr.getStartDistance()+e.getLength();
					if((dist < v.getStartDistance())&&(!visited_set.contains(v))){
						v.setStartDistance(dist);//update distance
						parent_map.put(v, curr);
						point_queue.add(v);//queue with priority
					}
				}
			}
		}
		
		return null;
	}

	/** Find the path from start to goal using A-Star search
	 * 
	 * @param start The starting location
	 * @param goal The goal location
	 * @return The list of intersections that form the shortest path from 
	 *   start to goal (including both start and goal).
	 */
	public List<GeographicPoint> aStarSearch(GeographicPoint start, GeographicPoint goal) {
		// Dummy variable for calling the search algorithms
        Consumer<GeographicPoint> temp = (x) -> {};
        return aStarSearch(start, goal, temp);
	}
	
	/** Find the path from start to goal using A-Star search
	 * 
	 * @param start The starting location
	 * @param goal The goal location
	 * @param nodeSearched A hook for visualization.  See assignment instructions for how to use it.
	 * @return The list of intersections that form the shortest path from 
	 *   start to goal (including both start and goal).
	 */
	public List<GeographicPoint> aStarSearch(GeographicPoint start, 
											 GeographicPoint goal, Consumer<GeographicPoint> nodeSearched)
	{
		Queue<Vertex> point_queue = new PriorityQueue<Vertex>();
		Set<Vertex> visited_set = new HashSet<Vertex>();
		Map<Vertex, Vertex> parent_map = new HashMap<Vertex, Vertex>();
		
		for(GeographicPoint p : vertices){
			Vertex v = intersections.get(p);
			v.setStartDistance(v.infinity());
			v.setEndDistance(v.infinity());
		}
		
		Vertex curr = intersections.get(start);
		curr.setStartDistance(0);
		curr.setEndDistance(start.distance(goal));
		point_queue.add(curr);
		while(!point_queue.isEmpty()){
			curr = point_queue.remove();
			if(!visited_set.contains(curr)){
				visited_set.add(curr);
				nodeSearched.accept(curr.getLocation());
				if(curr.getLocation().equals(goal))
					return reconstructPath(parent_map, intersections.get(start), intersections.get(goal));
				for(Vertex v : curr.getNeighbors()){
					Edge e = curr.getNeighborRoad(v);
					double dist = curr.getStartDistance()+e.getLength()+v.getLocation().distance(goal);
					if((dist < v.getStartDistance()+v.getEndDistance())&&(!visited_set.contains(v))){
						v.setStartDistance(curr.getStartDistance()+e.getLength());//update distance
						v.setEndDistance(v.getLocation().distance(goal));
						parent_map.put(v, curr);
						point_queue.add(v);//queue with priority
					}
				}
			}
		}
		
		return null;
	}

	
	
	public static void main(String[] args)
	{
		System.out.print("Making a new map...");
		MapGraph theMap = new MapGraph();
		System.out.print("DONE. \nLoading the map...");
		GraphLoader.loadRoadMap("data/testdata/simpletest.map", theMap);
		System.out.println("DONE.");
		
		// You can use this method for testing.  
		
		/* Use this code in Week 3 End of Week Quiz
		MapGraph theMap = new MapGraph();
		System.out.print("DONE. \nLoading the map...");
		GraphLoader.loadRoadMap("data/maps/utc.map", theMap);
		System.out.println("DONE.");

		GeographicPoint start = new GeographicPoint(32.8648772, -117.2254046);
		GeographicPoint end = new GeographicPoint(32.8660691, -117.217393);
		
		
		List<GeographicPoint> route = theMap.dijkstra(start,end);
		List<GeographicPoint> route2 = theMap.aStarSearch(start,end);

		*/
		
	}
	
}
