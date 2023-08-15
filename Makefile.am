bin_PROGRAMS = runasroot
runasroot_SOURCES = runasroot.c

package:
	sudo checkinstall --install=no --pkgversion=1.0 --pkgname $(bin_PROGRAMS)

install-exec-hook:
	chown root $(bindir)/$(bin_PROGRAMS)
	chmod u+s $(bindir)/$(bin_PROGRAMS)

