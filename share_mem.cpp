#include <fcntl.h>
#include <stdio.h>
#include <sys/mman.h>
#include <unistd.h>

class A {
public:
  A() : d(new int(0)) {}
  A(const A &h) : d(new int(*h.d)) {}
  ~A() { delete d; }
  int *d;
};

int main() {
  // 创建共享内存对象
  int fd = shm_open("/my_shm", O_CREAT | O_RDWR, S_IRUSR | S_IWUSR);
  if (fd == -1) {
    perror("shm_open");
    return 1;
  }

  // 调整共享内存的大小
  if (ftruncate(fd, 4096) == -1) {
    perror("ftruncate");
    return 1;
  }

  // 映射共享内存到进程的地址空间
  void *addr = mmap(NULL, 4096, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
  if (addr == MAP_FAILED) {
    perror("mmap");
    return 1;
  }

  // 修改共享内存
  char *data = (char *)addr;
  data[0] = 'H';

  // 解除映射
  if (munmap(addr, 4096) == -1) {
    perror("munmap");
    return 1;
  }

  // 关闭共享内存对象
  close(fd);

  // 删除共享内存对象
  shm_unlink("/my_shm");

  return 0;
}
