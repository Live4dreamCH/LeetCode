#include <iostream>
#include <mutex>
#include <shared_mutex>
#include <thread>
#include <vector>

// Shared resource
std::vector<int> shared_data;
std::shared_mutex rw_mutex; // Read-Write Mutex

// Reader function (shared access)
void reader(int id) {
  std::shared_lock<std::shared_mutex> lock(rw_mutex); // Shared lock for reading
  std::cout << "Reader " << id << " is reading data: ";
  for (const auto &val : shared_data) {
    std::cout << val << " ";
  }
  std::cout << std::endl;
}

// Writer function (exclusive access)
void writer(int id) {
  std::unique_lock<std::shared_mutex> lock(rw_mutex); // Unique lock for writing
  std::cout << "Writer " << id << " is writing data..." << std::endl;
  shared_data.push_back(id); // Modify the shared data
}

int main() {
  // Start multiple threads (readers and writers)
  std::thread reader1(reader, 1);
  std::thread reader2(reader, 2);
  std::thread writer1(writer, 1);
  std::thread writer2(writer, 2);

  // Join threads
  reader1.join();
  reader2.join();
  writer1.join();
  writer2.join();

  return 0;
}
