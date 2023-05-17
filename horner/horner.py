def evaluate_polynomial(coefficients, x):

    # Calculate the number of coefficients in the polynomial
    n = len(coefficients)

    # Initialize the result with the first coefficient
    result = coefficients[0]
    
    # Create a list to store intermediate results
    intermediate_results = [result]
    
    # Iterate over the remaining coefficients and calculate the intermediate results
    for i in range(1, n):
        result = result * x + coefficients[i]
        intermediate_results.append(result)
    
    # Return the list of intermediate results
    return intermediate_results

def get_polynomial():

    # Prompt the user to enter the coefficients of the polynomial
    coefficients = input("Enter the coefficients of the polynomial (separated by spaces): ")

    # Split the input string into a list of coefficient strings and convert the coefficient strings to float values and store them in a list
    polynomial = [float(coefficient) for coefficient in coefficients.split()]
    
    # Return the list of polynomial coefficients
    return polynomial

def print_intermediate_results(intermediate_results):

    # Filter out intermediate results that are zero
    filtered_results = [result for result in intermediate_results if result != 0]
    
    # Check if there are any non-zero intermediate results
    if filtered_results:
        print("Intermediate results:", end=" ")
        
        # Print the non-zero intermediate results separated by commas
        print(*filtered_results, sep=", ")

def main():

    # Get the polynomial coefficients from the user
    polynomial = get_polynomial()
    
    while True:

        # Prompt the user to enter a value for x
        x = float(input("Enter the value of x: "))
        
        # Evaluate the polynomial for the given x and get the intermediate results
        intermediate_results = evaluate_polynomial(polynomial, x)
        
        # Print the non-zero intermediate results
        print_intermediate_results(intermediate_results)
        
        # Get the final result from the intermediate results
        final_result = intermediate_results[-1]

        # Check if the final result is an integer and convert it if necessary
        if final_result.is_integer():
            final_result = int(final_result)
        
        # Print the final result of the polynomial evaluation
        print(f"The result of the polynomial evaluation is: {final_result}")
        
        # Prompt the user for the next action: continue, start a new calculation, or quit
        choice = input("Do you want to continue with the current problem (C), start a new calculation (N), or quit (Q)? ")
        
        # Process the user's choice

        # Start a new calculation by getting new polynomial coefficients
        if choice.lower() == "n":
            polynomial = get_polynomial()

        # Continue with the current problem by using the intermediate results as the new polynomial coefficients
        elif choice.lower() == "c":
            polynomial = intermediate_results[:-1]

        # Quit the program
        elif choice.lower() == "q":
            break
    
    print("Goodbye!")

# DO NOT DELETE THIS CODE OTHERWISE THE ENTIRE PROGRAM BREAKS

if __name__ == "__main__":
    main()
