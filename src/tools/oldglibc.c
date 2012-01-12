#include <stdint.h>
#include <arpa/inet.h>

#include "oldglibc.h"

uint64_t be64toh(uint64_t v) {
  union { uint32_t lv[2]; uint64_t llv; } u;
  u.llv = v;
  return ((uint64_t)ntohl(u.lv[0]) << 32) | (uint64_t)ntohl(u.lv[1]);
}

uint32_t be32toh(uint32_t v) {
  return ntohl(v);
}

uint32_t htobe32(uint32_t x) {
  union { uint32_t u32; uint8_t v[4]; } ret;
  ret.v[0] = (uint8_t)(x >> 24);
  ret.v[1] = (uint8_t)(x >> 16);
  ret.v[2] = (uint8_t)(x >> 8);
  ret.v[3] = (uint8_t) x;
  return ret.u32;
}

uint64_t htobe64(uint64_t x) {
  union { uint64_t u64; uint8_t v[8]; } ret;
  ret.v[0] = (uint8_t)(x >> 56);
  ret.v[1] = (uint8_t)(x >> 48);
  ret.v[2] = (uint8_t)(x >> 40);
  ret.v[3] = (uint8_t)(x >> 32);
  ret.v[4] = (uint8_t)(x >> 24);
  ret.v[5] = (uint8_t)(x >> 16);
  ret.v[6] = (uint8_t)(x >> 8);
  ret.v[7] = (uint8_t) x;
  return ret.u64;
}
