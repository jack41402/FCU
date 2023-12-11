// Vending Machine
#include<stdio.h>
#include<stdlib.h>

// Global variable declarations.
unsigned short bills[4]; // Four kinds of bills: 1-dollar, 5-dollar, 10-dollar, and 20-dollar.
unsigned short coins[3]; // Three kinds of coins: nickel, dime, and quarter.
unsigned short quantities[8]; // Eight products.
// The products of sold by the vending machine.
const char *items[8] = {"Coca Cola               ",
                        "Minute Maid Orange Juice",
                        "Evian Mineral Water     ", 
                        "M&M\'s Chocolate         ",
                        "Hershey\'s Chocolate Bar ", 
                        "Oreo Cookies            ", 
                        "Doritos Tortilla Chips  ",
                        "Pringles Potato Chips   "};
// Unist price of the eight products.
const float prices[8] = {1.65, 3.50, 2.80, 1.50, 1.85, 1.00, 3.25, 3.40}; 
char selected_button; 
float total_money = 0.0, total_price = 0.0; // Total deposited money and total price.

// Reset the deposited bills, coins, and product quantities to 0
void reset_bills_coins_quantities() {
  int i;
  
  total_money = 0; // Reset total deposited money to 0.
  total_price = 0; // Reset total price to 0.
  // The vending machine accepts four kinds of bills: 1-dollar, 5-dollar, 10-dollar, and 20-dollar.
  for (i=0; i<4; i++) bills[i] = 0;
  // The vending machine accepts three kinds of coins: nickel, dime, and quarter.
  for (i=0; i<3; i++) coins[i] = 0;
  // The vending machine sells eight products.
  for (i=0; i<8; i++) quantities[i] = 0;
}

// Show the current transaction stauts.
void show_transaction_state() {
  int i; 

  printf("\n#########################################################\n\n"); // Print a separate line.
  printf("  Current Transaction Status:\n"); // Print transation heading.
  printf("    Deposited Amount: %4.2f\n", total_money); // Print deposited money amount.
  if (total_price>0) { // Some products have been selected. 
    printf("    Total Price: %4.2f\n", total_price); // Print the total price.
    printf("    Selected Products:\n"); // Print heading for selected items.
    for (i=0; i<8; i++) { // Print the selected items.
      if (quantities[i]>0) printf("      %s: %-2d\n", items[i], quantities[i]); // Only item name and quantity.
    } 
  }
  else printf("    No product is selected.\n"); // No item is selected.
  printf("\n#########################################################\n\n"); // Print a separate line.
} 

// Print the operational menu.
void select_button() {
	
  show_transaction_state(); // Print the transaction state.
  // Output the operational menu, five selections.
  printf("    Select one of the following buttons:\n");
  printf("      a: Depoist bill(s) or coin(s)\n");
  printf("      b: Select product(s)\n");
  printf("      c: Cancel a product\n");
  printf("      d: Purchase the selected product(s)\n");
  printf("      e: Abort this transation\n");
  
  // Ask the customer to enter an operatioanl button.
  printf("\n>>> Select a button: "); 
  scanf("\n%c", &selected_button);
}

// To deposit bills. Acceptes only 1-dollar, 5-dollar, 10-dollar, or 20-dollar bills. 
void deposit_bills() {
  int bill; 
    
  do {
    printf(">>> Deposit 1-dollar, 5-dollar, 10-dollar, or 20-dollar bills (enter 0 to quit): ");     
    scanf("%d", &bill);
    switch (bill) {
      case 1: {bills[0]++; break;} 
      case 5: {bills[1]++; break;}
      case 10: {bills[2]++; break;}
      case 20: {bills[3]++; break;}
    }
    if (bill==1 || bill==5 || bill==10 || bill==20) { // If the bill is correctly entered
      printf("$$$$ Deposit a %d dollar bill\n", bill);
	  total_money =  total_money + bill; // Update the total money amount.
	} 
    else  if (bill!=0) printf("$$$$ Invalid bill deposit.\n"); // Invlid bill.
    else printf("$$$$ End of bill deposit\n"); // No more bills.  
    
    if (bill!=0) show_transaction_state(); // Print the transaction state.
  } while (bill != 0); // Continue if the bill is not zero.
}

