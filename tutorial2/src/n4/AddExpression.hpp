#ifndef ADDEXPRESSION_H
#define ADDEXPRESSION_H

#include "Expression.hpp"

class AddExpression : public BinaryExpression
{
public:
    AddExpression(Expression *x, Expression *y);
    int solve();
};

#endif
