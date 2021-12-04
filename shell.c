

char *lsh_read_line(void)
{
    int bufsize = LSH_RL_BUFSIZE;
    int position = 0;
    char *buffer = malloc(sizeof(char) * buffsize);
    int c;

    if(!buffer){
        fprintf(stderr, "lsh: allocation error\n")
        exit(EXIT_FAILURE);
    }

    while(1) {
        //read a character
        c = getchar();
        //// If we hit EOF, replace it with a null character and return.
        if( c == EOF || c == '\n') {
            buffer[position] = '\0';
            return buffer;
        } else{
            buffer[position] = c;
        }
        position++;

        //If we have exceeded the buffer, reallocate.
        if(position >= bufsize){
            bufsize += LSH_RL_BUFSIZE;
            buffer = realloc(buffer, bufsize);
            if(!buffer){
                fprintf(stderr, "lsh: allocation error\n");
                exit(EXIT_FAILURE);
            }
        }
    }
}

void lsh_loop(void)
{
    char *line;
    char **args;
    int status;

    do {
        print("> ");
        line = lsh_read_line();
        args = lsh_split_line(line);

        free(line);
        free(args);

    } while(status)
}


int main(int agrc, char **argv)
{
    lsh_loop();


    return EXIT_SUCESS;
}