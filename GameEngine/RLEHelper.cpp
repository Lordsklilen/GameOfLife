#include "RLEHelper.h"

RLEHelper::RLEHelper()
{
}


RLEHelper::~RLEHelper()
{
}
void RLEHelper::SaveFile(shared_ptr <RLEstorage> storage) {
	path aPath{ "c:\\nojkais" };
	create_directories(aPath);
}
//shared_ptr<RLEstorage> RLEHelper::LoadFile(string path) {
//
//	return nullptr;
//}
