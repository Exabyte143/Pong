# Pong++
Pong++ is a clone of the famous arcade game, Pong. Rewritten in C++.

## How to install
**Windows**
1. Install MingW https://sourceforge.net/projects/mingw-w64/files/Toolchains%20targetting%20Win32/Personal%20Builds/mingw-builds/installer/mingw-w64-install.exe/download **MAKE SURE TO SELECT x86_64 for your Architecture**
2. Add "C:\Program Files\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\bin" to your system path.
3. Clone this repo
4. Open the directory the game is located in cmd and run "mingw32-make"

After that it should be installed.

**Linux**
1. Open main.cpp remove these lines: #include "<Windows.h>", and "::ShowWindow(::GetConsoleWindow(), SW_HIDE);".
2. Clone this repo
3. Open the directory the game is located in your terminal and run "make".

After that it should be installed.

## How to play
Use WS to control Player1 and ↑↓ to control Player2.
