#ifndef __RENDER_TASK_H__
#define __RENDER_TASK_H__

#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"

extern QueueHandle_t render_task_queue;

#define RENDER_TASK_BOARD_ROW 20
#define RENDER_TASK_BOARD_COL 10
#define RENDER_TASK_MINO_SIZE 4
#define RENDER_TASK_MINO_ROT 4
#define RENDER_TASK_MINO_KIND 7
#define RENDER_TASK_NEXT_BLOCKS 3

typedef char Render_Board[RENDER_TASK_BOARD_ROW][RENDER_TASK_BOARD_COL];

typedef struct Mino_ {
	char type;
	char pos[2];
	char shape[RENDER_TASK_MINO_SIZE][RENDER_TASK_MINO_SIZE];
} Render_Mino;

typedef struct RenderTaskMessage_ {
	char messageID;
	Render_Board board;
	Render_Mino mino;
	int holdType;
	int nextType[RENDER_TASK_NEXT_BLOCKS];
	int score;
	int level;

} RenderTaskMessage;

#define RENDER_TASK_QUEUE_LENGTH 5
#define RENDER_TASK_QUEUE_SIZE sizeof(RenderTaskMessage)

#define RENDER_TASK_BACKGROUND 1
#define RENDER_TASK_BOARD 2
#define RENDER_TASK_TIMER 3
#define RENDER_TASK_HOLD 4
#define RENDER_TASK_NEXT_BLOCK 5
#define RENDER_TASK_SCORE 6
#define RENDER_TASK_LEVEL 7

#endif //__RENDER_TASK_H__
