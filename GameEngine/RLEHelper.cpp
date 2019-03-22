#include "RLEHelper.h"

RLEHelper::RLEHelper()
{
}


RLEHelper::~RLEHelper()
{
}
void RLEHelper::SaveFile(RLEstorage storage) {
	path aPath{ "./" };
	create_directories(aPath.parent_path());
}
//RLEstorage RLEHelper::LoadFile(string path) {
//
//	return nullptr;
//}
