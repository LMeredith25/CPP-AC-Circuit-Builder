#ifndef CLASSES_HEADER_GUARD_
#define CLASSES_HEADER_GUARD_
#include<iostream>
#include<complex.h>
#include<vector>
#include<memory>
#include<valarray>
#include<algorithm>
#include<sstream>
#include<string>
#include<locale>
#include<limits>



// Abstract class for component.


class component
{
public:
    static double _frequency;
public:
    virtual ~component(){};
    virtual std::complex<double> get_impedance()=0;
    virtual std::vector<std::shared_ptr<component>> get_property()=0;
    virtual double get_mag_impedance()=0;
    virtual std::string get_name()=0;
    virtual double get_phase_diff()=0;
    virtual std::string get_type()=0;
    virtual void info()=0;
    static void frequency_setter();
};


#endif
