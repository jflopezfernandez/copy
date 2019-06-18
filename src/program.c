
#include "copy.h"

void program_print_version_number(void) {
    printf("%s Version %s\n", PACKAGE_NAME, PACKAGE_VERSION);
}

void program_print_copyright(void) {
    printf("Copyright (C) 2019, Jose Fernando Lopez Fernandez.\n\n");
}

static const char* license_preamble =
"This program comes with ABSOLUTELY NO WARRANTY; for details type `show w'.\n"
"This is free software, and you are welcome to redistribute it\n"
"under certain conditions; type `show c' for details.\n";

void program_print_license_preamble(void) {
    printf("%s\n", license_preamble);    
}

static const char* license =
"This program is free software: you can redistribute it and/or modify\n"
"it under the terms of the GNU General Public License as published by\n"
"the Free Software Foundation, either version 3 of the License, or\n"
"(at your option) any later version.\n\n"
"This program is distributed in the hope that it will be useful,\n"
"but WITHOUT ANY WARRANTY; without even the implied warranty of\n"
"MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the\n"
"GNU General Public License for more details.\n\n"
"You should have received a copy of the GNU General Public License\n"
"along with this program.  If not, see <https://www.gnu.org/licenses/>.\n";

void program_print_license(void) {
    printf("%s\n", license);
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
