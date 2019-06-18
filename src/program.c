
#include "copy.h"

void program_print_version_number(void) {
    printf("%s Version %s\n", PACKAGE_NAME, PACKAGE_VERSION);
}

void program_print_copyright(void) {
    // TODO: Copyright
}

void program_print_license_preamble(void) {
    // TODO: program_print_license_preamble()
}

void program_print_license(void) {
    // TODO: program_print_license()
}

void program_print_usage(void) {
    printf("Usage: copy <source-file>\n");
}

void program_print_version(int long_version) {
    program_print_version_number();
    program_print_copyright();
    
    if (long_version == TRUE) {
        program_print_license();
    } else {
        program_print_license_preamble();
    }
}

void program_print_help(void) {
    program_print_version(FALSE);
    program_print_usage();
}
