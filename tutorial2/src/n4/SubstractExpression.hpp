#ifndef SUBSTRACTEXPRESSION_H
#define SUBSTRACTEXPRESSION_H

#include "Expression.hpp"

class SubstractExpression : public BinaryExpression
{
public:
    SubstractExpression(Expression *x, Expression *y);
    int solve();
};

#endif
