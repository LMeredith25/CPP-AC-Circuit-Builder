#ifndef BASE_COMPONENTS_HEADER_GUARD_
#define BASE_COMPONENTS_HEADER_GUARD_

#include "abstract_class.h"


// Resistor classes
class resistor : public component
{
protected:
    double _resistance{};
    std::complex<double> _resistor_impedance{};
public:
    ~resistor(){};
    resistor(){_resistance=0; _resistor_impedance=0;}
    resistor(double r) : _resistance{r}, _resistor_impedance{0.0} {}
    std::vector<std::shared_ptr<component>> get_property();
    std::complex<double> get_impedance();
    double get_resistance(){return _resistance;}
    std::string get_name(){return "0";}
    double get_mag_impedance(){return std::abs(get_impedance());}
    double get_phase_diff(){return std::arg(get_impedance());}
    std::string get_type(){return "resistor";}
    void info();
};


// Capacitor class

class capacitor : public component
{
protected:
double _capacitance{};
std::complex<double> _capacitor_impedance{};
public:
    ~capacitor(){};
    capacitor(){_capacitance=0; _capacitor_impedance=0;}
    capacitor(double c) : _capacitance{c}, _capacitor_impedance{0} {}
    std::vector<std::shared_ptr<component>> get_property();
    double get_capacitance(){return _capacitance;}
    std::complex<double> get_impedance();
    std::string get_name(){return "0";}
    double get_mag_impedance(){return std::abs(get_impedance());}
    double get_phase_diff(){return std::arg(get_impedance());}
    std::string get_type(){return "capacitor";}
    void info();
};


// Inductor class

class inductor : public component
{
protected:
    double _inductance;
    std::complex<double> _inductor_impedance;
public:
    ~inductor(){};
    inductor(){_inductance=0; _inductor_impedance=0;}
    inductor(double l) : _inductance{l}, _inductor_impedance{0} {}
    std::vector<std::shared_ptr<component>> get_property();
    std::complex<double> get_impedance();
    double get_inductance(){return _inductance;}
    std::string get_name(){return "0";}
    double get_mag_impedance(){return std::abs(get_impedance());}
    double get_phase_diff(){return std::arg(get_impedance());}
    std::string get_type(){return "inductor";}
    void info();
};


#endif