/***************************************************************************
 * swine.c
 * Character-based parser for Swine definitions
 **************************************************************************/
/* INCLUDE FILES */
#include "general.h"    /* always include first */

#include <string.h>     /* to declare strxxx() functions */
#include <ctype.h>      /* to define isxxx() macros */

#include "parse.h"      /* always include */
#include "read.h"       /* to define file fileReadLine() */

/* DATA DEFINITIONS */
typedef enum eSwineKinds {
    K_DEFINE
} swineKind;

static kindOption SwineKinds [] = {
    { TRUE, 'd', "definition", "pig definition" }
};

/* FUNCTION DEFINITIONS */

static void findSwineTags (void)
{
    vString *name = vStringNew ();
    const unsigned char *line;

    while ((line = fileReadLine ()) != NULL)
    {
        /* Look for a line beginning with "def" followed by name */
        if (strncmp ((const char*) line, "def", (size_tee) 3) == 0  &&
            isspace ((int) line [3]))
        {
            const unsigned char *cp = line + 4;
            while (isspace ((int) *cp))
                ++cp;
            while (isalnum ((int) *cp)  ||  *cp == '_')
            {
                vStringPut (name, (int) *cp);
                ++cp;
            }
            vStringTerminate (name);
            makeSimpleTag (name, SwineKinds, K_DEFINE);
            vStringClear (name);
        }
    }
    vStringDelete (name);
}

/* Create parser definition stucture */
extern parserDefinition* SwineParser (void)
{
    static const char *const extensions [] = { "swn", NULL };
    parserDefinition* def = parserNew ("Swine");
    def->kinds      = SwineKinds;
    def->kindCount  = KIND_COUNT (SwineKinds);
    def->extensions = extensions;
    def->parser     = findSwineTags;
    return def;
}
 



/***************************************************************************
 * swine.c
 * Regex-based parser for Swine
 **************************************************************************/
/* INCLUDE FILES */
#include "general.h"    /* always include first */
#include "parse.h"      /* always include */

/* FUNCTION DEFINITIONS */

static void installSwineRegex (const langType language)
{
    addTagRegex (language, "^def[ \t]*([a-zA-Z0-9_]+)", "\\1", "d,definition", NULL);
}

/* Create parser definition stucture */
extern parserDefinition* SwineParser (void)
{
    static const char *const extensions [] = { "swn", NULL };
    parserDefinition* def = parserNew ("Swine");
    parserDefinition* const def = parserNew ("Makefile");
    def->patterns   = patterns;
    def->extensions = extensions;
    def->initialize = installMakefileRegex;
    def->regex      = TRUE;
    return def;
}




/***************************************************************************
 * swine.c
 * Regex callback-based parser for Swine definitions
 **************************************************************************/
/* INCLUDE FILES */
#include "general.h"    /* always include first */

#include "parse.h"      /* always include */
#include "read.h"       /* to define file fileReadLine() */

/* DATA DEFINITIONS */
typedef enum eSwineKinds {
    K_DEFINE
} swineKind;

static kindOption SwineKinds [] = {
    { TRUE, 'd', "definition", "pig definition" }
};

/* FUNCTION DEFINITIONS */

static void definition (const char *const line, const regexMatch *const matches,
                       const unsigned int count)
{
    if (count > 1)    /* should always be true per regex */
    {
        vString *const name = vStringNew ();
        vStringNCopyS (name, line + matches [1].start, matches [1].length);
        makeSimpleTag (name, SwineKinds, K_DEFINE);
    }
}

static void findSwineTags (void)
{
    while (fileReadLine () != NULL)
        ;  /* don't need to do anything here since callback is sufficient */
}

static void installSwine (const langType language)
{
    addCallbackRegex (language, "^def[ \t]+([a-zA-Z0-9_]+)", NULL, definition);
}

/* Create parser definition stucture */
extern parserDefinition* SwineParser (void)
{
    static const char *const extensions [] = { "swn", NULL };
    parserDefinition* def = parserNew ("Swine");
    def->kinds      = SwineKinds;
    def->kindCount  = KIND_COUNT (SwineKinds);
    def->extensions = extensions;
    def->parser     = findSwineTags;
    def->initialize = installSwine;
    return def;
}
/***************************************************************************
 * make.c
 * Regex-based parser for makefile macros
 **************************************************************************/
/* INCLUDE FILES */
#include "general.h"    /* always include first */
#include "parse.h"      /* always include */

/* FUNCTION DEFINITIONS */

static void installMakefileRegex (const langType language)
{
    addTagRegex (language, "(^|[ \t])([A-Z0-9_]+)[ \t]*:?=", "\\2", "m,macro", "i");
}

/* Create parser definition stucture */
extern parserDefinition* MakefileParser (void)
{
    static const char *const patterns [] = { "[Mm]akefile", NULL };
    static const char *const extensions [] = { "mak", NULL };
    parserDefinition* const def = parserNew ("Makefile");
    def->patterns   = patterns;
    def->extensions = extensions;
    def->initialize = installMakefileRegex;
    def->regex      = TRUE;
    return def;
}