#include <ntddk.h>

BOOLEAN VmdtRunCheck();

VOID Msg(const char* text)
{
	while (text[0] != 0)
	{
		__outbyte(0x2F8, text[0]);
		text++;
	}
}

NTSTATUS DriverEntry(PDRIVER_OBJECT drvObj, PUNICODE_STRING regPath)
{
	UNREFERENCED_PARAMETER(drvObj);
	UNREFERENCED_PARAMETER(regPath);

	BOOLEAN checkPassed = VmdtRunCheck();

	checkPassed ?	Msg("(PASS) Register is cleared!\n") : 
					Msg("(FAIL) Register still contains bogus bits!\n");

	return STATUS_FAILED_DRIVER_ENTRY;
}
