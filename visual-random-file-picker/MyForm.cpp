//melkadze
#include "MyForm.h"
//this starts the form
using namespace visualrandomfilepicker;
[STAThreadAttribute]
int main() //array<System::String^> ^args
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(gcnew MyForm());
}