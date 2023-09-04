/*Write a program to handle the SIGINT and SIGTERM signals. From
inside the handler for SIGINT signal write an infinite loop to print
the message ‘Processing Signal’. Run the program and make use of
Ctrl+C more than once. Run the program once again and press
Ctrl+C once. Then use the kill command. What are your
observations?*/
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

// Signal handler for SIGINT (Ctrl+C)
void sigint_handler(int signum) {
    printf("Received SIGINT signal (Ctrl+C)\n");
    printf("Entering infinite loop to process the signal...\n");
    while (1) {
        printf("Processing Signal\n");
        sleep(1);  // Sleep for 1 second
    }
}

// Signal handler for SIGTERM (kill command)
void sigterm_handler(int signum) {
    printf("Received SIGTERM signal (kill command)\n");
    exit(0);  // Terminate the program gracefully
}

int main() {
    // Register the signal handlers
    if (signal(SIGINT, sigint_handler) == SIG_ERR) {
        perror("Unable to register SIGINT handler");
        return 1;
    }

    if (signal(SIGTERM, sigterm_handler) == SIG_ERR) {
        perror("Unable to register SIGTERM handler");
        return 1;
    }

    printf("Program is running. Press Ctrl+C to see the effect of SIGINT.\n");
    printf("Use 'kill' command to send SIGTERM signal to terminate the program.\n");

    // Keep the program running
    while (1) {
        sleep(1);
    }

    return 0;
}
