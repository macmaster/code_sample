package roadgraph;

import geography.GeographicPoint;

public class Edge {
	private Vertex start;
	private Vertex end;
	private String roadName;
	private String roadType;
	private double length;
	static final double DEFAULT_LENGTH = 0.01;
	
	public Edge(String roadName, String roadType, Vertex start, Vertex end, double length){
		this.roadName = roadName;
		this.roadType = roadType;
		this.length = length;
		this.start = start;
		this.end = end;
	}
	public Edge(String roadName, String roadType, Vertex start, Vertex end){
		this(roadName, roadType, start, end, DEFAULT_LENGTH);
	}
	public Edge(String roadName, Vertex start, Vertex end){
		this(roadName, "", start, end, DEFAULT_LENGTH);
	}
	
	public Vertex getEnd(){
		return end;
	}
	
	public GeographicPoint getStartPoint(){
		return start.getLocation();		
	}
	public GeographicPoint getEndPoint(){
		return end.getLocation();
	}
	public double getLength(){
		return length;
	}

	public String getRoadName(){
		return roadName;
	}
	
}
