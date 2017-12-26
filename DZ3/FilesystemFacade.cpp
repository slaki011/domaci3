#include "FilesystemFacade.h"

File* Filesystem::createFile(Text * fName, Folder * destFolder)
{
	CreateFile cf(fName, destFolder);
	cf.execute();
	return cf.f;
}
//done!
Folder* Filesystem::createFolder(Text * fName, Folder * parentFolder)
{
	CreateFolder cf(fName, parentFolder);
	cf.execute();
	return cf.f;
}
//done!
FSObject * Filesystem::listFolder(Folder * folder)
{
	ListDirectory ld(folder);
	ld.execute();
	return ld.rez;
}
//done!
Byte* Filesystem::readFile(File * file)
{
	ReadFile rf(file);
	rf.execute();
	return rf.stanje;
}
//done!
void Filesystem::writeFile(Byte * content,File* f)
{
	WriteFile wf(content,f);
	wf.execute();
}
//done!
void Filesystem::grantAccess(FSObject * fObj, Text * opName)
{
	AccessDescriptor* a = fObj->getAccessDescriptor();
	if (a->checkAccess(opName)) {
		return;
	}
	else {
		a->add(opName);
	}
}
//done!
void Filesystem::revokeAccess(FSObject * fObj, Text * opName)
{
	AccessDescriptor* a = fObj->getAccessDescriptor();
	if (a->checkAccess(opName)) {
		a->remove(opName);
	}
	else {
		return;
	}

}
//done!
//Folder Filesystem::openFolder(Text * folderPath)
//{
//	
//}
//FSObject * Filesystem::search(Text * objName)
//{
//	return nullptr;
//}
void Filesystem::copyPaste(FSObject * objToCopy, Folder * destFolder, Text * name)
{
	CopyPaste cp(objToCopy, destFolder, name);
	cp.execute();
}
//done!
void Filesystem::move(FSObject * objToMove, Folder * destFolder)
{
	Move m(objToMove, destFolder);
	m.execute();
}
//done!
bool Filesystem::deleteF(FSObject * objToDelete)
{
	DeleteObject del(objToDelete);
	del.execute();
	return del.check;
}
//done!
//long Filesystem::freeSpace()
//{
//	return 0;
//}