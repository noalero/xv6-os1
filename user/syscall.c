#include "kernel/param.h"
#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"
#include "kernel/fs.h"
#include "kernel/fcntl.h"
#include "kernel/syscall.h"
#include "kernel/memlayout.h"
#include "kernel/riscv.h"


void pause_system_dem(int interval, int pause_seconds, int loop_size) {
    int pid = getpid();
    for (int i = 0; i < loop_size; i++) {
        if (i % interval == 0 && pid == getpid()) {
            printf("pause system %d/%d completed.\n", i, loop_size);
        }
        if (i == loop_size / 2) {
            pause_system(pause_seconds);
        }
    }
    printf("\n");
}

void kill_system_dem(int interval, int loop_size) {
    int pid = getpid();
    for (int i = 0; i < loop_size; i++) {
        if (i % interval == 0 && pid == getpid()) {
            printf("kill system %d/%d completed.\n", i, loop_size);
        }
        if (i == loop_size / 2 && pid == getpid())
        {
            kill_system();
        }
    }
    printf("\n");
}


void set_economic_mode_dem(int interval, int loop_size) {
    int pid = getpid();
    set_economic_mode_dem(1,loop_size);
    for (int i = 0; i < loop_size; i++) {
        if (i % interval == 0 && pid == getpid()) {
            printf("set economic mode %d/%d completed.\n", i, loop_size);
        }
        if (i == loop_size / 2) {
            set_economic_mode_dem(0,loop_size);
        }
    }
    printf("\n");
}

int
main(int argc, char *argv[])
{  
    //set_economic_mode_dem(10, 100);
    pause_system_dem(10, 4, 100);
    print_status();
    sleep(3);

    kill_system_dem(10, 100);
    exit(0);
}