#include <iostream>
#include <chrono>
#include <system_error>
#include <thread>

#include <fcntl.h>
#include <sys/mman.h>

// constexpr uint32_t kTimerBase = 0x3F003000; // Raspbery Pi (CPU BCM2835)
constexpr uint32_t kTimerBase = 0x7E003000; // Raspbery Pi 4 B (CPU BCM2711)

struct SystemTimer
{
   uint32_t CS;
   uint32_t counter_lo;
   uint32_t counter_hi;
};

int main()
{

   int memfd = open("/dev/mem", O_RDWR | O_SYNC);
   if (memfd < 0)
   {
      throw std::system_error(errno, std::generic_category(),
                              "Failed to open /dev/mem. Make sure you run as root.");
   }

   SystemTimer *timer = (SystemTimer *)mmap(NULL, sizeof(SystemTimer),
                                            PROT_READ | PROT_WRITE, MAP_SHARED,
                                            memfd, kTimerBase);
   if (timer == MAP_FAILED)
   {
      throw std::system_error(errno, std::generic_category(),
                              "Memory mapping failed");
   }

   uint64_t prev = 0;
   for (int i = 0; i < 10; i++)
   {
      uint64_t time = ((uint64_t)timer->counter_hi << 32) + timer->counter_lo;
      std::cout << "System timer: " << time;
      if (i > 0)
      {
         std::cout << ", diff " << time - prev;
      }
      prev = time;
      std::cout << std::endl;
      std::this_thread::sleep_for(std::chrono::milliseconds(10));
   }
   return 0;
}