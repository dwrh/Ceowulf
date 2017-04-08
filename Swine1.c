/***************************************************************************
 * GAMS.c
 * Character-based parser for GAMS definitions
 **************************************************************************/
/* INCLUDE FILES */
#include "general.h"    /* always include first */

#include <string.h>     /* to declare strxxx() functions */
#include <ctype.h>      /* to define isxxx() macros */

#include "parse.h"      /* always include */
#include "read.h"       /* to define file fileReadLine() */

/* DATA DEFINITIONS */
typedef enum eGAMSKinds {
    K_DEFINE
} GAMSKind;

static kindOption GAMSKinds [] = {
    { TRUE, 'd', "definition", "pig definition" }
};

/* FUNCTION DEFINITIONS */

static void findGAMSTags (void)
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
            makeSimpleTag (name, GAMSKinds, K_DEFINE);
            vStringClear (name);
        }
    }
    vStringDelete (name);
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
    return def;
}
 


