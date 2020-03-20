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
#ifndef GETOPT_H_INCLUDED
#define GETOPT_H_INCLUDED
#ifdef __cplusplus
extern "C"
{
#endif // __cplusplus
///command-line arguments parser
/**
 * command-line parser that follows Utility Syntax Guidelines 3, 4, 5, 6,
 * 7, 9, and 10 in XBD Utility Syntax Guidelines of POSIX.1-2008. The function
 * uses the global variable optarg for storing option argument of the last
 * option that takes an argument, optind as index of the next argument to be
 * processed and optopt to store the last option that caused an error.
 * @param [in] argc is the argument counter - main's first argument
 * @param [in] argv is the argument vector - main's second argument
 * @param [in] optstring is a list of all expected options. If an option
 * requires an argument it must be followed by colon. Only alphanumeric
 * characters are supported.
 * @return the function returns the next option character specified on the
 * command line. A colon is returned if getopt() detects a missing argument and
 * the first character of optstring was a colon. A question mark is returned if
 * getopt() encounters an option character not in optstring or detects a missing
 * argument and the first character of optstring was not a colon. Otherwise,
 * getopt() shall return -1 when all command line options are parsed.
*/
extern int getopt(int argc, char * const argv[], const char * optstring);
///points to the last option argument
extern char * optarg;
/**
 * If it is not set to 0 and the first character of optstring is not a colon,
 * getopt shall print a diagnostic message to stderr
 */
extern int opterr;
///the index of the next element of the argv[] vector to be processed
extern int optind;
///the option character that caused an error
extern int optopt;
#ifdef __cplusplus
}
#endif // __cplusplus
#endif