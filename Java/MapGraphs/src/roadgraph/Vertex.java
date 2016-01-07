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
	
	public Vertex(){
		System.out.println("invalid node created!!!!!!!!!!");
		location = null;
		neighbors = null;
	}
	
	public Vertex(GeographicPoint location){
		this.location = location;
		this.neighbors = new ArrayList<Vertex>();
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
}
