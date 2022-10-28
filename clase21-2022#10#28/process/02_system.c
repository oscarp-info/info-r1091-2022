#include <stdlib.h>

int main()
{
  int r;

  // para capturar la salida del comando utilizaremos  popen, pronto...
  r = system("ls -l /");

  while (1)
    sleep(2);

  return r;
}
