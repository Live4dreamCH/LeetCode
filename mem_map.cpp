#include <fcntl.h>
#include <stdio.h>
#include <sys/mman.h>
#include <unistd.h>

int main() {
  int fd = open("example.txt", O_RDWR);
  if (fd == -1) {
    perror("open");
    return 1;
  }

  // 将文件映射到内存
  void *addr = mmap(NULL, 4096, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
  if (addr == MAP_FAILED) {
    perror("mmap");
    return 1;
  }

  // 修改映射的内存
  char *data = (char *)addr;
  data[0] = 'H';

  // 解除映射
  if (munmap(addr, 4096) == -1) {
    perror("munmap");
    return 1;
  }

  close(fd);
  return 0;
}
