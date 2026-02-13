#ifndef __ENGINE_HPP__
#define __ENGINE_HPP__

#include "i_input_handler.hpp"
#include "i_renderer.hpp"

#include "board/board.hpp"
#include "game_rule/key_mapper.hpp"
#include "game_rule/rule_zen.hpp"
#include "tetromino/tetromino_queue.hpp"
#include "util/action.hpp"

class Engine {
private:
	IInputHandler* input_handler;
	IRenderer* renderer;
    GameRule* rule;

    TetrominoQueue& tetromino_queue;
    Board& board;
    KeyMapper& key_mapper;

    int curr_mino = 0;
	int score = 0, new_score;
	int action;
	bool is_level_up = false;
	int key;
	int index = 0;
	int tick = 0;

public:
    /**
     * @brief 게임 수행 전 필드 초기화(생성자)
     * @param 플랫폼 종속 인터페이스
     * @return 게임엔진
     */
	Engine(IInputHandler* input_handler, IRenderer* renderer, Board& board, GameRule* rule, TetrominoQueue& tetromino_queue, KeyMapper& key_mapper);

    /**
     * @brief 루프 실행
     */
    void handle_loop();

    /**
     * @brief 타이머 틱 실행
     */
    void handle_tick();

    /**
     * @brief 입력 받아서 실행
     */
    void handle_input(int);

    /**
     * @brief 게임 메인루프 정지
     */
    void stop();

    /**
     * @brief 게임 종료 시 메모리 및 기타 자원정리
     * @return 게임 비정상 종료 시 에러코드 반환
     */
    int finish();

    /**
     * @brief 게임 엔진 및 멤버 변수 정리(소멸자)
     */
    ~Engine();
};

#endif //__ENGINE_HPP__
