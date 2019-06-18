
#ifndef PROJECT_INCLUDES_copy_H_
#define PROJECT_INCLUDES_copy_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>
#include <string.h>
#include <errno.h>
#include <math.h>
#include <signal.h>
#include <time.h>
#include <locale.h>
#include <limits.h>
#include <inttypes.h>

/* *nix specifix headers */
#include <unistd.h>
#include <getopt.h>

#if !defined(FALSE) || !defined(TRUE)
enum { FALSE = 0, TRUE = !FALSE };
#endif // FALSE || TRUE

#ifndef PROJECT_INCLUDES_FILE_H_
#include "file.h"
#endif // PROJECT_INCLUDES_FILE_H_

#ifndef PROJECT_INCLUDES_PROGRAM_H_
#include "program.h"
#endif // PROJECT_INCLUDES_PROGRAM_H_

#endif // PROJECT_INCLUDES_copy_H_

