/** StockService.java **
 * 
 * Author: Ronald Macmaster
 * 
 * Created on May 26, 2016
 * (c) Copyright IBM Corporation 2016
 * 
 *****************************************/
package stock;

/**
 * Stock service that returns the price of a stock
 * @author ronny
 * 
 */
public interface StockService {
	public double getPrice(Stock stock);
}
