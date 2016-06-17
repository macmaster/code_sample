/** Stock.java **
 * 
 * Author: Ronald Macmaster
 * 
 * Created on May 26, 2016
 * (c) Copyright IBM Corporation 2016
 * 
 *****************************************/
package stock;

/**
 * Data structure for the stock data type
 * @author ronny
 *
 */
public class Stock {

	private String stockId;
	private String name;
	private int quantity;

	public Stock(String stockId, String name, int quantity) {
		this.stockId = stockId;
		this.name = name;
		this.quantity = quantity;
	}

	public String getStockId() {
		return stockId;
	}

	public void setStockId(String stockId) {
		this.stockId = stockId;
	}

	public int getQuantity() {
		return quantity;
	}

	public String getTicker() {
		return name;
	}
}
