# 프로젝트 주제
STM32 LCD를 활용한 테트리스 게임 구현

## 환경
- pc : window11 + CubeIDE + CubeMX + TouchGFX Designer
- firmware : STM32 CortexM4 + FreeRTOS
- hardware : STM32F429Disco

## 전체 구조
 - 테트리스 게임 모듈(engine_task)
 - 렌더링 모듈(touchgfx)
 - 사운드 모듈(sound_task, sound_effect_task)
 - 타이머 모듈(timer)

## 모듈 별 역할
 - 테트리스 게임 모듈 : 실제 게임 로직 진행
 - 렌더링 모듈 : LCD 화면 그리기
 - 사운드 모듈 : 외부 요청에 따라 음악 재생
 - 타이머 모듈 : 특정 시간마다 게임 진행, 사용자 입력(조이스틱, 버튼) 확인

## IPC(태스크 간 통신 방식)
 - 타이머 모듈 	--[엔진 큐(engine_queue)]-----> 테트리스 모듈
 - 렌더링 모듈 	--[엔진 큐(engine_queue)]----> 테트리스 모듈
 - 테트리스 모듈 	--[렌더링 큐(render_queue)]--> 렌더링 모듈
 - 테트리스 모듈 	--[사운드 큐(sound_queue)]--> 사운드 모듈
 - 렌더링 모듈 	--[사운드 큐(sound_queue)]--> 사운드 모듈

## 시연 영상
https://github.com/user-attachments/assets/8b9fab29-cc02-4fc9-a9da-3363f0536e29

