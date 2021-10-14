#include <stdio.h>
#include <sys/stat.h>
#include <ftw.h>
#define MAX_FTW_DEPTH 16

static int num_dirs, num_regular;

// When callback() is called in ftw, it updates the respective counters when encountering either a file or a folder.
static int callback(const char *fpath, const struct stat *sb, int type) {
    if(type == 0){
        num_regular++;
    }
    if(type == 1 || type == 2){
        num_dirs++;
    }
    return 0;
}

int main(int argc, char** argv) {

    num_dirs = 0;
    num_regular = 0;

    ftw(argv[1], callback, MAX_FTW_DEPTH);

    printf("There were %d directories.\n", num_dirs);
    printf("There were %d regular files.\n", num_regular);

    return 0;
}