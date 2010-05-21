/*  
  FastLZ - lightning-fast lossless compression library

  Copyright (C) 2007 Ariya Hidayat (ariya@kde.org)
  Copyright (C) 2006 Ariya Hidayat (ariya@kde.org)
  Copyright (C) 2005 Ariya Hidayat (ariya@kde.org)

  Permission is hereby granted, free of charge, to any person obtaining a copy
  of this software and associated documentation files (the "Software"), to deal
  in the Software without restriction, including without limitation the rights
  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
  copies of the Software, and to permit persons to whom the Software is
  furnished to do so, subject to the following conditions:

  The above copyright notice and this permission notice shall be included in
  all copies or substantial portions of the Software.

  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
  THE SOFTWARE.
*/

#ifndef FASTLZ_H
#define FASTLZ_H

#include <inttypes.h>

#define flzuint8 uint8_t
#define flzuint16 uint16_t
#define flzuint32 uint32_t


#define FASTLZ_VERSION 0x000100

#define FASTLZ_VERSION_MAJOR     0
#define FASTLZ_VERSION_MINOR     0
#define FASTLZ_VERSION_REVISION  0

#define FASTLZ_VERSION_STRING "0.1.0"

#if defined (__cplusplus)
extern "C" {
#endif

/**
  Compress a block of data in the input buffer and returns the size of 
  compressed block. The size of input buffer is specified by length. The 
  minimum input buffer size is 16.

  The output buffer must be at least 5% larger than the input buffer  
  and can not be smaller than 66 bytes.

  If the input is not compressible, the return value might be larger than
  length (input buffer size).

  The input buffer and the output buffer can not overlap.
*/

int fastlz_compress(const void* input, int length, void* output);

/**
  Decompress a block of compressed data and returns the size of the 
  decompressed block. If error occurs, e.g. the compressed data is 
  corrupted or the output buffer is not large enough, then 0 (zero) 
  will be returned instead.

  The input buffer and the output buffer can not overlap.

  Decompression is memory safe and guaranteed not to write the output buffer
  more than what is specified in maxout.
 */

int fastlz_decompress(const void* input, int length, void* output, int maxout); 

/**
  Compress a block of data in the input buffer and returns the size of 
  compressed block. The size of input buffer is specified by length. The 
  minimum input buffer size is 16.

  The output buffer must be at least 5% larger than the input buffer  
  and can not be smaller than 66 bytes.

  If the input is not compressible, the return value might be larger than
  length (input buffer size).

  The input buffer and the output buffer can not overlap.

  Compression level can be specified in parameter level. At the moment, 
  only level 1 and level 2 are supported.
  Level 1 is the fastest compression and generally useful for short data.
  Level 2 is slightly slower but it gives better compression ratio.

  Note that the compressed data, regardless of the level, can always be
  decompressed using the function fastlz_decompress above.
*/  

int fastlz_compress_level(int level, const void* input, int length, void* output);

#if defined (__cplusplus)
}
#endif

#endif /* FASTLZ_H */