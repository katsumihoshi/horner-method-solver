# Horner's Method Solver

## Python Code Explained

1. The ***evaluate_polynomial*** function takes a list of polynomial coefficients and a value of x. It calculates the intermediate results of evaluating the polynomial using the Horner's method. It iterates over the coefficients and updates the result variable by multiplying it with x and adding the next coefficient. The intermediate results are stored in a list and returned at the end.

2. The ***get_polynomial*** function prompts the user to enter the coefficients of the polynomial as a space-separated string. It then splits the string into a list of coefficient strings. Each coefficient string is converted to a float value and added to a new list using a list comprehension. The function returns the list of polynomial coefficients.

3. The ***print_intermediate_results*** function takes a list of intermediate results and prints the non-zero results. It filters out the intermediate results that are equal to zero using a list comprehension and stores them in a new list. If there are any non-zero results, it prints them separated by commas.

4. The ***main*** function is where the main logic of the program resides. It starts by getting the polynomial coefficients from the user using the get_polynomial function.

5. Inside a while loop, the program prompts the user to enter a value for x. It then calls the ***evaluate_polynomial*** function with the polynomial coefficients and x to calculate the intermediate results. The intermediate results are printed using the ***print_intermediate_results*** function.

6. The final result is obtained from the last element of the intermediate results list. If the final result is an integer, it is converted to an integer using the ***is_integer()*** method and the ***int()*** function.

7. The program asks the user for the next action: continue with the current problem, start a new calculation, or quit. The user's choice is processed using a series of if statements. If the user chooses to start a new calculation, the polynomial coefficients are obtained again using the ***get_polynomial*** function. If the user chooses to continue with the current problem, the intermediate results are used as the new polynomial coefficients by excluding the last element. If the user chooses to quit, the program breaks out of the loop.

Overall, the program allows the user to enter the coefficients of a polynomial, evaluate the polynomial for different values of x, and perform multiple calculations or start new calculations based on user input. Intermediate results are displayed, and the final result is printed for each evaluation of the polynomial.

## C++ Code Explained

The program starts by including the necessary C++ libraries: iostream, vector, sstream, and limits. Then, it defines three functions:

1. ***evaluate_polynomial***: This function takes a vector of polynomial coefficients and a value of x. It evaluates the polynomial using Horner's method and returns a vector of intermediate results.

2. ***get_polynomial***: This function prompts the user to enter the coefficients of a polynomial and reads them from the input. It returns a vector containing the polynomial coefficients.

3. ***print_intermediate_results***: This function takes a vector of intermediate results and prints them to the console, skipping any zero values.

4. In the main function, the program first gets the polynomial coefficients from the user using ***get_polynomial***. Then, it enters a while loop, which continues until the user chooses to quit. Inside the loop, the program prompts the user to enter a value for x and reads it from the input. It then calls ***evaluate_polynomial*** to obtain the intermediate results of the polynomial evaluation. The intermediate results are printed using ***print_intermediate_results***. The final result is extracted from the intermediate results and stored in ***final_result***. If the final result is an integer (i.e., it has no fractional part), it is cast to an integer using ***static_cast***. The program prompts the user to choose one of three options: continue with the current problem, start a new calculation, or quit. Based on the user's choice, the program either retrieves a new polynomial, continues with the current problem by removing the last coefficient, or breaks out of the loop to exit the program.
