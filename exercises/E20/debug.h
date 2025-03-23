
#ifndef DEBUG_H
#define DEBUG_H

/*
setting the debug level between 0-4
*/
void set_debug_level(int debug_level);

/*
if debug_level <= current debug level, prints to stderr with dbgx
if > prints nothing and returns 0
 */
int dprintf(int debug_level, const char *fmt, ...);

#endif //DEBUG_H
