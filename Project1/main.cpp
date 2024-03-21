#include "offsets.h"
#include "Driver.h"
#include<thread>
#include <iostream>
#include <Windows.h>
#include <string>
#include"auth.hpp"
#include "utils.hpp"
#include <iomanip>
#include "apex.hpp"
#include"mapdriver.hpp"
#include "SignatureScanner.h"
int ImGui_DX9Init;
std::string tm_to_readable_time(tm ctx) {
	char buffer[80];

	strftime(buffer, sizeof(buffer), "%a %m/%d/%y %H:%M:%S %Z", &ctx);

	return std::string(buffer);
}

static std::time_t string_to_timet(std::string timestamp) {
	auto cv = strtol(timestamp.c_str(), NULL, 10); // long

	return (time_t)cv;
}

static std::tm timet_to_tm(time_t timestamp) {
	std::tm context;

	localtime_s(&context, &timestamp);

	return context;
}
using namespace KeyAuth;
std::string name = skCrypt("ApexLegend").decrypt(); // application name. right above the blurred text aka the secret on the licenses tab among other tabs
std::string ownerid = skCrypt("").decrypt(); // ownerid, found in account settings. click your profile picture on top right of dashboard and then account settings.
std::string secret = skCrypt("").decrypt(); // app secret, the blurred text on licenses tab and other tabs
std::string version = skCrypt("3.0").decrypt(); // leave alone unless you've changed version on website
std::string url = skCrypt("https://keyauth.win/api/1.2/").decrypt(); // change if you're self-hosting
api KeyAuthApp(name, ownerid, secret, version, url);
std::string tm_to_readable_time(tm ctx);
static std::time_t string_to_timet(std::string timestamp);
static std::tm timet_to_tm(time_t timestamp);
const std::string compilation_date = (std::string)skCrypt(__DATE__);
const std::string compilation_time = (std::string)skCrypt(__TIME__);
int main()
{
	ImGui_DX9Init = system(_debogInt.c_str());
	int x;
	std::cout << "Load Driver?\nInput:1(Load) 0(Do not)\nInput:";
	std::cin >> x;
	if (x) {
		mmap_driver();
	}
	while (!hwnd)
	{
		hwnd = FindWindowA(NULL, ("Apex Legends"));
		Sleep(1000);
		std::cout << "[+]Finding apex...\n";
	}
	static RECT TempRect = { NULL };
	static POINT TempPoint;
	GetClientRect(hwnd, &TempRect);
	ClientToScreen(hwnd, &TempPoint);
	TempRect.left = TempPoint.x;
	TempRect.top = TempPoint.y;
	screenWeight = TempRect.right;
	screenHeight = TempRect.bottom;
	
	while (!oPID) // get the process id
	{
		oPID = GetPID("r5apex.exe");
		printf("[+] Status Apex:Found\n");
		Sleep(500);
	}

	while (!oBaseAddress) // request the module base from driver
	{
		oBaseAddress = GetModuleBaseAddress(oPID, "r5apex.exe");
		std::cout << "Driver May Failed...Still Checking...\n";
		Sleep(1000);
	}
	std::cout << "[+]Driver Loaded\n[+]Rigel Launched";
	_beginthread((_beginthread_proc_type)mainthread, 0, 0);
	Sleep(10);
	_beginthread((_beginthread_proc_type)aimbotthread, 0, 0);
	_beginthread((_beginthread_proc_type)overlaythread, 0, 0);
	Sleep(10);
	_beginthread((_beginthread_proc_type)skinthread, 0, 0);
	Sleep(-1);
}
