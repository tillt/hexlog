//
//  hexlog_int.h
//

#ifndef HexLog_hexlog_int_h
#define HexLog_hexlog_int_h

#ifdef __cplusplus
extern "C"
{
#endif

void init_hexlog_(int (*print)(void *, const char *, ...));
void hexlog_(const char *data, const unsigned long size, void* context);

#ifdef __cplusplus
}
#endif

#endif
