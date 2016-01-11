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

	public double RoadMultiplier(){
		if(roadType.equals("motorway")||
		   roadType.equals("motorway_link")||
		   roadType.equals("trunk")){
			return 1.0;
		}
		else if(roadType.equals("primary")||
				roadType.equals("primary_link")||
				roadType.equals("secondary")||
				roadType.equals("secondary_link")){
			return 1.1;
		}
		else if(roadType.equals("residential")||
				roadType.equals("living_street")||
				roadType.equals("tertiary")||
				roadType.equals("unclassified")){
			return 1.4;
		}
		else{
			return 1.0;
		}
	}
	
}
