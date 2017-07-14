
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <unistd.h>
#include <time.h>

char* print_size(uint64_t v)
{
  static char buff[256];
  
  uint64_t b = v % 1024;
  v /= 1024;
  uint64_t kb = v % 1024;
  v /= 1024;
  uint64_t mb = v % 1024;
  v /= 1024;
  uint64_t gb = v;
  
  char* ptr = buff;
  if (gb)
    ptr += sprintf(ptr, "%dG ", gb);
  if (mb)
    ptr += sprintf(ptr, "%dM ", mb);
  if (kb)
    ptr += sprintf(ptr, "%dk ", kb);
  if (b)
    ptr += sprintf(ptr, "%d", b);
  
  return buff;
}

int main (int argc, const char* argv[])
{
    setvbuf(stdout, NULL, _IOLBF, 0);
  
    uint64_t total = 0;
    size_t size = 1024;
    int rise = 1;
    uint32_t* ptr = 0;
    
    srand(time(0));
    
    while (size > sizeof(*ptr) ) {
        printf("%d ", size);
        ptr = malloc(size);
        
        if (ptr == 0) {
            printf("failed, total=%s\n", print_size(total));
            size /= 2;
            rise = 0;
        } else {
            total += size;
            printf("allocated, total=%s\n", print_size(total));
            
            uint32_t* p = ptr;
            uint32_t* end = ptr + size/sizeof(*p);
            while (p < end) {
                *p++ = rand();
            }
            printf("initialized\n");
            
            if (rise) {
                if (size < 1024*1024*1024) {
                    size *= 2;
                }
            }
        }
    }
    


	return 0;
}
