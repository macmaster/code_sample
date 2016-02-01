/*******************************Order.h******************************************/
/* Author: Ronald Macmaster
 * Date: 1/31/2016
 *
 * Order class which represents market book orders 									  */

using namespace std;

enum ordertype {null, buy, sell};

class Order{
  
 public:
	string id;
	float price;
	int quantity;
	ordertype type;
		
	// Order constructor. default order values are invalid
	Order(string order_id = "", float order_price = -1, 
			int order_quantity = -1, ordertype order_type = null){
			 
		id = order_id;
		price = order_price;
		quantity = order_quantity;
		type = order_type;
		
	}
	
	// Copy Constructor
	Order(Order &copy){
		id = copy.id;
		price = copy.price;
		quantity = copy.quantity;
		type = copy.type;
	}
	
};
