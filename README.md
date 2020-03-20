A cross-platform simple implementation of the function **getopt** complying with **POSIX.1-2008** provided under **LGPL V3** license. The library defines the following symbols:
```C
	int getopt(int argc, char * const argv[], const char *optstring);
	extern char *optarg;
	extern int opterr, optind, optopt;
```