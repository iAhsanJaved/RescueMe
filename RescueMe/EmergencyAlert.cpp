#include "EmergencyAlert.h"



EmergencyAlert::EmergencyAlert()
{
	this->node = gcnew Node();
	this->emergencyTypeID = 0;
	this->image = "";
}

EmergencyAlert::EmergencyAlert(Node ^ node, int emergencyTypeID, String ^ image)
{
	this->node = node;
	this->emergencyTypeID = emergencyTypeID;
	this->image = image;
}

bool EmergencyAlert::postAlert()
{
	try
	{
		// Data
		String ^data = "{\"node_id\":\"" + this->node->id 
			+ "\",\"emergency_type_id\":\"" + this->emergencyTypeID 
			+ "\",\"image\":\"" + this->image + "\"}";
		
		array<Byte> ^buffer = Encoding::UTF8->GetBytes(data);

		// Create HTTP Web request
		System::Net::HttpWebRequest ^request = safe_cast<System::Net::HttpWebRequest^>(System::Net::HttpWebRequest::Create(
			this->APIEndPoint));
		request->Method = "POST";
		request->Accept = "application/json, text/javascript, */*; q=0.01";
		request->ContentType = "application/json; charset=UTF-8";
		request->KeepAlive = true;
		request->ContentLength = buffer->Length;

		// Retrieve the request stream so we can write the POST data
		System::IO::Stream ^stream = request->GetRequestStream(); // this crashes
		// Write the POST request
		stream->Write(buffer, 0, buffer->Length);

		// Retrieve the response
		System::Net::HttpWebResponse ^response = safe_cast<System::Net::HttpWebResponse^>(request->GetResponse());

		// Retrieve the response stream
		String^ responeString = (gcnew StreamReader(response->GetResponseStream()))->ReadToEnd();

		stream->Close();
		response->Close();

		if (responeString->Contains("\"fail\":false"))
		{
			return true;
		}

	}
	catch (WebException^ wex)
	{
		MessageBox::Show(wex->ToString(), "WebException", MessageBoxButtons::OK, MessageBoxIcon::Asterisk);
	}

	return false;
}
