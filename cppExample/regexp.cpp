#include <regex>
#include <iostream>
int main()
{
    try {
        //if (std::regex_match ("subject", std::regex("(sub)(.*)") ))
        if (std::regex_match ("subject", std::regex(".*") ))
        std::cout << "string literal matched\n";
    } catch(std::regex_error &e)
    {
        std::cout<<e.code();
    }
    return 0;
}
