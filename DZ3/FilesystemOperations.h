#pragma once
#include"FilesystemObject.h"


class FSOperation {
private:
	Text opName;
public:
	FSOperation(Text t):opName(t){}
	virtual void execute() = 0;
	Text getName();
};

class ReadFile :private FSOperation{
private:
	File* f;
	Byte* stanje;
public:
	ReadFile(File fn) :FSOperation("ReadFile"),f(&fn) {}
	void execute() {
		stanje = f->read();
	}
};
class WriteFile :private FSOperation {
public:
	WriteFile(File fn) :FSOperation("WriteFile") {}
	void execute();
};
class CreateFile :private FSOperation {
public:
	CreateFile(File fn) :FSOperation("CreateFile") {}
	void execute();
};
class DeleteObject :private FSOperation {
public:
	DeleteObject(File fn) :FSOperation("DeleteObject") {}
	void execute();
};
class CreateFolder :private FSOperation {
public:
	CreateFolder(File fn) :FSOperation("CreateFolder") {}
	void execute();
};
class CopyPaste :private FSOperation {
public:
	CopyPaste(File fn) :FSOperation("CopyPaste") {}
	void execute();
};
class ListDirectory :private FSOperation {
public:
	ListDirectory(File fn) :FSOperation("ListDirectory") {}
	void execute();
};
class Search :private FSOperation {
public:
	Search(File fn) :FSOperation("Search") {}
	void execute();
};
class ProtectedOperation :private FSOperation {
	void execute();															//koj je ovo kurac????
};