#include "interface.h"


bool check_input(std::string input) 
{
    bool is_valid = true;
    for (int i{}; i<input.length(); i++) {

        if (!isdigit(input[i]))
        {
            is_valid = false;
            break;
        }
}

std::string series_or_parallel(std::string s_or_p)
{
    std::string new_s_or_p;

    while(true){
        std::cout <<  "\nIs this sub circuit serial or parallel. Type s for series or p for parallel: ";
        std::getline(std::cin, s_or_p);
        if(s_or_p.size()==1){
            if(s_or_p=='s' || s_or_p=='p'){
                break;
            }
        }
    }
    new_s_or_p = s_or_p;
    return new_s_or_p;
}

// Generic Menu for numbered menus

int generic_menu(std::string a, int int_a, int number_of_choices, std::string menu_options)
{
    while(true){
        std::cout << menu_options;
        std::getline(std::cin, a);
        if (check_input(a)){
            int_a = std::stoi(a);
            if (int_a>=1 && int_a<=number_of_choices){
                break;
            }
        }
        std::cout << "\n\nIncorrect input. Press enter.\n" << std::endl;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    return int_a;
}

std::string component_choice(std::string r_l_c)
{
    std::string choice{};
    while(true){
        std::cout << "\n\nSelect a component to add:\1.Resistor.\n2Non-ideal resistor.\nCapacitor.\nNone-ideal capacitor.\nInductor.\nNon-ideal inductor.\n";
        std::getline(std::cin, r_l_c);
        if (check_input(r_l_c)){
            if (r_l_c=="R" || r_l_c=="C" || r_l_c=="L" || r_l_c=="NIR"){
                break;
            }
        }
        std::cout << "Please only enter R, C, L or NIR. Press enter to continue.\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    choice = r_l_c;
    return choice;
}


double get_property(double multiplier, std::string question, std::string error_message)
{
    double temp_value{};
    double double_value{};
    while(true){
        try{
            std::cout << question;
            std::cin >> temp_value;
 
            if (temp_value<=0){
                throw(temp_value);
            }
            else if (temp_value>=0){         
                break;
            }
        }
        catch(double) {
            std::cout << error_message << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
    double_value = temp_value*multiplier;std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return double_value;
}

// Return circuit vector of components


std::vector<std::shared_ptr<component>> create_circuit(std::vector<std::shared_ptr<component>> vec, double component_choice)
{
    std::vector<std::shared_ptr<component>> final_vector{};
    if (component_choice==1){
        std::string ask_resistance{"\nWhat is the resistance in Ohms: "};
        std::string error_message{"Invalid input. Resistance must be number greater than zero."};
        double resistance{get_property(1.0, ask_resistance, error_message)};
        std::cout << "Resistor stored.";
        vec.emplace_back(new resistor(resistance)); 
    }
    else if (component_choice==2){
        non_ideal_resistor r{}; 
        r = return_non_ideal<non_ideal_resistor>();
        vec.emplace_back(new non_ideal_resistor(r.get_inductance(), r.get_capacitance(), r.get_resistance()));
    }
    else if (component_choice==3){
        std::string ask_capacitance{"\nWhat is the capacitance in nF: "};
        std::string error_message{"Invalid input. Capacitance must be number greater than zero."};
        double capacitance{get_property((1E-9), ask_capacitance, error_message)};
        std::cout << "Capacitor stored.";
        vec.emplace_back(new capacitor(capacitance)); 
    }
    else if (component_choice==4){
        non_ideal_capacitor c{}; 
        c = return_non_ideal<non_ideal_capacitor>();
        vec.emplace_back(new non_ideal_capacitor(c.get_inductance(), c.get_capacitance(), c.get_resistance()));
        }
    else if (component_choice==5){
        std::string ask_inductance{"\nWhat is the inductance in nH: "};
        std::string error_message{"Invalid input. Inductance must be number greater than zero."};
        double inductance{get_property((1E-9), ask_inductance, error_message)};
        std::cout << "Inductor stored.";
        vec.emplace_back(new inductor(inductance)); 
    }
    else if (component_choice==6){
        non_ideal_inductor l{}; 
        l = return_non_ideal<non_ideal_inductor>();
        vec.emplace_back(new non_ideal_inductor(l.get_inductance(), l.get_capacitance(), l.get_resistance()));
    }
    final_vector = vec;
    return final_vector;
}

void output_components(std::vector<std::shared_ptr<component>> vec, std::string error_message)
{
    if (vec.size()==0)
    {
        std::cout << error_message << std::endl;
    } 
    else if (vec.size()>=1)
    {
        std::cout << "\n\nContents:\n----------------------\n";
        for (auto comp_it=vec.begin(); comp_it<vec.end(); ++comp_it){
            (*comp_it)->info();
        }
    }
}

void remove_component(std::vector<std::shared_ptr<component>> vec)
{
    if (vec.size()==0){
        std::cout << "\nNo components stored.\n";
    }
    else if (vec.size()>0){
        vec.pop_back();
        std::cout << "\n\nPrevious component removed.\n";
    }
}


// Returns the circuit vector of the added circuit

std::vector<std::shared_ptr<component>> get_added_circuit_vector(std::vector<std::shared_ptr<component>> vec, std::string name)
{
    std::vector<std::shared_ptr<component>> adding_vector{};

    if (vec.size()==0){
        std::cout << "\nNo circuits have yet been stored.\n";
    }

    else if (vec.size()>0){

        std::cout << "\n\nHere are the stored circuits:\n\n";
        
        for (auto vec_it=vec.begin(); vec_it<vec.end(); ++vec_it){
            std::cout << "Name: " << (*vec_it)->get_name() << std::endl;
        } 

        std::string circuit_one{};
        std::string circuit_two{};
        std::string null_name_one{"null"};
        std::string null_name_two{"null"};
        std::string how_to_add{};
        std::cout << "\nEnter the name of the first circuit you would like to add: ";
        std::getline(std::cin, circuit_one);
        std::cout << "\nEnter the name of the second circuit you would like to add: ";
        std::getline(std::cin, circuit_two);

        for (auto vec_it=vec.begin(); vec_it<vec.end(); ++vec_it){
            if ((*vec_it)->get_name() == circuit_one){
                if ((*vec_it)->get_type() == "series"){
                    adding_vector.emplace_back(new serial_sub_circuit((*vec_it)->get_property(), null_name_one));
                }
                else if ((*vec_it)->get_type() == "parallel"){
                    adding_vector.emplace_back(new parallel_sub_circuit((*vec_it)->get_property(), null_name_two));
                }
            }

            if ((*vec_it)->get_name() == circuit_two){
                if ((*vec_it)->get_type() == "series"){
                    adding_vector.emplace_back(new serial_sub_circuit((*vec_it)->get_property(), null_name_one));
                }
                else if ((*vec_it)->get_type() == "parallel"){
                    adding_vector.emplace_back(new parallel_sub_circuit((*vec_it)->get_property(), null_name_one));
                }
            }
        }
    }
    return adding_vector;
}

// Main Menu function

void main_menu()
{
    std::string answer{};
    int int_answer{};
    std::string serial_or_parallel{};
    std::vector<std::shared_ptr<component>> circuits_vector{};
    std::string master_string{"\n---------\nMain Menu\n---------\n1. Create circuit.\n2. Stored circuits.\n3. Add circuits.\n4. Exit program.\n\nEnter 1, 2, 3 or 4: "};
    std::string no_circuits_error{"\n\nNo circuits have yet been created."};

    do{
        int_answer = generic_menu(answer, int_answer, 4, master_string);
        if (int_answer==1){
            serial_or_parallel = series_or_parallel(serial_or_parallel);
            if (serial_or_parallel=="s"){
                serial_sub_circuit s{};
                s = get_circuit<serial_sub_circuit>();
                circuits_vector.emplace_back(new serial_sub_circuit(s.get_property(), s.get_name()));
            }
            else if (serial_or_parallel=="p"){
                parallel_sub_circuit p{};
                p = get_circuit<parallel_sub_circuit>();
                circuits_vector.emplace_back(new parallel_sub_circuit(p.get_property(), p.get_name()));
            }
        }
        else if (int_answer==2){
            output_components(circuits_vector, no_circuits_error);
        }
        else if (int_answer==3){
            std::string how_to_add{};
            std::string added_circuit_name{};
            std::vector<std::shared_ptr<component>> added_circuit_vector{};
            std::cout << "\nEnter the name of the resultant circuit: ";
            std::getline(std::cin, added_circuit_name);
            added_circuit_vector = get_added_circuit_vector(circuits_vector, added_circuit_name);
            while(true){
                std::cout << "\n\nWould you like to add these circuits it series or parallel? Type s for series or p for parallel: ";
                std::getline(std::cin, how_to_add);
                if (how_to_add.size()==1){
                    if (how_to_add=="s" || how_to_add=="p"){
                        break;
                    }
                }
                std::cout << "\nPlease enter only s or p. Press enter to continue.\n";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
            if (how_to_add == "s"){
                circuits_vector.emplace_back(new serial_sub_circuit(added_circuit_vector, added_circuit_name));
                std::cout << "\nCircuits added and have been stored in 'stored circuits'.\n";
            }
            else if (how_to_add == "p"){
                circuits_vector.emplace_back(new parallel_sub_circuit(added_circuit_vector, added_circuit_name));
                std::cout << "\nCircuits added and have been stored in 'stored circuits'.\n";
            }
        }
    }
    while(int_answer==1 || int_answer==2 || int_answer==3);
        
    if (int_answer==4){
        std::cout << "\n\nEnd of program.\n\n";
    }
}

