#include "Switch.h"
#include<fstream>
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
void Switch::Draw(Output* pOut,bool selected)
{
	//Call output class and pass gate drawing info to it.
	if (SrcPin.getStatus() == LOW)
		pOut->DrawSWITCHOFF(m_GfxInfo, selected);
	if (SrcPin.getStatus() == HIGH)
		pOut->DrawSWITCHON(m_GfxInfo, selected);
}

void Switch::save()
{
	double Cx, Cy;
	Cx = (m_GfxInfo.x1 + m_GfxInfo.x2) / 2.0;
	Cy = (m_GfxInfo.y1 + m_GfxInfo.y2) / 2.0;
	ofstream the_added_component;
	the_added_component.open("file format.txt",ios::app);
	the_added_component << endl << "switch"  << "     " << id << "     " << get_mlabel() << "     " << Cx << "     " << Cy << "     " << endl;
	the_added_component.close();
}

//returns status of outputpin
int Switch::GetOutPinStatus()
{
	return SrcPin.getStatus();
}


//returns status of Inputpin #n
int Switch::GetInputPinStatus(int n )
{
	return -1;	//n starts from 1 but array index starts from 0.
}

//Set status of an input pin ot HIGH or LOW
void Switch::setInputPinStatus(int n, STATUS s)
{
	return;
}
int Switch::getm_Inputs()
{
	return  0;
}
OutputPin* Switch::getoutputpin()
{
	return (&SrcPin);
}