package module3;

//Java utilities libraries
import java.util.ArrayList;
//import java.util.Collections;
//import java.util.Comparator;
import java.util.List;

//Processing library
import processing.core.PApplet;

//Unfolding libraries
import de.fhpotsdam.unfolding.UnfoldingMap;
import de.fhpotsdam.unfolding.marker.Marker;
import de.fhpotsdam.unfolding.data.PointFeature;
import de.fhpotsdam.unfolding.marker.SimplePointMarker;
import de.fhpotsdam.unfolding.providers.Google;
import de.fhpotsdam.unfolding.providers.MBTilesMapProvider;
import de.fhpotsdam.unfolding.utils.MapUtils;

//Parsing library
import parsing.ParseFeed;

/** EarthquakeCityMap
 * An application with an interactive map displaying earthquake data.
 * Author: UC San Diego Intermediate Software Development MOOC team
 * @author Ronny MacMaster
 * Date: December 23, 2015
 * */
public class EarthquakeCityMap extends PApplet {

	// You can ignore this.  It's to keep eclipse from generating a warning.
	private static final long serialVersionUID = 1L;

	// IF YOU ARE WORKING OFFLINE, change the value of this variable to true
	private static final boolean offline = false;
	
	// Less than this threshold is a light earthquake
	public static final float THRESHOLD_MODERATE = 5;
	// Less than this threshold is a minor earthquake
	public static final float THRESHOLD_LIGHT = 4;

	/** This is where to find the local tiles, for working without an Internet connection */
	public static String mbTilesString = "blankLight-1-3.mbtiles";
	
	// The map
	private UnfoldingMap map;
	
	//feed with magnitude 2.5+ Earthquakes
	private String earthquakesURL = "http://earthquake.usgs.gov/earthquakes/feed/v1.0/summary/2.5_week.atom";

	
	public void setup() {
		size(950, 600, OPENGL);
		
		if (offline) {
		    map = new UnfoldingMap(this, 200, 50, 700, 500, new MBTilesMapProvider(mbTilesString));
		    earthquakesURL = "2.5_week.atom"; 	// Same feed, saved Aug 7, 2015, for working offline
		}
		else {
			map = new UnfoldingMap(this, 200, 50, 700, 500, new Google.GoogleMapProvider());
			// IF YOU WANT TO TEST WITH A LOCAL FILE, uncomment the next line
			//earthquakesURL = "2.5_week.atom";
		}
		
	    map.zoomToLevel(2);
	    MapUtils.createDefaultEventDispatcher(this, map);	
		
	    // The List you will populate with new SimplePointMarkers
	    List<Marker> markers = new ArrayList<Marker>();

	    //Use provided parser to collect properties for each earthquake
	    List<PointFeature> earthquakes = ParseFeed.parseEarthquake(this, earthquakesURL);
	    
	    for(PointFeature f : earthquakes){
		    	//System.out.println(f.getProperties());
		    	//System.out.println(f.getLocation());
		    	markers.add(createMarker(f));
	    }
	    System.out.println("Markers Size: " + markers.size());
	    System.out.println("Earthquacke Count: " + earthquakes.size());
	    
	    map.addMarkers(markers);
	   
	}
		
	// A suggested helper method that takes in an earthquake feature and 
	// returns a SimplePointMarker for that earthquake
	private SimplePointMarker createMarker(PointFeature feature)
	{	 
	    int yellow = color(255, 255, 0), red = color(255, 0, 0), blue = color(0, 0, 255);
		float mag = Float.parseFloat(feature.getProperty("magnitude").toString());
		SimplePointMarker smark = new SimplePointMarker(feature.getLocation(), feature.getProperties());
		if(mag < 4.0){
			smark.setColor(blue);
			smark.setRadius((float) 7.5);
			System.out.println("Magnitude: " + smark.getProperty("magnitude") + "\t Color: Blue");
		}
		else if((mag >= 4.0)&&(mag <= 4.9)){
			smark.setColor(yellow);
			smark.setRadius((float) 10);
			System.out.println("Magnitude: " + smark.getProperty("magnitude") + "\t Color: Yellow");
		}
		else
		{
			smark.setColor(red);
			smark.setRadius((float) 12.5);
			System.out.println("Magnitude: " + smark.getProperty("magnitude") + "\t Color: Red");
		}
		return smark;
	}
	
	public void draw() {
	    background(10);
	    map.draw();
	    addKey();
	}


	// helper method to draw key in GUI
	// TODO: Implement this method to draw the key
	private void addKey() 
	{	
		fill(255,255,255);
		rect(25, 50, 150 , 300, 10);
		fill(0, 0, 255); 	ellipse(40,125,7,7); //blue markers
		fill(255, 255, 0); 	ellipse(40,175,10,10);//yellow markers
		fill(255, 0, 0); 	ellipse(40,225,15,15);//red markers
		fill(0,60,0);
		text("Earthquake Key", 40, 80);
		text("Below 4.0 Magnitude", 52, 130);
		text("4.0 + Magnitude", 52, 180);
		text("5.0 + Magnitude", 52, 230);
	}
}
