/*
 * EWF sectors section
 *
 * Copyright (c) 2006, Joachim Metz <forensics@hoffmannbv.nl>,
 * Hoffmann Investigations. All rights reserved.
 *
 * Refer to AUTHORS for acknowledgements.
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *
 * - Redistributions of source code must retain the above copyright notice,
 *   this list of conditions and the following disclaimer.
 * - Redistributions in binary form must reproduce the above copyright notice,
 *   this list of conditions and the following disclaimer in the documentation
 *   and/or other materials provided with the distribution.
 * - Neither the name of the creator, related organisations, nor the names of
 *   its contributors may be used to endorse or promote products derived from
 *   this software without specific prior written permission.
 * - All advertising materials mentioning features or use of this software
 *   must acknowledge the contribution by people stated in the acknowledgements.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDER, COMPANY AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef _EWF_SECTORS_H
#define _EWF_SECTORS_H

#include <unistd.h>
#include <stdio.h>

#ifdef __cplusplus
extern "C" {
#endif

#define EWF_SECTORS_CHUNK ewf_sectors_chunk_t

typedef uint8_t ewf_sectors_chunk_t;

EWF_SECTORS_CHUNK *ewf_sectors_chunk_alloc( uint32_t size );
EWF_SECTORS_CHUNK *ewf_sectors_chunk_realloc( EWF_SECTORS_CHUNK *sectors_chunk, uint32_t previous_size, uint32_t new_size );
EWF_SECTORS_CHUNK *ewf_sectors_chunk_wipe( EWF_SECTORS_CHUNK *sectors_chunk, uint32_t size );
void ewf_sectors_chunk_free( EWF_SECTORS_CHUNK *sectors_chunk );
int8_t ewf_sectors_chunk_uncompress( EWF_SECTORS_CHUNK *sectors_chunk, uint32_t *size, EWF_SECTORS_CHUNK *compressed_sectors_chunk, uint32_t compressed_size );
int8_t ewf_sectors_chunk_compress( EWF_SECTORS_CHUNK *compressed_sectors_chunk, uint32_t *compressed_size, EWF_SECTORS_CHUNK *sectors_chunk, uint32_t size, int8_t compression_level );
int32_t ewf_sectors_chunk_read( EWF_SECTORS_CHUNK *sectors_chunk, int file_descriptor, off_t offset, uint32_t size );
int32_t ewf_sectors_chunk_write( EWF_SECTORS_CHUNK *sectors_chunk, int file_descriptor, uint32_t size );
void ewf_sectors_chunk_fprint( FILE *stream, EWF_SECTORS_CHUNK *sectors_chunk );

#ifdef __cplusplus
}
#endif

#endif

