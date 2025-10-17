#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    //create all files
    FILE *f1 = fopen("file1.txt", "w");
    FILE *f2 = fopen("file2.txt", "w");
    FILE *f3 = fopen("file3.txt", "w");

    if (!f1 || !f2 || !f3) {
        perror("file creation failed");
        exit(1);
    }

    fprintf(f1, "#File 1, Abdalrhman Islam, RegNo: 2305152\n");
    fprintf(f2, "#File 2, Abdalrhman Islam, RegNo: 2305152\n");
    fprintf(f3, "#File 3, Abdalrhman Islam, RegNo: 2305152\n");

    fclose(f1);
    fclose(f2);
    fclose(f3);

    // files name
    char *files[] = {"file1.txt", "file2.txt", "file3.txt"};

    // craete 3 child
    for (int i = 0; i < 3; i++) {
        pid_t pid = fork();

        if (pid < 0) {
            perror("fork failed");
            exit(1);
        }

        if (pid == 0) {
            // Child process
            printf("Child %d displaying %s:\n", i + 1, files[i]);
            fflush(stdout); //ensure strings print before execute
            execlp("cat", "cat", files[i], NULL);
            perror("exec failed");
            exit(1);
        } else {
            wait(NULL); //wait all childrens end
        }
    }

    printf("All children have finished.\n");
    return 0;
}