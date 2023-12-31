#include "main.h"
/**
 * main: entry point
 * Return: 0
 */
int main(int argc, char *argv[], char **env)
{
    char *prompt_line;
    char *pointer_prompt = NULL, *pointer_prompt2 = NULL;
    char *token;
    size_t size = 0;
    ssize_t handle_error = 0;
    const char *limit = " \n\t\r";
    int token_count = 0, a, b;
    int argv_count;
    (void)argc;
   
    
    while (1)
    {
        prompt_line = "$ ";
        _print_string(prompt_line);
        handle_error = getline(&pointer_prompt, &size, stdin);

        /*printf("%s\n",pointer_prompt);*/

        if (handle_error == EOF)
        {
            _putchar('\n');
            break;
        }
        /*_print_string(pointer_prompt);*/

        /*printf("%s",pointer_prompt);*/

        if ((strcmp(pointer_prompt, "exit") == 0))
            exit(-1);

        if ((strcmp(pointer_prompt, "\n") == 0))
            continue;

        /* =============== allocate memeor for the copy of pointer ====================*/
        pointer_prompt2 = malloc(sizeof(char *) * handle_error);
        if (pointer_prompt2 == NULL)
        {
            perror("sh");
            free(pointer_prompt);
            return (-1);
        }
        /*make a copy of string*/
        strcpy(pointer_prompt2, pointer_prompt);

        /*calculate number of tokens*/
        token = strtok(pointer_prompt, limit);
        while (token != NULL)
        {
            token_count++;
            token = strtok(NULL, limit);
        }
        token_count++;

        /*allocate space for array of strings (tokens)*/
        argv = malloc(sizeof(char *) * token_count);
        if (argv == NULL)
        {
            perror("sh");
            free(pointer_prompt);
            free(pointer_prompt2);
            return (-1);
        }
        /*allocate memory for copied string*/
        token = strtok(pointer_prompt2, limit);
        for (a = 0; token != NULL; a++)
        {
            argv[a] = strdup(token);
            argv[a] = malloc(sizeof(char) * strlen(token));
            strcpy(argv[a], token);
            token = strtok(NULL, limit);
        }
/* ============================================================ */
        if ((strcmp(argv[0], "exit") == 0))
            exit(-1);

        if ((strcmp(argv[0], "\n") == 0))
            continue;

        /*printf("%s\n",argv[0]);*/

        if ((strcmp(argv[0], "-1") == 0))
        {
             exit(-1);
        }


        /*execute command*/
        execute(argv, env);

        for (argv_count = 0; argv_count < a; argv_count++)
        {
            free(argv[a]);
        }

        argv[a] = NULL;
        for (b = 0; b < a; b++)
        {
            free(argv[b]);
        }

        free(argv);
        free(pointer_prompt2);
    }
    free(pointer_prompt);

    return (0);
}