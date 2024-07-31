#if defined(__APPLE__)
#include <sys/random.h>
#include <unistd.h>
#include <stdexcept>

extern "C" {

ssize_t getrandom(void *buf, size_t buflen, unsigned int flags) {
    (void)flags; // Ignore flags as getentropy does not use them
    if (getentropy(buf, buflen) == -1) {
        return -1;
    }
    return buflen;
}

} // extern "C"
#endif
