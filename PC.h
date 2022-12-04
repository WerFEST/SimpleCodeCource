#pragma once
#ifndef _PC_H_
#define _PC_H_


class PC
{
public:
	enum PCState {
		ON,
		OFF,
		SLEEP
	};

	void SetState(PCState state) { this->state = state; }
	PCState GetState() { return state; }

private:
	PCState state;
};


#endif // !_PC_H_
