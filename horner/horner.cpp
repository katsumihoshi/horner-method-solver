#include <iostream>
#include <vector>
#include <sstream>
#include <limits> // Added limits header

// Function to evaluate a polynomial given its coefficients and a value of x
std::vector<double> evaluate_polynomial(const std::vector<double>& coefficients, double x) {
    int n = coefficients.size();
    double result = coefficients[0];

    std::vector<double> intermediate_results;
    intermediate_results.push_back(result);

    // Evaluate the polynomial using Horner's method
    for (int i = 1; i < n; i++) {
        result = result * x + coefficients[i];
        intermediate_results.push_back(result);
    }

    // Return the intermediate results of polynomial evaluation
    return intermediate_results;
}

// Function to get the coefficients of a polynomial from user input
std::vector<double> get_polynomial() {
    std::string input;
    std::cout << "Enter the coefficients of the polynomial (separated by spaces): ";
    std::getline(std::cin, input);

    std::istringstream iss(input);
    std::vector<double> polynomial;
    double coefficient;

    // Parse the user input and store coefficients in a vector
    while (iss >> coefficient) {
        polynomial.push_back(coefficient);
    }

    // Return the polynomial coefficients
    return polynomial;
}

// Function to print intermediate results of polynomial evaluation
void print_intermediate_results(const std::vector<double>& intermediate_results) {
    std::vector<double> filtered_results;
    for (double result : intermediate_results) {
        if (result != 0) {
            filtered_results.push_back(result);
        }
    }

    if (!filtered_results.empty()) {
        std::cout << "Intermediate results: ";
        for (size_t i = 0; i < filtered_results.size(); i++) {
            std::cout << filtered_results[i];
            if (i != filtered_results.size() - 1) {
                std::cout << ", ";
            }
        }
        std::cout << std::endl;
    }
}

int main() {

    // Get the polynomial coefficients from the user
    std::vector<double> polynomial = get_polynomial();

    while (true) {
        double x;
        std::cout << "Enter the value of x: ";
        std::cin >> x;

        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        // Evaluate the polynomial
        std::vector<double> intermediate_results = evaluate_polynomial(polynomial, x);

        // Print intermediate results of polynomial evaluation
        print_intermediate_results(intermediate_results);

        // Get the final result of polynomial evaluation
        double final_result = intermediate_results.back();

        // Check if the final result is an integer and cast it if true
        if (final_result == static_cast<int>(final_result)) {
            final_result = static_cast<int>(final_result);
        }

        std::cout << "The result of the polynomial evaluation is: " << final_result << std::endl;

        std::string choice;
        std::cout << "Do you want to continue with the current problem (C), start a new calculation (N), or quit (Q)? ";
        std::getline(std::cin, choice);

        if (choice == "n" || choice == "N") {
            polynomial = get_polynomial(); // Get new polynomial coefficients for a new calculation
        }
        else if (choice == "c" || choice == "C") {
            polynomial = std::vector<double>(intermediate_results.begin(), intermediate_results.end() - 1); // Continue with the current problem by removing the last coefficient
        }
        else if (choice == "q" || choice == "Q") {
            break; // Exit the while loop and end the program
        }
    }

    std::cout << "Goodbye!" << std::endl;

    return 0; // Exit the program
}
