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



