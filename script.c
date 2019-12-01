#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <pwd.h>

#include <unistd.h>
#include <fcntl.h>
#include <time.h>

int main(){
  while(1){
    usleep(1000000);
    FILE *pf;
    char cwd[1024];
    int fd;
    //  getcwd(cwd, sizeof(cwd));
    struct passwd *pw = getpwuid(getuid());
    const char *homedir = pw->pw_dir;

    fd = open("./recentFiles.txt", O_RDWR | O_CREAT, 0777);

    char command[200];
    int a = sprintf(command, "nohup find %s -newermt \"-10 seconds\" | grep %s >> recentFiles.txt", homedir, homedir);  

    pf = popen(command, "r");
  }
}

