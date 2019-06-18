
#include "copy.h"

int option_match(const char* input_str, ...) {
    va_list arg_pointer;
    va_start(arg_pointer, input_str);

    const char* option_str = NULL;

    while ((option_str = va_arg(arg_pointer, const char*)) != NULL) {
        if (strcmp(input_str, option_str) == 0) {
            va_end(arg_pointer);
            return TRUE;
        }
    }

    va_end(arg_pointer);
    return FALSE;
}

int main(int argc, char *argv[])
{
    // Verify the user supplied program arguments. If they did not, print an
    // error message and the help menu, and exit with error.
    if (argc == 1) {
        fprintf(stderr, "No input specified.\n\n");
        program_print_help();

        return EXIT_SUCCESS;
    }

    // Available Program Options
    int option_prepend_padding = FALSE;
    int option_force_execution = FALSE;
    
    // Program Option Configuration
    char* input_file_name   = NULL; // TODO: Verify this was changed before using
    char* output_file_name  = NULL; // TODO: Verify this was changed before using

    uint8_t prepend_padding_bytes = 3;
    uint8_t prepend_padding_value = 0;

    // Parse program options
    
    // Flag to indicate whether we should skip current string.
    int skip_next_string = FALSE;
    
    for (int i = 1; i < argc; ++i) {
        // Check the skip flag before doing anything. This flag will come in
        // handy when we have to process an option with an argument.
        if (skip_next_string == TRUE) {
            // Reset the flag before moving on.
            skip_next_string = FALSE;
            
            // Terminate current iteration.
            continue;
        }

        // Check whether the current input string begins with a dash, indicating
        // that it is an option specifier. Option values/arguments will be 
        // skipped over explicitly using the 'skip_next_string' flag. 
        if (argv[i][0] != '-') {
            // If the current string does not begin with a dash, we will assume
            // it's our input file name.
            input_file_name = argv[i];
            
            // Continue parsing the options.
            continue;
        }

        if (option_match(argv[i], "-f", "--force", 0)) {
            option_force_execution = TRUE;
            continue;
        }

        if (option_match(argv[i], "-o", 0)) {
            // Make sure there is at least one more parameter in the argument
            // vector, and if there's not let the user know what they did wrong
            // and exit with an error status.
            if ((i + 1) == argc) {
                fprintf(stderr, "Output filename expected after option: '-o'\n");

                return EXIT_FAILURE;
            }

            // Having verified the argument vector has at least one more 
            // parameter, verify it does not look like an option (meaning make 
            // sure it does not start with a dash).
            if (argv[i+1][0] == '-') {
                // The user probably did not mean to make a file name start with
                // a dash. Let them know about their mistake and exit with an
                // error code. Before that, though, make sure the force flag was
                // not specified.
                if (option_force_execution == FALSE) {
                    // The force flag has not been set, so let the user know
                    // about the error and exit.
                    fprintf(stderr, "Invalid filename: %s\n", argv[i+1]);
                    fprintf(stderr, "To force execution, use the '-f' or '--force' flags.\n");

                    return EXIT_FAILURE;
                }

                // Since the force flag was specified, simply carry on.
            }

            // Make sure to set the skip flag so the next argument is not parsed.
            skip_next_string = TRUE;

            // Set the output file's name.
            output_file_name = strdup(argv[i+1]);

            // Continue to the next option.
            continue;
        }

        if (option_match(argv[i], "-h", "--help", 0)) {
            program_print_help();

            return EXIT_SUCCESS;
        }
        
        if (option_match(argv[i], "--version", 0)) {
            printf("<Program Version Info>\n");

            return EXIT_SUCCESS;
        }

        // TODO: More intense option parsing needs implementing.    
        fprintf(stderr, "Invalid option: %s\n", argv[i]);

        return EXIT_FAILURE;
    }

    // TODO: Resolve input file name

    // Check whether input file name was actually set
    if (input_file_name == NULL) {
        fprintf(stderr, "No input file specified.\n");

        return EXIT_FAILURE;
    }

    // Check whether output file name was specified.
    if (output_file_name == NULL) {
        // If the output file's name was not explicitly set by the user, simply
        // append the suffix ".copy" to the input file's name.
        int output_file_name_set = asprintf(&output_file_name, "%s.copy", input_file_name);

        if (output_file_name_set == -1) {
            fprintf(stderr, "[Error] Failed to allocate memory for output file name\n");

            return EXIT_FAILURE;
        }
    }

    // TODO: Remove
    // printf("Program Execution...\n");
    // printf("\tInput file name: %s\n", input_file_name);
    // printf("\tOutput file name: %s\n", output_file_name);

    FILE* input_file = file_open(input_file_name, "r");

    char current_character = 0;

    while ((current_character = fgetc(input_file)) != EOF) {
        printf("%c", current_character);
    }

    if (fclose(input_file) == EOF) {
        fprintf(stderr, "[Error] Failed to close input file: %s\n", input_file_name);

        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
    
/* -------------------------------------------------------------------------- */

    while (*++argv) {
        FILE* input_file = file_open(*argv, "r");
        FILE* output_file = file_open("output", "w");

        int c = 0;

        if (option_prepend_padding == TRUE) {
            fprintf(output_file, "%c", prepend_padding_bytes);

            for (int i = 0; i < prepend_padding_bytes; ++i) {    
                fprintf(output_file, "%c", prepend_padding_value);
            }
        }

        while ((c = fgetc(input_file)) != EOF) {
            fprintf(output_file, "%c", c);
        }

        // Print final newline
        fprintf(output_file, "\n");

        if (fclose(output_file) == EOF) {
                fprintf(stderr, "Fatal error while attempting to close file: %s\n", *argv);

                break;
            }

        if (fclose(input_file) == EOF) {
            fprintf(stderr, "Fatal error while attempting to close file: %s\n", *argv);

            return EXIT_FAILURE;
        }
    }

    return EXIT_SUCCESS;
}
