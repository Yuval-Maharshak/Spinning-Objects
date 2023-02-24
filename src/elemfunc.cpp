#include "elemfunc.h"

/* power implementation */

power::power (scalar base, scalar exp) {
    this->base = base;
    this->exp = exp;
}

double power::call (double x) {
    double currBase = (base.isVar)? x : base.num;
    double currExp = (exp.isVar)? x : exp.num;

    return pow(currBase, currExp);
}