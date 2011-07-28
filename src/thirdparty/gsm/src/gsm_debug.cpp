#include "mipconfig.h"

#ifdef MIPCONFIG_SUPPORT_GSM

/*
 * Copyright 1992 by Jutta Degener and Carsten Bormann, Technische
 * Universitaet Berlin.  See the accompanying file "COPYRIGHT" for
 * details.  THERE IS ABSOLUTELY NO WARRANTY FOR THIS SOFTWARE.
 */

/* $Header: /home/jori/CVSROOT/jvoiplib/src/thirdparty/gsm/src/gsm_debug.cpp,v 1.2 2004/09/02 14:47:35 jori Exp $ */

#include "private.h"

#ifndef	NDEBUG

/* If NDEBUG _is_ defined and no debugging should be performed,
 * calls to functions in this module are #defined to nothing
 * in private.h.
 */

#include <stdio.h>
#include "proto.h"

void gsm_debug_words P4( (name, from, to, ptr), 
	char 	      * name,
	int		from,
	int		to,
	word		* ptr)
{
	int 	nprinted = 0;

	fprintf( stderr, "%s [%d .. %d]: ", name, from, to );
	while (from <= to) {
		fprintf(stderr, "%d ", ptr[ from ] );
		from++;
		if (nprinted++ >= 7) {
			nprinted = 0;
			if (from < to) putc('\n', stderr);
		}
	}
	putc('\n', stderr);
}

void gsm_debug_longwords P4( (name, from, to, ptr),
	char 	      * name,
	int		from,
	int		to,
	longword      * ptr)
{
	int 	nprinted = 0;

	fprintf( stderr, "%s [%d .. %d]: ", name, from, to );
	while (from <= to) {

		fprintf(stderr, "%d ", (int)ptr[ from ] );
		from++;
		if (nprinted++ >= 7) {
			nprinted = 0;
			if (from < to) putc('\n', stderr);
		}
	}
	putc('\n', stderr);
}

void gsm_debug_longword P2(  (name, value),
	char		* name,
	longword	  value	)
{
	fprintf(stderr, "%s: %d\n", name, (int)value );
}

void gsm_debug_word P2(  (name, value),
	char	* name,
	word	  value	)
{
	fprintf(stderr, "%s: %d\n", name, (int)value);
}

#endif

#endif // MIPCONFIG_SUPPORT_GSM
