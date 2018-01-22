#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
#include <vector>


bool On= true,Calc_on = true;
std::vector<double> history_log = {};
double n1,n2;


void setup()
{
    std::cout << "Welcome to this interactive calculator experience!\n" << "Please follow instructions to insure you use this software to its fullest extent.\n";
    std::cout << "If you see this on your screen \n\nInput:\n\n";
    std::cout << "The program is waiting for your input. If you don't know what to input, type help.\n\n";
    std::cout << "Commands:\ncalculator\nhistory\ncommands\nstop\n\n";

}

std::string str_to_lower(std::string user_input)
{
    for (char &x:user_input)
        x = tolower(x);
    return user_input;
}


std::string input()
{
    std::string user_input;
    std::cout << "Input:\n";
    std::cin >> user_input;

    return str_to_lower(user_input);
}


void debug_command(std::string const& input)
{
    std::cout <<"Unable to determine command. Type commands for available commands.\n";
    auto x = std::numeric_limits<std::streamsize>::max();
    std::cin.ignore(x,'\n');

}

void run_history()
{
    std::cout << "History of previous answers:\n\n";
    for (int x=0;x< history_log.size();x++)
    {
        std::cout << x+1 << ")" << history_log[x]<<"\n";
    }
}

void run_print_commands()
{
    std::cout << "Commands:\ncalculator\nhistory\ncommands\nstop\n\n";
}

void cal_input_logic(std::string input)
{
    if (input == "minus")
    {
        std::cin >> n1 >> n2;

        double result = n1-n2;
        history_log.push_back(result);
        std::cout << n1 << " - " << n2 << " = " << result <<"\n\n";
    }
    else if (input == "add")
    {
        std::cin >> n1 >> n2;

        double result = n1+n2;
        history_log.push_back(result);
        std::cout << n1 << " + " << n2 << " = " << result <<"\n\n";}
    else if (input == "divide")
    {
        std::cin >> n1 >> n2;

        double result = n1/n2;
        history_log.push_back(result);
        std::cout << n1 << " / " << n2 << " = " << result <<"\n\n";}
    else if(input == "multiply")
    {
        std::cin >> n1 >> n2;

        double result = n1*n2;
        history_log.push_back(result);
        std::cout << n1 << " * " << n2 << " = " << result <<"\n\n";}
    else if (input == "history")
    {
        run_history();
    }
    else if(input == "stop")
    {
        Calc_on = false;
        std::cout << "\nCalculator closed\n";
    }
    else if (input == "commands")
    {
        std::cout << "Commands:\ncalculator\nhistory\ncommands\nstop\n\n";
    }
    else
    {
        std::cout << "\nUnknown command. Type commands for available commands.\n\n";
    }
    auto x = std::numeric_limits<std::streamsize>::max();
    std::cin.ignore(x,'\n');
}

void run_calculator()
{
    std::cout <<"Calculator loaded\n";
    std::cout <<"Welcome to calculator mode.\n\nCommands:\nadd (n1) (n2)\nminus (n1) (n2)\ndivide (n1) (n2)\nmultiply (n1) (n2)\nstop\nhistory\n";


    while (Calc_on)
    {
        cal_input_logic(input());

    }
}

int input_logic(std::string const& input)
{

     if (input == "calculator")
    {
      run_calculator();
    } else if (input == "history")
    {
        run_history();
    } else if (input == "commands")
    {
        run_print_commands();
    } else if (input == "stop")
    {
        On = false;

    } else
        debug_command(input);


}


void run_command(int const& input_code)
{
    if (input_code == 1)
    {}

}







int main()
{
    int input_logic_code;
    setup();
    while (On)
    {
        input_logic(input());



    };


    return 0;
}