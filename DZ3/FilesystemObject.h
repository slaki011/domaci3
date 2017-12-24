#pragma once
#include<string>
#include<vector>
using namespace std;


typedef char* Text;
typedef char* Byte;


class FSObject {
private:
	AccessDescriptor accessDescriptor;
	Text name;
public:
	FSObject(Text nm,Folder* fn):name(nm),parent(fn){}
	Folder* parent;                                                               //0..1 ?????
	Text getName();
	AccessDescriptor getAccessDescriptor();
	virtual void accept(FilesystemVisitor* v) = 0;
	virtual long size() = 0;
	virtual FSObject* copy() = 0;
	~FSObject();
};
class Folder :public FSObject {
private:
	
public:
	Folder(Text a, Folder* fn) :FSObject(a, fn) {}
	void accept(FilesystemVisitor* v) {	}
	void add(FSObject* o);
	long size() {}
	std::vector<FSObject*> getObjects();
	void remove(FSObject* obj);
	std::vector<FSObject*> containedObjects;
	FSObject* copy() {}
	~Folder();
};

class File :public FSObject {
private:
	Byte* content;
public:
	File(Text a, Folder* fn) :FSObject(a, fn), content(nullptr) {}
	void accept(FilesystemVisitor* v) {}
	void write(Byte content) {}
	FSObject* copy() {}
	long size() {}
	Byte* read() {}
	~File();
};

class FilesystemVisitor {
public:
	virtual void visitFile(File f) = 0;
	virtual void visitFolder(Folder f) = 0;
};

class SearchVisitor :public FilesystemVisitor {
private:
	Text filepath;
public:
	void visitFile(File f);
	void visitFolder(Folder f);
	vector<FSObject*> foundObjects;
};

class AccessDescriptor {
private:
	FSObject* protectedObject;
	Text* allowedOperations;
public:
	AccessDescriptor():allowedOperations(nullptr), protectedObject(nullptr){}
	void add(Text operationName);
	void remove(Text operationName);
	Text* getAllowedOperations();
	bool checkAccess(Text operationName);
	~AccessDescriptor();
};

