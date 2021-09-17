#include <unistd.h>
#include <string.h>
#include <malloc.h>

int main(int argc, char **argv) {
    char **patchedArgv = argv;
    if (argc > 1 && (strcmp(argv[1], "log") == 0 ||
                     strcmp(argv[1], "status") == 0 ||
                     strcmp(argv[1], "merge-recursive") == 0 ||
                     strcmp(argv[1], "diff") == 0)) {
        patchedArgv = malloc((argc + 1) * sizeof(char *));
        patchedArgv[0]=argv[0]; // git
        patchedArgv[1]=argv[1]; // command like "log"
        patchedArgv[2]="-M20";  // patch --find-renames[=<n>]
        size_t otherArgv = (argc - 2 /*git log*/) * sizeof(char *);
        if(otherArgv == 0)
        {
            patchedArgv[3] = '\0';
        } else{
            memmove(patchedArgv + 3, argv + 2, otherArgv);
        }
    }
    return execvp("git.orig", patchedArgv);
}
