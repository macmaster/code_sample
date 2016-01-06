/**
 * @author Ronald MacMaster
 *
 * A node within the MapGraph
 * Nodes in the graph are intersections between roads or dead ends
 */
package roadgraph;

import java.util.List;
import java.util.ArrayList;

class MapNode {
	private List<MapNode> neighbors;
	private double latitude, longitude;
	
	public MapNode(){
		longitude = latitude = 0.0;
		neighbors = null;
	}
	
	public MapNode(double latitude, double longitude){
		this.latitude = latitude;
		this.longitude = longitude;
		this.neighbors = new ArrayList<MapNode>();
	}
	
	
	
	
	
	
	
	
	private List<MapNode> getNeighbors(){
		return neighbors;
	}
	
	private double getLatitude(){
		return latitude;
	}
	
	private double getLongitude(){
		return longitude;
	}

}
