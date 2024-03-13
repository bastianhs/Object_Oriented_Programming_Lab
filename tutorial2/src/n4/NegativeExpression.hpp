#ifndef NEGATIVEEXPRESSION_H
#define NEGATIVEEXPRESSION_H

#include "Expression.hpp"

class NegativeExpression : public UnaryExpression
{
public:
    NegativeExpression(Expression *x);
    int solve();
};

#endif
