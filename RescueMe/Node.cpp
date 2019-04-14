#include "Node.h"


Node::Node()
{
	this->id = "";
	this->key = "";
}

Node::Node(String^ id, String^ key)
{
	this->id = id;
	this->key = key;
}

bool Node::verify()
{
	try
	{
		// Create HTTP Web request
		System::Net::HttpWebRequest ^request = safe_cast<System::Net::HttpWebRequest^>(System::Net::HttpWebRequest::Create(
				this->APIEndPoint + "?id="+this->id+"&key="+this->key));
		
		// Retrieve the response
		System::Net::HttpWebResponse ^response = safe_cast<System::Net::HttpWebResponse^>(request->GetResponse());
		
		// Retrieve the response stream
		String^ responeString = (gcnew StreamReader(response->GetResponseStream()))->ReadToEnd();

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
