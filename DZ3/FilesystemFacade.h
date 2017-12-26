#pragma once
#include"FilesystemObject.h"
#include"FilesystemOperations.h"

class Filesystem {
public:
	Folder* rootFolder;
	File* createFile(Text* fName, Folder* destFolder);
	Folder* createFolder(Text* fName, Folder* parentFolder);
	FSObject* listFolder(Folder* folder);
	Byte* readFile(File* file);
	void writeFile(Byte* content);
	void grantAccess(FSObject* fObj, Text* opName = nullptr);
	void revokeAccess(FSObject* fObj, Text* opName = nullptr);
	Folder openFolder(Text* folderPath);
	FSObject* search(Text* objName);
	void copyPaste(FSObject* objToCopy, Folder* destFolder, Text* name);
	void move(FSObject* objToMove, Folder* destFolder);
	bool deleteF(FSObject* objToDelete);
	long freeSpace();
};