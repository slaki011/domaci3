#include "FilesystemOperations.h"

void WriteFile::execute()
{

}

void CreateFile::execute()
{
	f = new File(fName, destFolder);
}

void DeleteObject::execute()
{
}

void CreateFolder::execute()
{
	f = new Folder(fName, parentFolder);
}

void CopyPaste::execute()
{
	rez = objToCopy->copy();
	rez->parent = destFolder;
	rez->setName(name);
}

void ListDirectory::execute()
{
	for (unsigned int i = 0; i < folder->containedObjects.size(); i++) {
		rez[i] = *(folder->containedObjects[i]);
	}
}

void Search::execute()
{
}

void ProtectedOperation::execute()
{
}

Text* FSOperation::getName()
{
	return this->opName;
}

void ReadFile::execute()
{
	stanje = f->read();
}
