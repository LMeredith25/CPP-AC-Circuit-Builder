#include "abstract_class.h"

void component::frequency_setter()
{
    double f{};
    while(true){
        try{
            std::cout << "\nEnter the frequency in MHz: ";
            std::cin >> f;
            if (f<=0){
                throw(f);
               }
            else if (f>0){
                break;
            }
        }
        catch(double f) {
            std::cout << "Invalid input. Frequency must be number greater than zero." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
    _frequency = f*(1E6);
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}