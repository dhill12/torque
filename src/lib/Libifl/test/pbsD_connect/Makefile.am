include $(top_srcdir)/buildutils/config.mk

PROG_ROOT = ../..

AM_CFLAGS = -g -DTEST_FUNCTION -I${PROG_ROOT}/ -I${PROG_ROOT}/${PBS_MACH} --coverage -DPBS_DEFAULT_FILE=\"$(PBS_DEFAULT_FILE)\"

lib_LTLIBRARIES = libpbsD_connect.la

AM_LDFLAGS = @CHECK_LIBS@ ${lib_LTLIBRARIES}

check_PROGRAMS = test_pbsD_connect

libpbsD_connect_la_SOURCES = scaffolding.c ${PROG_ROOT}/pbsD_connect.c
libpbsD_connect_la_LDFLAGS = @CHECK_LIBS@ -shared

test_pbsD_connect_SOURCES = test_pbsD_connect.c

check_SCRIPTS = coverage_run.sh

TESTS = ${check_PROGRAMS} coverage_run.sh

coverage_run.sh:
	echo 'cp -p .libs/pbsD_connect.gc* . >/dev/null 2>&1' > $@
	echo 'RESULTS=($$(gcov pbsD_connect.gcda))' >> $@
	echo 'PARSED_RESULT="TOTALCOV -- $${RESULTS[1]}: Lines($${RESULTS[5]})- $${RESULTS[3]}"' >> $@
	echo 'echo -e "\033[40m\033[1;33m$$PARSED_RESULT\033[0m"' >> $@
	chmod +x $@

CLEANFILES = coverage_run.sh *.gcno *.gcda *.gcov core *.lo
