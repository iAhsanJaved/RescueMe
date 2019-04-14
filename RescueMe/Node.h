#pragma once
using namespace System;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Net;
using namespace System::IO;

ref class Node
{
private:
	String^ APIEndPoint = "http://127.0.0.1:3333/api/v1/nodes/verify";
public:
	String^ id;
	String^ key;
	

	Node();
	Node(String^ id, String^ key);
	bool verify();
};

