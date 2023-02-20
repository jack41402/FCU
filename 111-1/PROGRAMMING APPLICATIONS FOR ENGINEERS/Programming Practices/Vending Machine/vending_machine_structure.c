/*
   Write a C program to define a vending machine using a data structure and 
   to simulate this vending machine with the following rules. 
   The data structure of a vending machine must inlcude all components of 
   the vending machine as its attributes.  This vending machine sells 
   the following eight products:
     A: Coca Cola, unit price US $1.65
	 B: Minute Maid Orange Juice, unit price US $3.50
	 C: Evian Mineral Water, unit price $2.80
	 D: M&M's Chocolate, unit price $1.50
	 E: Hershey's Chocolate Bar, unit price $1.85
	 F: Oreo Cookies, unit price $1.00
	 G: Doritos Tortilla Chips, unit price $3.25
	 H: Pringles Potato Chips, unit price $3.40
	 
   The vending machine starts with the five operational mode as below:
	 a. Deposit bill(s) or coin(s),
	 b. Select product(s),
	 c. Cancel a product,
	 d. Purchse puoduct(s),
	 e. Abort transaction.

    1. When button 'a' is selected, the vending machine enters the money deposit state and 
	   the customer can deposit either bills or coins. Before each money deposit, enter 'B' 
	   for bill deposit and 'C' for coin deposit.
       i. When the money deposit is 'B', the customer can deposit a 1-dollar, 5-dollar,
	      10-dollar, or 20-dollar bill by entering integer 1, 5, 10, or 20 to represent 
		  the value of a bill, respectively. The money deposit state ends when the value 
		  is 0. If the integer value is a number other than 0, 1, 5, 10, and 20 , the 
		  money deposit is ignored, the vending mahine stays in the money deposit state. 
	  ii. When the money deposit is 'C', the customer can deposit a nickel (5 cents), 
	      a dime (10 cents), or a quarter (25 cents) using integer 5, 10, or 25 to 
		  represent the value of a coin, respectively. The money deposit state ends when 
		  the value is 0.  If the integer value is a number other than 0, 5, 10, and 25, 
		  the money deposit is ignored and the vending mahine stays in the money deposit 
		  state.
     iii. If the money depoist is neither 'B' nor 'C', the input is ignored and the money 
	      deposit state ends. The vending machine is back to wait for the next operational 
		  mode.
    2. When button 'b' is selected, the vending machine enters the product selection state
	   and the customer can select a product by entering one of characters 'A', 'B', 'C', 
	   'D', 'E', 'F', 'G', and 'H' as described above. In state  'b', a customer may select 
	   multiple items until he/she enters 'Q' to quit; if any of the other characters is 
	   entered, it is ignored.
    3. When button 'c' is selected, the customer can cancel a selected product item by 
	   entering one of 'A', 'B', 'C', 'D', 'E', 'F', 'G', and 'H'. Each time a button 'c' 
	   is selected, only one item can be canceled. If any of the other characters is 
	   entered, it is ignored. When a product is canceled, its quantity in the current 
	   trasaction must be greater than 0 and the quantity is decreased by 1; otherwise, the 
	   cancellation has no effect.
    4. When button 'd' is selected, the total price of the selected products is calculated.
       i. If the deposited money is greater than or equal to the total price, output the 
	      selected products and quantities to simulate the vending machine dropping the 
		  selected products and return the changes to the customer. The returned changes 
		  contain coins only and must be the least number of coins. You may assume the 
		  vending machine has sufficient inventory of products and coins. A transaction 
		  is completed when the changes are returned. The vending machine may begin a 
		  new transaction.
      ii. If the deposited money is less than the total price, show a message 
	      "Insufficient Deposit and enter state a to deposit additional money.
    5. When button 'e' is selected, the current transaction is aborted, return all the 
	   deposit money to the customer. Assume the vending machine can return both bills and
	   coins. Show the value and the number for each bill or coin deposited by the 
	   customer and the total amount returned. When the transaction is canceled, 
	   the deposited money is returned. The vending machine may begin a new transaction.

   At the end of each of the above steps, show the current transaction status including 
   the total deposit amonut, the name of each selected product with its unit price, and 
   the total price of the selected products.
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Global variable declarations.
typedef struct {
  char name[40];
  float price;
} Item;

typedef struct {
  unsigned short bills[4]; // Four kinds of bills: 1-dollar, 5-dollar, 10-dollar, and 20-dollar.
  unsigned short coins[3]; // Three kinds of coins: nickel, dime, and quarter.
  unsigned short quantities[8]; // Eight kinds of products.
  Item items[8]; // Eight prouduct are sold by the vending machine. 
  char selected_button;
  float total_money; // Total deposited money.
  float total_price; // Total selected price.
} Vending_Machine;

// The products of sold by the vending machine.
const char items[8][40]= {"Coca Cola               ",
                          "Minute Maid Orange Juice",
					  	  "Evian Mineral Water     ", 
						  "M&M\'s Chocolate         ",
						  "Hershey\'s Chocolate Bar ", 
						  "Oreo Cookies            ", 
						  "Doritos Tortilla Chips  ",
						  "Pringles Potato Chips   "};
// Unist price of the eight products.
const float prices[8] = {1.65, 3.50, 2.80, 1.50, 1.85, 1.00, 3.25, 3.40};

// Forward reference of function reset_bills_coins_quantities.
void reset_bills_coins_quantities(Vending_Machine*);

void initial_vending_machine(Vending_Machine *vm_ptr) {
  int i;
  
  for (i=0; i<8; i++) {
  	//(vm_ptr->items[i]).name = (char *) malloc(strlen(items[i])+1);
  	strcpy((vm_ptr->items[i]).name, items[i]); // Initial item name.
  	(vm_ptr->items[i]).price = prices[i]; // Initial item price.
  }
  reset_bills_coins_quantities(vm_ptr); // Reset bills, coins, and quantities.
}

// Reset the deposited bills, coins, and product quantities to 0
void reset_bills_coins_quantities(Vending_Machine *vm_ptr) {
  int i;
  
  vm_ptr->total_money = 0; // Reset total deposited money to 0.
  vm_ptr->total_price = 0; // Reset total price to 0.
  // The vending machine accepts four kinds of bills: 1-dollar, 5-dollar, 10-dollar, and 20-dollar.
  for (i=0; i<4; i++) vm_ptr->bills[i] = 0;
  // The vending machine accepts three kinds of coins: nickel, dime, and quarter.
  for (i=0; i<3; i++) vm_ptr->coins[i] = 0;
  // The vending machine sells eight products.
  for (i=0; i<8; i++) vm_ptr->quantities[i] = 0;
}

// Show the current transaction stauts.
void show_transaction_state(Vending_Machine *vm_ptr) {
  int i; 

  printf("\n#########################################################\n\n"); // Print a separate line.
  printf("  Current Transaction Status:\n"); // Print transation heading.
  printf("    Deposited Amount: %4.2f\n", vm_ptr->total_money); // Print deposited money amount.
  if (vm_ptr->total_price>0) { // Some products have been selected. 
    printf("    Total Price: %4.2f\n", vm_ptr->total_price); // Print the total price.
    printf("    Selected Products:\n"); // Print heading for selected items.
    for (i=0; i<8; i++) { // Print the selected items.
      if (vm_ptr->quantities[i]>0) // Print only when quantity is not zero.
	    printf("      %s: %-2d\n", (vm_ptr->items[i]).name, vm_ptr->quantities[i]); 
    } 
  }
  else printf("    No product is selected.\n"); // No item is selected.
  printf("\n#########################################################\n\n"); // Print a separate line.
} 

// Print the operational menu.
void select_button(Vending_Machine *vm_ptr) {
	
  show_transaction_state(vm_ptr); // Print the transaction state.
  // Output the operational menu, five selections.
  printf("    Select one of the following buttons:\n");
  printf("      a: Depoist bill(s) or coin(s)\n");
  printf("      b: Select product(s)\n");
  printf("      c: Cancel a product\n");
  printf("      d: Purchase the selected product(s)\n");
  printf("      e: Abort this transation\n");
  
  // Ask the customer to enter an operatioanl button.
  printf("\n>>> Select a button: "); 
  scanf("\n%c", &(vm_ptr->selected_button));
}

// To deposit bills. Acceptes only 1-dollar, 5-dollar, 10-dollar, or 20-dollar bills. 
void deposit_bills(Vending_Machine *vm_ptr) {
  int bill; 
    
  do {
    printf(">>> Deposit 1-dollar, 5-dollar, 10-dollar, or 20-dollar bills (enter 0 to quit): ");     
    scanf("%d", &bill);
    switch (bill) {
      case 1: {vm_ptr->bills[0]++; break;} 
      case 5: {vm_ptr->bills[1]++; break;}
      case 10: {vm_ptr->bills[2]++; break;}
      case 20: {vm_ptr->bills[3]++; break;}
    }
    if (bill==1 || bill==5 || bill==10 || bill==20) { // If the bill is correctly entered
      printf("$$$$ Deposit a %d dollar bill\n", bill);
	  vm_ptr->total_money =  vm_ptr->total_money + bill; // Update the total money amount.
	} 
    else  if (bill!=0) printf("$$$$ Invalid bill deposit.\n"); // Invlid bill.
    else printf("$$$$ End of bill deposit\n"); // No more bills.  
    
    if (bill!=0) show_transaction_state(vm_ptr); // Print the transaction state.
  } while (bill != 0); // Continue if the bill is not zero.
}

// To deposit coins. Only nickel (5 cents), dime (10 cents), or quarter (25 cents) is deposited.
void deposit_coins(Vending_Machine *vm_ptr) {
  int coin; 
    
  do {
    printf(">>> Deposit a nickel (5 cents), a dime (10 cents), or a quarter (25 cents) (enter 0 to quit): ");     
    scanf("%d", &coin);
    switch (coin) {
      case 5: {vm_ptr->coins[0]++; 
      printf("$$$$ Deposit a nickel (%d cents).\n", coin);
	  break;} 
      case 10: {vm_ptr->coins[1]++; 
      printf("$$$$ Deposit a dime (%d cents).\n", coin);break;}
      case 25: {vm_ptr->coins[2]++; 
      printf("$$$$ Deposit a quarter (%d cents).\n", coin);break;}
    }
    if (coin==5 || coin==10 || coin==25) vm_ptr->total_money +=  coin * 0.01; // Update the total money amount.
    else  if (coin!=0) printf("$$$$ Invalid coin deposit.\n"); // Invalid coin.
    else printf("$$$$ End of coin deposit\n"); // No more coins.   
    
    if (coin!=0) show_transaction_state(vm_ptr);
  } while (coin != 0); 
}

// Depoist bills or coins. Judy by an input characd
void deposit_bills_coins(Vending_Machine *vm_ptr) {
  char bill_coin;
  
  printf("$$$$ Enter 'B' for bills or 'C' for coins: "); // Print deposit heading.
  scanf("\n%c", &bill_coin); // Enter a character.
  printf("\n");
  if (bill_coin=='B') deposit_bills(vm_ptr); // 'B' for bills.
  else if (bill_coin=='C') deposit_coins(vm_ptr); // 'C' for coins.
  else printf("$$$$ No money is deposited.\n"); // Inalid input.
}

// Select itesm; can be repeated.
void select_items(Vending_Machine *vm_ptr) {
  char item; // 'A' to 'H for an item. 'Q' to quit.
  int i; // Loop variable.
  
  do {
    printf("\tProduct items (enter a product code)¡G\n");  // Print the product selections.
    for (i=0; i<8; i++) printf("\t  %c: %s\t$%4.2f\n", 'A'+i, // Print product items and prices.
	                           (vm_ptr->items[i]), (vm_ptr->items[i]).price);
    printf("\t  Q: End of product selection\n"); 
    printf("\n>>> Enter Product code: "); 
    scanf("\n%c", &item);
    if (item>='A' && item<='H') { // 'A' to 'H for an item. 'Q' to quit.
      printf("**** Product selected¡G%s\n\n", (vm_ptr->items[item-'A']).name); 
      ++vm_ptr->quantities[item-'A']; // Update quantity.
      vm_ptr->total_price += (vm_ptr->items[item-'A']).price; // Upadte total price.
    }
    else if (item!='Q') printf("**** Invalid items. No product is selected.\n\n"); // Invalid item.
  } while (item != 'Q');
  printf("**** End of product selection\n\n"); 
}

// Cancel an item.
void cancel_item(Vending_Machine *vm_ptr) {
  char item; // 'A' to 'H for a canceled item.
  int i; 
  
  printf("\tSelected Product(s):\n"); // Print the product selections.
  for (i=0; i<8; i++) printf("\t%c: %s\t%4.2f\n", 'A'+i, // Print product code, item, and price.
                             (vm_ptr->items[i]).name, (vm_ptr->items[i]).price); 
  printf("\n"); 
  printf("\n>>> Enter a product code: "); // 'A' to 'H for a canceled item.
  scanf("\n%c", &item);
  if (item>='A' && item<='H' && vm_ptr->quantities[item-'A']>0) { // The canceled item must be selected before.
    printf("**** Canceled product¡G%s\n\n", (vm_ptr->items[item-'A']).name);  // Print the product.
    --vm_ptr->quantities[item-'A']; // Decrement the quantity of the canceled item
    vm_ptr->total_price -= (vm_ptr->items[item-'A']).price; // Update the total price.
  } 
  else printf("**** Invalid item. No product is canceled.\n\n"); // Invalid product code.
}

// Dispense the items purchased by printing the selected items and quantities.
void dispense_items(Vending_Machine *vm_ptr) {
  int i; 
  
  printf("**** Pruchase product(s):\n");
  for (i=0; i<8; i++)
    if (vm_ptr->quantities[i] > 0) printf("\t%s¡G %-2d\n", (vm_ptr->items[i]).name, vm_ptr->quantities[i]);
}

// Return the changes. 
void return_changes(Vending_Machine *vm_ptr) {
  int changes = (int) ((vm_ptr->total_money - vm_ptr->total_price) * 100); // Compute the changes in cents.
  
  printf("**** Return changes USD %4.2f\n", vm_ptr->total_money - vm_ptr->total_price); // The amount of changes.
  if (changes >= 25) {printf("\t%d quarter(s)\n", changes / 25);  changes = changes % 25; } // Quarter.
  if (changes >= 10) {printf("\t%d dime(s)\n", changes / 10);  changes = changes % 10; } // Dimes.
  if (changes >= 5)  {printf("\t%d Nickel(s)\n", changes / 5);  changes = changes % 5; } // Nickels.
  printf("\n");
} 

// Purchase products.
void purchase_products(Vending_Machine *vm_ptr) {
  if (vm_ptr->total_price==0) { // Must have selected some products.
    // If not, do not dispense products.
    printf("**** No product is selected. Enter 'e', if to abort this transaction.\n");
    vm_ptr->selected_button = 'c'; // Set to a state other than 'd' or 'e'.
	show_transaction_state(vm_ptr); 
  } 
  else if (vm_ptr->total_money >= vm_ptr->total_price) { // Must deposit enough money.
    dispense_items(vm_ptr); // Dispense proudct itesm.
    return_changes(vm_ptr); // Return changes to customer.
    reset_bills_coins_quantities(vm_ptr);  // Neither bills nor coins are deposited.
  } 
  else {
    printf("**** Insufficient deposited money. Deposit bills or coids.\n\n");
    vm_ptr->selected_button = 'a'; // Set the state to money deposit state.
    deposit_bills_coins(vm_ptr); // Deposit more money.
  } 
}

// When transaction is aborted, return the deposits bills and coins.
void return_bills_coins(Vending_Machine *vm_ptr) {
  
  printf("**** Return deposited bills and coins, total USD %4.2f.\n", vm_ptr->total_money);
  if (vm_ptr->bills[0]>0) printf("\t1-dollar bill: %d\n", vm_ptr->bills[0]); 
  if (vm_ptr->bills[1]>0) printf("\t5-dollar bill: %d\n", vm_ptr->bills[1]);
  if (vm_ptr->bills[2]>0) printf("\t10-dollar bill: %d\n", vm_ptr->bills[2]);
  if (vm_ptr->bills[3]>0) printf("\t20-dollar bill: %d\n", vm_ptr->bills[3]);
  if (vm_ptr->coins[0]>0) printf("\tnickel (5-cent): %d\n", vm_ptr->coins[0]);
  if (vm_ptr->coins[1]>0) printf("\tdime (10-cent): %d\n", vm_ptr->coins[1]);
  if (vm_ptr->coins[2]>0) printf("\tquarter (25-cent): %d\n", vm_ptr->coins[2]);
  printf("\n");
}

void abort_transaction(Vending_Machine *vm_ptr) {
  if (vm_ptr->total_money > 0) return_bills_coins(vm_ptr); // Return the deposit money to customer.
  printf("**** This transation is aborted.\n\n"); // Abort message.
  reset_bills_coins_quantities(vm_ptr); // Reset bill/coin deposit and product quantities to 0.
}

// Execution a transaction.
void execute_transaction(Vending_Machine *vm_ptr) {
  int i; // Loop variable
  
  reset_bills_coins_quantities(vm_ptr); // Reset bill/coin deposit and product quantities to 0.
  
  do { // Repeat until a transaction is completed or aborted.
    select_button(vm_ptr); // Enter a selected button.
    switch (vm_ptr->selected_button) { // Five case: 'a' to 'e'.
      case 'a': { // Bills or coins deposit.
           deposit_bills_coins(vm_ptr);
           break; 
           }
      case 'b': { // Item selection.
           select_items(vm_ptr); 
           break;
           } 
      case 'c': { // Item cancellation.
           cancel_item(vm_ptr); 
           break;
           } 
      case 'd': { // Purchase items.
           purchase_products(vm_ptr); 
           break;
           } 
      case 'e': { // Abord transaction.
           abort_transaction(vm_ptr);
           break; }
      default: {printf("@@@@ Invalid selection\n\n");} 
    }
  } while (vm_ptr->selected_button!='d' && vm_ptr->selected_button!='e');   
}

int main(void) {
  Vending_Machine vm;  // A vending machine
  char transaction; // Start a transaction or not.
  
  initial_vending_machine(&vm); // Initial items and prices of the vending machine.    
  do {
    printf(">>> Enter \'Y\' to start a transaction and \'N\' to quit: ");
    scanf("\n%c", &transaction);
    printf("\n"); 
    if (transaction == 'Y') execute_transaction(&vm);
  } while (transaction != 'N'); 
  
  return 0;
}