// To deposit coins. Only nickel (5 cents), dime (10 cents), or quarter (25 cents) is deposited.
void deposit_coins() {
  int coin; 
    
  do {
    printf(">>> Deposit a nickel (5 cents), a dime (10 cents), or a quarter (25 cents) (enter 0 to quit): ");     
    scanf("%d", &coin);
    switch (coin) {
      case 5: {coins[0]++; 
               printf("$$$$ Deposit a nickel (%d cents).\n", coin);
							 break;} 
      case 10: {coins[1]++; 
                printf("$$$$ Deposit a dime (%d cents).\n", coin);
								break;}
      case 25: {coins[2]++; 
                printf("$$$$ Deposit a quarter (%d cents).\n", coin);
								break;}
    }
    if (coin==5 || coin==10 || coin==25) total_money =  total_money + coin * 0.01; // Update the total money amount.
    else  if (coin!=0) printf("$$$$ Invalid coin deposit.\n"); // Invalid coin.
    else printf("$$$$ End of coin deposit\n"); // No more coins.   
    
    if (coin!=0) show_transaction_state();
  } while (coin != 0); 
}

// Depoist bills or coins.
void deposit_bills_coins() {
  char bill_coin;
  
  printf("$$$$ Enter 'B' for bills or 'C' for coins: "); // Print deposit heading.
  scanf("\n%c", &bill_coin); // Enter a character.
  printf("\n");
  if (bill_coin=='B') deposit_bills(); // 'B' for bills.
  else if (bill_coin=='C') deposit_coins(); // 'C' for coins.
  else printf("$$$$ No money is deposited.\n"); // Inalid input.
}

// Select items; can be repeated.
void select_items() {
  char item; // 'A' to 'H for an item. 'Q' to quit.
  int i; // Loop variable.
  
  do {
    printf("\tProduct items (enter a product code)¡G\n");  // Print the product selections.
    for (i=0; i<8; i++) printf("\t  %c: %s\t$%4.2f\n", 'A'+i, items[i], prices[i]);
    printf("\t  Q: End of product selection\n"); 
    printf("\n>>> Enter Product code: "); 
    scanf("\n%c", &item);
    if (item>='A' && item<='H') { // 'A' to 'H for an item. 'Q' to quit.
      printf("**** Product selected¡G%s\n\n", items[item-'A']); 
      ++quantities[item-'A']; // Update quantity.
      total_price = total_price + prices[item-'A']; // Upadte total price.
    }
    else if (item!='Q') printf("**** Invalid items. No product is selected.\n\n"); // Invalid item.
  } while (item != 'Q');
  printf("**** End of product selection\n\n"); 
}

// Cancel an item.
void cancel_item() {
  char item; // 'A' to 'H for a canceled item.
  int i; 
  
  printf("\tSelected Product(s):\n"); // Print the product selections.
  for (i=0; i<8; i++) printf("\t%c: %s\t%4.2f\n", 'A'+i, items[i], prices[i]);
  printf("\n"); 
  printf("\n>>> Enter a product code: "); // 'A' to 'H for a canceled item.
  scanf("\n%c", &item);
  if (item>='A' && item<='H' && quantities[item-'A']>0) { // The canceled item must be selected before.
    printf("**** Canceled product¡G%s\n\n", items[item-'A']);  // Print the product.
    --quantities[item-'A']; // Decrement the quantity of the canceled item
    total_price = total_price - prices[item-'A']; // Update the total price.
  } 
  else printf("**** Invalid item. No product is canceled.\n\n"); // Invalid product code.
}

