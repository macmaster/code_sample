/**
 * @author Ronald MacMaster
 *
 * A node within the MapGraph
 * Nodes in the graph are intersections between roads or dead ends
 */
package roadgraph;

import java.util.List;
import java.util.ArrayList;
import geography.GeographicPoint;

public class Vertex {
	private List<Vertex> neighbors;
	private GeographicPoint location;
	private double start_distance;
	private double end_distance;
	
	public Vertex(GeographicPoint location){
		this.location = location;
		this.neighbors = new ArrayList<Vertex>();
		start_distance = 0;
		end_distance = 0;
	}
	
	public List<Vertex> getNeighbors(){
		return neighbors;
	}
	
	public boolean addNeighbor(Vertex new_neighbor){
		if((new_neighbor == null)||neighbors.contains(new_neighbor))
			return false;
		else{
			neighbors.add(new_neighbor);
			return true;
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
}
