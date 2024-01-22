/*
 * button.h
 *
 *  Created on: Jan 16, 2024
 *      Author: Lenovo
 */

#ifndef INC_BUTTON_H_
#define INC_BUTTON_H_

// states for state machine
typedef enum {
	IDLE = 0, DEBOUNCE, PRESSED, REPEAT
} BUTTON_STATE;

// struct for button
typedef struct {
	BUTTON_STATE state;
	GPIO_TypeDef* GpioPort;
	uint16_t GpioPin;
	uint32_t TimerDeboune;
	uint32_t lastTick;
	uint32_t TimerLongPress;
	uint32_t TimerRepeat;
	void(*ButtonPressed)(void);
	void(*ButtonLongPress)(void);
	void(*ButtonRepeat)(void);
} TButton;

// public functions
void ButtonSetDebounceTimer(TButton *Key, uint32_t Miliseconds);
void ButtonSetTimerLongPress(TButton *Key, uint32_t Miliseconds);
void ButtonSetTimerRepeat(TButton *Key, uint32_t Miliseconds);
void ButtonInitKey(TButton *Key, GPIO_TypeDef *GpioPort, uint16_t GpioPin,
		uint32_t TimerDeboune, uint32_t TimerLongPress, uint32_t TimerRepeat);
void ButtonTask(TButton *Key);
void ButtonRegisterPressCallback(TButton* Key, void (*Callback));
void ButtonRegisterLongPressCallback(TButton *Key, void *Callback);
void ButtonRegisterRepeatCallback(TButton *Key, void *Callback);



#endif /* INC_BUTTON_H_ */
