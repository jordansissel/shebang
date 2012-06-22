/* shebang helper.
 *
 * This tool lets you sanely execute things from the shebang line
 * at the top of a script.
 * 
 * Problem solved by this program:
 * This line won't work like you might expect:
 *   #!/usr/bin/env scriptname arg1 arg2 ...
 *
 * When executed, this will run this:
 *   /usr/bin/env "scriptname arg1 arg2 ..."
 *
 * The above is likely not what you wanted, you wanted:
 *   /usr/bin/env "scriptname" "arg1" "arg2" ...
 *
 * If you use this program, it'll work as expected:
 *   #!/usr/bin/shebang scriptname arg1 arg2
 */

#include <stdio.h> /* for printf */
#include <unistd.h> /* for execvp */
#include <stdlib.h> /* for calloc */
#include <string.h> /* for memcpy */

int main(int argc, char **argv) {
  char *cmd;
  char **newargv;

  newargv = calloc(argc + 2, sizeof(char *));
  newargv[0] = "/bin/sh";
  newargv[1] = "-c";
  asprintf(&(newargv[2]), "%s \"$@\"", argv[1]);
  memcpy(newargv + 3, argv + 2, (argc - 2) * sizeof(char *));

  //for (int i = 0; i < argc + 2; i ++) {
    //printf("newargv[%d]: %s\n", i, newargv[i]);
  //}

  execvp("/bin/sh", newargv);
  return -1;
}
