#ifndef CIRCUIT_TYPES_HEADER_GUARD_
#define CIRCUIT_TYPES_HEADER_GUARD_

#include "abstract_class.h"


// Series sub circuit


class serial_sub_circuit : public component
{
protected:
    std::string _circuit_name{};
    std::complex<double> _total_impedance{};
    std::complex<double> _temp_impedance{};
    std::vector<std::shared_ptr<component>> _series_components{};
public:
    ~serial_sub_circuit(){};
    serial_sub_circuit() : _total_impedance{0} {}
    serial_sub_circuit(std::vector<std::shared_ptr<component>> components, std::string name) : _series_components{components}, _total_impedance{0}, _circuit_name{name} {}
    std::vector<std::shared_ptr<component>> get_property(){return _series_components;}
    std::complex<double> get_impedance();
    std::string get_name(){return _circuit_name;}
    double get_mag_impedance(){return std::abs(get_impedance());}
    double get_phase_diff(){return std::arg(get_impedance());}
    std::string get_type(){return "series";}
    void info();
};



// Parallel sub circuit


class parallel_sub_circuit : public component
{
protected:
    std::string _circuit_name;
    std::complex<double> _total_impedance;
    std::complex<double> _temp_impedance;
    std::vector<std::shared_ptr<component>> _parallel_components;
public:
    ~parallel_sub_circuit(){};
    parallel_sub_circuit() : _total_impedance{0} {}
    parallel_sub_circuit(std::vector<std::shared_ptr<component>> components, std::string name) : _parallel_components{components}, _total_impedance{0}, _circuit_name{name} {}
    std::vector<std::shared_ptr<component>> get_property(){return _parallel_components;}
    std::complex<double> get_impedance();
    std::string get_name(){return _circuit_name;}
    double get_mag_impedance(){return std::abs(get_impedance());}
    double get_phase_diff(){return std::arg(get_impedance());}
    std::string get_type(){return "parallel";} 
    void info();
};

#endif