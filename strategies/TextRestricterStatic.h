#include <memory>
#include <iostream>
#include "TextRestrictionStrategy.h"

template <typename TextRestrictionStrategy>
class TextRestricter
{
public:
    explicit TextRestricter(TextRestrictionStrategy&& strategy)
        : strategy_(std::move(strategy))
    {}

    void PrintText(std::string const& text) const
    {
        if (strategy_.Check(text))
        {
            std::cout << text << std::endl;
        }
        else
        {
            std::cout << "** Given text was restricted. **" << std::endl;
        }
    }

    bool ConcatText(std::string const& text_1,
                    std::string const& text_2,
                    std::string& concatedText) const
    {
        concatedText = text_1 + text_2;

        if (strategy_.Check(concatedText))
        {
            return true;
        }
        else
        {
            concatedText.clear();
            return false;
        }
    }

private:
    TextRestrictionStrategy strategy_;
};