// the compile command is =   gcc -o Cstream Cstream.c -02
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>

volatile sig_atomic_t running = 1;

void handle_signal(int sig) {
    running = 0;
}

int main() {
    signal(SIGINT, handle_signal);
    signal(SIGTERM, handle_signal);
    
    const char* command_one = "echo Error command not set Ctrl+c to kill";
//    const char* command_two = "multiple commands can be added in lines like this one here or you can leave this commented out";
    printf("Cstream streaming a stream of commands started. Using: %s\n", command_one);
    printf("Press Ctrl+C to stop\n");
    
    while (running) {
        system(command_one);
//	system(command_two);   ~ if multiple commands are added they need to be specified in this while loop matching the names of possible added commands above as shown on this line
        usleep(30000); // 30ms delay - can be changed 
    }
    
    printf("Cstream stream of commands halted.\n");
    return 0;
}
