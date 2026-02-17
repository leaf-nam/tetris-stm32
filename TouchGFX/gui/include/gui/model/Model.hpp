#ifndef MODEL_HPP
#define MODEL_HPP

#include <render_task.h>

class ModelListener;

class Model
{
public:
	Render_Board board;

    Model();

    void bind(ModelListener* listener)
    {
        modelListener = listener;
    }

    void tick();

protected:
    ModelListener* modelListener;

private:
    void updateBoard(RenderTaskMessage& msg);
};

#endif // MODEL_HPP
