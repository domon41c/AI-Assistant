#include <iostream>
#include <windows.h>
#include <mmsystem.h>
#include <stdio.h>
#include "main.h"
#include <Lmcons.h>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <thread>

int main()
{
    TCHAR username[UNLEN + 1];
    DWORD size = UNLEN + 1;
    GetUserName((TCHAR*)username, &size);

    system("Color 0A");

    const char* messages[] = {"\nHello my Owner", "\nI love you bro", "\nTime to drink coffee", "\nWhat you need?", "\nLet's play", "\nStart AI mode", "\nEnter the help command"};

    srand(time(nullptr));

    PlaySound(TEXT("Sounds/Hello.wav"), NULL, SND_ASYNC);
    std::cout << "Hi, I'm your PC voice assistant, how can I help you sir?" << std::endl;

    std::cout << "I love you " << username << std::endl;

    while(1)
    {
        std::cout << "\n\n--------------------------------------------------------" << std::endl;

        Message();

        int index = rand() % (sizeof(messages) / sizeof(*messages));

        std::cout << messages[index] << std::endl;

        int wait_time = rand() % 5 + 1;
        std::this_thread::sleep_for(std::chrono::seconds(wait_time));
    }
}