#pragma once
#include"FilesystemObject.h"


class FSOperation {
private:
	Text* opName;
public:
	FSOperation(Text* t):opName(t){}
	virtual void execute() = 0;
	Text* getName();
};

class ReadFile :public FSOperation{
private:
	
public:
	File* f;
	Byte* stanje;
	ReadFile(File* fn) :FSOperation("ReadFile"),f(fn) {}
	void execute();
};
class WriteFile :public FSOperation {
public:
	WriteFile(Byte* f) :FSOperation("WriteFile") {}
	void execute();
};
class CreateFile :public FSOperation {
private:
	Text* fName;
	Folder* destFolder;
public:
	File* f;
	CreateFile(Text* fName,Folder* destFolder) :FSOperation("CreateFile"),fName(fName),destFolder(destFolder) {}
	void execute();
};
class DeleteObject :public FSOperation {
public:
	DeleteObject(File fn) :FSOperation("DeleteObject") {}
	void execute();
};
class CreateFolder :public FSOperation {
public:
	Folder* f;
	Folder* parentFolder;
	Text* fName;
	CreateFolder(Text* fName,Folder* parentFolder) :FSOperation("CreateFolder"),fName(fName),parentFolder(parentFolder) {}
	void execute();
};
class CopyPaste :public FSOperation {
public:
	FSObject *objToCopy, *rez;
	Folder* destFolder;
	Text* name;
	CopyPaste(FSObject* objToCopy,Folder* destFolder,Text* name) :FSOperation("CopyPaste"),name(name),objToCopy(objToCopy),destFolder(destFolder) {}
	void execute();
};
class ListDirectory :public FSOperation {
public:
	FSObject* rez;
	Folder* folder;
	ListDirectory(Folder* f) :FSOperation("ListDirectory"),folder(f) {}
	void execute();
};
class Search :public FSOperation {
public:
	Search(File fn) :FSOperation("Search") {}
	void execute();
};
class ProtectedOperation :public FSOperation {
	void execute();															//koj je ovo kurac????
};