/*
    Copyright (c) 20220 - Musab Albirair <musabalbirair@gmail.com>
    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU Lesser General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/
#include <stdio.h>//for printing to standard error
#include <ctype.h>
char * optarg;
int opterr = 1, optind = 1, optopt;
static int internalIndex = 1;
///adjust optind & internalIndex to point to the next potential option.
static void advance(char * const argv[])
{
	if (!argv[optind][internalIndex + 1])
	{
		++optind;
		internalIndex = 1;
	}
	else
		++internalIndex;
}
int getopt(int argc, char * const argv[], const char * optstring)
{
	//if all arguments were consumed || the argument doesn't start with '-'
	//or its equal to the string "-"
	if (!argv[optind] || '-' != *argv[optind] || !argv[optind][1])
		return -1;
	//if the argument is the string "--"
	if ('-' == argv[optind][1] && !argv[optind][2])
	{
		++optind;
		return -1;
	}
	int current = 0;
	//search for the character pointed to by optind & internalIndex in optstring
	while (optstring[current] != argv[optind][internalIndex] &&
			optstring[current])
		++current;
	//if the current character isn't an option
	if (!optstring[current])
	{
		optopt = argv[optind][internalIndex];
		if (opterr && ':' != *optstring)
			fprintf(stderr, "%s: invalid option '%c'\n", *argv,
					optopt);
		advance(argv);
		return '?';
	}
	if (!isalnum(optstring[current]))
	{
		fprintf(stderr, "%s: '%c' isn't alphanumeric\n", *argv,
				optstring[current]);
		return -1;
	}
	//if the option takes an argument
	if (':' == optstring[current + 1])
	{
		//if the argument is separated from its option
		if (!argv[optind][internalIndex + 1])
		{
			optarg = argv[optind + 1];
			optind += 2;
			if (optind > argc)
			{
				optopt = optstring[current];
				optind = argc;//to avoid faulty behavior in subsequent calls
				if (':' == *optstring)
					return ':';
				if (opterr)
					fprintf(stderr, "%s: the option '%c' requires an argument\n"
							, *argv, optopt);
				return '?';
			}
		}
		else
			optarg = argv[optind++] + internalIndex + 1;
		internalIndex = 1;
	}
	else
		advance(argv);
	return optstring[current];
}