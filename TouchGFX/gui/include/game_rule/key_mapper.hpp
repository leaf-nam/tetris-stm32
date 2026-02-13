#ifndef __KEY_MAPPER_HPP__
#define __KEY_MAPPER_HPP__

#include <unordered_map>
#include "i_input_handler.hpp"
#include "util/action.hpp"

class KeyMapper
{
private:
public:
    KeyMapper() = default;
    Action map_key(int key);
};

#endif
