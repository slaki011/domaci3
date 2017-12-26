#include "FilesystemFacade.h"

File* Filesystem::createFile(Text * fName, Folder * destFolder)
{
	CreateFile cf(fName, destFolder);
	cf.execute();
	return cf.f;
}

Folder* Filesystem::createFolder(Text * fName, Folder * parentFolder)
{
	CreateFolder cf(fName, parentFolder);
	cf.execute();
	return cf.f;
}

FSObject * Filesystem::listFolder(Folder * folder)
{
	ListDirectory ld(folder);
	ld.execute();
	return ld.rez;
}

Byte* Filesystem::readFile(File * file)
{
	ReadFile rf(file);
	rf.execute();
	return rf.stanje;
}

void Filesystem::writeFile(Byte * content)
{
	WriteFile wf(content);
	//??????? kome upisujes?

}

void Filesystem::grantAccess(FSObject * fObj, Text * opName)
{
}

void Filesystem::revokeAccess(FSObject * fObj, Text * opName)
{
}

Folder Filesystem::openFolder(Text * folderPath)
{
	
}

FSObject * Filesystem::search(Text * objName)
{
	return nullptr;
}

void Filesystem::copyPaste(FSObject * objToCopy, Folder * destFolder, Text * name)
{
	CopyPaste cp(objToCopy, destFolder, name);
	cp.execute();
}

void Filesystem::move(FSObject * objToMove, Folder * destFolder)
{
}

bool Filesystem::deleteF(FSObject * objToDelete)
{
	return false;
}

long Filesystem::freeSpace()
{
	return 0;
}
