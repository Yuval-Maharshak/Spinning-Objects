#include "head.h"

class ElemFunc {
    public:
        double call(double x);
};

class Function {
    
};

enum binaryOperation {
    plus,
    times,
    compose
};

typedef union nodeVal {
    binaryOperation op;
    ElemFunc *func;
} nodeVal;

class funcNode {
    private:
        nodeVal value;
        funcNode *left;
        funcNode *right;
    public:
        void setVal(nodeVal v);
        nodeVal getVal();
        void setLeft(funcNode * l);
        funcNode * getLeft();
        void setRight(funcNode * r);
        funcNode * getRight();
};