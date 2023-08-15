// vi:set nu ai ap aw smd showmatch tabstop=4 shiftwidth=4:
#include	<stdio.h>
#include	<stdlib.h>
#include	<sys/types.h>
#include	<unistd.h>
#include	<string.h>

/* the program */
int main(void) {
	int status=0;
	char cmd[128];

	/* run as uid 0 */
	setuid(0);

	/* announce what we are doing */
	printf("Setting permissions on /tmp/yocto to 0777\n");

	/* setup the command buffer */
	/* this is where you specify the special command you need to run as root. */
	/* the "| exit 1" is included to ensure if the command fails, it's status get returned */
	strcpy(cmd,"chmod -R 0777 /tmp/yocto || exit 1");

	/* run the command, save return code from the command executed */
	status = system(cmd);
	
	/* check status for failure (the chmod failed) */
	if ( status != 0 ) {
		exit(1);
	}

	/* fallthru, we succeeded */
	exit(0);

}


