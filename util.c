#include "util.h"

//------- UTILITY FUNCTIONS
bool is_label(const char* x, const size_t s){
    return x[s-1] == ':';
}

bool is_immediate(const char* x, const size_t s){
    return x[0] == '#';
}

bool is_command(const char* x, const size_t s){
    bool flag = false;
    for(int i = 0; i < 11; i++){
        if(strcmp(x, commands[i])==0){
            flag = true;
            break;
        }
    }
    return flag;
}
bool find_sections(char* filename, int *save_here)
{
    const char code_start[] = ".code";
    const char code_end[] = ".endcode";
    const char data_start[] = ".data";
    const char data_end[] = ".enddata";

    FILE *fp = fopen(filename, "r");
    if(fp==NULL){
        printf("Could not open the file %s\n", filename);
        return false;
    }
    // The biggest string we are searching for is 8 chars long
    // So this buffer is all we need. [9 chars + null makes sure
    // that we didn't just find a suffix].
    char buffer[10];
    memset(buffer, 0, 10);
    int count = 0;
    while(fscanf(fp, "%s", buffer) == 1){
        if(strcmp(code_start, buffer) == 0){
            save_here[0] = count;
        }
        if(strcmp(code_end, buffer) == 0){
            save_here[1] = count;
        }
        if(strcmp(data_start, buffer) == 0){
            save_here[2] = count;
        }
        if(strcmp(data_end, buffer) == 0){
            save_here[3] = count;
        }
        count++;
    }
    fclose(fp);
    return true;
}