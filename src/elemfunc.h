#include "function.h"

typedef struct scalar {
    double num;
    bool isVar;
} scalar;

class power: public ElemFunc {
    private:
        scalar base;
        scalar exp;
    public:
        power(scalar base, scalar exp);
        double call(double x);
};
