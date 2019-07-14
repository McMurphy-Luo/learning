#include "DllMain.h"
#include <Windows.h>
#include <tchar.h>

class Test {
public:
  Test() {
    throw 0;
    OutputDebugString(_T("Loaded!!!!!\r\n"));
  }
};

Test test;

void __stdcall DoSomeThing() {
  MessageBox(NULL, _T("Hello World"), _T("Hello World"), 0);
}