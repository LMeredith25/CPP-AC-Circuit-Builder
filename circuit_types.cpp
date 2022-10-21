#include "circuit_types.h"


// Serial sub circuit class

std::complex<double> serial_sub_circuit::get_impedance()
{
    for (auto component_it=_series_components.begin(); component_it<_series_components.end(); ++component_it){
         _temp_impedance += (*component_it)->get_impedance();
    }
    _total_impedance = _temp_impedance;
    _temp_impedance=0;

    return _total_impedance;
}

void serial_sub_circuit::info(){
    std::cout << "\nCircuit Name: " << _circuit_name << "\nCircuit type: Series" << "\nTotal impedance: " << get_impedance() << "\nMagnitude of impedance: " << get_mag_impedance() << "\nPhase shift: " << get_phase_diff() << "\n\n";
}


//  Parallel sub circuit class

std::complex<double> parallel_sub_circuit::get_impedance()
{
    std::complex<double> inverse_impedance{};
    for (auto component_it=_parallel_components.begin(); component_it<_parallel_components.end(); ++component_it){
        inverse_impedance += pow((*component_it)->get_impedance(),-1); 
    } 
    _temp_impedance = pow(inverse_impedance,-1);
    _total_impedance = _temp_impedance;
    _temp_impedance=0;
    
    return _total_impedance;
} 


void parallel_sub_circuit::info(){
    std::cout << "\nCircuit Name: " << _circuit_name << "\nCircuit type: Parallel" << "\nTotal impedance: " << get_impedance() << "\nMagnitude of impedance: " << get_mag_impedance() << "\nPhase shift: " << get_phase_diff() << "\n\n";
}
