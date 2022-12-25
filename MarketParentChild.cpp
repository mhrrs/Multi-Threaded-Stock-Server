#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <string.h>
#include "List.h"
#include "Stock.h"
#include "Market.h"
using namespace std;

int main(){
	//declare variables needed to create the pipes and fork off the child 
	int fd_top[2];
	int fd_bottom[2];
	pid_t pid;
	char line[80];


	// create two pipes and check for errors
	...

	// fork off child process
	// check for errors based on return value

	...

	/*  
	 * block of code for parent 
	 */
		// declare variables 
		//Market object using default parameters
		//money variable set to 0.0
		//any other variables needed ...
		...

		// close unused ends of the pipes
		...


		//display current balance, read in the stockfile, display list of stocks
		...


		// wait for child process to send purchase request through the pipe
		...

		// parse out parameters
		...

		

		// echo the child's request to the screen
		...


		// try to find stock by symbol (use Market class methods); report error
		... 
	
	
		// if not found, send "0@0.00:NULL:No such stock" to child and exit
		...

		// if found, use stored price, quantity and cost to check for value client request
			// Does the market have enough shares? Limit sale based on 
			//	 - number available
			//	 - client funds
		...
	

		// remove stocks from market
		...

		// update money
		...

		// display confirmation to screen
		...


		// send confirmation to child
		...


		// construct string with purchase confirmation
		...

		// send purchase request to child via pipe
		...
	
		// wait for child to exit; display error if appropriate
		...

		//then display the updated balance and stocklist
		...

		// and  write out the updated stockfile
		...

	   // and then parent exits
  		...


	/*  
	 * block of code for parent 
	 */
		// Wait 1 second to allow parent display to occur first
		sleep(1);

		//close unused ends of the pipes
		...


		// declare variables:
		// child maintains a list of stocks ; the list is initially empty
		// and a money balance, initialized to $10,000
		// and other variables as needed
		...

		// Child displays initial account balance and list of stocks owned
		...

		
		// prompt the user to enter a stock symbol and a quantity
		...


		// build a C++ string that contains sym, quantity and money 
		... 

		// use the string functions str() to turn your C++ string
		// object into a string, and then apply c_str() to make
		// it a null-terminated string, suitable for sending through the pipe
		...

		// send the purchase request string to the parent/server through one pipe
		...
		
		// get the response from the parent/server through the other pipe
		...

		// parse out the elements of the returned string
		// check for exceptions thrown by std::stoi and std::stod
		...

		// If the return value from the parent is successful
	   	// make a new stock object	based on the return string
			...
			// insert it into the list of stocks owned
			...
			// and update the account balance
			...

		// display updated balance and stock list 
		...
	
		// and then exit
		..

}
