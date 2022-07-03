/*
* Programmer: Jack Balster
* Class: CptS 121; Lab Section 4
* Programming Assignment: Programming Assignment 4
* Date: 2/19/2022
* Description: This program contains functions that allows the user to play a game of craps.
* It allows the user to place wagers and displays according messages.
*/


#include "header.h"

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
void print_game_rules(void)
{
    printf("Rules of Craps:\n\n");
    printf("A player rolls two dice. Each die has six faces. These faces contain 1, 2, 3, 4, 5, and 6 spots.\n");
    printf("After the dice have come to rest, the sum of the spots on the two upward faces is calculated.\n");
    printf("If the sum is 7 or 11 on the first throw, the player wins.\n");
    printf("If the sum is 2, 3, or 12 on the first throw, the player loses (i.e. the house wins).\n");
    printf("If the sum is 4, 5, 6, 8, 9, or 10 on the first throw, then the sum becomes the player's point.\n");
    printf("To win, you must continue rolling the dice until you make your point.\n");
    printf("The player loses by rolling a 7 before making the point.\n\n");
}


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
double get_bank_balance(void)
{
    double balance = 0.0;
    printf("Please provide your initial bank balance: ");
    scanf("%lf", &balance);
    return balance;
}
int check_balance_amount(double balance)
{
    int amount = 0;
    if (balance > 0)
    {
        amount = 1;
    }
    else
    {
        printf("Balance needs to be larger than 0\n\n", balance);
    }
    return amount;
}

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
double get_wager_amount(void)
{
    double bet = 0.0;
    printf("What is your wager: ");
    scanf("%lf", &bet);
    return bet;
}


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
int check_wager_amount(double wager, double balance)
{
    int amount = 0;
    if ((wager <= balance) && (wager > 0))
    {
        amount = 1;
    }
    else
    {
        printf("Wager needs to be less than balance and larger than 0\n\n", balance);
    }
    return amount;
}


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
int roll_die(void)
{
    int die = 0;
    die = rand() % 6 + 1;
    return die;
}


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
int calculate_sum_dice(int die1_value, int die2_value)
{
    int sum = 0;
    sum = die1_value + die2_value;
    return sum;
}


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
int is_win_loss_or_point(int sum_dice)
{
    int outcome = 0;
    if ((sum_dice == 7) || (sum_dice == 11))
    {
        outcome = 1;
    }
    else if (((sum_dice == 2) || (sum_dice == 3)) || (sum_dice == 12))
    {
        outcome = 0;
    }
    else
    {
        outcome = 2;
    }
    return outcome;
}


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
int is_point_loss_or_neither(int sum_dice, int point_value)
{
    int outcome = 0;
    if ((sum_dice == point_value))
    {
        outcome = 1;
    }
    else if (sum_dice == 7)
    {
        outcome = 0;
    }
    else
    {
        outcome = 2;
    }
    return outcome;
}


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
double adjust_bank_balance(double bank_balance, double wager_amount, int add_or_subtract)
{
    double adjust = 0.0;
    if (add_or_subtract == 1)
    {
        adjust = bank_balance + wager_amount;
    }
    else if (add_or_subtract == 0)
    {
        adjust = bank_balance - wager_amount;
    }
    return adjust;
}


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
void chatter_messages(int number_rolls, int win_loss_neither, double initial_bank_balance, double current_bank_balance)
{
    if (win_loss_neither == 1)
    {
        printf("You win!!! Congrats!!! \n");
    }
    else
    {
        printf("You lose!!! That sucks!!!\n");
    }
    if (current_bank_balance <= 0)
    {
        printf("Sorry, you busted!!!\n");
    }
    if ((current_bank_balance / initial_bank_balance) >= 2.0)
    {
        printf("You've more than doubled your money, now's the time to cash in your chips!\n");
    }
    else if ((current_bank_balance / initial_bank_balance) > 1.0)
    {
        printf("You have more money than you started with!!!\n");
    }
    else if ((current_bank_balance / initial_bank_balance) < 0.5)
    {
        printf("Your balance is not doing well lol :( \n");
    }
    printf("Number of rolls this game: %d\n", number_rolls);
    printf("Your starting bank balance was: %.2lf\n", initial_bank_balance);
    printf("Your current bank balance is: %.2lf\n", current_bank_balance);
}


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
int replay_menu(double balance)
{
    char input = '\0';
    int condition = 0;
    do {
        if (balance == 0)
        {
            printf("You have no money, goodbye!\n");
            condition = 0;
        }
        else
        {
            printf("Do you want to play again?: (y or n) \n\n");
            scanf(" %c", &input);
            if (input == 'y')
            {
                condition = 1;
            }
            else if (input == 'n')
            {
                condition = 0;
            }
            else if (input != 'y' || input != 'n')
            {
                condition = 2;
                printf("Please enter a valid option\n");
            }
        }
    } while ((condition != 1) && (condition != 0));
    return condition;
}


/*
* Function: play_game ()
* Date Created:
* Date Last Modified:
* Description: This function plays the game of craps/calls all the functions
* Input parameters: 
* Returns: 
* Preconditions:
* Postconditions:
*/
void play_game()
{
    /* Include the srand function to allow the dice rolling to be random */
    srand((unsigned int)time(NULL));

    /* Declare the variables */
    double starting_balance, current_balance, wager = 0.0;
    int dice1, dice2, sum, point, first_roll_check, win_lose, num_of_rolls = 0;

    /* Display game rules and get/check initial balance from user */
    print_game_rules();
    do
    {
        starting_balance = get_bank_balance();
    } while (check_balance_amount(starting_balance) != 1); 
    
    /* set the current balance to the starting balance*/
    current_balance = starting_balance;
    
    /* Do while loop for the gameplay */
    do
    {

        num_of_rolls = 0;
        /* Get wager from user */
        do
        {
        wager = get_wager_amount(current_balance);
        } while (check_wager_amount(wager, current_balance) != 1);

        /* Roll the dice */
        dice1 = roll_die();
        dice2 = roll_die();


        /* Track number of rolls, sum the dice, and see if they won, lost, or set their point */
        num_of_rolls++;
        sum = calculate_sum_dice(dice1, dice2);
        first_roll_check = is_win_loss_or_point(sum);

        /* If they set their point, roll again until they get it, or, else they won or lost */
        if (first_roll_check == 2)
        {
            point = sum;
            do
            {
            dice1 = roll_die();
            dice2 = roll_die();

            num_of_rolls++;
            sum = calculate_sum_dice(dice1, dice2);
            } while (is_point_loss_or_neither(sum, point) == 2);
            win_lose = is_point_loss_or_neither(sum, point);
        }
        else
        {
            win_lose = first_roll_check;
        }

        /* Update current balance and display messages accordingly */
        current_balance = adjust_bank_balance(current_balance, wager, win_lose);
        chatter_messages(num_of_rolls, win_lose, starting_balance, current_balance);

        /* Replay option or exit game loop */
    } while (replay_menu(current_balance) == 1);

   
}
  

    
