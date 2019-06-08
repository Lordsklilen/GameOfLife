#include "MainForm.h"

using namespace System::Windows::Forms;
using namespace CLRWindowOutput;
using namespace System::Configuration;

void MarshalString(String ^ s, string& os);
shared_ptr<RLEstorage> ReadConfig();

[STAThreadAttribute]
int main()
{

	auto config = ReadConfig();
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	MainForm mainForm;
	mainForm.SetConfig(config);
	Application::Run(%mainForm);
	return 0;
}

shared_ptr<RLEstorage> ReadConfig() {
	auto result = shared_ptr<RLEstorage>(new RLEstorage());
	string x = "";
	string y = ""; 
	MarshalString(ConfigurationManager::AppSettings["x"], x);
	MarshalString(ConfigurationManager::AppSettings["y"], y);
	result->x = stoi(x,nullptr);
	result->y = stoi(y,nullptr);
	return result;
}

