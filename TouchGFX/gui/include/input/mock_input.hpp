#ifndef __MOCK_INPUT_HPP__
#define __MOCK_INPUT_HPP__

#include "i_input_handler.hpp"

class MockInput: public IInputHandler
{
    int scan();
};

#endif //__MOCK_INPUT_HPP__
