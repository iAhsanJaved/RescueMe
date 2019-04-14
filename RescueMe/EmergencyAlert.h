#pragma once
#include "Node.h"
using namespace System;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Net;
using namespace System::IO;
using namespace System::Text;

ref class EmergencyAlert
{
private:
	String^ APIEndPoint = "http://127.0.0.1:3333/api/v1/emergencyAlerts/store";
public:
	Node^ node;
	int emergencyTypeID;
	String^ image;
	EmergencyAlert();
	EmergencyAlert(Node^ node, int emergencyTypeID, String^ image);
	bool postAlert();
};

