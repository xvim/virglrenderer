/* This file is generated by venus-protocol git-e05ae158. */

/*
 * Copyright 2020 Google LLC
 * SPDX-License-Identifier: MIT
 */

#ifndef VN_PROTOCOL_RENDERER_CS_H
#define VN_PROTOCOL_RENDERER_CS_H

#include <assert.h>

/*
 * These types/functions are expected
 *
 *   struct vn_cs_encoder
 *   vn_cs_encoder_write
 *
 *   struct vn_cs_decoder
 *   vn_cs_decoder_set_fatal
 *   vn_cs_decoder_get_fatal
 *   vn_cs_decoder_lookup_object
 *   vn_cs_decoder_reset_temp_pool
 *   vn_cs_decoder_alloc_temp
 *   vn_cs_decoder_read
 *   vn_cs_decoder_peek
 *
 *   vn_object_id
 *   vn_cs_handle_indirect_id
 *   vn_cs_handle_load_id
 *   vn_cs_handle_store_id
 *   vn_cs_get_object_handle
 */
#include "vkr_cs.h"

struct vn_cs_encoder;
struct vn_cs_decoder;

typedef vkr_object_id vn_object_id;

static inline void
vn_cs_encoder_write(struct vn_cs_encoder *enc, size_t size, const void *val, size_t val_size)
{
   struct vkr_cs_encoder *e = (struct vkr_cs_encoder *)enc;
   vkr_cs_encoder_write(e, size, val, val_size);
}

static inline void
vn_cs_decoder_set_fatal(const struct vn_cs_decoder *dec)
{
   const struct vkr_cs_decoder *d = (struct vkr_cs_decoder *)dec;
   vkr_cs_decoder_set_fatal(d);
}

static inline bool
vn_cs_decoder_get_fatal(const struct vn_cs_decoder *dec)
{
   const struct vkr_cs_decoder *d = (struct vkr_cs_decoder *)dec;
   return vkr_cs_decoder_get_fatal(d);
}

static inline void *
vn_cs_decoder_lookup_object(const struct vn_cs_decoder *dec, vn_object_id id)
{
   const struct vkr_cs_decoder *d = (const struct vkr_cs_decoder *)dec;
   return vkr_cs_decoder_lookup_object(d, id);
}

static inline void
vn_cs_decoder_reset_temp_pool(struct vn_cs_decoder *dec)
{
   struct vkr_cs_decoder *d = (struct vkr_cs_decoder *)dec;
   vkr_cs_decoder_reset_temp_pool(d);
}

static inline void *
vn_cs_decoder_alloc_temp(struct vn_cs_decoder *dec, size_t size)
{
   struct vkr_cs_decoder *d = (struct vkr_cs_decoder *)dec;
   return vkr_cs_decoder_alloc_temp(d, size);
}

static inline void
vn_cs_decoder_read(struct vn_cs_decoder *dec, size_t size, void *val, size_t val_size)
{
   struct vkr_cs_decoder *d = (struct vkr_cs_decoder *)dec;
   vkr_cs_decoder_read(d, size, val, val_size);
}

static inline void
vn_cs_decoder_peek(const struct vn_cs_decoder *dec, size_t size, void *val, size_t val_size)
{
   const struct vkr_cs_decoder *d = (const struct vkr_cs_decoder *)dec;
   vkr_cs_decoder_peek(d, size, val, val_size);
}

static inline bool
vn_cs_handle_indirect_id(VkObjectType type)
{
   return vkr_cs_handle_indirect_id(type);
}

static inline vn_object_id
vn_cs_handle_load_id(const void **handle, VkObjectType type)
{
   return vkr_cs_handle_load_id(handle, type);
}

static inline void
vn_cs_handle_store_id(void **handle, vn_object_id id, VkObjectType type)
{
    vkr_cs_handle_store_id(handle, id, type);
}

static inline uint64_t
vn_cs_get_object_handle(const void **handle, VkObjectType type)
{
   const struct vkr_object *obj = *(const struct vkr_object **)handle;
   return obj ? obj->handle.u64 : 0;
}

static inline void
vn_encode(struct vn_cs_encoder *enc, size_t size, const void *data, size_t data_size)
{
   assert(size % 4 == 0);
   /* no vn_cs_encoder_reserve; vn_cs_encoder_write must do size check */
   /* TODO check if the generated code is optimal */
   vn_cs_encoder_write(enc, size, data, data_size);
}

static inline void
vn_decode(struct vn_cs_decoder *dec, size_t size, void *data, size_t data_size)
{
   assert(size % 4 == 0);
   vn_cs_decoder_read(dec, size, data, data_size);
}

#endif /* VN_PROTOCOL_RENDERER_CS_H */
