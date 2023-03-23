/**
 * Copied from https://github.com/shiguredo/sora-cpp-sdk/blob/9b7fb4ed457b386fc4a26566d7ddbe9c9aaf613e/third_party/lyra/lyra.h
 */

#ifndef LYRA_H_INCLUDED
#define LYRA_H_INCLUDED

#include <stddef.h>
#include <stdint.h>

#include <emscripten.h>

extern "C" {

struct lyra_encoder;
struct lyra_decoder;
struct lyra_vector_u8;
struct lyra_vector_s16;

EMSCRIPTEN_KEEPALIVE
lyra_encoder* lyra_encoder_create(int sample_rate_hz,
                                  int num_channels,
                                  int bitrate,
                                  bool enable_dtx,
                                  const char* model_path);
EMSCRIPTEN_KEEPALIVE
lyra_vector_u8* lyra_encoder_encode(lyra_encoder* encoder,
                                    const int16_t* audio,
                                    size_t length);
EMSCRIPTEN_KEEPALIVE
void lyra_encoder_destroy(lyra_encoder* encoder);

EMSCRIPTEN_KEEPALIVE
lyra_decoder* lyra_decoder_create(int sample_rate_hz,
                                  int num_channels,
                                  const char* model_path);
EMSCRIPTEN_KEEPALIVE
bool lyra_decoder_set_encoded_packet(lyra_decoder* decoder,
                                     const uint8_t* encoded,
                                     size_t length);
EMSCRIPTEN_KEEPALIVE
lyra_vector_s16* lyra_decoder_decode_samples(lyra_decoder* decoder,
                                             int num_samples);
EMSCRIPTEN_KEEPALIVE
void lyra_decoder_destroy(lyra_decoder* decoder);

EMSCRIPTEN_KEEPALIVE
size_t lyra_vector_u8_get_size(lyra_vector_u8* v);
EMSCRIPTEN_KEEPALIVE
uint8_t* lyra_vector_u8_get_data(lyra_vector_u8* v);
EMSCRIPTEN_KEEPALIVE
void lyra_vector_u8_destroy(lyra_vector_u8* v);

EMSCRIPTEN_KEEPALIVE
size_t lyra_vector_s16_get_size(lyra_vector_s16* v);
EMSCRIPTEN_KEEPALIVE
int16_t* lyra_vector_s16_get_data(lyra_vector_s16* v);
EMSCRIPTEN_KEEPALIVE
void lyra_vector_s16_destroy(lyra_vector_s16* v);
}

#endif