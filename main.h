#include <iostream>
#include <windows.h>
#include <mmsystem.h>
#include <stdio.h>
#include <cstdlib>
#include <ctime>

#ifndef MAIN_H_
#define MAIN_H_

char ch[100];

void Message()
{
    gets(ch);

    if(strcmp(ch, "hi")==0)
    {
        system("Color 0B");
        PlaySound(TEXT("Sounds/Hello.wav"), NULL, SND_ASYNC);
        std::cout << "Hi, I'm your PC voice assistant, how can I help you sir?" << std::endl;
        system("Color 0A");
    }
    else if(strcmp(ch, "open program")==0)
    {
        std::string program_name;
        std::cout << "Enter program name: ";
        system("Color 0B");
        std::cin >> program_name;
        PlaySound(TEXT("Sounds/Open.wav"), NULL, SND_ASYNC);
        std::cout << "OK, I'm opening it...";
        Sleep(3000);

        std::system(program_name.c_str());
        system("Color 0A");

    }
    else if(strcmp(ch, "start ai")==0)
    {
        system("Color 0B");
        PlaySound(TEXT("Sounds/StartAI.wav"), NULL, SND_ASYNC);
        std::cout << "I am starting an AI chat based on OpenAI" << std::endl;
        Sleep(5000);
        system("start test/ai.exe");
        exit(0);
    }
    else if(strcmp(ch, "shutdown computer")==0)
    {
        system("Color 0B");
        PlaySound(TEXT("Sounds/Shutdown.wav"), NULL, SND_ASYNC);
        std::string answer;
        std::cout << "Are you sure you want to shut down the computer? (yes/no): ";
        std::cin >> answer;

        if (answer == "yes") {
            PlaySound(TEXT("Sounds/ShutdownNow.wav"), NULL, SND_ASYNC);
            std::cout << "Shutdown computer..." << std::endl;
            Sleep(5000);
            std::system("shutdown /s /t 0");
        }
        else if (answer == "no") {
            std::cout << "Stop shutdown" << std::endl;
            system("Color 0A");
        }
    }
    else if(strcmp(ch, "clear")==0)
    {
        system("cls");
    }
    else if(strcmp(ch, "time")==0)
    {
        PlaySound(TEXT("Sounds/Time.wav"), NULL, SND_ASYNC);
        std::time_t result = std::time(nullptr);
        std::cout << std::asctime(std::localtime(&result))
            << result << " Windows local time\n";
    }
    else if(strcmp(ch, "cats")==0)
    {
        system("Color 0B");
        PlaySound(TEXT("Sounds/GenArt.wav"), NULL, SND_ASYNC);
        std::cout << "Generate ASCII art..." << std::endl;
        Sleep(5000);
        system("start ArtGen/main.exe");
        exit(0);
    }
    else if(strcmp(ch, "help")==0)
    {
        std::cout << "My all commands: \n-hi : hello :) \n-open program : open any programs \n-shutdown computer : shutdown your computer \n-clear : clear text from console \n-time : show local time \n-cats : generate random ASCII cat art \n-start ai : start AI chat" << std::endl;
    }
}

#endif // MAIN_H_