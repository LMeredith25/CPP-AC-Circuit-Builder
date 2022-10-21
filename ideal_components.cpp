#include "ideal_components.h"

// ----------------------------------------------------------------

// Resistor class

std::complex<double> resistor::get_impedance()
{
    _resistor_impedance = std::complex(_resistance,0.0);
    return _resistor_impedance;
}

void resistor::info()
{
    std::cout << "Resistor:\nFrequency: " << _frequency << " Hz\nResistance: " << _resistance << " Ohms\nimpedance: "
    << get_impedance() << " Ohms\n" << "Phase shift: " << get_phase_diff() << "\n----------------------" << std::endl;
}

std::vector<std::shared_ptr<component>> resistor::get_property()
{
    std::vector<std::shared_ptr<component>> resistance_vec{};
    resistance_vec.emplace_back(new resistor(_resistance));
    return resistance_vec;
}




// Capacitor class

std::complex<double> capacitor::get_impedance()
{
    _capacitor_impedance = std::complex(0.0,(-1/(2*M_PI*_frequency*_capacitance)));
    return _capacitor_impedance;
}

void capacitor::info()
{
    std::cout << "Capacitor:\nFrequency: " << _frequency << " Hz\nCapacitance: " << _capacitance << " Farads\nimpedance: "
    << get_impedance() << " Ohms\n" << "Phase shift: " << get_phase_diff() << "\n----------------------" << std::endl;
}

std::vector<std::shared_ptr<component>> capacitor::get_property()
{
    std::vector<std::shared_ptr<component>> capacitance_vec{};
    capacitance_vec.emplace_back(new capacitor(_capacitance));
    return capacitance_vec;
}




// Inductor class

std::complex<double> inductor::get_impedance()
{
    _inductor_impedance = std::complex(0.0,2*M_PI*_frequency*_inductance);
    return _inductor_impedance;
}

void inductor::info()
{
    std::cout << "Inductor:\nFrequency: " << _frequency << " Hz\nInductance: " << _inductance << " Henrys\nimpedance: "
    << get_impedance() << " Ohms\n" << "Phase shift: " << get_phase_diff() << "\n----------------------" << std::endl;
}

std::vector<std::shared_ptr<component>> inductor::get_property()
{
    std::vector<std::shared_ptr<component>> inductance_vec{};
    inductance_vec.emplace_back(new capacitor(_inductance));
    return inductance_vec;
}







