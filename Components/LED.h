#include"Component.h"
#include "InputPin.h"
class LED :public Component
{
	InputPin the_output;  //the output pin from the gates 
	Output* the_status; //that make me able to use the drawing functions 
public:
	LED(const GraphicsInfo& r_GfxInfo);
	void Operate();
	int GetInputPinStatus(int n);
	void setInputPinStatus(int n, STATUS s);
	void Draw(Output* pOut);
	int GetOutPinStatus();
	virtual int getm_Inputs();
	InputPin* getinputpin(int n);
};