#ifndef RANDOM_WRAPPER_H
#define RANDOM_WRAPPER_H

#if defined(__APPLE__)
extern "C" {
ssize_t getrandom(void *buf, size_t buflen, unsigned int flags);
}
#endif

#endif // RANDOM_WRAPPER_H
