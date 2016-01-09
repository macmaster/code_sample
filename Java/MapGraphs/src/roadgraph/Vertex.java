/**
 * @author Ronald MacMaster
 *
 * A node within the MapGraph
 * Nodes in the graph are intersections between roads or dead ends
 */
package roadgraph;

import java.util.Set;
import java.util.HashMap;
import java.util.HashSet;
import geography.GeographicPoint;

@SuppressWarnings("rawtypes")
public class Vertex implements Comparable{
	private Set<Edge> neighbors; // list of all roads out of node
	private HashMap<GeographicPoint, Edge> roads; // map of roads out of node (endpnt, road)
	private GeographicPoint location;
	private double start_distance;
	private double end_distance;
	
	public Vertex(GeographicPoint location){
		this.location = location;
		this.neighbors = new HashSet<Edge>();
		this.roads = new HashMap<GeographicPoint, Edge>(); 
		start_distance = 0;
		end_distance = 0;
	}
	
	
	public boolean addNeighbor(Edge new_neighbor){
		if((new_neighbor == null)||neighbors.contains(new_neighbor))
			return false;
		else{
			neighbors.add(new_neighbor);
			roads.put(new_neighbor.getEndPoint(), new_neighbor);
			return true;
		}
	}

	public Set<Vertex> getNeighbors(){
		Set<Vertex> neighbors = new HashSet<Vertex>();
		for(Edge e: this.neighbors)
			neighbors.add(e.getEnd());
		return neighbors;
	}
	
	public Edge getNeighborRoad(Vertex neighbor){
		Edge road = roads.get(neighbor.getLocation());
		if(road == null){
			throw new IllegalArgumentException();
		}
		else{
			return road;
		}
	}
	
	public GeographicPoint getLocation(){
		return location;
	}
	public void setEndDistance(double dist){
		end_distance = dist;
	}
	public void setStartDistance(double dist){
		start_distance = dist;
	}
	public double getStartDistance(){
		return start_distance;
	}
	public double getEndDistance(){
		return end_distance;
	}
	
	public double infinity(){
		return Double.MAX_VALUE;
	}
	
	public int compareTo(Object o){
		Vertex v = (Vertex)o;
		Double dist = this.getStartDistance() + this.getEndDistance();
		Double other_dist = v.getStartDistance() + v.getEndDistance();
		return dist.compareTo(other_dist);
	}
	public boolean equals(Object o){
		Vertex v = (Vertex)o;
		return this.location.equals(v.location);
	}
}
