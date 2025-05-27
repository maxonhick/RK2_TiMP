#ifndef LENGTH_RESTRICTION_STRATEGY_H
#define LENGTH_RESTRICTION_STRATEGY_H

#include "TextRestrictionStrategy.h"

class LengthRestrictionStrategy : public TextRestrictionStrategy
{
public:
    LengthRestrictionStrategy(std::size_t minLength, std::size_t maxLength)
        : minLength_(minLength), maxLength_(maxLength)
    {}

    bool Check(std::string const& text) const override
    {
        auto length = text.length();

        if (length < minLength_ || length > maxLength_)
        {
            return false;
        }

        return true;
    }

private:
    std::size_t minLength_, maxLength_;
};

#endif // LENGTH_RESTRICTION_STRATEGY_H