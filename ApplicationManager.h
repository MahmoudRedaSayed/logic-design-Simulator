#ifndef APPLICATION_MANAGER_H
#define APPLICATION_MANAGER_H

#include "Defs.h"
#include "GUI\Output.h"
#include "GUI\Input.h"
#include "Actions\Action.h"
#include "Components\Component.h"
#include"Actions\Save.h"
//Main class that manages everything in the application.
class ApplicationManager
{

	enum { MaxCompCount = 200 };	//Max no of Components	

private:
	int CompCount;		//Actual number of Components
	int RemCompCount;
	Component* CompList[MaxCompCount];	//List of all Components (Array of pointers)
	Component* RemComp[MaxCompCount];   //List of recently removed Components
	Output* OutputInterface; //pointer to the Output Clase Interface
	Input* InputInterface; //pointer to the Input Clase Interface
	Save* the_saver;
	Component* Selected_Comp;
public:


public:	
	ApplicationManager(); //constructor

	//Reads the required action from the user and returns the corresponding action type
	ActionType GetUserAction();
	
	//Creates an action and executes it
	void ExecuteAction(ActionType);
	
	void UpdateInterface();	//Redraws all the drawing window

	//Gets a pointer to Input / Output Object
	Output* GetOutput();
	Input* GetInput();

	//Adds a new component to the list of components
	void AddComponent(Component* pComp);
	void GetComponentList(Component** &, int&);
	
	void DeleteComponent(Component* pComp);
	void CheckWhichComponent(int, int, Component*&);
	void SetSelectedComponent(Component*);
	void DeleteAllConnnectionsWithThisInputPin(InputPin* P);
	void DeleteAllConnnectionsWithThisOutputPin(OutputPin* P);
	void Undo();
	void Redo();
	int get_compcount();
	

	//destructor
	~ApplicationManager();
};

#endif