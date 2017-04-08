/***************************************************************************
 * GAMS.c
 * Regex callback-based parser for GAMS definitions
 **************************************************************************/
/* INCLUDE FILES */
#include "general.h"    /* always include first */

#include "parse.h"      /* always include */
#include "read.h"       /* to define file fileReadLine() */

/* DATA DEFINITIONS */
typedef enum eGAMSKinds {
    K_DEFINE
} GAMSKind;

static kindOption GAMSKinds [] = {
	{ FALSE,  'b', "block data", "block data"},
	{ TRUE,  'c', "comment",     "common blocks"},
    { FALSE, 'd', "definition", " definition" },
	{ TRUE,  'e', "equation",      "entry points"},
	{ FALSE,  'f', "function",   "functions"},
	{ FALSE, 'i', "interface",  "interface contents, generic names, and operators"},
	{ FALSE,  'k', "component",  "type and structure components"},
	{ FALSE,  'l', "label",      "labels"},
	{ FALSE, 'L', "local",      "local, common block, and namelist variables"},
	{ FALSE,  'm', "module",     "modules"},
	{ TRUE,  'n', "namelist",   "namelists"},
	{ TRUE,  'p', "parameter",    "programs"},
	{ TRUE,  's', "scalar", "scalars"},
	{ TRUE,  't', "table",       "tablar input data"},
	{ TRUE,  'v', "variable",   "program (global) and module variables"}
};

/* FUNCTION DEFINITIONS */

static void definition (const char *const line, const regexMatch *const matches,
                       const unsigned int count)
{
    if (count > 1)    /* should always be true per regex */
    {
        vString *const name = vStringNew ();
        vStringNCopyS (name, line + matches [1].start, matches [1].length);
        makeSimpleTag (name, GAMSKinds, K_DEFINE);
    }
}

static void findGAMSTags (void)
{
    while (fileReadLine () != NULL)
        ;  /* don't need to do anything here since callback is sufficient */
}

static void installGAMS (const langType language)
{
    addCallbackRegex (language, "^def[ \t]+([a-zA-Z0-9_]+)", NULL, definition);
}

/* Create parser definition stucture */
extern parserDefinition* GAMSParser (void)
{
    static const char *const extensions [] = { "swn", NULL };
    parserDefinition* def = parserNew ("GAMS");
    def->kinds      = GAMSKinds;
    def->kindCount  = KIND_COUNT (GAMSKinds);
    def->extensions = extensions;
    def->parser     = findGAMSTags;
    def->initialize = installGAMS;
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