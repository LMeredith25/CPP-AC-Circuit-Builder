#ifndef INTERFACE_HEADER_GUARD_
#define INTERFACE_HEADER_GUARD_

#include "abstract_class.h"
#include "ideal_components.h"
#include "circuit_types.h"
#include "non_ideals.h"

// Functions for the main menu

bool check_input(std::string input);
int generic_menu(std::string a, int int_a, int number_of_choices, std::string menu_options);
std::string component_choice(std::string r_l_c);
double get_property(double multiplier, std::string question, std::string error_message);
std::vector<std::shared_ptr<component>> create_circuit(std::vector<std::shared_ptr<component>> vec, double component_choice);
void output_components(std::vector<std::shared_ptr<component>> vec, std::string error_message);
void main_menu();

// Templated Functions 

template<class circuit_type>
circuit_type get_circuit()
{
    std::string add_or_remove{};
    int int_add_or_remove{};
    std::string components_string{"\n\n1. Add component.\n2. View circuit components.\n3. Remove last component.\n4. Complete circuit.\n\nEnter 1, 2, 3 or 4: "};
    std::string what_component{};
    double dbl_what_component{};
    std::string chosen_component{};
    std::string no_components_error{"\n\nThis circuit contains no components."};
    std::vector<std::shared_ptr<component>> circuit_type_vec{};
    std::string circuit_name{};
    circuit_type final_circ{};
    std::string add_component{"\n\nWould you like to add a:\n\n1. Resistor.\n2. Non-ideal resistor.\n3. Capacitor.\n4. None-ideal capacitor.\n5. Inductor.\n6. Non-ideal inductor.\n\nEnter a number between 1 and 6: "};

    std::cout << "Enter sub circuit name: ";
    std::getline(std::cin, circuit_name); 
    std::cout << "\n\nCircuit construction of " << circuit_name;

    do{
        int_add_or_remove = generic_menu(add_or_remove, int_add_or_remove, 4, components_string);

        if(int_add_or_remove==1)
        {
            dbl_what_component = generic_menu(what_component, dbl_what_component, 6, add_component);
            circuit_type_vec = create_circuit(circuit_type_vec, dbl_what_component);
        }
        else if (int_add_or_remove==2){
            output_components(circuit_type_vec, no_components_error);
        }
        else if (int_add_or_remove==3){ 
            if (circuit_type_vec.size()==0){
                std::cout << "\nNo components stored.\n";
            }
            else if (circuit_type_vec.size()>0){
                circuit_type_vec.pop_back();
                std::cout << "\n\nPrevious component removed.\n";
            }
        }
    }
    while (int_add_or_remove==1 || int_add_or_remove==2 || int_add_or_remove==3);
    
    if (int_add_or_remove==4){
        circuit_type circ(circuit_type_vec, circuit_name);
        std::cout << "\nCircuit Stored.\n" << std::endl;
        final_circ = circ; 
    }
    return final_circ; 
}


template<class non_ideal>
non_ideal return_non_ideal()
{    
    std::string ask_inductance{"\nWhat is the inductance in nH: "}; 
    std::string ask_capacitance{"\nWhat is the capacitance in nF: "};
    std::string ask_resistance{"\nWhat is the resistance in Ohms: "};
    std::string error_message_1{"Invalid input. Inductance must be number greater than zero."};
    std::string error_message_2{"Invalid input. Capacitance must be number greater than zero."};
    std::string error_message_3{"Invalid input. Resistance must be number greater than zero."};

    double inductance{get_property((1E-9), ask_inductance, error_message_1)};
    double capacitance{get_property((1E-9), ask_capacitance, error_message_2)};
    double resistance{get_property(1.0, ask_resistance, error_message_3)};
    
    std::cout << "\nNon ideal resistor stored.";
    non_ideal a{non_ideal(inductance, capacitance, resistance)}; 
    return a;
}

#endif






