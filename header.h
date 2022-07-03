/*
* Programmer: Jack Balster
* Class: CptS 121; Lab Section 4
* Programming Assignment: Programming Assignment 4
* Date: 2/19/2022
* Description: This program contains functions that allows the user to play a game of craps.
* It allows the user to place wagers and displays according messages.
*/


#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>;
#include <time.h>;
#include <stdlib.h>;
#include <math.h>;

/*
* Function: print_game_rules ()
* Date Created:
* Date Last Modified:
* Description: This function displays the rules of craps
* Input parameters:
* Returns:
* Preconditions:
* Postconditions:
*/
void print_game_rules(void);

/*
* Function: get_bank_balance ()
* Date Created:
* Date Last Modified:
* Description: This function asks for and stores the intial balance of the user
* Input parameters: Number from the user
* Returns: The balance (amount/number) from the user
* Preconditions:
* Postconditions:
*/
double get_bank_balance(void);

/*
* Function: get_wager_amount ()
* Date Created:
* Date Last Modified:
* Description: This function asks for and stores the wager of the user
* Input parameters: Number from the user
* Returns: The wager amount from the user
* Preconditions:
* Postconditions:
*/
double get_wager_amount(void);

/*
* Function: check_wager_amount ()
* Date Created:
* Date Last Modified:
* Description: This function checks to see that the wager amount entered is valid
* Input parameters: The wager amount and balance amount
* Returns: If the wager is valid or not/an according message
* Preconditions:
* Postconditions:
*/
int check_wager_amount(double wager, double balance);

/*
* Function: roll_die ()
* Date Created:
* Date Last Modified:
* Description: This function rolls the die and generates a random number between 1-6
* Input parameters:
* Returns: The die amount (1-6)
* Preconditions:
* Postconditions:
*/
int roll_die(void);

/*
* Function: calculate_sum_die ()
* Date Created:
* Date Last Modified:
* Description: This function calculates the sum of the 2 dice rolls
* Input parameters: The die amounts (1-6)
* Returns: The sum of the two die values
* Preconditions:
* Postconditions:
*/
int calculate_sum_dice(int die1_value, int die2_value);

/*
* Function: is_win_loss_or_point ()
* Date Created:
* Date Last Modified:
* Description: This function determines if the sum of the dice is a win, loss, or set their point
* Input parameters: The sum of the dice
* Returns: If the sum is a win, loss, or they set their point
* Preconditions:
* Postconditions:
*/
int is_win_loss_or_point(int sum_dice);

/*
* Function: is_point_loss_or_neither ()
* Date Created:
* Date Last Modified:
* Description: This function determines if the sum of the dice equals their point, loss, or neither
* Input parameters: The sum of the dice and the point they set
* Returns: If the sum of the dice is their point, loss, or neither
* Preconditions:
* Postconditions:
*/
int is_point_loss_or_neither(int sum_dice, int point_value);

/*
* Function: adjust_bank_balance ()
* Date Created:
* Date Last Modified:
* Description: This function updates the balance based on the starting balance and wager amount
* Input parameters: Wager amount, starting balance, win, loss, or neither
* Returns: The updated balance based on the outcome of the game
* Preconditions:
* Postconditions:
*/
double adjust_bank_balance(double bank_balance, double wager_amount, int add_or_subtract);

/*
* Function: chatter_messages ()
* Date Created:
* Date Last Modified:
* Description: This function displays messages based on the updated balance and outcome of the game
* Input parameters: Current/updated balance, outcome of the game
* Returns: A message based on the amount of the balance and outcome of the game
* Preconditions:
* Postconditions:
*/
void chatter_messages(int number_rolls, int win_loss_neither, double initial_bank_balance, double current_bank_balance);

/*
* Function: replay_menu ()
* Date Created:
* Date Last Modified:
* Description: This function runs if player has money. It also restarts the game (loop) or ends the game based on user input
* Input parameters: The balance and the character 'y' or 'n' for yes or no
* Returns: Plays another game or exits program
* Preconditions:
* Postconditions:
*/
int replay_menu(double balance);

/*
* Function: play_game ()
* Date Created:
* Date Last Modified:
* Description: This function plays the game of craps using all functions
* Input parameters:
* Returns: Exits program
* Preconditions:
* Postconditions:
*/
void play_game(); 

/*
* Function: check_balance_amount ()
* Date Created:
* Date Last Modified:
* Description: This function makes sure the balance is greater than 0
* Input parameters: User inputted balance amount
* Returns: The balance
* Preconditions:
* Postconditions:
*/
int check_balance_amount(double balance); 
