#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include <unistd.h>
#include <fcntl.h>

int main(void)
{
  struct termios old_attr, new_attr;
  unsigned char character;

  tcgetattr(STDIN_FILENO, &old_attr);
  new_attr = old_attr;

  new_attr.c_lflag &= ~(ICANON | ECHO);

  tcsetattr(STDIN_FILENO, TCSANOW, &new_attr);

  fcntl(STDIN_FILENO, F_SETFL, fcntl(STDIN_FILENO, F_GETFL) | O_NONBLOCK);

  while (1)
  {
    int input = getchar();

    if (input != EOF)
    {
      character = (unsigned char)input;
      putchar(character);
      printf("%c", character);
    }
  }

  tcsetattr(STDIN_FILENO, TCSANOW, &old_attr);

  return 0;
}
