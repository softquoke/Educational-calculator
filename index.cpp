#include <iostream>

double input_numeric(double result, int count_fail = 0)
{
    double numeric;

    if (count_fail >= 5) { exit(0); }

    std::cout << "[" << result << "] numeric> ";
    std::cin >> numeric;

    if (std::cin.fail())
    {
        std::cin.clear();
        std::cin.ignore();
        std::cout << "> exception! Write numeric pleas!" << std::endl;
        std::cout << std::endl;
        count_fail++;
        return input_numeric(result, count_fail);
    }

    return numeric;
}

std::string input_math_operation(double result)
{
    std::string math_operation;
    
    std::cout << "[" << result << "] operat.> ";
    std::cin >> math_operation;

    if (math_operation == "Q") { 
        std::cout << std::endl;
        std::cout << "// result = " << result << std::endl; 
        exit(0);
    }

    return math_operation;
}


int main()
{
    double x, y;
    double result = 0;
    double *link_result = &result;
    bool run = true;
    std::string math_operation = "";

    std::cout << std::endl;
    std::cout << "Created by softquoke´ ®" << std::endl;
    std::cout << "It's a calculator! \"C\" - is the zeroing of calculations \"Q\" - exit" << std::endl;
    std::cout << "\'operat\' - math operations. You can write to \'+\', \'-\', \'*\', \'/\' or \'C\', \'Q\'" << std::endl;
    std::cout << std::endl;

    result = input_numeric(*link_result);
    while (run)
    {
        math_operation = input_math_operation(*link_result);
        if (math_operation != "C") 
            if (math_operation == "+" || math_operation == "-" || math_operation == "*" || math_operation == "/") {
                x = input_numeric(*link_result);
                if (math_operation == "+") result += x;
                if (math_operation == "-") result -= x;
                if (math_operation == "*") result *= x;
                if (math_operation == "/") result /= x;    

                std::cout << "// result = " << result << std::endl;

            } else {
                std::cout << "this is not math operations! Examples: \'+\', \'-\', \'*\', \'/\'" << std::endl;
                std::cout << "\"C\" - is the zeroing of calculations \"Q\" - exit" << std::endl;
                std::cout << std::endl;
            }
        else { result = 0; result = input_numeric(*link_result); }
    }

    return 0;
}

