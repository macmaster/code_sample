/** Portfolio.java **
 * 
 * Author: Ronald Macmaster
 * 
 * Created on May 26, 2016
 * (c) Copyright IBM Corporation 2016
 * 
 *****************************************/
package stock;

import java.util.List;

/**
 * Portfolio of a stock collection
 * @author ronny
 *
 */
public class Portfolio {
	
	   private StockService stockService;
	   private List<Stock> stocks;

	   public StockService getStockService() {
	      return stockService;
	   }
	   
	   public void setStockService(StockService stockService) {
	      this.stockService = stockService;
	   }

	   public List<Stock> getStocks() {
	      return stocks;
	   }

	   public void setStocks(List<Stock> stocks) {
	      this.stocks = stocks;
	   }

	   public double getMarketValue(){
	      double marketValue = 0.0;
	      
	      for(Stock stock:stocks){
	         marketValue += stockService.getPrice(stock) * stock.getQuantity();
	      }
	      return marketValue;
	   }

}
