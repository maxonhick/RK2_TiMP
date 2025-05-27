#ifndef TEXT_RESTRICTION_STRATEGY_H
#define TEXT_RESTRICTION_STRATEGY_H

#include <string>

class TextRestrictionStrategy
{
public:
    virtual ~TextRestrictionStrategy() = default;

    virtual bool Check(std::string const& text) const = 0;
};

#endif // TEXT_RESTRICTION_STRATEGY_H