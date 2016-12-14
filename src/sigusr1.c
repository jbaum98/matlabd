/*
 * kill.c
 *
 * This Matlab Mex program allows you to send a signal to a process.
 *
 * Written by Joshua V Dillon
 *
 * Revision History:
 * Jan. 20. 2011  First release.
 *
 * This code can be compiled from within Matlab or command-line, assuming the
 * system is appropriately setup.  To compile, invoke: mex kill.c
 *
 */

#include <sys/types.h>
#include <signal.h>
#include "mex.h"

/* ------------------------------------------------------------------------- */
/* Matlab gateway function                                                   */
/* (see kill.m for description)                                              */
/* ------------------------------------------------------------------------- */
void mexFunction( int nlhs,       mxArray *plhs[], 
                  int nrhs, const mxArray *prhs[]  )
{
	pid_t pid;
	int sig=SIGTERM;

	/* check min number of arguments */
	if ( nrhs!=1 )
		mexErrMsgIdAndTxt("MATLAB:kill",
				"Minimum input arguments missing; must supply "
				"pid.");

	/* get pid */
	if ( mxIsNumeric(prhs[0]) && mxGetNumberOfElements(prhs[0])==1 )
		pid = (pid_t)mxGetScalar(prhs[0]);
	else
		mexErrMsgIdAndTxt("MATLAB:kill",
				"First input argument must be a valid PID "
				"(scalar integer).");

	if ( kill(pid,SIGUSR1) == -1 ) {
		mexErrMsgIdAndTxt("MATLAB:kill",
			"Failed to send the signal.");
	}
	
}

/*
 * Copyright (c) 2011, Joshua V Dillon
 * All rights reserved.
 * 
 * Redistribution and use in source and binary forms, with or
 * without modification, are permitted provided that the
 * following conditions are met:
 *  * Redistributions of source code must retain the above
 *    copyright notice, this list of conditions and the
 *    following disclaimer.
 *  * Redistributions in binary form must reproduce the above
 *    copyright notice, this list of conditions and the
 *    following disclaimer in the documentation and/or other
 *    materials provided with the distribution.
 *  * Neither the name of the author nor the names of its
 *    contributors may be used to endorse or promote products
 *    derived from this software without specific prior written
 *    permission.
 * 
 * THIS SOFTWARE IS PROVIDED BY JOSHUA V DILLON ''AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED
 * TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL JOSHUA
 * V DILLON BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
 * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 */


/* 
 * Programmer's Notes:
 *
 * MEX C API:
 * http://www.mathworks.com/access/helpdesk/help/techdoc/apiref/bqoqnz0.html
 *
 * Testing:
 */


