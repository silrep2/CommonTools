
#include <sys/time.h>
#include <cstdint>
namespace sil{
    class Timer{
    private:
        struct timeval m_startTime;
    public:
        Timer(){gettimeofday(&m_startTime, NULL);}
        inline void Reset(){gettimeofday(&m_startTime, NULL);}
        // in usec
        inline uint64_t GetTimeInterval(){
            struct timeval endTime;
            gettimeofday(&endTime, NULL);
            uint64_t timeInterval = (endTime.tv_sec - m_startTime.tv_sec) * 1000000 + endTime.tv_usec - m_startTime.tv_usec;
            return timeInterval;
        }
}