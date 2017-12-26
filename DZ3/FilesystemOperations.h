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
//done!
class ReadFile :public FSOperation{
private:
	
public:
	File* f;
	Byte* stanje;
	ReadFile(File* fn) :FSOperation("ReadFile"),f(fn) {}
	void execute();
};
//done!
class WriteFile :public FSOperation {
public:
	File* f;
	Byte* content;
	WriteFile(Byte* content,File* f) :FSOperation("WriteFile"),f(f),content(content) {}
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
//done!
class DeleteObject :public FSOperation {
public:
	bool check;
	FSObject* objToDelete;
	DeleteObject(FSObject *objToDelete) :FSOperation("DeleteObject"),objToDelete(objToDelete),check(false) {}
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
//done!
class CopyPaste :public FSOperation {
public:
	FSObject *objToCopy, *rez;
	Folder* destFolder;
	Text* name;
	CopyPaste(FSObject* objToCopy,Folder* destFolder,Text* name) :FSOperation("CopyPaste"),name(name),objToCopy(objToCopy),destFolder(destFolder) {}
	void execute();
};
//done!
class ListDirectory :public FSOperation {
public:
	FSObject* rez;
	Folder* folder;
	ListDirectory(Folder* f) :FSOperation("ListDirectory"),folder(f) {}
	void execute();
};
//done!
class Search :public FSOperation {
public:
	Search(File fn) :FSOperation("Search") {}
	void execute();
};
class ProtectedOperation :public FSOperation {
	void execute();															//koj je ovo kurac????
};
class Move :public FSOperation {
public:
	FSObject *objToMove;
	Folder* destFolder;
	Move(FSObject * objToMove, Folder * destFolder) :FSOperation("Move"),objToMove(objToMove),destFolder(destFolder) {}
	void execute();
};