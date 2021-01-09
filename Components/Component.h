#ifndef _COMPONENT_H
#define _COMPONENT_H

#include "..\Defs.h"
#include "..\GUI\Output.h"
// enum TheNameOfTheComponents
//{
//	AND2=1 ,
//	AND3=2 ,
//	BUFFER=3 ,
//	LED=4 ,
//	NAND2=5,
//	NOR2=6,
//	NOR3=7,
//	NOT=8,
//	OR2=9,
//	Switch=10,
//	XNOR2=11,
//	XOR2=12,
//	XOR3=13
//};
//Base class for classes Gate, Switch, and LED.
class Component
{
private:
	string m_Label;
protected:
	GraphicsInfo m_GfxInfo;	//The parameters required to draw a component
	 int id;
	 static int Countofcomp;
public:
	
	Component(const GraphicsInfo &r_GfxInfo);
	virtual void Operate() = 0;	//Calculates the output according to the inputs
	virtual void Draw(Output* pOut,bool selected=0) ;	//for each component to Draw itself
	void SetId(int);
	int GetId();
	int getid();
	virtual int GetOutPinStatus()=0;	//returns status of outputpin if LED, return -1
	virtual int GetInputPinStatus(int n)=0;	//returns status of Inputpin # n if SWITCH, return -1

	virtual void setInputPinStatus(int n, STATUS s)=0;	//set status of Inputpin # n, to be used by connection class.
	virtual int getm_Inputs()=0;
	virtual void save()=0 ;
	virtual void load(int x, int y, string label, int u)=0;
	GraphicsInfo GetLocation();
	void set_Location(GraphicsInfo the_new);
	void Setmlabel(string thereadingname);
	void SetLabel(string);
	void SetLocation(GraphicsInfo);
	string get_mlabel();
	bool IsInsideMe(int, int);
	Component();	
	
	//Destructor must be virtual
	virtual ~Component();
};

#endif
