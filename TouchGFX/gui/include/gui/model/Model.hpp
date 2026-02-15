#ifndef MODEL_HPP
#define MODEL_HPP

#include <board/board.hpp>

class ModelListener;

class Model
{
public:
	BoardT board;

    Model();

    void bind(ModelListener* listener)
    {
        modelListener = listener;
    }

    void tick();
protected:
    ModelListener* modelListener;
};

#endif // MODEL_HPP
