#ifndef NON_IDEALS_COMPONENTS_HEADER_GUARD_
#define NON_IDEALS_HEADER_GUARD_

#include "abstract_class.h"


// Non ideal resistor class

class non_ideal_resistor : public component
{
protected:
    std::complex<double> _total_impedance{};
    double _inductance{};
    double _capacitance{};
    double _resistance{};
    std::vector<std::shared_ptr<component>> ni_res{0};
public:
    ~non_ideal_resistor(){};
    non_ideal_resistor(){_total_impedance=0; _resistance=0; _capacitance=0; _inductance;}
    non_ideal_resistor(double l, double c, double r) : _inductance{l}, _capacitance{c}, _resistance{r} {}
    std::complex<double> get_impedance();
    double get_mag_impedance(){return std::abs(get_impedance());}
    double get_phase_diff(){return std::arg(get_impedance());}
    std::string get_type(){return "non-ideal resistor";}
    std::string get_name(){return "0";}
    void info();
    std::vector<std::shared_ptr<component>> get_property(){return ni_res;}
    double get_inductance(){return _inductance;}
    double get_capacitance(){return _capacitance;}
    double get_resistance(){return _resistance;}
};


// Non ideal capacitor class

class non_ideal_capacitor : public component
{
protected:
    std::complex<double> _total_impedance{};
    double _inductance{};
    double _capacitance{};
    double _resistance{};
    std::vector<std::shared_ptr<component>> ni_cap{0};
public:
    ~non_ideal_capacitor(){};
    non_ideal_capacitor(){_total_impedance=0; _resistance=0; _capacitance=0; _inductance;}
    non_ideal_capacitor(double l, double c, double r) : _inductance{l}, _capacitance{c}, _resistance{r} {}
    std::complex<double> get_impedance();
    double get_mag_impedance(){return std::abs(get_impedance());}
    double get_phase_diff(){return std::arg(get_impedance());}
    std::string get_type(){return "non-ideal capacitor";}
    std::string get_name(){return "0";}
    void info();
    std::vector<std::shared_ptr<component>> get_property(){return ni_cap;}
    double get_inductance(){return _inductance;}
    double get_capacitance(){return _capacitance;}
    double get_resistance(){return _resistance;}
};


// Non ideal inductor class

class non_ideal_inductor : public component
{
protected:
    std::complex<double> _total_impedance{};
    double _inductance{};
    double _capacitance{};
    double _resistance{};
    std::vector<std::shared_ptr<component>> ni_ind{0};
public:
    ~non_ideal_inductor(){};
    non_ideal_inductor(){_total_impedance=0; _resistance=0; _capacitance=0; _inductance;}
    non_ideal_inductor(double l, double c, double r) : _inductance{l}, _capacitance{c}, _resistance{r} {}
    std::complex<double> get_impedance();
    double get_mag_impedance(){return std::abs(get_impedance());}
    double get_phase_diff(){return std::arg(get_impedance());}
    std::string get_type(){return "non-ideal inductor";}
    std::string get_name(){return "0";}
    void info();
    std::vector<std::shared_ptr<component>> get_property(){return ni_ind;}
    double get_inductance(){return _inductance;}
    double get_capacitance(){return _capacitance;}
    double get_resistance(){return _resistance;}
};


#endif

