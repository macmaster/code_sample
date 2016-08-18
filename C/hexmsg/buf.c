#include <syslog.h>

char buffer[4028];

int main() {

   int i;

   for (i=0; i<=40280; i++)
       buffer[i]='A';

   syslog(LOG_ERR, buffer);
}
