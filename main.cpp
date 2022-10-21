// AC Circuit Builder

#include "abstract_class.h"
#include "ideal_components.h"
#include "circuit_types.h"
#include "interface.h"

double component::_frequency = 0;

int main()
{
    std::cout << "\n-------------------\nAC Circuit Builder\n-------------------\n";
    component::frequency_setter(); 
    main_menu();
    return 0;
}


