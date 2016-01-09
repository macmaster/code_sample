/**
 * @author Ronald MacMaster
 *
 * A node within the MapGraph
 * Nodes in the graph are intersections between roads or dead ends
 */
package roadgraph;

import java.util.Set;
import java.util.HashSet;
import geography.GeographicPoint;

@SuppressWarnings("rawtypes")
public class Vertex implements Comparable{
	private Set<Edge> neighbors; // list of all roads out of node
	private GeographicPoint location;
	private double start_distance;
	private double end_distance;
	
	public Vertex(GeographicPoint location){
		this.location = location;
		this.neighbors = new HashSet<Edge>();
		start_distance = 0;
		end_distance = 0;
	}
	
	
	public boolean addNeighbor(Edge new_neighbor){
		if((new_neighbor == null)||neighbors.contains(new_neighbor))
			return false;
		else{
			neighbors.add(new_neighbor);
			return true;
		}
	}

	public Set<Vertex> getNeighbors(){
		Set<Vertex> neighbors = new HashSet<Vertex>();
		for(Edge e: this.neighbors)
			neighbors.add(e.getEnd());
		return neighbors;
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
	
	public int compareTo(Object o){
		Vertex v = (Vertex)o;
		return ((Double)this.getStartDistance()).compareTo((Double)v.getStartDistance());
	}
	public boolean equals(Object o){
		Vertex v = (Vertex)o;
		return this.location.equals(v.location);
	}
}