// Dispense the items purchased by printing the selected items and quantities.
void dispense_items() {
  int i; 
  
  printf("**** Pruchase product(s):\n");
  for (i=0; i<8; i++)
    if (quantities[i] > 0) printf("\t%s¡G %-2d\n", items[i], quantities[i]);
}

// Return the changes. 
void return_changes() {
  int changes = (int) ((total_money - total_price) * 100); // Compute the changes in cents.
  
  printf("**** Return changes USD %4.2f\n", total_money - total_price); // The amount of changes.
  if (changes >= 25) {printf("\t%d quarter(s)\n", changes / 25);  changes = changes % 25; } // Quarters.
  if (changes >= 10) {printf("\t%d dime(s)\n", changes / 10);  changes = changes % 10; } // Dimes.
  if (changes >= 5)  {printf("\t%d Nickel(s)\n", changes / 5);  changes = changes % 5; } // Nickels.
  printf("\n");
} 

// Purchase products.
void purchase_products() {
  if (total_price==0) { // Must have selected some products.
    // If not, do not dispense products.
    printf("**** No product is selected. Enter 'e', if to abort this transaction.\n");
    selected_button = 'c'; // Set to a state other than 'd' or 'e'.
	show_transaction_state(); 
  } 
  else if (total_money >= total_price) { // Must deposit enough money.
    dispense_items(); // Dispense proudct itesm.
    return_changes(); // Return changes to customer.
    reset_bills_coins_quantities();  // Neither bills nor coins are deposited.
  } 
  else {
    printf("**** Insufficient deposited money. Deposit bills or coins.\n\n");
    selected_button = 'a'; // Set the state to money deposit state.
    deposit_bills_coins(); // Deposit more money.
  } 
}

// When transaction is aborted, return the deposits bills and coins.
void return_bills_coins() {
  
  printf("**** Return deposited bills and coins, total USD %4.2f.\n", total_money);
  if (bills[0]>0) printf("\t1-dollar bill: %d\n", bills[0]); 
  if (bills[1]>0) printf("\t5-dollar bill: %d\n", bills[1]);
  if (bills[2]>0) printf("\t10-dollar bill: %d\n", bills[2]);
  if (bills[3]>0) printf("\t20-dollar bill: %d\n", bills[3]);
  if (coins[0]>0) printf("\tnickel (5-cent): %d\n", coins[0]);
  if (coins[1]>0) printf("\tdime (10-cent): %d\n", coins[1]);
  if (coins[2]>0) printf("\tquarter (25-cent): %d\n", coins[2]);
  printf("\n");
}

void abort_transaction() {
  if (total_money > 0) return_bills_coins(); // Return the deposit money to customer.
  printf("**** This transation is aborted.\n\n"); // Abort message.
  reset_bills_coins_quantities(); // Reset bill/coin deposit and product quantities to 0.
}

// Execution a transaction.
void execute_transaction() {
  int i; // Loop variable
  
  reset_bills_coins_quantities(); // Reset bill/coin deposit and product quantities to 0.
  
  do { // Repeat until a transaction is completed or aborted.
    select_button(); // Enter a selected button.
    switch (selected_button) { // Five case: 'a' to 'e'.
      case 'a': { // Bills or coins deposit.
           deposit_bills_coins();
           break; 
           }
      case 'b': { // Item selection.
           select_items(); 
           break;
           } 
      case 'c': { // Item cancellation.
           cancel_item(); 
           break;
           } 
      case 'd': { // Purchase items.
           purchase_products(); 
           break;
           } 
      case 'e': { // Abord transaction.
           abort_transaction();
           break; }
      default: {printf("@@@@ Invalid selection\n\n");} 
    }
  } while (selected_button!='d' && selected_button!='e');   
}

int main(void) {
  char transaction; 
    
  do {
    printf(">>> Enter \'Y\' to start a transaction and \'N\' to quit: ");
    scanf("\n%c", &transaction);
    printf("\n"); 
    if (transaction == 'Y') execute_transaction();
  } while (transaction != 'N'); 
  
  return 0;
}
