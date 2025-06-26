
Simple AI Assistant Console App
This is a basic C++ console-based AI assistant program. It understands simple text commands, responds with randomized friendly messages, tells jokes, shows the current time, and can perform basic arithmetic operations (add, subtract, multiply, divide). It also gracefully handles unrecognized commands.

Features
Recognizes greetings like "hello"

Responds to "how are you" and "thanks" with varied replies

Shows current system time with "time" command

Tells random jokes with "joke" command

Performs basic math calculations with commands like:

add 5 10

subtract 10 3

multiply 4 7

divide 20 5 (handles division by zero)

Case insensitive commands

Simple input parsing and error handling

User can exit by typing quit

Usage
Run the program, then type commands at the prompt.
Example commands:

sql
hello
how are you
thanks
time
joke
add 3 5
subtract 10 4
multiply 7 8
divide 20 4
quit
How to build
You need a C++ compiler supporting C++11 or newer.

Compile (Linux/macOS):
bash
g++ -o ai_assistant main.cpp
./ai_assistant
Compile (Windows with MinGW):
bash
g++ -o ai_assistant.exe main.cpp
ai_assistant.exe
Code Overview
Uses getline to read full lines from user input

Converts input to lowercase for case-insensitive command matching

Splits input into tokens to parse math commands

Uses srand and rand for randomized responses

Uses C++ STL containers (vector<string>) to store possible responses
