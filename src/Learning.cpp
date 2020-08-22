#include <Windows.h>
#include <tchar.h>
#include <iostream>
#include <sstream>

using std::basic_stringstream;
using std::basic_string;
using std::endl;
using std::wcout;

typedef void (__stdcall *LibraryFunction)();

int main(int argc, char* argv[]) {

  HMODULE dll_loaded = NULL;

  basic_stringstream<TCHAR> debug_stream;
  size_t index = 0;
  for (; index < 10000; ++index) {
    dll_loaded = LoadLibraryEx(_T("learning_dll.dll"), NULL, 0);
    if (dll_loaded == NULL) {
      debug_stream << _T("Load module failed, windows error code is ") << GetLastError() << " loaded times is " << index << endl;
      break;
    }
    FreeLibrary(dll_loaded);
    dll_loaded = NULL;
  }
  basic_string<TCHAR> dll_loaed_error_string = debug_stream.str();
  if (dll_loaed_error_string.empty()) {
    dll_loaed_error_string = _T("All load succeeded");
  }
  OutputDebugString(dll_loaed_error_string.c_str());
  wcout << dll_loaed_error_string;
  return 0;
}
