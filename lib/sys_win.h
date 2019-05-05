#ifndef SYS_WIN_H
#define SYS_WIN_H

#include <stdint.h>
#include <stdlib.h>
#include <Windows.h>
#include <sddl.h>

#include <iostream>
#include <iomanip>
#include <memory>

struct heap_delete
{
    typedef LPVOID pointer;
    void operator()(LPVOID p)
    {
        ::HeapFree(::GetProcessHeap(), 0, p);
    }
};
typedef std::unique_ptr<LPVOID, heap_delete> heap_unique_ptr;

struct handle_delete
{
    typedef HANDLE pointer;
    void operator()(HANDLE p)
    {
        ::CloseHandle(p);
    }
};

typedef std::unique_ptr<HANDLE, handle_delete> handle_unique_ptr;
typedef uint32_t uid_t;
BOOL GetUserSID(HANDLE token, PSID* sid);
uid_t GetUID(HANDLE token);
uid_t getuid();
uid_t geteuid();


#endif // SYS_WIN_H
