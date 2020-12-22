#include "Switch.h"

Switch::Switch(const GraphicsInfo& r_GfxInfo) :SrcPin(5)
{

	m_GfxInfo.x1 = r_GfxInfo.x1;
	m_GfxInfo.y1 = r_GfxInfo.y1;
	m_GfxInfo.x2 = r_GfxInfo.x2;
	m_GfxInfo.y2 = r_GfxInfo.y2;
}


void Switch::Operate()
{
	//caclulate the output status as the ANDing of the two input pins

	//Add you code here
	//Click is Operate
	if (SrcPin.getStatus() == LOW)
		SrcPin.setStatus(HIGH);
	else
		SrcPin.setStatus(LOW);

	return;
}


// Function Draw
// Draws 2-input AND gate
void Switch::Draw(Output* pOut)
{
	//Call output class and pass gate drawing info to it.
	if (SrcPin.getStatus() == LOW)
		pOut->DrawSWITCHOFF(m_GfxInfo);
	if (SrcPin.getStatus() == HIGH)
		pOut->DrawSWITCHON(m_GfxInfo);
}

//returns status of outputpin
int Switch::GetOutPinStatus()
{
	return SrcPin.getStatus();
}


//returns status of Inputpin #n
int Switch::GetInputPinStatus()
{
	return -1;	//n starts from 1 but array index starts from 0.
}

//Set status of an input pin ot HIGH or LOW
void Switch::setInputPinStatus(STATUS s)
{
	return;
}
