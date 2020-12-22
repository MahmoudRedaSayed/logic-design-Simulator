#pragma once
#include "component.h"
#include "OutputPin.h"
class Switch :
    public Component
{
private:
	OutputPin SrcPin;	//The Source pin of this connection (an output pin of certain Component)
public:
	Switch(const GraphicsInfo& r_GfxInfo);
	virtual void Operate();	//Calculates the output according to the inputs
	virtual void Draw(Output* pOut);//for each component to Draw itself


	virtual int GetOutPinStatus();	//returns status of outputpin if LED, return -1
	virtual int GetInputPinStatus();	//returns status of Inputpin # n if SWITCH, return -1

	virtual void setInputPinStatus( STATUS s=LOW);	//set status of Inputpin # n, to be used by connection class.

};

