#include "non_ideals.h"

// Non-ideal resistor function definitions


std::complex<double> non_ideal_resistor::get_impedance()
{ 
    double alpha, real, imag, omega;
    omega = 2*M_PI*_frequency;
    alpha = 1.0/(omega*_capacitance);
    real = ((_resistance*alpha*alpha)/(_resistance*_resistance + alpha*alpha));
    imag = ((omega*_inductance) - (((_resistance*_resistance)*alpha)/(_resistance*_resistance + alpha*alpha)));
    _total_impedance = std::complex(real, imag);
    return _total_impedance;
}


void non_ideal_resistor::info()
{
    std::cout << "Non-ideal resistor:\nFrequency: " << _frequency << " Hz\nInductance: " << _inductance << " Henrys\nCapacitance: " << _capacitance << "Farads\nResistance: " << _resistance << "Ohms\nimpedance: " << get_impedance() << " Ohms\n" << "Phase shift: " << get_phase_diff() << "\n----------------------" << std::endl;
}

// Non-ideal capacitor function definitions

std::complex<double> non_ideal_capacitor::get_impedance()
{
    double imag, omega;
    omega = 2*M_PI*_frequency;
    imag = ((omega*_inductance) - (1/(omega*_capacitance)));
    _total_impedance = std::complex(_resistance, imag);
    return _total_impedance;
}

void non_ideal_capacitor::info()
{
    std::cout << "Non-ideal capacitor:\nFrequency: " << _frequency << " Hz\nInductance: " << _inductance << " Henrys\nCapacitance: " << _capacitance << "Farads\nResistance: " << _resistance << "Ohms\nimpedance: " << get_impedance() << " Ohms\n" << "Phase shift: " << get_phase_diff() << "\n----------------------" << std::endl;
}


// Non-ideal inductor function definitions

std::complex<double> non_ideal_inductor::get_impedance()
{
    std::complex<double> inverse_impedance{};
    std::complex<double> imped_1{};
    std::complex<double> imped_2{};
    double omega{};
    omega = 2*M_PI*_frequency;
    imped_1 = std::complex(_resistance, (omega*_inductance));
    imped_2 = std::complex(0.0, (-1.0/(omega*_capacitance)));
    _total_impedance = ((imped_1*imped_2)/(imped_1+imped_2));
    return _total_impedance;
}

void non_ideal_inductor::info()
{
    std::cout << "Non-ideal inductor:\nFrequency: " << _frequency << " Hz\nInductance: " << _inductance << " Henrys\nCapacitance: " << _capacitance << "Farads\nResistance: " << _resistance << "Ohms\nimpedance: " << get_impedance() << " Ohms\n" << "Phase shift: " << get_phase_diff() << "\n----------------------" << std::endl;
}


