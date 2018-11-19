//mutex

#include <windows.h>
#include <stdio.h>
#define THREADCOUNT 2

HANDLE ghMutex;

DWORD WINAPI WriteToDatabase(LPVOID);

int main()
{
	HANDLE aThread[THREADCOUNT];
	DWORD ThreadID;
	int i;
	DWORD Ret;
	// ������� �������� ���������� ��� ���������� ���������
	ghMutex = CreateMutex(
		NULL,              // �������� ���� ������� �� ���������
		FALSE,           // �������� ���������� ���������� ��������
		NULL);             // �� ������������� ��� ��������� ����������
	if (ghMutex == NULL)
	{
		wprintf(L"CreateMutex() failed, error %d\n", GetLastError());
		return -1;
	}
	else
		wprintf(L"CreateMutex() is Ok\n");
	// �������� ������� �������
	wprintf(L"Creating the worker threads...\n");
	for (i = 0; i < THREADCOUNT; i++)
	{
		aThread[i] = CreateThread(
			NULL,       // ���������� ������
			0,          // ��������� ������ ����� (0 � ��� � ������������� ������)
			(LPTHREAD_START_ROUTINE)WriteToDatabase, //������� ������
			NULL,       // �������� ������ (��� ����������)
			0,          // ����� �������� (default, �����)
			&ThreadID); // ������������� ������
		if (aThread[i] == NULL)
		{
			wprintf(L"CreateThread() failed, error: %d\n", GetLastError());
			return -1;
		}
		else
			wprintf(L"CreateThread() #%i is OK\n", i);
	}
	// ���������, ���� ��� ������ �����������
	// WAIT_OBJECT_0, WAIT_ABANDONED_0, WAIT_TIMEOUT, WAIT_FAILED
	Ret = WaitForMultipleObjects(THREADCOUNT, aThread, TRUE, INFINITE);
	wprintf(L"WaitForMultipleObjects() return value is %d\n", Ret);
	// Close thread and mutex handles
	for (i = 0; i < THREADCOUNT; i++)
	{
		if (CloseHandle(aThread[i]) != 0)
			wprintf(L"Thread %d handle was successfully closed...\n", GetCurrentThreadId());
		else
			wprintf(L"Failed to close thread %d handle...\n", GetCurrentThreadId());
	}
	CloseHandle(ghMutex);
	system("pause");
	return 0;
}

DWORD WINAPI WriteToDatabase(LPVOID lpParam)
{
	DWORD dwCount = 0, dwWaitResult;
	// Request ownership of mutex.
	while (dwCount < 20)
	{
		dwWaitResult = WaitForSingleObject(
			ghMutex,    // handle to mutex
			INFINITE);  // no time-out interval
		switch (dwWaitResult)
		{
			// The thread got ownership of the mutex
		case WAIT_OBJECT_0:
			__try {
				// TODO: Write to the database
				wprintf(L"Thread %d writing to database, count #%d\n", GetCurrentThreadId(), dwCount);
				dwCount++;
			}
			__finally {
				// Release ownership of the mutex object
				if (!ReleaseMutex(ghMutex))
				{
					// Handle error.
				}
			}
			break;
			// The thread got ownership of an abandoned mutex

			// The database is in an indeterminate state
		case WAIT_ABANDONED:
			return FALSE;
		}
	}
	return TRUE;
}