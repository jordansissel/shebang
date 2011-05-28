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

#include <stdio.h>
#include <unistd.h>

int main(int argc, char **argv) {
  char *cmd;
  char *newargv[4];

  /* argv[0] is the program name, don't care */
  /* argv[1] is the string after the #!command */
  /* argv[2] is the name of the file you are executing */
  asprintf(&cmd, "%s %s", argv[1], argv[2]);
  newargv[0] = "/bin/sh";
  newargv[1] = "-c";
  newargv[2] = cmd;
  newargv[3] = NULL;
  execvp("/bin/sh", newargv);
  return -1;
}
