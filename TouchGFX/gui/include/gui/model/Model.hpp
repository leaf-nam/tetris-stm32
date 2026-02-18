#ifndef MODEL_HPP
#define MODEL_HPP

#include <render_task.h>

class ModelListener;

class Model
{
public:
	Render_Board board;
	int hold;
	int next[RENDER_TASK_NEXT_BLOCK_SIZE];

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
    void updateHold(RenderTaskMessage& msg);
    void updateNext(RenderTaskMessage& msg);
};

#endif // MODEL_HPP
