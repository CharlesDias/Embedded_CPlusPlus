#include <cstdint>
#include <string.h>

constexpr size_t kMaxFileNameSize = 256;
constexpr size_t kBufferSize = 4096;
constexpr size_t kMaxDevices = 16;

class SerialDevice 
{
   public:
      SerialDevice():
         file_descriptor(-1), input_lenght(0), output_lenght(0)
      { }

      bool Init(const char* name) 
      {
         strncpy(device_file_name, name, sizeof(device_file_name));
      }

      bool Write(const uint8_t* data, size_t size) 
      {
         if(size > sizeof(output_buffer)) 
         {
            throw "Data size exceeds the limit";
         }
         memcpy(output_buffer, data, size);
      }

      size_t Read(uint8_t* data, size_t size) 
      {
         if(size < input_lenght) 
         {
            throw "Read buffer is too small";
         }
         memcpy(data, input_buffer, input_lenght);
         return input_lenght;
      }

   private:
      char device_file_name[256];
      uint8_t input_buffer[kBufferSize];
      uint8_t output_buffer[kBufferSize];
      int file_descriptor;
      size_t input_lenght;
      size_t output_lenght;
};


int main() 
{
   SerialDevice devices[kMaxDevices];
   size_t number_of_devices = 0;

   uint8_t data[] = "Hello";
   devices[0].Init("test");
   devices[0].Write(data, sizeof(data));
   number_of_devices = 1;

   return 0;
}