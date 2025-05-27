#ifndef NO_RESTRICTION_STRATEGY_H
#define NO_RESTRICTION_STRATEGY_H

#include "TextRestrictionStrategy.h"

class NoRestrictionStrategy : public TextRestrictionStrategy
{
public:
    bool Check(std::string const& text) const override
    {
        return true;
    }
};

#endif // NO_RESTRICTION_STRATEGY_H