#ifndef CURSE_RESTRICTION_STRATEGY_H
#define CURSE_RESTRICTION_STRATEGY_H

#include "TextRestrictionStrategy.h"

class CurseRestrictionStrategy : public TextRestrictionStrategy
{
public:
    bool Check(std::string const& text) const override
    {
        auto npos = std::string::npos;

        if (text.find("fuck") != npos || text.find("shit") != npos)
        {
            return false;
        }
        
        return true;
    }
};

#endif // CURSE_RESTRICTION_STRATEGY_H